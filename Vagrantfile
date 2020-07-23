# -*- mode: ruby -*-
# vi: set ft=ruby :

# All Vagrant configuration is done below. The "2" in Vagrant.configure
# configures the configuration version (we support older styles for
# backwards compatibility). Please don't change it unless you know what
# you're doing.
Vagrant.configure("2") do |config|
		
		
		
  # The most common configuration options are documented and commented below.
  # For a complete reference, please see the online documentation at
  # https://docs.vagrantup.com.

  # Every Vagrant development environment requires a box. You can search for
  # boxes at https://vagrantcloud.com/search.
  config.vm.box = "kalilinux/rolling"

  # Disable automatic box update checking. If you disable this, then
  # boxes will only be checked for updates when the user runs
  # `vagrant box outdated`. This is not recommended.
  # config.vm.box_check_update = false

  # Create a forwarded port mapping which allows access to a specific port
  # within the machine from a port on the host machine. In the example below,
  # accessing "localhost:8080" will access port 80 on the guest machine.
  # NOTE: This will enable public access to the opened port
  # config.vm.network "forwarded_port", guest: 80, host: 8080

  # Create a forwarded port mapping which allows access to a specific port
  # within the machine from a port on the host machine and only allow access
  # via 127.0.0.1 to disable public access
  # config.vm.network "forwarded_port", guest: 80, host: 8080, host_ip: "127.0.0.1"

  # Create a private network, which allows host-only access to the machine
  # using a specific IP.
  # config.vm.network "private_network", ip: "192.168.33.10"

  # Create a public network, which generally matched to bridged network.
  # Bridged networks make the machine appear as another physical device on
  # your network.
  # config.vm.network "public_network"

  # Share an additional folder to the guest VM. The first argument is
  # the path on the host to the actual folder. The second argument is
  # the path on the guest to mount the folder. And the optional third
  # argument is a set of non-required options.
  # config.vm.synced_folder "../data", "/vagrant_data"

  # Provider-specific configuration so you can fine-tune various
  # backing providers for Vagrant. These expose provider-specific options.
  # Example for VirtualBox:
  #
	#config.vm.provider "virtualbox" do |vb|
    # Display the VirtualBox GUI when booting the machine
		#vb.gui = true
  
		#vb.customize ["modifyvm", :id, "--vram", "256"]
  
		#vb.memory = "1024"
   #end
  #

  # View the documentation for the provider you are using for more
  # information on available options.

  # Enable provisioning with a shell script. Additional provisioners such as
  # Ansible, Chef, Docker, Puppet and Salt are also available. Please see the
  # documentation for more information about their specific syntax and use.
  
	#this runs every time the vm boots, used for testing
	#config.vm.provision :shell, path: "vagrant/bootstrap2.sh", inline: <<-SHELL, run: 'always' 
	#	echo Routine startup procedure

	#SHELL
	
	#only runs the first time the vm boots (will run again after a vagrant destroy)
	config.vm.provision :shell, inline: <<-SHELL
		echo Preparing to install Visual Studio Code
		apt-get update
		sudo apt install curl gpg software-properties-common apt-transport-https
		curl -sSL https://packages.microsoft.com/keys/microsoft.asc | sudo apt-key add -
		echo "deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main" | sudo tee /etc/apt/sources.list.d/vscode.list
		sudo apt update
		sudo apt install code
		mkdir /home/vagrant/Documents/repos
		#git clone https://github.com/vipra-uwf/vipra.git /home/vagrant/Documents/repos
		#TODO ssh key
		#xrandr --output Virtual1 --mode 1680x1050 #doesn't work here for some reason
		sudo cp /usr/share/backgrounds/kali-16x9/kali-neon.png /usr/share/backgrounds/kali/kali-mesh-16x9.png
		sudo touch Desktop/start.sh
		echo "xrandr --output Virtual1 --mode 1680x1050" >> Desktop/start.sh
		chmod +x Desktop/start.sh
		echo Provisioning Completed	 
	SHELL
end



