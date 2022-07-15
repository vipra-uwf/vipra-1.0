

dist:
	cd ./VIPRA_Launcher/server && npm run build
	docker build . -t testdeploy
