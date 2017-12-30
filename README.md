# ksnip-deb-packaging
Repository for creating .deb binaries for ksnip

## Creating a Package from existing release

First step is getting the Repo from GitHub, run following command from a directory where you would like to create the package:
```
dporobic@linux:~/projects/$ git clone https://github.com/DamirPorobic/ksnip-deb-packaging.git
```

Switch to the branch that you want to build, in this example, we want to build version 1.4.0 on a 64bit system:
```
dporobic@linux:~/projects/$ cd ksnip-1.4.0/
dporobic@linux:~/projects/ksnip-1.4.0/$
```

Now you have the option to create the package with GPG singing (requires creating GPG Key upfront):
```
dporobic@linux:~/projects/ksnip-1.4.0/$ debuild
```
Or without signing:  
```
dporobic@linux:~/projects/ksnip-1.4.0/$ debuild -us -uc
```
Whatever option you choose, the build should run and succeed (when all dependencies ar fulfilled). The .deb file, 
along with some other files, should be in the parent directory:
```
dporobic@linux:~/projects/ksnip-1.4.0/$ cd ..
dporobic@linux:~/projects/$ ls *.deb
ksnip_1.4.0-1_amd64.deb
dporobic@linux:~/projects/$
```
