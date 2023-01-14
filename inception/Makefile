

all:
	docker-compose -f srcs/docker-compose.yml up --build

stop:
	docker-compose -f srcs/docker-compose.yml down -v

re: clean all

clean: stop
	@docker image rm nginx wordpress mariadb
	@docker volume rm srcs_mariadb_data srcs_wordpress_data

.PHONY:
	all stop clean