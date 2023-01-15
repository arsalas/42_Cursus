all: up

up:
	@docker-compose -f srcs/docker-compose.yml up --build

down:
	@docker-compose -f srcs/docker-compose.yml down -v

re: clean up

clean: down
	@docker image rm -f nginx wordpress mariadb
	@docker volume rm -f srcs_mariadb_data srcs_wordpress_data

.PHONY:
	all down clean re up