
<h1 align="center">Laboratoire Bazel</h1>

[![Pré-engagement](https://github.com/ThibFrgsGmz/BazelLab/actions/workflows/pre_commit.yaml/badge.svg)](https://github.com/ThibFrgsGmz/BazelLab/actions/workflows/pre_commit.yaml)

Un espace d'expérimentation conçu pour explorer les capacités de Bazel dans un environnement multi-langages.

Ce projet vise à approfondir la connaissance de la construction logicielle avec Bazel dans un environnement multi-langages. Il permet d'expérimenter avec des langages de programmation tels que le C++, Python et Rust. Le projet explore les avantages de Bazel pour la gestion des dépendances et l'optimisation des constructions dans un cadre diversifié. Créé pour faciliter l'apprentissage et l'innovation, "BazelLab" offre une chance d'améliorer la compétence en programmation et de comprendre les subtilités des systèmes de construction contemporains, tout en restant dans un environnement confortable et autodirigé.

## Utilisation de Bazelisk pour la gestion de projet

### Introduction à Bazelisk

Dans ce projet, nous imposons l'utilisation de [Bazelisk](https://github.com/bazelbuild/bazelisk) en tant que gestionnaire de version pour Bazel, notre principal outil de construction. Bazelisk sert d'enveloppe indispensable autour de Bazel, fournissant plusieurs avantages clés cruciaux pour le développement logiciel sophistiqué.

### Implications de ne pas utiliser Bazelisk

Négliger l'utilisation de Bazelisk dans ce projet pourrait entraîner plusieurs défis significatifs :

### Installation de Bazelisk

1. Pour installer Bazelisk et garantir une expérience de développement sans heurts, suivez ces étapes :

```sh
curl -LJO "https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-linux-amd64"
chmod +x bazelisk-linux-amd64
mv bazelisk-linux-amd64 /usr/local/bin/bazel
```

Pour vérifier l'installation, exécutez la commande suivante :

```sh
bazel version
```

2. Utilisation :
Utilisez la commande bazel comme d'habitude dans vos processus de construction.
Bazelisk gérera automatiquement la version de Bazel, s'alignant sur les spécifications de votre projet.


## Pré-engagement

Ce projet utilise pre-commit pour automatiser les contrôles de qualité du code avant de valider les modifications. pre-commit est un outil qui permet d'exécuter automatiquement une série de contrôles (hooks) sur vos fichiers à chaque validation. Cela garantit que le code soumis respecte les normes de qualité définies dans le projet.
Configuration

La configuration de pre-commit est définie dans le fichier .pre-commit-config.yaml à la racine du projet. Ce fichier spécifie les hooks à exécuter et la manière de les exécuter. Pour installer et configurer pre-commit localement, il suffit d'exécuter la commande suivante

```sh
pre-commit install
```

### Mise à jour et exécution des hooks

Pour mettre à jour les hooks de pre-commit et les exécuter sur tous les fichiers du projet, vous pouvez utiliser la commande suivante :

```sh
pre-commit autoupdate --freeze && pre-commit run -a
```

### Exécuter avec Bazel

Pour exécuter les hooks pre-commit avec Bazel, utilisez la commande suivante :

```sh
bazel run //scripts:lint
```

## Génération de la base de données de compilation avec Hedron

Hedron est un outil utile pour générer une base de données de compilation (compile database) à partir de projets Bazel. Cette base de données est essentielle pour l'intégration de Bazel avec des outils externes tels que les analyseurs statiques de code et les éditeurs de texte pour une meilleure prise en charge du développement.

Pour utiliser Hedron et générer une base de données de compilation, exécutez simplement la commande :

```sh
bazel run :refresh_compile_commands
```

## Gestion des dépendances avec Bazel

Dans ce projet, Bazel est utilisé pour maintenir et mettre à jour les dépendances Python. Les commandes ci-dessous sont utilisées pour assurer la cohérence des versions des dépendances à travers le développement.


```sh
bazel mod deps --lockfile_mode=update
```

```sh
bazel run //third_party/pip:requirements.update
```

Elles simplifient le processus de mise à jour et garantissent la compatibilité des dépendances, contribuant ainsi à la stabilité du projet.


## Tests de Fuzzing avec Bazel

Dans ce projet, nous utilisons des tests de fuzzing pour détecter des bogues, des vulnérabilités et des comportements inattendus dans notre code. Les tests de fuzzing consistent à injecter des données aléatoires ou semi-aléatoires dans notre programme pour tester sa robustesse.

### Configuration des Tests de Fuzzing

Pour exécuter les tests de fuzzing dans notre projet, nous avons configuré des options spécifiques dans Bazel pour utiliser les moteurs de fuzzing libFuzzer en combinaison avec AddressSanitizer (ASan) et UndefinedBehaviorSanitizer (UBSan) pour détecter les erreurs de mémoire et les comportements indéfinis dans notre code C/C++.

Voici les commandes de configuration pour les tests de fuzzing avec Bazel :

```starlark
build:asan-libfuzzer --@rules_fuzzing//fuzzing:cc_engine=@rules_fuzzing//fuzzing/engines:libfuzzer
build:asan-libfuzzer --@rules_fuzzing//fuzzing:cc_engine_instrumentation=libfuzzer
build:asan-libfuzzer --@rules_fuzzing//fuzzing:cc_engine_sanitizer=asan

build:ubsan-libfuzzer --@rules_fuzzing//fuzzing:cc_engine=@rules_fuzzing//fuzzing/engines:libfuzzer
build:ubsan-libfuzzer --@rules_fuzzing//fuzzing:cc_engine_instrumentation=libfuzzer
build:ubsan-libfuzzer --@rules_fuzzing//fuzzing:cc_engine_sanitizer=ubsan
```

Ces configurations nous permettent de détecter efficacement les erreurs et les bogues potentiels dans notre code, contribuant ainsi à améliorer sa qualité et sa fiabilité.

### Exécution des Tests de Fuzzing

Pour exécuter les tests de fuzzing avec les configurations définies, utilisez les commandes suivantes :

```starlark
bazel run --config=asan-libfuzzer //src/lib/containers:fuzz_test
bazel run --config=ubsan-libfuzzer //src/lib/containers:fuzz_test
```

Ces commandes lancent respectivement les tests de fuzzing avec les configurations ASan-libfuzzer et UBSan-libfuzzer sur notre code source situé dans le répertoire src/lib/containers.


# Codechecker

1. Checkout repository
2. Install LLVM
3. Get CodeChecker
    1. `pip3 install codechecker`
4. Prepare JSON compilation Database
    1. `bazel run :refresh_compile_commands`
5. Execute static analysis
    1. `CodeChecker analyze compile_commands.json --output external/tmp --jobs $(nproc)`
6. Parse and convert results to HTML
   1. `CodeChecker parse /mnt/c/Users/33673/Documents/codechecker --export "html" --output /mnt/c/Users/33673/Documents/codechecker/toto`
7. Store the result in the CodeChecker server/database (upload analysis of the main branch for diff with PR)
    1. `CodeChecker store  /mnt/c/Users/33673/Documents/codechecker/ --url "http://localhost:8001/Default" --name "Mon Premier Essai" --tag "UnTag"`
    2. Idea: create a baseline file from the reports which contains the legacy finding.
8. Diff current results against previously stored run
    1.
