# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|

	config.vm.box = "generic/ubuntu1804"
	#TODO remove this line, no longer attempting to use ssh
	config.ssh.forward_agent = true #needed for git repo ssh key

	config.vm.provider "virtualbox" do |vb|

	end

	#only runs the first time the vm boots (will run again after a vagrant destroy)
	config.vm.provision :shell, inline: <<-SHELL #run: 'always'
		set -x #echo on
		echo "$(tput setaf 6)$(tput bold)Setting up boost for odeint $(tput sgr 0)"
		sudo apt-get install libboost-dev -y

		echo "$(tput setaf 6)$(tput bold)Setting up Python 3.8 $(tput sgr 0)"
		sudo apt-get update
		sudo apt-get install build-essential zlib1g-dev libncurses5-dev libgdbm-dev libnss3-dev libssl-dev libreadline-dev libffi-dev libsqlite3-dev wget libbz2-dev -y
		wget https://www.python.org/ftp/python/3.8.5/Python-3.8.5.tgz
		tar -xf Python-3.8.5.tgz
		cd Python-3.8.5
		./configure --enable-optimizations
		sudo make altinstall
		sudo apt-get install -y python3.8-dev
		cd ..
		rm Python-3.8.5.tgz #cleanup

		sudo apt-get install make
		sudo apt-get install build-essential -y #installs g++

			#does not work
		#echo "$(tput setaf 6)$(tput bold)Setting up VIPRA $(tput sgr 0)"
		#mkdir -p ~/.ssh
		#chmod 700 ~/.ssh
		#ssh-keyscan -H github.com >> ~/.ssh/known_hosts
		#ssh -T git@github.com
		#git clone git@github.com:vipra-uwf/vipra.git # /home/vagrant/Documents/repos

			#setup git repo
		mkdir vipra
		cd ./vipra
		git init
		git remote add origin https://github.com/vipra-uwf/vipra.git
		mkdir VIPRA
		#use `sudo git pull origin master` and login once you're in the box

		#setup rapidxml (not tested)
		echo "$(tput setaf 6)$(tput bold)Setting up rapidxml $(tput sgr 0)"
		test -e rapidxml || sudo git clone --depth=1 --branch=master https://github.com/dwd/rapidxml.git ./VIPRA/rapidxml
		rm -rf ./vipra/rapidxml/.git

		echo Provisioning Completed
	SHELL
end
