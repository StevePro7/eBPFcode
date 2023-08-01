##### README.md
###### 31-Aug-2023

Reference: https://github.com/joaniedavis/cmock_example
<hr />
CMock installation

```
sudo apt install ruby
sudo apt install ruby-bundler
cd  ~/GitHub
mkdir ThrowTheSwitch
git clone --recursive https://github.com/throwtheswitch/cmock.git
cd cmock
bundle install
```
New Project
```
Launch Terminal
cd /home/stevepro
ceedling new HelloCCMock
Launch VS Code | Open Folder /home/stevepro/HelloCCMock
```
Hello CMock
```
Copy joaniedavis/cmock_example/inc files into HelloCeedling
Update project.yml to include "inc" folder
```
Test drive
```
cd /home/stevepro/HelloCCMock
ruby ~/GitHub/ThrowTheSwitch/cmock/lib/cmock.rb -oproject.yml inc/rectangle.h
```