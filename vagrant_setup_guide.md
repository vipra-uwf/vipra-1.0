## Installation

1. [Download & Install Vagrant](https://www.vagrantup.com/downloads.html) (240MB)

2. [Download & Install VirtualBox](https://www.virtualbox.org/wiki/Downloads) (101MB)

3. Restart computer

4. Verify local VIPRA repo is up to date

5. Create and configure VM
`username@hostname:~/vipra$ vagrant up`

6. Log in to VM 
`username: vagrant | password : vagrant`

7. Clone VIPRA repository
`vagrant@kali:~$ git clone https://github.com/vipra-uwf/vipra.git`

8. Navigate to VIPRA directory 
`vagrant@kali:~$ cd vipra/VIPRA`

9. Compile and execute VIPRA program 
`vagrant@kali:~/vipra/VIPRA$ make ccr`

---

## Additional commands

Shutdown VM
`username@hostname:~/vipra$ vagrant halt`

Launch VM
`username@hostname:~/vipra$ vagrant up`

Shutdown then launch VM
`username@hostname:~/vipra$ vagrant reload`

Rebuild VM to its original state
`username@hostname:~/vipra$ vagrant destroy`
`username@hostname:~/vipra$ vagrant up`
