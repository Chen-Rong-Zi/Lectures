### 1、请通过查询网络，在自己的Linux系统中安装zsh，并通过下面两个实验来比较zsh与bash的性能。 

1.1. 比较zsh和bash的启动时间。 （提示：使用命令time shell名字 -i -c exit） 
![bash_vs_zsh](/home/rongzi/Pictures/screenshot/24-07-27_10:55:07.png)

1.2. 设计一个简单的脚本，分别在zsh和bash中运行，测量其运行时间。
![找素数](/home/rongzi/Pictures/screenshot/24-07-27_11:32:55.png)

### 2、请通过查询网络，将用户的默认shell切换为zsh，并安装Oh My Zsh，给出如何通过修改zsh的配置文件来设置主题和插件，以及如何在不重新登录的情况下应用新配置的方法，并谈谈自己的使用体会。

2.1. change to zsh
![chsh](/home/rongzi/Pictures/screenshot/24-07-27_11:35:40.png)

2.2. theme and plugins
    2.2.1 oh-my-zsh的readme中说明，通过.zshrc中的theme变量来控制主题
![theme](/home/rongzi/Pictures/screenshot/24-07-27_11:44:52.png)
    2.2.2 修改`~/.zshrc`中的theme
![change theme variable](/home/rongzi/Pictures/screenshot/24-07-27_17:35:24.png)
    2.2.3 `source ~/.zshrc`使配置生效
![theme ls](/home/rongzi/Pictures/screenshot/24-07-27_11:48:22.png)


### 添加zsh-autosuggestions插件，根据`https://github.com/zsh-users/zsh-autosuggestions`仓库README.md文件的安装方法,
#### 3.1. 克隆仓库到`~/.oh-my-zsh/plugins`中,
![git clone](/home/rongzi/Pictures/screenshot/24-07-27_17:17:20.png)

克隆到本地

![git clone real](/home/rongzi/Pictures/screenshot/24-07-27_17:48:26.png)

#### 3.2. 在`~/.zshrc`中的plugins中加入zsh-autosuggestions
![plugins](/home/rongzi/Pictures/screenshot/24-07-27_17:25:14.png)
#### 3.3. `source ~/.zshrc`使配置生效

##### 3.3.1. 命令补全
![find prime](/home/rongzi/Pictures/screenshot/24-07-27_17:28:30.png)
##### 3.3.2. 脚本补全
![cat](/home/rongzi/Pictures/screenshot/24-07-27_17:28:22.png)
