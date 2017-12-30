# ksnip-deb-packaging
Repository for creating .deb binaries for [ksnip](https://github.com/DamirPorobic/ksnip)

## Creating a Package from existing release

First step is getting the Repo from GitHub, run following command from a directory where you would like to create the package:
```
dporobic@linux:~/$ git clone https://github.com/DamirPorobic/ksnip-deb-packaging.git
```

Switch to the version directory that you want to build, in this example, we want to build version 1.4.0 on a 64bit system:
```
dporobic@linux:~/$ cd ksnip-deb-packaging/ksnip-1.4.0/
dporobic@linux:~/ksnip-deb-packaging/ksnip-1.4.0/$
```

Now you have the option to create the package with GPG singing (requires creating GPG Key upfront):
```
dporobic@linux:~/ksnip-deb-packaging/ksnip-1.4.0/$ debuild
```
Or without signing:  
```
dporobic@linux:~/ksnip-deb-packaging/ksnip-1.4.0/$ debuild -us -uc
```
Whatever option you choose, the build should run and succeed (when all dependencies ar fulfilled). The .deb file, 
along with some other files, should be in the parent directory:
```
dporobic@linux:~/ksnip-deb-packaging/ksnip-1.4.0/$ cd ..
dporobic@linux:~/ksnip-deb-packaging/$ ls *.deb
ksnip_1.4.0-1_amd64.deb
dporobic@linux:~/ksnip-deb-packaging/$
```

## Adding a new version

We assume that the Repo was downloaded as explained in "Creating a Package from existing release".
In order to create a new version, we need first the source .tar.gz file for this new version. We are downloading the version 1.4.0,  please replace this number with the correct version:
```
dporobic@linux:~/ksnip-deb-packaging/$ wget https://github.com/DamirPorobic/ksnip/archive/v1.4.0.tar.gz
```
Next, rename the .tar.gz file so it has the correct format:
```
dporobic@linux:~/ksnip-deb-packaging/$ mv v1.4.0.tar.gz ksnip_1.4.0.orig.tar.gz
```
Lets unpack the .tar.gz file and create a sup directory for the package files:
```
dporobic@linux:~/ksnip-deb-packaging/$ tar -xf ksnip_1.4.0.orig.tar.gz
dporobic@linux:~/ksnip-deb-packaging/$ cd ksnip-1.4.0/
dporobic@linux:~/ksnip-deb-packaging/ksnip-1.4.0/$ mkdir debian
dporobic@linux:~/ksnip-deb-packaging/ksnip-1.4.0/$ cd debian
dporobic@linux:~/ksnip-deb-packaging/ksnip-1.4.0/debian/$
```
Now we need some packaging files, we can use the same files that were used for a previous version, but update the changelog
and other files if required:
```
dporobic@linux:~/ksnip-deb-packaging/ksnip-1.4.0/debian/$ cp -r ../../ksnip-1.3.2/debian/{changelog,copyright,rules,compat,control,source} .
```
Now update any files that require updating, probably changelog and eventually other files too. When this done, you can return to the version parent directory and build the package as explained in "Creating a Package from existing release".
