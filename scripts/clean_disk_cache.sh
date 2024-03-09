#!/usr/bin/env bash
#
# Ce script nettoie les fichiers du cache disque de Bazel qui n'ont pas été utilisés depuis un certain nombre de jours spécifié.

set -eu

# Par défaut, utilisez le même répertoire que dans le fichier `.blazerc` du projet, mais vous pouvez définir
# cette variable d'environnement pour la remplacer.
: ${BAZEL_DISK_CACHE_PATH:=~/.cache/bazel}

# Détermine le nombre de jours à partir des arguments de ligne de commande, ou utilise la valeur par défaut de 30 jours.
jours="${1:-30}"

# Affiche un message indiquant le nettoyage des fichiers inutilisés depuis plus de $jours jours dans le cache Bazel.
echo "Nettoyage des fichiers inutilisés depuis plus de $jours jours dans le cache Bazel."

# Calcule et affiche quelques statistiques approximatives sur le nombre de fichiers à supprimer.
nombre_total_fichiers=$(find "$BAZEL_DISK_CACHE_PATH" -type f | wc -l)
nombre_fichiers_obsoletes=$(find "$BAZEL_DISK_CACHE_PATH" -type f -atime +$jours | wc -l)
echo "Suppression de $nombre_fichiers_obsoletes fichiers sur un total de $nombre_total_fichiers."

# Affiche une demande de confirmation à l'utilisateur avant de supprimer les fichiers, sauf si l'option "--force" est spécifiée.
if [[ ! "$*" =~ "--force" ]]; then
    read -rp "Appuyez sur Entrée pour supprimer les fichiers obsolètes, ou Ctrl+C pour annuler."
fi

# Supprime les fichiers obsolètes en utilisant la commande find avec l'option -delete.
find "$BAZEL_DISK_CACHE_PATH" -type f -atime +$jours -print0 | while IFS= read -r -d '' file; do
    if [[ -w "$file" ]]; then
        rm -f "$file"
    else
        echo "Permission refusée pour supprimer $file."
    fi
done
