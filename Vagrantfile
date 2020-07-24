# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|
		
	config.vm.box = "kalilinux/rolling"
	config.ssh.forward_agent = true #needed for git repo ssh key
 
	
	#only runs the first time the vm boots (will run again after a vagrant destroy)
	config.vm.provision :shell, inline: <<-SHELL #run: 'always' 
		#INSTALLING VISUAL STUDIO CODE
		echo Preparing to install Visual Studio Code
		apt-get update
		sudo apt install curl gpg software-properties-common apt-transport-https
		curl -sSL https://packages.microsoft.com/keys/microsoft.asc | sudo apt-key add -
		echo "deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main" | sudo tee /etc/apt/sources.list.d/vscode.list
		sudo apt update
		sudo apt install code
		
		#SETTING UP REPO
		mkdir /home/vagrant/Documents/repos
		#sudo apt-get update
		#sudo apt-get install -y git
		mkdir -p ~/.ssh
		chmod 700 ~/.ssh
		ssh-keyscan -H github.com >> ~/.ssh/known_hosts
		ssh -T git@github.com
		git clone git@github.com:vipra-uwf/vipra# /home/vagrant/Documents/repos
		
		#SETTING UP OPTIONAL START SCRIPT
		sudo cp /usr/share/backgrounds/kali-16x9/kali-neon.png /usr/share/backgrounds/kali/kali-mesh-16x9.png
		sudo touch Desktop/start.sh
		echo "xrandr --output Virtual1 --mode 1680x1050" >> Desktop/start.sh
		chmod +x Desktop/start.sh
		echo Provisioning Completed
	SHELL
end



