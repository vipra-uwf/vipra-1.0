1. Download vagrant from [vagrantup.com](https://www.vagrantup.com/downloads.html) (240MB) and install it


2. Download VirtualBox from [virtualbox.org](https://www.virtualbox.org/wiki/Downloads) (101MB) and install it


3. You’ll need to restart your computer after installing VirtualBox


4. Make sure your VIPRA repo is up-to-date


5. cd to the VIPRA repo and run `$ vagrant up`, this may take a while.  The vm will launch when it’s done


6. Once the VM boots, login with vagrant for the username and password


7. Run `$ git clone https://github.com/vipra-uwf/vipra.git Documents/repos`


8. Run `$ cd Documents/repos/vipra/VIPRA`


9. Run `$ make ccr` to make sure it works




##Additional commands
To shut down the vm run `$ vagrant halt`


To launch the vm run `$ vagrant up`


`$ vagrant reload` is the same as running `$ vagrant halt` and `$ vagrant up`


To rebuild the vm to its original state run `$ vagrant destroy` and then `$ vagrant up`, it won’t take as long as in the first setup because it doesn’t have to download the box again