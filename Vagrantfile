# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|

	config.vm.box = "generic/debian10"
	#config.ssh.forward_agent = true #needed for git repo ssh key

	config.vm.provider "virtualbox" do |vb|
	    # Display the VirtualBox GUI when booting the machine
	    vb.gui = true

	    # Customize the amount of memory on the VM:
	    # vb.memory = "1024"
	end


	#only runs the first time the vm boots (will run again after a vagrant destroy)
	config.vm.provision :shell, inline: <<-SHELL #run: 'always'
		echo Setting up GUIs
		sudo apt-get update
		#dpkg --configure -a #another possible fix?
		sudo tasksel install desktop kde-desktop #install desktop environment
		startx
		#sudo apt-get install lightdm -y #install display manager
		#sudo dpkg-reconfigure lightdm #set default display manager
		#sudo systemctl start lightdm #start the display manager

		#INSTALLING VISUAL STUDIO CODE
#		echo Preparing to install Visual Studio Code
#		apt update
#		sudo apt install curl gpg software-properties-common apt-transport-https
#		curl -sSL https://packages.microsoft.com/keys/microsoft.asc | sudo apt-key add -
#		echo "deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main" | sudo tee /etc/apt/sources.list.d/vscode.list
#		sudo apt update
#		sudo apt install code

		#SETTING UP REPO
#		mkdir /home/vagrant/Documents/repos
		#sudo apt-get update
		#sudo apt-get install -y git
#		mkdir -p ~/.ssh
#		chmod 700 ~/.ssh
#		ssh-keyscan -H github.com >> ~/.ssh/known_hosts
#		ssh -T git@github.com
#		git clone git@github.com:vipra-uwf/vipra # /home/vagrant/Documents/repos

		#SETTING UP OPTIONAL START SCRIPT
#		sudo cp /usr/share/backgrounds/kali-16x9/kali-neon.png /usr/share/backgrounds/kali/kali-mesh-16x9.png

		#sudo touch Desktop/start.sh
		#echo "xrandr --size 1366x768" >> Desktop/start.sh
		#echo "lookandfeeltool -a org.kde.breezedark.desktop" >> Desktop/start.sh
		#chmod +x Desktop/start.sh
		echo Provisioning Completed
	SHELL
end
