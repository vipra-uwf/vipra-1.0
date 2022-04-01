# TODO make build script

VIPRA_DIR = ./VIPRA
GENERATED_DIR = ${VIPRA_DIR}/input_data

deploy:
	docker build -t $@ .

generateDocker:
	docker build -t container${CONFIG_ID} ${GENERATED_DIR} -e configID=${CONFIG_ID}