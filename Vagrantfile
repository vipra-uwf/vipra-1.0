# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|

	config.vm.box = "generic/debian10"
	#config.ssh.forward_agent = true #needed for git repo ssh key

	config.vm.provider "virtualbox" do |vb|
	    # Display the VirtualBox GUI when booting the machine
	    #vb.gui = true

	    # Customize the amount of memory on the VM:
	    # vb.memory = "1024"
	end


	#only runs the first time the vm boots (will run again after a vagrant destroy)
	config.vm.provision :shell, inline: <<-SHELL #run: 'always'
		#set -x #echo on
		echo Setting up boost...
		sudo apt-get install libboost-dev

		echo Setting up VIPRA repo
		mkdir /home/vagrant/Documents/repos
		git clone https://github.com/vipra-uwf/vipra.git /home/vagrant/Documents/repos

			#ssh key stuff, not working yet
		#mkdir -p ~/.ssh
		#chmod 700 ~/.ssh
		#ssh-keyscan -H github.com >> ~/.ssh/known_hosts
		#ssh -T git@github.com
		#git clone git@github.com:vipra-uwf/vipra # /home/vagrant/Documents/repos

		echo Provisioning Completed
	SHELL
end
