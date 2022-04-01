
VIPRA_DIR = ./VIPRA
GENERATED_DIR = ${VIPRA_DIR}/input_data

deploy:
	docker build -t $@ .

generateDocker:
	docker build --build-args CONFIGID=${CONFIG_ID} -t container${CONFIG_ID} ${GENERATED_DIR}