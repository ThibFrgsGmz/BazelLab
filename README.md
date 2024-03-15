# BazelLab
A space for experimentation designed to explore Bazel's capabilities in a multi-language environment.

This project aims to deepen knowledge of software building with Bazel in a multi-language environment. It allows for experimentation with programming languages such as C++, Python, and Rust. The project explores the benefits of Bazel for managing dependencies and optimizing builds in a diverse framework. Created to facilitate learning and innovation, "BazelLab" offers a chance to enhance programming proficiency and comprehend the intricacies of contemporary build systems, all while remaining in a comfortable and self-directed environment.


## Utilizing Bazelisk for Project Management

### Introduction to Bazelisk

In this project, we mandate the use of [Bazelisk](https://github.com/bazelbuild/bazelisk) as the version manager for Bazel, our primary build tool. Bazelisk serves as an indispensable wrapper around Bazel, providing several key benefits crucial for sophisticated software development:

- **Automated Bazel Version Management**: Bazelisk ensures uniformity across the development lifecycle by enforcing the usage of a specific Bazel version, as declared in the .bazelversion file. This uniformity mitigates build inconsistencies and compatibility issues across different Bazel versions.
- **Ease of Use and Consistency**: By automating the Bazel version updates, Bazelisk simplifies the developer experience, eliminating the need for manual management and potential version mismatches.
- **Optimized Continuous Integration**: Bazelisk’s alignment of Bazel versions between local development environments and CI/CD pipelines ensures reproducible builds, crucial for reliable and efficient software deployment.

### Implications of Not Using Bazelisk

Neglecting the use of Bazelisk in this project could lead to several significant challenges:

- **Version Inconsistency**: Developers might end up using divergent Bazel versions, leading to non-reproducible builds and unexpected build failures.
- **Management Overhead**: Manual version management of Bazel is not only tedious but also prone to human error, which can be detrimental in a high-stakes development environment.
- **CI/CD Complications**: Discrepancies in Bazel versions between development and CI/CD environments can result in unforeseen failures during integration and deployment processes.

### Installing Bazelisk

1: To install Bazelisk and ensure a seamless development experience, follow these steps:

- Download Bazelisk:
    - For Unix-based systems (Linux/MacOS), execute:
```sh
curl -LJO "https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-linux-amd64"
chmod +x bazelisk-linux-amd64
mv bazelisk-linux-amd64 /usr/local/bin/bazel
```

2. Verify the Installation:
Run bazel version to ensure that Bazelisk has been correctly installed and is operational.

3. Usage:
Utilize the bazel command as usual in your build processes. Bazelisk will automatically manage the Bazel version, aligning with the specifications in your project.


# pre-commit

Ce projet utilise pre-commit pour automatiser les contrôles de qualité du code avant de valider les modifications. pre-commit est un outil qui vous permet d'exécuter automatiquement une série de contrôles (hooks) sur vos fichiers à chaque validation. Cela permet de s'assurer que le code soumis respecte les standards de qualité définis dans le projet.

## Configuration

La configuration de pre-commit est définie dans le fichier .pre-commit-config.yaml à la racine du projet. Ce fichier spécifie les hooks à exécuter et la manière de les exécuter. Pour installer et configurer pre-commit localement, il suffit d'exécuter la commande suivante :

```sh
pre-commit install
```

Ceci installera les hooks pre-commit dans votre dépôt local et les exécutera automatiquement à chaque validation.

## Mise à jour et exécution des hooks

Pour mettre à jour les hooks de pre-commit et les exécuter sur tous les fichiers du projet, vous pouvez utiliser la commande suivante :


```sh
pre-commit autoupdate --freeze && pre-commit run -a
```

Cela mettra à jour les crochets de pré-commission selon la configuration spécifiée dans votre fichier .pre-commit-config.yaml et exécutera ensuite ces crochets sur tous les fichiers du projet.

## Exécuter avec Bazel

Pour exécuter les hooks pre-commit avec Bazel, utilisez la commande suivante :

```sh
bazel run //scripts:lint
```

Cette commande exécutera les crochets de pré-commission spécifiés dans votre configuration de pré-commission à l'aide de Bazel. Assurez-vous que Bazel est correctement configuré et installé sur votre système avant d'exécuter cette commande.
