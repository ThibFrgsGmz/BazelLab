#pragma once

#include <cmath>
#include <algorithm>

enum class RampMode {
    RATE,
    DURATION
};

class Ramp {
public:
    /// Constructeur pour initialiser la rampe.
    ///
    /// @param mode Le mode de la rampe : RATE ou DURATION.
    /// @param start_value La valeur de départ de la rampe.
    /// @param target_value La valeur cible que la rampe doit atteindre.
    /// @param rate_or_duration Le taux (pour le mode RATE) ou la durée (pour le mode DURATION) de la rampe.
    ///                         Dans le mode RATE, il représente la vitesse de montée/descente de la rampe en unités par seconde.
    ///                         Dans le mode DURATION, il représente le temps total pour atteindre la valeur cible en secondes.
    Ramp(RampMode mode, double start_value, double target_value, double rate_or_duration)
        : _mode(mode),
          _start_value(start_value),
          _current_value(start_value),
          _target_value(target_value),
          _rate_or_duration(rate_or_duration > 0.0 ? rate_or_duration : 1.0) {}

    /// Met à jour la valeur actuelle de la rampe en fonction du temps écoulé.
    ///
    /// @param delta_t Temps écoulé depuis la dernière mise à jour, en secondes.
    /// @return La nouvelle valeur actuelle de la rampe après la mise à jour.
    ///
    /// La méthode calcule la nouvelle valeur de la rampe en fonction du mode de rampe. Si le mode est RATE, la méthode ajuste
    /// la valeur en fonction du taux de changement et du temps écoulé. Si le mode est DURATION, la méthode ajuste la valeur
    /// en fonction de la durée écoulée par rapport au temps total de la rampe.
    double update(double delta_t) {
        if (_finished) {
            return _current_value;
        }

        if (_mode == RampMode::RATE) {
            double distance_to_target = _target_value - _current_value;
            double max_movement = _rate_or_duration * delta_t;

            if (std::abs(distance_to_target) <= max_movement) {
                _current_value = _target_value;
                _finished = true;
            } else {
                _current_value += (distance_to_target > 0 ? max_movement : -max_movement);
            }
        } else if (_mode == RampMode::DURATION) {
            _elapsed_time += delta_t;
            if (_elapsed_time >= _rate_or_duration) {
                _current_value = _target_value;
                _finished = true;
            } else {
                _current_value = _start_value + (_target_value - _start_value) * (_elapsed_time / _rate_or_duration);
            }
        }

        return _current_value;
    }

    /// Réinitialise la rampe avec de nouvelles valeurs.
    ///
    /// @param mode Le mode de la rampe : RATE ou DURATION.
    /// @param start_value Nouvelle valeur de départ de la rampe.
    /// @param target_value Nouvelle valeur cible de la rampe.
    /// @param rate_or_duration Nouveau taux ou durée pour la rampe.
    ///                         Dans le mode RATE, il représente la vitesse de montée/descente de la rampe en unités par seconde.
    ///                         Dans le mode DURATION, il représente le temps total pour atteindre la valeur cible en secondes.
    void reset(RampMode mode, double start_value, double target_value, double rate_or_duration) {
        _mode = mode;
        _start_value = start_value;
        _current_value = start_value;
        _target_value = target_value;
        _rate_or_duration = (rate_or_duration > 0.0) ? rate_or_duration : 1.0;
        _elapsed_time = 0.0;
        _finished = false;
    }

    /// Obtient la valeur actuelle de la rampe.
    ///
    /// @return La valeur actuelle de la rampe.
    ///
    /// La méthode retourne la valeur actuelle de la rampe après la dernière mise à jour.
    double get_current_value() const {
        return _current_value;
    }

    /// Vérifie si la rampe a atteint la valeur cible.
    ///
    /// @return Vrai si la rampe a atteint la valeur cible, sinon faux.
    ///
    /// La méthode retourne vrai si la rampe a terminé sa montée ou descente et a atteint la valeur cible. Sinon, elle retourne faux.
    bool is_finished() const {
        return _finished;
    }

private:
    RampMode _mode{}; ///< Mode de la rampe (RATE ou DURATION).
    double _start_value{}; ///< Valeur de départ de la rampe.
    double _current_value{}; ///< Valeur actuelle de la rampe.
    double _target_value{}; ///< Valeur cible de la rampe.
    double _rate_or_duration{}; ///< Taux ou durée pour la rampe, en fonction du mode.
    double _elapsed_time{}; ///< Temps écoulé depuis le début de la rampe, uniquement en mode DURATION.
    bool _finished{}; ///< Indique si la rampe a terminé son mouvement.
};
