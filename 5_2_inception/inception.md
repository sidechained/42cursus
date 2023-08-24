Aim is to create an infrastructure of services, each in own docker container (named after the service) running on a VM running Debian

# What is docker compose?

Docker Compose is a tool that allows you to define and manage multi-container Docker applications. It uses a YAML file to define the services, networks, and volumes required for your application to run. With Docker Compose, you can easily orchestrate the deployment of interconnected containers, specifying their configurations and relationships in a single file. This simplifies the process of setting up and managing complex applications that consist of multiple interacting services. It's particularly useful for development, testing, and staging environments, as it enables consistent and reproducible setups across different systems.

# Example of docker-compose.yml

Here's a concise example of a docker-compose.yml file for a simple web application:

```
version: '3'
services:
  web:
    image: nginx:latest
    ports:
      - "80:80"
```

This example defines a single service named "web" using the NGINX official image. It maps port 80 from the host to port 80 in the container, allowing access to the NGINX web server.

# What is a Dockerfile?

A Dockerfile is a text-based configuration file used in Docker to define the steps and commands needed to create a Docker image. It specifies the base image, installation of software packages, copying files into the image, setting environment variables, and configuring the containerized application. When the Dockerfile is used to build an image, each instruction results in a new layer that contributes to the final image. This image can then be used to run isolated and portable containers containing the application and its dependencies.
	
# What are the best practices for writing Dockerfiles and how does PID 1 come into that?

- Use Official Base Images: Start with official and trusted base images from Docker Hub to ensure security and stability.
- Keep Images Small: Minimize the number of layers and installed components to reduce image size and improve performance.
- Use Layer Caching Wisely: Order instructions from least likely to change to most likely to change to leverage Docker's caching mechanism effectively.
- Combine RUN Instructions: Combine multiple RUN commands using && to reduce the number of layers created.
- Clean Up After RUN: Remove unnecessary files, caches, and temporary artifacts in the same RUN instruction to avoid bloating the image.
- Use COPY Instead of ADD: Prefer COPY over ADD for copying files to the image, as it's simpler and doesn't include extra features like URL fetching.
- Minimize Number of Instructions: Keep the number of instructions in the Dockerfile to a minimum to enhance readability and maintainability.
- Specify Work Directory: Use the WORKDIR instruction to set a consistent working directory within the container.
- Use .dockerignore: Create a .dockerignore file to exclude unnecessary files from being copied into the image.
- Use ENTRYPOINT or CMD: Specify the main process using ENTRYPOINT or CMD to ensure the container starts the desired application.

# What is PID 1?

In traditional Linux systems, PID 1 is the first process that is started when the operating system boots up. It plays a crucial role in process management and system initialization. However, running PID 1 in a Docker container requires special considerations.

When writing Dockerfiles, it's important to ensure that the main process of the container (often defined using CMD or ENTRYPOINT) effectively becomes PID 1. This is essential because PID 1 is responsible for reaping orphaned child processes and handling signals. If the main process is not properly configured as PID 1, certain signals like SIGTERM, which are used for graceful container shutdown, might not be handled correctly.

To address this, Docker provides an option called "tini" (short for "Tiny Init") that can be used as a lightweight init system. Tini ensures proper signal handling and reaping of child processes, making it suitable for serving as PID 1 within a container. Including Tini as your container's entrypoint can help ensure proper process management and signal handling, aligning with best practices for writing Dockerfiles.

# How is a Makefile used to create Docker images?

It must set up your entire application (i.e., it has to build the Docker images using docker-compose.yml).

A Makefile is a text file used to automate tasks, often in software development. While it's not the most common tool for creating Docker images (Dockerfiles are typically used for that purpose), you can use a Makefile to streamline the process of building and managing Docker images along with other tasks.

Here's a basic example of how a Makefile can be used to create Docker images:

```
# Define variables
COMPOSE_FILE = docker-compose.yml

.PHONY: build up down

# Build the Docker images
build:
	docker-compose -f $(COMPOSE_FILE) build

# Start the containers
up:
	docker-compose -f $(COMPOSE_FILE) up -d

# Stop and remove the containers
down:
	docker-compose -f $(COMPOSE_FILE) down
```

In this Makefile:

- COMPOSE_FILE variable specifies the path to your docker-compose.yml file.
- build target uses docker-compose build to build the images specified in the compose file.
- up target uses docker-compose up -d to start the containers in detached mode.
- down target uses docker-compose down to stop and remove the containers.
You can save this content into a file named Makefile in the same directory as your docker-compose.yml file. To use it, navigate to that directory in your terminal and run commands like make build, make up, and make down to build the images and start or stop the containers as needed.

# Other Rules

Must build the docker images yourself

Setup: 
- container: NGINX with TLSv1.2 or TLSv1.3 only
- container: WordPress + php-fpm (installed & configured) only without nginx
	- wordpress db must have two users one of which is admin
	- admin username can’t contain admin/Admin or administrator/Administrator (e.g., admin, administrator, Administrator, admin-123 etc).
- container: MariaDB only without nginx.
• volume: A volume that contains your WordPress database.
• volume: A second volume that contains your WordPress website files.
- volumes will be available in the /home/login/data folder. replace login with your own
• network: establishes connection between containers
Containers must restart in case of a crash.

configure your domain name so it points to your local IP address.
This domain name must be login.42.fr
use your own login
For example, if your login is wil, wil.42.fr will redirect to the IP address pointing to wil’s website.

# Also: 
- The latest tag is prohibited.
- No password must be present in your Dockerfiles.
- It is mandatory to use environment variables.
- Also, it is strongly recommended to use a .env file to store environment variables. The .env file should be located at the root of the srcs directory.
- Your NGINX container must be the only entrypoint into your infrastructure via the port 443 only, using the TLSv1.2 or TLSv1.3 protocol.
