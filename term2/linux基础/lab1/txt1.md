### 1. 在/tmp下新建一个名为test的目录。
!['mkdir test'](/home/rongzi/Pictures/screenshot/24-07-24_15:50:41.png)

### 2. 用命令man查看命令touch的使用手册。
![man touch](/home/rongzi/Pictures/screenshot/24-07-24_17:24:05.png)

### 3. 用命令touch在test目录中新建一个名为test的文件。
![touch test](/home/rongzi/Pictures/screenshot/24-07-24_16:03:27.png)

### 4. 用命令echo将以下内容一行一行地写入test文件。
#!/bin/sh
curl --head --silent https://www.nju.edu.cn
![redirection](/home/rongzi/Pictures/screenshot/24-07-24_16:04:21.png)

### 5. 尝试执行这个文件，即将该脚本的路径（./test）输入到您的shell中并回车。如果程序无法执行，请使用ls命令来获取信息并给出其不能执行的原因。
![run test](/home/rongzi/Pictures/screenshot/24-07-24_16:05:06.png)

### 6. 查看命令chmod的手册，使用命令chmod改变test文件的权限，使 ./test 能够成功执行，不要使用sh test来执行该程序。
![tldr chmod](/home/rongzi/Pictures/screenshot/24-07-24_17:25:03.png)
![run test success](/home/rongzi/Pictures/screenshot/24-07-24_16:07:46.png)

### 7. 请问你的shell是如何知道这个文件需要使用sh来解析的。请通过网络搜索“unix shebang”来了解更多信息。
shell的命令执行步骤
    1. 命令扩展(本次lab不涉及)
    2. 命令执行
        + 如果命令a是一个shell函数，执行函数并退出，否则下一步
        + 如果命令是一个shell内置命令，执行命令并推出，否则下一步
        + 搜索PATH中的目录如果有对应的程序，运行程序，否则下一步
        + 如果操作系统不能处理这种可执行文件的格式，并且程序是一个#!开头的非目录文件，那么第一行的其余部分指定了这个程序的解释器。
    解释器的参数由下面三部分组成：程序第一行中解释器名称之后的可选的一个参数， 程序的名称，命令行参数，如果有的话。
bash的man手册中关于#!的部分
![shebang](/home/rongzi/Pictures/screenshot/24-07-24_17:27:16.png)

### 8. 请使用 | 和 > ，将test文件输出的最后5行内容写入自己主目录下的last-5-lines.txt文件中。
![last-5-lines](/home/rongzi/Pictures/screenshot/24-07-24_16:24:53.png)

