# CodeChecker Deployment flow

## Docker 

Docker provides a way to run applications securely isolated in a container, packaged with all its dependencies and libraries.

- [Install Docker](https://www.digitalocean.com/community/tutorials/how-to-install-and-use-docker-on-ubuntu-22-04)
- [Install Docker Compose](https://www.digitalocean.com/community/tutorials/how-to-install-and-use-docker-compose-on-ubuntu-22-04)


### Deploy server with Sqlite

Docker Compose is a tool for defining and running multi-container Docker applications.

CodeChecker server can be easily run by defining the services that make up your app in docker-compose.yml so they can be run together in an isolated environment.

To run a simple CodeChecker server with SQLite database run:

```sh
docker compose -f docker-compose.sqlite.yml up -d
```

### Run the analysis

```sh
docker build -t codechecker-analysis-image -f tools/lint/Dockerfile.analysis .
docker start codechecker-analyzer
docker exec -it codechecker-analyzer /bin/bash
```