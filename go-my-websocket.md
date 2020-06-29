# 造轮子 Websocket 现在就 Go
MD: 2019‎年‎12‎月17‎日，‏‎03:45:10

笔者坚果有幸从事软件开发，一直都是兴趣驱动的工作。第一次接触计算机是 1999 年后，用来学习的电脑是大哥买来准备学 CAD 的 486 机，当时 CPU 还是威胜的 333MHz 主频，硬盘也只有 4GB，系统是 Windows 98 SE。那时所谓的学电脑纯属拆玩具模式，手上可用的资源不多，网络也不发达，没有太丰富的参考资料，相关的图书也不算丰富。翻查硬盘或系统光盘文件都能成了日常活动，除此之外，DOS 游戏也和红白机具有一样的可玩性。彼时，BAT 脚本和 Windows 系统光盘中 QBasic 脚本编程工具成了不错的好玩具。后来玩起了 Visual Studio 6.0，主要是 VB 和 VBA 脚本编程，C 语言也开始了解一些，C++ 几乎没有基础可言，所以 Visual C++ 一直玩不动 MFC 什么的更是不知云云。当然了，集成开发工具提供的最大的好处也就体现在这，即使你是个傻瓜也能毫不費力地运行配置好的模板程序，编译成完整的可运行程序。不知不觉，坚果从曾经的傻瓜程序员一路走到今天，没有兴趣带领还真不会有今天。

[TOC]

## 内容提要

这是我二进 GitChat 的创作，距离今年 ‎6 ‎月分‎第一次发布《从 JavaScript 入门到 Vue 组件实践》大谈前端技术全局观、30' JavaScript 入门课，还有 VSCode 和 Sublime 这些好用的开发工具。到如今已经有近半年时间，‎期间经历了较大的工作变动，技术上已经由脚本后端转到 Golang 为主，这是一种一直期待的语言。期间也学到一些技术领域比较不容易学习到的知识，有项目管理层面的，有职业规划方面的，对知识付费时代也有了更深入的理解。

那么 Golang 作为一款以便利的并发编程的语言，用在后端的开发真的是不要太好。

Golang 虽然它已经有 10 岁大了，最早接触也是 2012 年左右，但是真正花心思学起来是今年的 7 月份。Golang 号称 21 世纪的 C 语言，这确实是对我最大的吸引力，它的特点可以总结为 C + OOP，以松散组合的方式去实现面向对象的编程思维。完全不像 C++ 把对象数据模型设计的异常复杂，把一种编程语言搞得自己发明人都不能完全掌握。当然每种语言都有它的适用领域及特点，免不了一堆人贬低 Golang 没有泛型之类，确实 Golang 1.x 就是没有提供实现。如日中天的 Python 就是个典型，作为奇慢的脚本解析型语言，慢这个缺点完全掩盖不了它中人工智能算法领域的应用，也完全阻挡不了爬虫一族赖以为生。这种取舍其实就是一种效益的体现，选择恰当的工具做适合的事！

我们将从网络协议层面来打开 Golang 编程大门，学习关于 Websocket 网络协议的相关知识点，在 TCP/IP 协议栈中，新加入的 Websocket 分量也是重量级的。WebSocket 作为实时性要求较高场合的应用协议，主要应用在在线网页聊天室、页游行业等等。掌握 Websocket 技能，你值得拥有！


在本轮学习中，你可以 Get 到技能：

- 如何拥有快速掌握一种计算机语言的能力；
- 入门 TCP/IP 协议森林；
- telnet 工具的使用；
- 理解几个基本网络概念：
	- Persistent connection 长连接；
	- Temporary connection 短连接；
	- Polling 轮询；
	- LongPolling 长轮询；
- Websocket 核心的数据帧 Data Framing 构造；
- Websocket 握手连接建立数据通讯过程；
- 实现一个 go-my-websocket 简约版 Websocket 服务器；
- 深入分解 Golang 的 Engine.io 及 Socket.io 的应用；
- 获得一份完整的电子版 PDF；
- 获得一份完整的 go-my-websocket 代码；
- 通过交流活动获得问题解答机会；

<style>
	html { background: #e6ece6; }
	body { outline:none; background: #f9fcfc; width:auto; margin: 16px 0px 16px 32px; }
	p { color:#423c3c; line-height: 1.8em; }
	.toc:hover { width:auto; max-width:75%; overflow-y: scroll; }
	.toc { position: fixed; z-index:2; box-shadow:0px 0px 5px #ffdc28; background-image: linear-gradient(to top, #c573c5 0%, #969ee8 100%); top: 0; left:0; margin:0; padding:16px 16px 16px 0; width: 32px; box-sizing:border-box; height:100%; overflow:hidden; white-space: nowrap; }
	.toc ul { border-left: #ffd0d0 dotted 3px; margin-left: 28px;}
	.toc ul ul { margin-left: 14px;}
	.toc ul ul li { margin-left: -16px;}
	.toc li { margin-left: -14px; list-style: square; color: white; line-height: 20px; font-size:14px; }
	.toc li:hover { list-style: disc;}
	.toc a { color:white; text-indent:1em; text-decoration: none;}
	.toc a:hover { color:#ecbe35; }
	@media (min-width: 768px) {
	}
	@media only screen and (min-width: 768px){
		body { width: 45em; margin: 16px auto; }
		.toc { left: 50%; margin-left:-25em;  }
		.toc li { margin-left:-20px; }
	}
	@media print { 
		/*a[href]:after { content: none; }
		  a[href^="http://"]:after {content: " (" attr(href) ") ";}
		a:after {content: none !important;}
		 */
		  a:after {content: " (" attr(href) ") "; visibility: hidden;}
		.markdown-body pre code,
		pre { white-space: pre-wrap;word-wrap: break-word; width:100%; font-size:font-size: 0.7em;}
		body { border:none; margin:16px; }
		h1,h2 { page-break-before:always; }
		.toc { box-shadow: none; }
		.toc ul { border: none; }
		.toc li { }
		.toc { width:auto; position:static; left:0; margin:auto; }
	}
	img {max-height: 680px !important;}
</style>

![gitchat](https://p1-tt.byteimg.com/img/tos-cn-i-0022/ea3b5c026e7940f2827feaac33164b88~noop_750x1298.jpeg)
[Gitchat 活动页](https://gitbook.cn/gitchat/activity/5df7ecb85d2ecb0a746047df)


> 从任天堂红白机时代接触单片机，尽管那时不懂却被深深吸引了；从 MS-DOS 时代结缘计算机，就这样一路披荆斩棘前行；很多人说 IT 人是吃青春饭的，对于我，一个 80 后，在乳臭未干的时候就闻到这饭香了，到现在也没觉得吃够吃厌倦了。我只当这是个兴趣，现在这个爱好还能给我带来一份收入而已。
>
> by Jeangowhy 微信同名(jimboyeah◉gmail.com) 
>
> Tue Dec 17 2019 04:23:08 GMT+0800 (深圳宝安)


## 当代晶体管计算机材料基础

在上个世纪，多亏材料学的贡献，电气领域除了导体、绝缘体外，又出现了半导材料。所谓半导体，也就是导电特性介于导体和绝缘体之间，在不同的生产工艺条件下可以得到不同的导电特性。

正是由于半导体材料的出现促成了传统的电子管计算机升级换代为晶体管计算机，也就是当代流行的计算机，其实更古老遥远的计算机是机械结构的。

材料的导电性是由材料中的自由电子 Extra electron 的数量决定的。从能量的角度来看，自由电子的能量比较高，因此往外力的作用下可以自由移动，如电场。如果将它们集中起来，就是导带 Conduction Band，剩下的部分就是价带 Valence Band。价带的电子如果获得足够的能量，也能够变成导带的自由电子。从价带到导带之间的能量差距称为能隙。

一般导体为金属材料，能隙非常小，在室温下，只需很小的能量价带的电子就能够很容易跳跃至导带而导电；绝缘体的静隙比较大，电子很难跳跃至导带，所以不导电；半导体的能隙介于导体和绝缘体之间，只要给予适当的能量或者改变能隙的大小，就能够导电。

在半导体小加入合适的杂质就可以改变和控制它的能隙大小。如在纯硅 Si 中掺杂少量的 砷 As 或磷 P，二者的最外层有五个电子，而 Si 外层只有 4 个电子，因此不能形成外层 8 个电子结构，就会多出——个自由电子，这样就形成了 N 型半导体；如果在纯 Si 中掺人少量的硼 B，由于硼的最外层只有三个电子，这样就少了一个电子，形成了一个 P 型半导体，假象其为空穴 Hole。这里的 N/P 并不是指其带电的极性，而是为了命名材料的离子化特性，任何材料对外都是电中性。

半导体中的自由电子和空穴通称为载流子 Carrier，没有掺杂的普通半导体巾也是有自由电子和空穴的，只是数量相对比较少而已。因此这些原本就有的自由电子和空穴统称为少数载流子简称少子；因为掺杂而形成的自由电子和空穴的数晕相对比较多，因此通称为多数载流子简称多子。

掺杂造成半导体材料中局部自由电子或者空穴增加的过程称为离子化。前者称为 Negative 负离子化，后者称为 Positive 正离子化。仅采用掺杂工艺形成的 N 型半导体因为自由电子数量偏多而对外显现负极性，有时候也标识为 `N-`，相应的 P 型半导体标为 `P+`。采用非掺杂工艺，如高能离子辐照、激光照射等方法可以让价带的电子获得足够高的能量而成为自由电子，也可以让自由电子失去足够多的能量而降低为价带的非自由电子，这种方法称为激发，采用激发的方法使 N 型半导体中的空穴增多，使之对外显示正极性，就成为 `N+` 半导体；使 P 型半导体中的自由电子增多，使之对外显示负极性，就成为 `P-` 半导体。

这两种材料的导电特性有些差异，`自由电子导电`的方式与导线线巾电流的流动类似，在电场作用下，负离子化 Ionization 程度高的原子将多余的电子向着离子化程度比较低的方向传递；`空穴导电`则是正离子化的材料中，原子核外由于电子缺失形成的窄穴在电场作用下，空穴被少子（白由电子）补入而造成类似空穴移动现象所形成的电流，一般称为正电流。

将这两种基本的半导体材料紧密接触到一起，就会形成 PN 结构造，也就是二极管 Diode 的原型。由于这个紧密接触面的存在，P 极材料的空穴会与 N 极材料的电子在漂移运动中结合，从而使原本电中性的材料在 PN 结接触面上形成一个由 N 极指向 P 极的弱电场。

电子漂移运动的结果是使空间电荷区变窄，扩散运动加强。最后，多子的扩散和少子的漂移达到动态平衡，在 P 型半导体和 N 型半导体的结合面两侧，留下离子薄层，这个离子薄层形成的空间电荷区称为 PN 结，结的内电场方向由 N 区指向 P 区。在 PN 结空间电荷区，由于缺少多子，所以也称耗尽层。

由于这个弱电场的存在，使得 PN 结具有单向导电性，内部电场的阻力会阻止电子由 P 区流向 N 区。因此只有施加反向的电场力来可复 PN 结内部电场的阻力，即个 P 区施加正电压才能使 PN 结导通。

PN 结正向导通参考动画示意图

![pn-junction-colored.gif](https://github.com/jimboyeah/demo/blob/go-my-websocket/pn-junction-colored.gif)

利用 PN 结的这种特性，可以制造出结构更加巧妙的三级管，这种晶体管元件有三个引脚，分别是集电极 c、 基极 b，发射极 e。三极管的基本特性是具有放大信号的作用，典型的应用是通过控制基极的微小电压变化，来改变 c-e 两极的大电流的变化，它们的关系可以用一个放大倍数 β 来表示。这样就可以把它当做一个开关看待，传统的开关是机械执行开关动作，而三级管通过 b 的输入电压信号来控制 c-e 两级的开关状态。这个种电子开关也就是数字电路的基本结构，开关状态可以用数字 0 和 1 两种状态对应起来，也就是数字电路的二进制起源。

在计算的世界里，一切皆是开关！存储器使用开关来保存数据，一个字节基本有 8 个开关来对应 8-bit 数据。CPU 内部的指令系统也是对应的开关状态，每一条指令应用的是一组开关的状态，或与指令的类型有关，或与指令使用的操作数有关，或与指令的内存寻址有关。CPU 在执行内存中的指令时使用的程序计数器 PC 也是通关开关来记录当前程序的执行位置，通过修改程序下一条需要执行的指令位置就可以实现程序的代码的跳转。


## 如何快速掌握一门计算机语言

前面小節其实就是为了理解什么是编程语言做铺垫的，理解了程序的运行硬件环境，再来掌握某种语言其实没有那么难，难的是那些在整个计算机领域通行的算法和数据结构。

通用的计算机系统指令集的基本功能都是相似的，基本有对 CPU 内部寄存器的读写、对内存数据的读写，还有一些指令用来控制程序流程的执行，通常是一些跳转指令，汇编语言会记作 JMP。

在硬件基础之上，可以将编程语言分成三个大类：

- 模拟 CPU 指令系统的语言，它的编程模式非常接近 CPU 的运行流程，如汇编、Forth 等；
- 像 C 语言这些人类更容易读得懂的高级语言，能提供人类更容易接受的语法规则，更容易读懂，但是需要编译形成机器指令供 CPU 执行，Golang 就是其中之一，在不考虑虚拟机的情况下 Java 也是可以当成这一类看待；
- 不需要编译的脚本型语言，如 JavaScript、TypeScript、PHP、Python 等，它们也提供了易读写的语法结构，但是它们不需要先编译，在执行脚本程序时 CPU 需要先运行的是脚本解析引擎，由它来解析脚本该如何运行。

初学编程是比较容易受误导进入语言之争的，我认为没有最好的语言，只有最合适的语言，不论是 PHP 是最好的言语还是 Python 懂得人生苦短，这些其实就是从实际出发喊出的口号。有人觉得入门 PHP 够简单，做项目够轻松所以 PHP 对他是最好的。有人觉得项目的时间有限，Python 提供的框架可以轻松帮助他搞定工作回家哄女朋友，Ok，好像不会有女朋友的吧 😂。

所以，初学者不要陷入语言之争，应该从自身需求出发，实在不行学我，PHP、Python 都搞一点，上手一些小应用看看，慢慢就可以对他们的优劣有看法。我在学 Pythong 的时候尝试了一个多线程的下载器：

![Multi-thread Downloader](https://github.com/jimboyeah/demo/blob/go-my-websocket/mtd.jpg)

其实使用 PHP 也可以很方便完成这些工作，没有必要纠结。但是如果你的数学基础扎实，有志往人工智能方向、大数据应用方向发展，那么选择 Pythong 自然错不了。


你可以参考王垠写过的一篇《如何掌握所有的程序语言》，对于我更偏向于把一种语言以下概念进行拆解：

- 它的类型系统有什么，如字符串、数值、整型、浮点等，特殊类型，如 Golang 的 rune；
- 它是如何定义和使用内存地址的，即变量或对象的定义语法；
- 它的基本流程控制结构是什么样的，如循环、条件判断；
- 它是如何组织语言体系内的抽象数据结构的，即函数的规则、类对象的规则；
- 它有些什么特殊语法点，如 lambda、闭包、匿名等等；
- 它的内存回收机制、内存访问机制等等；
- 它的应用范围，扩展能力，常用库模块；

对一门语言有了一个大体掌握，那么接下来就是真正深挖编程能力的时候了，也就是解决问题的能力，这时候才真正体现算法与数据结构素质的作用。试问，你不懂 TCP/IP 协议栈里面的数据包结构又不懂 HTTP 的情况下能开发什么好的 Web 应用出来呢！在计算机领域，算法和数据结构才是真正通用的知识，任何一门语言都不及其重要。学编程的重点应该学包含算法及数据结构的知识点，各种网络协议算是比较重要的一个知识点，而且涉及的面也广。本文的主角 Websocket 就是非常适合用来做学习的一个协议，难度不算太多，适合入门。 



## TCP/IP 网络协议森林入门

TCP/IP 作为应用最广泛的基础底层协议，开发者实际应用的协议如 HTTP、Websocket、FTP 等常见的应用层协议都是构建于 TCP/IP 协议之上的。为了简化理解互联网的协议森林，可以分成三个简单模块来理解：

- 物理链路 ☢
	
	网络硬件为各种协议提供物理链路支持，数据可以在网络间传输，这里主要关注网卡的物理地址 MAC - Media Access Control Address；

- 数据传输 ☢
	
	底层 TCP/IP 协议为基础的网络通讯提供支持，经由网卡向网络发送的数据可以理解为一个数据包，里面记录了 IP 地址和端口号；

- 数据应用 ☢
	
	上层应用协议利用底层协议为程序的网络数据交互需求提供支持；


来看看 RFC791/793 文档的一份图表：

                                       +-------------+
                                       | app header  |          +-------------+
                                       | & user data |          | application |
                                       +-------------+ <======= +-------------+
                                       |             |                   |
                                       V             V                   |
                           +-----------+-------------+                   V
                           |    TCP    | application |               +--------+
                           |   Header  |     data    |               |  TCP   |
                           +-----------+-------------+ <============ +--------+
                           |<----- TCP Segment ----->|                   |
                           V                         V                   |
               +-----------+-----------+-------------+                   V
               |     IP    |    TCP    | application |               +--------+
               |   Header  |   Header  |     data    |               |   IP   |
               +-----------+-----------+-------------+ <============ +--------+
               |<----------- IP Datagram ----------->|                   |
               V                                     V                   V
    +----------+-----------+-----------+-------------+----------+    +--------+
    | Ethernet |     IP    |    TCP    | application | Ethernet |    |Ethernet|
    |  Header  |   Header  |   Header  |     data    | Trailer  |    | Driver |
    +----------+-----------+-----------+-------------+----------+ <= +--------+
    | 14 bytes    20 bytes    20 bytes     N bytes     4 bytes  |
    |<-------------- Ethernet Frame (46-1500 bytes) ----------->|

    Figure 1.7. Encapsulation of data as it goes down the protocol stack.

这份图表解析了，底层协议如何为上层协议提供数据包装。应用程序发送数据时，会经过每一个协议层打包封装，添加上相应的协议头信息，再通过网络链路传输。TCP - Transmission Control Protocol 即控制传输的协议，它提供了端口号机制供各种应用层协议使用，比如 HTTP 默认使用 80 端口，FTP 协议默认使用 21 端口等等。再底层一点的 IP - Internet Protocol 即网际协议提供 IP 地址机制，各种应用就建立于基础的 IP 地址加端口的网络传输机制之上。再底层的就涉及网络硬件设计了，以太网链路层为网卡设计了 MAC 物理地址，数据包在网络上传递就依据 MAC 来送达和接收。

以邮政系统来形象的比喻，每个家庭就像是一台电脑，每个家庭成员看做应用程序，大门外的邮箱作为网卡，邮局作为路由器。那么信件可以理解为，数据包，邮政编码就是 MAC，信件内容就是程序传输的数据，信封就是底层协议给数据封装的协议头。

图表展示了 IP 数据报含有 IP 地址信息涉及到路由走向，20 字节是必须的最小长度。这也是 IP 地址的由来，因为需要这个地址来实现 IP 包的传输。TCP 数据段含有通讯端口信息涉及数据在应用程序的发送和接收流向，这也是传输控制协议这个名称的由来，因为 TCP 通过端口信息控制数据包在不同应之间得传递。Ethernet 的 Frame 包含网络硬件的 MAC 地址，涉及的是数据在网络链路中的传输。

TCP 协议提供了可靠数据传输服务，与 UDP 协议不同，TCP 是连接导向的协议，发送数据前需要建立可靠连接。TCP/IP 详解 《TCP/IP Illustrated, Volume 1: The Protocols》 第十八章撰文讲解了 TCP 的连接建立与终结 TCP Connection Establishment and Termination。可以使用 tcpdump/WinDump 命令工具抓包分析，-w 这个参数可以导入到文件中，方便用 WireShark、Tshark 等网络分析工具来分析。

一句话概括 TCP 的建立和结束连接就是，三次握手 3-Way Handshake，四次挥手 4-Way Wavehand。TCP 协议头中提供了 6-bit 控制位，可以用来指定六种不同用途的 TCP 数据包：

- ACK - Acknowledgment field significant 应答确认；
- FIN - No more data from sender 用在结束连接；
- PSH - Push Function 推送标志，用于推送数据而不是使用数据队列处理，表示数据包要尽快交给应用层处理；
- RST - Reset the connection 连接重置；
- SYN - Synchronize sequence numbers 同步序列，用在建立连接，每个 SYN segment 消耗一个序列号，即使后续序列号加一；
- URG - Urgent Pointer field significant 紧急标志，用于需要应用层紧急处理的数据包；

以下假设宅男 Client 和腐女 Server 两方通讯的情景：

- C: 搭个讪可以吗 :) 发送第一个 SYN segment 并附带一个随机的初始序列号 ISN - initial sequence number，如 1415531521；
- S: 可以啊 :) 响应一个 SYN segment，也发送一个 ISN 序列号，并将 Client 发送的 ISN 加一通过 ACK Number 发回作为应答确认；
- C: 太好了 :)  再发送一个 SYN Segment 应答确认，并将 Server 响应的 ISN 加一通过 ACK Number 发回作为应答确认；
- 愉快地传输数据中......
- C: 我要忙其它事了下次再见 :( 发送 FIN segment 附带序列号；
- S: 好哒去忙吧 :) 响应 ACK segment，序列号加一；
- S: 再见 :) 发送 FIN segment 
- C: 再见 :) 响应 ACK segment

以上情形是正常网络条件下的典型流程，实际上可能出现连接超时。断开连接也可以由服务端发起，一个TCP连接是全双工，在终止过程执行到一半时，还可能出现数据还在发送的情况，即 TCP Half-Close，完整的程序流程参考 TCP State Transition Diagram。


## telnet 工具的使用

TCP 网络世界，一切皆 Socket！事实也是，现在的网络编程几乎都是用的 socket。

Telnet 作为一个标准的 TCP 协议应用程序，通过它可以建立 TCP 连接，然后发送制符串内容到服务器，这样就可以利用它来模块 HTTP 的数据传输，类似的邮件协议、 FTP 也能模拟的。

用 Telnet 来模拟 HTTP 请求，首先需要了解 HTTP 请求的数据结构，为了简化只采用最简单的 HTTP 协议头，只有 GET 动作及 URL 路径：

	GET /chat/telnet HTTP/1.1
	Host: localhost

那么现在就执行 telnet 连接到服务器，以连接 localhost 为例，一旦连接后所有敲到命令界面的字符都会实时发送到服务器的接收缓存区中，包括回车符也是。

	telnet localhost 80

在命令界面中将以上内容敲进去，回车两次表示 HTTP 头部的结束标志，接着等待服务器回复，也可以先复制好这些 HTTP 协议头信息粘贴到 telnet 命令界面中：

	telnet localhost 80
	GET /chat/telnet HTTP/1.1
	Host: localhost

如果服务程序在运行，那么服务器有可能回复以下内容：

	HTTP/1.1 404 Not Found
	Content-Type: text/plain; charset=utf-8
	X-Content-Type-Options: nosniff
	Date: Sat, 21 Dec 2019 18:01:29 GMT
	Content-Length: 19

	404 page not found

这就是一个完整的 HTTP 请求，尽管服务器表示没有相应的页面。这些字符串就是 HTTP 协议的构成，它就是用文本表达的协议，还有 FTP、 STMP 等协议也都是使用文本表达的。在后面的 Websocket 测试中可能需要用到以下的 HTTP 请求：

	telnet localhost 8000
	GET /socket.io/ HTTP/1.1
	Host: localhost
	Connection: Upgrade
	Sec-WebSocket-Extensions: permessage-deflate; client_max_window_bits
	Sec-WebSocket-Key: HRaJmux1hUnhnw4iNlYCYA==
	Sec-WebSocket-Version: 13
	Upgrade: websocket

利用快捷键 `Ctrl+]` 打开命令控制界面，这样就可以通过工具主界面来操作各中选项，也可以看见输入的内容：

	GET /IO HTTP/1.1ft Telnet Client
	HOST: localhost
	Escape 字符为 'CTRL+]'

	Microsoft Telnet> ?

	命令可能是缩写。支持的命令为:

	c    - close                    关闭当前连接
	d    - display                  显示操作参数
	o    - open hostname [port]     连接到主机(默认端口 23)。
	q    - quit                     退出 telnet
	set  - set                      设置选项(键入 'set ?' 获得列表)
	sen  - send                     将字符串发送到服务器
	st   - status                   打印状态信息
	u    - unset                    解除设置选项(键入 'set ?' 获得列表)
	?/h  - help                     打印帮助信息

	Microsoft Telnet> set ?
	bsasdel         发送 Backspace 键作为删除
	crlf            换行模式 - 引起 return 键发送 CR 和 LF
	delasbs         发送 Delete 键作为退格
	escape x        x 是进入 telnet 客户端提示的 escape 字符
	localecho       打开 localecho
	logfile x       x 是当前客户端的日志文件
	logging         启用日志
	mode x          x 是控制台或流
	ntlm            启用 NTLM 身份验证
	term x          x 是 ansi、vt100、vt52 或 vtnt

在 Telnet 控制界面直接回车回到交互界面，或者使用 send 命令发送数据，多按几次回车就好：

	Microsoft Telnet> send apple
	发送字符串 apple


## WebSocket vs Polling

在这里需要先理解几个概念：

- Persistent connection 长连接
- Temporary connection 短连接
- Polling 轮询
- LongPolling 长轮询 

所谓长连接就是根据 TCP 协议连接后，在数据传输完成时还保持 TCP 连接不断开，不发连接重置 RST - Reset the connection 包、不进行四次握手断开，并等待对方继续用这个 TCP 通道传输数据，相反的就是短连接。通常 HTTP 连接就是短连接，浏览器建立 TCP 连接请求页面，服务器发送数据，然后关闭连接。下次再需要请求数据时又重新建立 TCP 连接，一问一答是短连接的一个特点。而新的 HTTP 2.0 规范中，为了提高性能则使用了长连接来复用同一个 TCP 连接来传送不同的文件数据。

参考 RFC 2616 HTTP 1.1 规范文档相关部分 [Persistent connection](https://tools.ietf.org/html/rfc2616#page-44)

HTTP 头信息 Connection: Keep-alive 是 HTTP 1.0 浏览器和服务器的实验性扩展，当前的 HTTP 1.1 RFC 2616 文档没有对它做说明，因为它所需要的功能已经默认开启，无须带着它，但是实践中可以发现，浏览器的报文请求都会带上它。如果不希望使用长连接，则要在请求报文首部加上 Connection: close。

《HTTP权威指南》提到，有部分古老的 HTTP 1.0 代理不理解 Keep-alive，而导致长连接失效：客户端-->代理-->服务端，客户端带有 Keep-alive，而代理不认识，于是将报文原封不动转给了服务端，服务端响应了 Keep-alive，也被代理转发给了客户端，于是保持了 `客户端-->代理` 连接和 `代理-->服务端` 连接不关闭，但是，当客户端第发送第二次请求时，代理会认为当前连接不会有请求了，于是忽略了它，长连接失效。书上也介绍了解决方案：遇到 HTTP 1.0 就忽略 Keep-alive，客户端就知道当前不该使用长连接。

使用了HTTP长连接（HTTP persistent connection ）之后的好处，包括可以使用HTTP 流水线技术（HTTP pipelining，也有翻译为管道化连接），它是指，在一个TCP连接内，多个HTTP请求可以并行，下一个HTTP请求在上一个HTTP请求的应答完成之前就发起。

Client 和 Server 间的实时数据传输是一个很重要的需求，但早期 HTTP 只能通过 AJAX 轮询 Pooling 方式实现，客户端定时向服务器发送 Ajax 请求，服务器接到请求后马上返回响应信息并关闭连接，这就时短连接的应用。轮询带来以下问题：

- 服务器必须为同一个客户端的轮询请求建立不同的 TCP 连接，算上 TCP 的三握手过程，每个 HTTP 连接的建立就需要来回通讯将近 10 次；
- 客户端脚本需要维护出站/入站连接的映射，即管理本地请求与服务器响应的对应关系；
- 请求中有大半是无用，每一次的 HTTP 请求和应答都带有完整的 HTTP 头信息，浪费带宽和服务器资源。

长轮询 LongPolling 是基于长连接实现的，是对 Polling 的一种改进。Client 发送请求，此时 Server 可以发送数据或等待数据准备好：

- 如果 Server 有新的数据需要传送，就立即把数据发回给 Client，收到数据后又立即再发送 HTTP 请求。
- 如果 Server 没有新数据需要传送，与 Polling 的方式不同的是，Server 不是立即发送回应给 Client，而是将这个请求保持住，等待有新的数据来到，再去响应这个请求。
- 如果 Server 长時没有数据响应，这个 HTTP 请求就会超时，Client 收到超时信息后，重新向服务器发送一个 HTTP 请求，循环这个过程。

LongPolling 的方式虽然在某种程度上减少了网络带宽和 CPU 利用率等问题，但仍存在缺陷，因为 LongPolling 还是基于一问一答的 HTTP 协议模式。当 Server 的数据更新速度较快，Server 在传送一个数据包给 Client 后必须等待下一个 HTTP 请求到来，才能传递第二个更新的数据包给 Client，这种场景在 HTTP 上实现的实时聊天几多人游戏是常见的。这样的话，Client 显示实时数据最快的时间为 2 倍 RTT 往返时间。还不考虑网络拥堵的情况，这个应该是不能让用户接受的。另外，由于 HTTP 数据包的头部数据量很大，通常有 400 多个字节，但真正被服务器需要的数据却很少，可能只有 10 个字节左右，这样的数据包在网络上周期性传输，难免对网络带宽是一种浪费。

WebSocket 正是基于支持客户端和服务端的双向通信、简化协议头这些需求下，基于 HTTP 和 TCP 的基础上登上了 Web 的舞台。由于 HTTP 协议的原设计不是用来做双向通讯的，它只是一问一答的执行，客户端发送请求，服务器进行答复，客服端需要什么文件，服务器就提供文件数据。

WebSocket 通信协议是一种双向通信协议，在建立连接后，WebSocket 服务器和 Client 都能主动的向对象发送或接收数据，就像 Socket 一样，所以建立在 Web 基础上的 WebSocket 需要通过升级 HTTP 连接来实现类似 TCP 那样的握手连接，连接成功后才能相互通信。相互沟通的 Header 很小，大概只有 2Bytes。服务器不再被动的接收到浏览器的请求之后才返回数据，而是在有新数据时就主动推送给浏览器。

WebSocket 协议本质上是一个基于 TCP 的协议。为了建立一个 WebSocket 连接，客户端浏览器首先要向服务器发起一个 HTTP 请求，这个请求和通常的 HTTP 请求不同，包含了一些附加头信息，其中附加头信息 `Upgrade: WebSocket` 表明这是一个申请协议升级的 HTTP 请求，服务器端解析这些附加的头信息然后产生应答信息返回给客户端，客户端和服务器端的 WebSocket 连接就建立起来了，双方就可以通过这个连接通道自由的传递信息，并且这个连接会持续存在直到客户端或者服务器端的某一方主动的关闭连接。

因为 WebSocket 是一种新的通信协议，尽管目前还是草案，没有成为标准，市场上已经有成熟的 WebSocket 协议开源 Library 实现可供使用。

关于 Websocket 协议，本文接下来主要介绍以下两部分内容：

- Websocket 握手机制细节
- Websocket 数据帧结构


## Websocket Hanshake

Websocket 协议通信分为两个部分，先是握手，再是数据传输。	主要是建立连接握手 Opening Handshake，断开连接握手 Closing Handshake 则简单地利用了 TCP closing handshake (FIN/ACK)，在做 Websocket 实现时直接省略了这个过程。

如下就是一个基本的 Websocket 握手的请求与回包:

Open handshake 请求

    GET /chat HTTP/1.1
    Host: server.example.com
    Origin: http://example.com
    Upgrade: websocket
    Connection: Upgrade
    Sec-WebSocket-Key: dGhlIHNhbXBsZSBub25jZQ==
    Sec-WebSocket-Protocol: chat, superchat
    Sec-WebSocket-Version: 13

Open handshake 响应

    HTTP/1.1 101 Switching Protocols
    Upgrade: websocket
    Connection: Upgrade
    Sec-WebSocket-Accept: s3pPLMBiTxaQ9kYGzzhZRbK+xOo=
    Sec-WebSocket-Protocol: chat

Websocket 需要使用到的附加信息头主要有以下几个：

- Sec-WebSocket-Key 
- Sec-WebSocket-Extensions 客户端查询服务端是否支持指定的扩展特性
- Sec-WebSocket-Accept 客户端认证
- Sec-WebSocket-Protocol 子协议查询
- Sec-WebSocket-Version 协议版本号

Websocket协议中如何确保客户端与服务端接收到握手请求呢？ 这里就要说到HTTP的两个头部字段，`Sec-Websocket-Key` 与 `Sec-Websocket-Accept`。

- 首先客户端发起请求，在头部`Sec-Websocket-Key`中随机生成 base64 字符串；

		Sec-WebSocket-Key: dGhlIHNhbXBsZSBub25jZQ==

- 服务端收到请求后，根据头部`Sec-Websocket-Key`与约定的 GUID, [RFC4122]) `258EAFA5-E914-47DA-95CA-C5AB0DC85B11` 拼接；

		dGhlIHNhbXBsZSBub25jZQ==258EAFA5-E914-47DA-95CA-C5AB0DC85B11

- 使用 SHA-1 算法得到拼接的字符串的摘要 hash，最后用 base64 编码放入头部 `Sec-Websocket-Accept` 返回客户端做认证。

		SHA1= b37a4f2cc0624f1690f64606cf385945b2bec4ea

		Sec-WebSocket-Accept: s3pPLMBiTxaQ9kYGzzhZRbK+xOo=

更详细的说明可以看 RFC 6455 - The WebSocket Protocol 文档。



## Data Framing 数据帧

根据 RFC 6455 定义，websocket 消息统称为 messages，可以由多个帧 frame 构成。有文本数据帧，二进制数据帧，控制帧三种，Websocket 官方定义有 6 种类型并预留了 10 种类型用于未来的扩展。

### Base Framing Protocol 帧数据构造

了解完 websocket 握手的大致过程后，这个部分介绍下 Websocket 数据帧与分片传输的方式，主要头部信息是前面的 2 byte。

	  0                   1                   2                   3
	  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
	 +-+-+-+-+-------+-+-------------+-------------------------------+
	 |F|R|R|R| opcode|M| Payload len |    Extended payload length    |
	 |I|S|S|S|  (4)  |A|     (7)     |             (16/64)           |
	 |N|V|V|V|       |S|             |   (if payload len==126/127)   |
	 | |1|2|3|       |K|             |                               |
	 +-+-+-+-+-------+-+-------------+ - - - - - - - - - - - - - - - +
	 |     Extended payload length continued, if payload len == 127  |
	 + - - - - - - - - - - - - - - - +-------------------------------+
	 |     and more continued        |Masking-key, if MASK set to 1  |
	 +-------------------------------+-------------------------------+
	 | Masking-key (continued)       |          Payload Data         |
	 +-------------------------------- - - - - - - - - - - - - - - - +
	 :                     Payload Data continued ...                :
	 + - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +
	 |                     Payload Data continued ...                |
	 +---------------------------------------------------------------+

- FIN: 1 bit 表示是否为分片消息 fragment 的最后一个数据帧的标记位，第一帧也可能是最后一帧。
- RSV1, RSV2, RSV3: 保留，都是 1 bit。
- opcode: 表示传输的 Payload 数据格式，如1表示纯文本（utf8)数据帧，2表示二进制数据帧

	| Opcode | 原文说明                      | 用途 |
	| :---- | :---------------------------- | :---------------- |
	| %x0	| denotes a continuation frame	| 标记是否为后续帧	|
	| %x1	| denotes a text frame			| 标记一个文本帧	|
	| %x2	| denotes a binary frame		| 标记一个二进制数据帧	|
	| %x3-7	| are reserved for further non-control frames | 为非控制帧保留的标记	|
	| %x8	| denotes a connection close	| 标记断开连接控制帧	|
	| %x9	| denotes a ping				| 标记一个 Ping 探测帧	|
	| %xA	| denotes a pong				| 标记一个 Pong 回响帧 	|
	| %xB-F	| are reserved for further control frames | 为控制帧保留的标记	|

- MASK: 表示 Payload 数据是否进行标记运算 client-to-server masking，和 Masking-key 相关。
- Payload length: 传输数据内容的总长度。

	可以是 7 bits, 7+16 bits, or 7+64 bits，后两种对应条件是 Payload len == 126/127，即分别增加。

	载荷数据 Payload data 长度为 0-125 字节时，他就是 payload length 总载荷长度。

	如果 Payload len = 126，那么后续的 2 bytes 无符号整数表示 payload length；
	如果 Payload len = 127，那么后续的 8 bytes 无符号整数作为 payload length 但最高有效位必须为 0。

- Masking-key:  0 or 4 bytes

	MASK==1 时用 4 bytes 表示 Masking-key，所有从 client 发送到 server 的数据需要与 Masking-key 进行异或操作，防止一些恶意程序直接获取传输内容内容。

	Masking-key 由客户端随机生成 32-bit 值，不能被预测，[RFC4086] 讨论了关于安全敏感应用熵的合适来源

	[RFC4086] discusses what entails a suitable source of entropy for security-sensitive applications.

	要将标记过的 Payload data 转换回来，或者对数据进行标记的算法是统一的，并且不用考虑转换数据的方向。第 i 的标记数据由第 i 位的原始数据 XOR Masking-Key[i % 4] 得到。

		Octet i of the transformed data ("transformed-octet-i") is the XOR of
		octet i of the original data ("original-octet-i") with octet at index
		i modulo 4 of the masking key ("masking-key-octet-j"):

		    j                   = i MOD 4
		    transformed-octet-i = original-octet-i XOR masking-key-octet-j

	注意数据帧的 Payload length 是指用户数据长度即 Masking-key 后面的数据长度，并不含 Masking-key 的长度。

- Payload data:  (x+y) bytes

    载荷数据 Payload data 等于扩展数据 Extension data 与 Application data 的总和。

	一般 Extension data 为 0 字节，除非 Payload len 指定 126/127 这两个值，并且数据长度需要在 opening handshake 握手阶段协商确定。

	Application data 会占据 Extension data 后面的位置，长度是 Payload length 减掉 Extension data 的长度。


### Fragmentation 消息分片

当一个完整消息体大小不可知时，Websocket 支持分片传输 Fragmentation。这样可以方便服务端使用可控大小的 buffer 来传输分段数据，减少带宽压力，同时可以有效控制服务器内存。

同时在多路传输的场景下，可以利用分片技术使不同的 namespace 的数据能共享对外传输通道。不用等待某个大的 message 传输完成，进入等待状态。

对于控制数据帧 Control Frames 不能使用分片方式，并且 Playload 数据不大于 125 bytes，但可以在分片帧中插队传输。通过 opcodes 最高位置位来标记控制帧，0x8 (Close), 0x9 (Ping), 0xA (Pong)，Opcodes 0xB-0xF 保留。

fragmentation 分片规则:

- 无分片消息作为单帧 single frame 传输，FIN 置位且 opcode 不为 0。
- 分片消息 fragmented message 包括单帧的分片消息 FIN 清位且 opcode 不为 0，后续任意 opcode 为 0 的帧，再跟 FIN=1 opcode=0 的结束帧。分片消息作为一个消息整体，

      EXAMPLE: 对于一个三分片的 text message

      - the first fragment  opcode = 0x1 and a FIN bit clear;
      - the second fragment opcode = 0x0 and a FIN bit clear;
      - the third fragment  opcode = 0x0 and a FIN bit that is set.

- 控制帧 Control frames 可以再分片中插队传输，单本身本能作为分片方式传输。
- 消息分片 Message fragments 必须按发送方的顺序传送给接收方。
- 两条分片消息不能交错传递，除非已经协商好对应的扩展处理。
- 端点必须能处理分片消息中间插入的控制帧。

### Extensibility 扩展特性

扩展特性支持 Extensibility，Websocket 协议设计考虑了扩展特性支持，通过 Sec-WebSocket-Extensions 来协商需要支持的特性，客户端需要服务器支持的扩展特性添加到这个信息头中。服务端接收到后进行确认，如果支持某个特性，就通过这个信息头返回告诉客服端是支持的特性。常用的有信息压缩扩展有消息压缩 permessage-deflate，对消息进行压缩，deflate 就是给气球放气的意思，也是压缩算法名称，表示压缩很形象。如果这个消息需要分片发送，那么就对压缩过的数据进行分割发送，接收时先拼接在解压缩。

比如客户端查询时发送信息头如下，表示和服务器协商一下压缩扩展：

	Sec-WebSocket-Extensions: permessage-deflate; client_max_window_bits

那么服务器如果支持消息压缩扩展功能，那么协商返回结果如下：

	Sec-WebSocket-Extensions: permessage-deflate
	Sec-WebSocket-Extensions: permessage-deflate; server_no_context_takeover; client_no_context_takeover

permessage-deflate 有四个配置参数，配置两端的两个工作方式 `no_context_takeover`、 `max_window_bits`。后者配置 DEFLATE 压缩算法的滑动窗口参数，参考 RFC 7692 关于术语 LZ77 sliding window：

- server_no_context_takeover
- client_no_context_takeover
- server_max_window_bits
- client_max_window_bits

关于扩展特性，不规范也不完整可能的应用建议：

- opcode 保留位可以定义使用；
- 保留位根据每帧需要进行设置；
- 保留位可以给 opcode 使用如果需要；

关于压缩算法相关的参考材料：

- [RFC 1950 - ZLIB compressed data format specification version 3](https://tools.ietf.org/html/rfc1950)
- [RFC 1951 - DEFLATE Compressed Data Format Specification ver 1.3](https://tools.ietf.org/html/rfc1951)
- [RFC 7692 - Compression Extensions for WebSocket](https://tools.ietf.org/html/rfc7692)


### Frame Examples 帧数据样本

	*  0x81 0x05 0x48 0x65 0x6c 0x6c 0x6f

- 单帧文本消息 "Hello"，使用 masking 

	*  0x81 0x85 0x37 0xfa 0x21 0x3d 0x7f 0x9f 0x4d 0x51 0x58

- 分片文本消息 "Hel"、 "lo"，不使用 masking 

	*  0x01 0x03 0x48 0x65 0x6c (contains "Hel")
	*  0x80 0x02 0x6c 0x6f (contains "lo")

- 单帧文本断开连接消息，附带状态码 1001，使用 masking，以下两条都是 1001 断开连接消息

	* 8882 8976 8DDA 8A9F
	* 8882 C831 8FE2 CBD8

- 两个连续帧，使用 masking，分别是 Socket.io 的 ping message 和 close message，没有状态码

	* C183 4C93 383A 7E9138 8880 A34E A2C4

- Ping 消息请求与回应，前者不使用 masking，Ping 可以附带任意的数据，回应时回发对应的内容，这里的内容是 "Hello"

	*  0x89 0x05 0x48 0x65 0x6c 0x6c 0x6f
	*  0x8a 0x85 0x37 0xfa 0x21 0x3d 0x7f 0x9f 0x4d 0x51 0x58

- 256 bytes 二进制数据帧，不使用 masking

	*  0x82 0x7E 0x0100 [256 bytes of binary data]

- 64KiB 二进制数据帧，不使用 masking

	*  0x82 0x7F 0x0000000000010000 [65536 bytes of binary data]


## Socket.io & Engine.io Overview

Socket.io 是 JavaScript 库，用于 Web 应用中实现客户端与服务端建立全双工通信。Socket.io 基于 Engine.io 提供服务，Engine.io 则是对 Websocket 协议进行的上层封装，包括连接的管理、心跳与维活及提供 room 的广播机制与异步 io 等特性，同时在 Websocket 不可用时，提供长轮询作为备选方式获取数据。命名空间 namespace 和房间号 room 是 Socket.io 的基本通讯对象组织结构，客户端连接可以指定要连接的 namespace 默认是根命名空间 `/`，然后可以加入任意的房间号，服务器可以给指定的命名空间或房间号的客户广播消息，或者给指定的某个用户回复消息。

Socket.io 与 Engine.io 的依赖关系大概如下：

- engine.io 和 engine.io-client 根据 engine.io-protocl 协议通过 engine.io-parser 模块解析接收到的数据包；
- socket.io 和 socket.io-client 根据 socket.io-protocl 协议通过 socket.io-parser 模块解析接收到的数据包；
- engine.io 为 socket.io 提供底层支持；
- engine.io-client 为 socket.io-client 提供底层支持；
- socket.io 为 socket.io-client 提供服务，两者互相进行数据通讯。
- 此外，还有 socket.io-redis 扩展库通过 socket.io-adapter 进行扩展。

组件列表：

- [ssocket.io](https://github.com/socketio/socket.io)
- [socket.io-client](https://github.com/socketio/socket.io-client)
- [socket.io-parser](https://github.com/socketio/socket.io-parser)
- [socket.io-adapter](https://github.com/socketio/socket.io-adapter)
- [socket.io-redis](https://github.com/socketio/socket.io-redis)
- [engine.io](https://github.com/socketio/engine.io)
- [engine.io-client](https://github.com/socketio/engine.io-client)
- [engine.io-parser](https://github.com/socketio/engine.io-parser)

这里要注意就是 Socket.io 不是 Websocket 的实现，Socker.io 有自己的协议说明，Socker.io 握手及数据传输都有自定义的 metadata 与认证逻辑，比如头部的 sid。

Socket.io Handshake

- client 发 http 请求，URL: /${yourpath}?EIO=3&transport=polling&t=abcd
- server 返回并带上 header: set-cookie=xxx
- client 使用 cookie 作为 sid，URL: /${yourpath}?EIO=3&transport=polling&t=abcd&sid=xxx

注意与 Engine.io 的 Packet 类型有所不同，但是 Socket.io 的 packet 实际是借助的 Engine.io 的 Message 发送的，在后面实例中可以看到 Packet 的编码方式。当连接出错的时候，Socket.io 会通过自动重连机制重新连接。

API 参考：

- [Socket.io Server API](https://socket.io/docs/server-api/)
- [Socket.io Client API](https://socket.io/docs/client-api/)
- [chat-example](https://socket.io/get-started/chat/)

官方网站源文件可以在 socket.io-website 仓库找到：
[socket.io-website](https://github.com/socketio/socket.io-website)

其它相关链接：

- [engine.io-protocol](https://github.com/socketio/engine.io-protocol)
- [socket.io-protocol](https://github.com/socketio/socket.io-protocol)
- [npm package engine.io](https://www.npmjs.com/package/engine.io)
- [npm package socket.io](https://www.npmjs.com/package/socket.io)



安装 socket.io，开发环境下会默认安装客户端，如果只需要客户端可以单独只安装 socket.io-client。

	$ npm install --save socket.io
	$ npm install --save socket.io-client

Socket.io 的服务器也会通过 URL `/socket.io/socket.io.js` 暴露 Javascript 客户端。还可以通过 CDN 加载客户端：

	https://cdnjs.com/libraries/socket.io
	
	https://cdnjs.cloudflare.com/ajax/libs/socket.io/2.3.0/socket.io.js

其它支持的客户端语言：

- [Socket.io for Java](https://github.com/socketio/socket.io-client-java)
- [Socket.io for C++](https://github.com/socketio/socket.io-client-cpp)
- [Socket.io for Swift](https://github.com/socketio/socket.io-client-swift)
- [Socket.io for Dart](https://github.com/rikulo/socket.io-client-dart)
- [Socket.io for Python](https://github.com/miguelgrinberg/python-socketio)
- [Socket.io for .Net](https://github.com/Quobject/SocketIoClientDotNet)


### Engine.io 协议

Engine.io server 必须提供三类传输方式支持:

- websocket
- polling
	- jsonp
	- xhr

客户端通过 engine.io 的 url 建立通信连接，服务端在 response 中返回一个 open 的 packet，JSON 编码数据格式如下:

- sid: session id （String）
- upgrades: 传输类型(Array)
- pingTimeout: 服务端通信超时配置，客户端用于超时检测(Number)
- pingInterval: 服务端通信定时器配置，客户端用于超时检测(Number)

收到 client 发送的 ping packets 时，server 必须限定时间内发送 pong packets 回应。client 与 server 可以随意交换 message pakcets，直到连接结束。

engine.io URL 的组成如下:

	/engine.io/[?\<query string>]

engine.io: 只允许由库自身进行修改
query string: 可选字段，并提供了四个保留字段:

- transport: 声明传输方式，可选值: polling，websocket
- j: 如果传输方式为 polling，但是需要 JSONP 的响应，则 j 必须设置为 JSONP 响应的 index
- sid: 如果客户端已经分配了一个 session id 则 sid 必须包含在 query string 中
- b64: 如果客户端不支持 XHR2 则必须在 query string 中加上 b64=1 标识，以通知服务端所有二进制数据应该进行 base64 编码

engine.io 数据包只有数据包 Packet、 载荷 payload 两种编码方式，Packet 由类型 ID `packet-id` 和数据 data 两部分构成。 Packet 编码可以是 UTF8 或二进制数据，编码格式如下:

	<type_id>[<data>]

例如:

	2probe

发送二进制数据也是同样的格式，包类型 type_id 是一个整型，具体含义如下:

- 0 `open` 由 server 发送的新开连接回应；
- 1 `close` 请求断开连接；
- 2 `ping` 由 client 发送的探测消息，可附带内容，期待 server 端回应一个 `pong` 消息并附带同样的内容；

	举例

	- client 发送: 2probe
	- server 发送: 3probe

- 3 `pong` 由 server 发送的回应包；
- 4 `message` 这是消息包类型，用于 client 和 server 双方传输数据，并执行 onMessage 事件回调；

	举例 1
	- server 发送: 4HelloWorld
	- client 接收: socket.on('message', function (data) { console.log(data); });
	
	举例 2
	- client 发送: 4HelloWorld
	- server 接收: socket.on('message', function (data) { console.log(data); });

- 5 `upgrade` 在 engine.io 升级传输方式时的数据包，client 用它来协商是否支持传输升级，如果支持，server 会 flush 清送旧连接的数据并转换到新的传输方式。
- 6 `noop` 非操作包，主要用来完成一个轮询周期。

	举例 client 通过 upgrade 进入新的传输方式连接
	- client 发送 2probe
	- server 接收并发送 3probe
	- client 接收并发送 5
	- server 清送数据 flush 并关闭旧连接，然后切换到新的传输方式。

载荷 Playload 即多个 Packet 打包构造，主要用在不支持分片的传输方式上，如轮询。在不支持 XHR2 的情况下，载荷 Payload 编码方式只支持字符串数据发送，二进制数据会经由 base64 编码后打包。

	<length1>:<packet1>[<length2>:<packet2>[...]]

在支持 XHR2 的情况下，Payload 编码格式如下：

	<0 for string data, 1 for binary data><Any number of numbers between 0 and 9><The number 255><packet1 (first type, then data)>[...]

如果 UTF-8 字符串和二进制数据并存，每个字符的作为一个码值写入字节中。

以建立一个连接为例解析 engine.io packet 数据包的结构：

	const client = io('https://myhost.com');

通常 engine.io server 会响应信息:

	{
	  "type": "open",
	  "data": {
	    "sid": "36Yib8-rSutGQYLfAAAD",  // the unique session id
	    "upgrades": ["websocket"],      // the list of possible transport upgrades
	    "pingInterval": 25000,          // the 1st parameter for the heartbeat mechanism
	    "pingTimeout": 5000             // the 2nd parameter for the heartbeat mechanism
	  }
	}

那么 engine.io-parser 会接收到的两个消息包，实际是一个 Payload，需要解析的信息数据就是:

	'96:0{"sid":"hLOEJXN07AE0GQCNAAAB","upgrades":["websocket"],"pingInterval":25000,"pingTimeout":5000}2:40'

拆解各个部分：

	  "96"  # the length of the first message
	  ":"   # a separator between length and content
	  "0"   # the "open" message type
	  '{"sid":"hLOEJXN07AE0GQCNAAAB","upgrades":["websocket"],"pingInterval":25000,"pingTimeout":5000}' # the JSON-encoded handshake data
	  "2"   # the length of the second message
	  ":"   # a separator between length and content
	  "4"   # the "message" message type
	  "0"   # the "open" message type in Socket.IO protocol


### Socket.io 协议

socket.io-protocol 内容可以参考官方文档的 [Under the hood](https://socket.io/docs/internals/)

Socket.io Packet 构建于 Engine.io 之上，主要是利用了 4 `message` 消息包类型来传输以下消息包。

- Packet#CONNECT (0)
- Packet#DISCONNECT (1)
- Packet#EVENT (2)
- Packet#ACK (3)
- Packet#ERROR (4)
- Packet#BINARY_EVENT (5)
- Packet#BINARY_ACK (6)

主要的是后面 5 种，CONNECT 负责连接到服务器的指定命名空间 nsp，然后使用其它消息包进行通讯。这些包的数据基本都是是一个 JSON 数组，第一个元素是事件名称，后面的参数可以是任意的 JSON 数据。

对于 `BINARY_EVENT` 可以含有非 JSON 的二进制数据，可以是 Buffer, ArrayBuffer, Blob, 或者 File。服务端解码得到的是 Buffer，客户端通常是 ArrayBuffer。在不支持二进制数据的旧浏览上，二进制数据会使用 JSON 占位符替代 `{base64: true, data: <base64_bin_encoding>}`。当 BINARY_EVENT 或 ACK 包开始解码时，二进位数据先设置占位符，然后使用 Parser 模块的解码器方法 `Decoder#add(Object:encoding)` 还原数据，然后触发 decoded 事件。

`ACK`、 `BINARY_ACK` 两个消息类型在对方表明对当前事件期待一个确认答复时使用，需要配合 ack 函数使用，配套的 socket.io API 有以下三个。如果在发送消息时传入了 ack 回调函数，表明期待对方响应一个 ACK 答复。如果执行 ACK 回调函数进行答复时使用了二进制数据，就会发送一个 `BINARY_ACK` 消息而不是 `ACK`。

- socket.send([…args][, ack])
- socket.emit(eventName[, …args][, ack])
- socket.on(eventName, (data, ack) => { ... })

同样，接收方也需要在 `socket.on()` 事件中进行响应，否则不会触发 `ACK`、 `BINARY_ACK` 消息。参考服务端程序代码如下，需要参考前面安装 socket.io 模块，前端页面模板 socket-client.tpl 就不贴出来了，需要的可以通过后面的 Github 地址获取。服务程序发送 chat 事件消息过程没有期待对方回复 ACK 消息，因为没有传入 ack 回调函数，但是如果对方发送 chat 消息时服务端是可以进行 ACK 消息响应的：

	var app = require('http').createServer(handler)
	var io = require('socket.io')(app, { perMessageDeflate: true });
	var fs = require('fs');

	app.listen(7001);

	function handler(req, res) {
	    var url = req.client.parser.incoming.url;
	    console.log(req.client.parser.incoming.url)
	    var f = {
	        "/": "/app/view/socket-client.tpl",
	        "/public/theme.css": "/app/public/theme.css",
	        "/public/socket.io.js": "/node_modules/socket.io-client/dist/socket.io.js",
	        "/public/socket.io.js.map": "/node_modules/socket.io-client/dist/socket.io.js.map",
	    } [url]
	    fs.readFile(__dirname + (f || url), function(err, data) {
	        if (err) {
	            res.writeHead(404);
	            return res.end('File Not Found: ' + (f || url));
	        }
	        res.writeHead(200);
	        res.end(data);
	    });
	}

	io.on('connection', function(socket) {
	    console.log("socket io connection", socket.nsp.name);
	    socket.emit('chat', { hello: 'world' });
	    socket.on('chat', (data, ack) => {
	        var buf = Buffer.from(data, "utf8");
	        console.log("socket io on chat", data, ack, buf);
	        if (ack && ack.constructor.name == "Function") ack('woo chat');
	    });
	    socket.on('binary', (data, ack) => {
	        console.log("binary data", data, ack);
	        if (ack && ack.constructor.name == "Function") ack('woo binary');
	    });
	});

以一个 Socket.io client 与 server 交互中产生的数据为列：

- server: 0{"sid":"kLn6AcJAiY6QziUJAAAL","upgrades":[],"pingInterval":25000,"pingTimeout":5000}
- server: 0x34 0x30
- client: 

		0x32, 0x31, 0x32, 0x88, 0x56, 0x4A, 0xCE, 0x48, 
		0x2C, 0x51, 0xD2, 0x51, 0xF2, 0x48, 0xCD, 0xC9, 
		0xC9, 0x57, 0x08, 0xCE, 0x4F, 0xCE, 0x4E, 0x2D, 
		0xD1, 0xCB, 0xCC, 0x57, 0x54, 0x8A, 0x05, 0x00

- server: 430["woo chat"]
- client: 50-["protobuf", "CgxoZWxsbyBiaW5hcnkQYxoDQUJDIyoIZ29vZCBieWUk"]
- server: 42["packet","packet received!"]
- client: 451-["binary",{"_placeholder":true,"num":0}]
- client: 
		
		0x04, 0x65, 0x66, 0x67

- server: 431["woo binary"]	
- client: 0x32 0x02 0x00
- server: 0x33
- client: 0x03 0xe9 
- server: 0x03 0xe9 

客户端发送的第一条数据是使用消息压缩产生的二进制数据，创建 Socketio 服务不使用压缩选项 `{perMessageDeflate:false}` 对应的消息如下：

	420["chat","Hello Socket.io!"]

服务端对应回复的是一个 ACK 消息，`430["woo chat"]`，4 表示 Engine.io 协议的 `message`，3 表示 Socket.io 协议的 ACK，跟着的数字 0 是个递增数字。

第二条数据是经过 base64 编码的二进制数据，由 Google Protocol Bufffer 协议生成。

	0A 0C 68 65 6C 6C 6F 20 62 69 6E 61 72 79 10 63 1A 03 41 42  ..hello binary.c..AB
	43 23 2A 08 67 6F 6F 64 20 62 79 65 24                       C#*.good bye$       

Protocol Buffer 简称 Protobuf，是 Google 公司内部的混合语言数据标准，是一种轻便高效的结构化数据存储格式，可以用于结构化数据串行化，或者说序列化。它很适合做数据存储或 RPC 数据交换格式。可用于通讯协议、数据存储等领域的语言无关、平台无关、可扩展的序列化结构数据格式。使用 .proto 文件定义报文对象，使用编译工具生成指定言语的代码。目前提供了广泛的语言支持，有 C++、Java、Python、Go、JavaScfript 等等语言的 API。

客户端发送的第三条数据是指定 binary 方式发送的 `BINARY_EVENT` 二进制消息，相应的客户代码：

	// var socket = io(namespace);
	// socket.binaryType = 'arraybuffer';
	// socket.send(new ArrayBuffer);
	var buffer = new Uint8Array([0x65,0x66,0x67]);
	socket.binary(true).emit("binary", buffer, function(data){
		console.log("binary ack", data)
	});


## Dive into go-socket.io
[gorilla websocket](https://godoc.org/github.com/gorilla/websocket)
[go-socket.io](https://github.com/googollee/go-socket.io)
[godoc go-socket.io](https://godoc.org/github.com/googollee/go-socket.io)
[godoc go-engine.io](https://godoc.org/github.com/googollee/go-engine.io)

go-socket.io 和 go-engine.io 是 Golang 实现版本，这个小节来探究 go-socket.io 模块架构是如何设计，主线研究 TCP 请求如何经过层层 API 传递到 go-socket.io 内部。

先来了解 API 执行流程，看图加深印象，单纯代码容易陷入混乱：

![API layout](https://github.com/jimboyeah/demo/blob/go-my-websocket/api-layout.png)

接下来阅读三个模块涉及的 API 代码。

## go-socket.io 架构

go-socket.io 包导出了三个主要对象 Brodadcast、Conn、Server，分别用于命名空间的组织、连接管理、go-engine.io 服务器封装。

注意 go-socket.io 源代码中的 namespaceConn 对象并没完全定义 socketio.Conn 接口，而是通过嵌入 conn 对象内的 engineio.Conn 对象实现 socketio.Conn 接口的。

此外，内部非导出的重要对象有：

- namespaceHandler 命名空间事件处理器，管理各种事件，使用私有属性 onConnect, onDisconnect, onError, events 保存事件响应函数；
- conn 对 engineio.Conn 连接进行管理，数据的编码解码；
- namespaceConn 即导出的 socketio.Conn 接口类型，命名空间连接管理，将命名空间与 conn 关联起来，为用户连接提供上下文对象 Context 和广播机制 Broadcast；
- parser 内部包提供 Decoder、Encoder 实现 Websocket 数据的编码解码；

通过 NewServer() 全局方法建立 Server 对象，并执行 Serve() 方法来激活 go-engine.io 服务器监听服务：

	// Serve serves go-socket.io server
	func (s *Server) Serve() error {
		for {
			conn, err := s.eio.Accept()
			if err != nil {
				return err
			}
			go s.serveConn(conn)
		}
	}

Server 服务器对象实现了 http.Handler 接口，一般通过 `http.Handle("/socket.io/", server)` 方式将入站请求挂接到 `ServeHTTP()` 方法，由这里转入 go-engine.io 内部 Server 对象执行响应动作：

	func (s *Server) ServeHTTP(w http.ResponseWriter, r *http.Request) {
		s.eio.ServeHTTP(w, r)
	}

在 eio.ServeHTTP() 内部会对 HTTP 连接进行升级，Websocket 连接是通过 upgrader.Upgrade() 将 HTTP 连接升级得到的，也就是按 Websocket 协议进行握手的过程。然后是开始发送一条 OPEN 消息，注意就是包含 PingInterval、 PingTimeout、 Upgrades 等的数据。然后就进入 session.serveHTTP() 开始正式数据通讯：

	func (s *session) serveHTTP(w http.ResponseWriter, r *http.Request) {
		s.upgradeLocker.RLock()
		conn := s.conn
		s.upgradeLocker.RUnlock()

		if h, ok := conn.(http.Handler); ok {
			h.ServeHTTP(w, r) // transport.conn.ServeHTTP()
		}
	}

在整个系统中 `engineio.session` 对象是处于一个非常核心的位置，它掌管了来自 websocket 的连接对象。而 `socketio.conn` 则从更上层封装了 socket.io-protocl 定义的协议，它控制的 Socket.io 的事件和数据包的读写以及通过 namespaceHandler 的 dispatch() 方法将事件分发到 Server 注册的事件处理函数。

回到 socketio.Server 对象，它暴露了一系列方法用来注册事件处理函数，主要是 OnConnect、 OnDisconnect、 OnError、 OnEvent，事件处理函数会被保存到内部的 handlers 中，它是一个命名空间映射对象，通过 getNamespace() 方法获取对应命名空间的事件处理函数集合：  

	func (s *Server) getNamespace(nsp string) *namespaceHandler {
		if nsp == "/" {
			nsp = ""
		}
		ret, ok := s.handlers[nsp]
		if ok {
			return ret
		}
		handler := newHandler()
		s.handlers[nsp] = handler
		return handler
	}

每一个 namespaceHandler 对象都管理着一套事件处理函数，对应标准事件 OnConnect、 OnDisconnect、 OnError 和用户定义事件 OnEvent：

	type namespaceHandler struct {
		onConnect    func(c Conn) error
		onDisconnect func(c Conn, msg string)
		onError      func(c Conn, err error)
		events       map[string]*funcHandler
	}

在 Server.Serve() 内会执行私有方法 `serveConn()` 将 engineio.Conn，handlers 及 broadcast 等打包为 conn 对象，这样就接管了从 Server 中注册的事件。 conn.connect() 方法执行连接，一并构造一个默认的 `/` namespaceConn 对象。

	func (s *Server) serveConn(c engineio.Conn) {
		_, err := newConn(c, s.handlers, s.broadcast)
		if err != nil {
			root := s.handlers[""]
			if root != nil && root.onError != nil {
				root.onError(nil, err)
			}
			return
		}
	}

	func newConn(c engineio.Conn, handlers map[string]*namespaceHandler, broadcast Broadcast) (*conn, error) {
		ret := &conn{
			Conn:       c,
			broadcast:  broadcast,
			encoder:    parser.NewEncoder(c),
			decoder:    parser.NewDecoder(c),
			errorChan:  make(chan errorMessage),
			writeChan:  make(chan writePacket),
			quitChan:   make(chan struct{}),
			handlers:   handlers,
			namespaces: make(map[string]*namespaceConn),
		}
		if err := ret.connect(); err != nil {
			ret.Close()
			return nil, err
		}
		return ret, nil
	}

同时用 engineio.Conn 连接对象作为 `FrameWriter`、 `FrameReader` 来实例化一组 `Encoder`、 `Decoder` 对数据流进行编码解码，也就是说 go-socket.io 对数据流的读写操作是在 parser.Decoder、 parser.Encoder 内进行的。在 parser 内还定义了一组常量，也是比较有趣的一段代码，通过定义一个等价 byte 类型的 Type，再用它来表是事件的类型，并且类型名字还叫 Type 这样更容易理解用途，又不必考虑 Type 存储的是什么数据，交给 iota 常量生成器就好了。

	const (
		Connect Type = iota  // Connect type
		Disconnect           // Disconnect type
		Event                // Event type
		Ack                  // Ack type
		Error                // Error type

		binaryEvent          // BinaryEvent type
		binaryAck            // BinaryAck type
		typeMax
	)

而另外 conn 管理的 namespaceHandler 对象有个很重要的方法 dispatch()，它会根据 parser.Header 指定的事件类型来分发事件，调用事件处理函数。

	func (h *namespaceHandler) dispatch(c Conn, header parser.Header, event string, args []reflect.Value) ([]reflect.Value, error) {
		switch header.Type {
		case parser.Connect:
			var err error
			if h.onConnect != nil {
				err = h.onConnect(c)
			}
			return nil, err
		case parser.Disconnect:
			msg := ""
			if len(args) > 0 {
				msg = args[0].Interface().(string)
			}
			if h.onDisconnect != nil {
				h.onDisconnect(c, msg)
			}
			return nil, nil
		case parser.Error:
			msg := ""
			if len(args) > 0 {
				msg = args[0].Interface().(string)
			}
			if h.onError != nil {
				h.onError(c, errors.New(msg))
			}
		case parser.Event:
			namespaceHandler := h.events[event]
			if namespaceHandler == nil {
				return nil, nil
			}
			return namespaceHandler.Call(append([]reflect.Value{reflect.ValueOf(c)}, args...))
		}
		return nil, errors.New("invalid packet type")
	}

dispatch() 分派事件的位置都在 `socketio.conn` 内进行，主要是两个位置：

- socketio.conn 实例化时执行 connect() 开始连接时；
- socketio.conn 执行 serveRead() 读取数据流时；

开始连接 connect() 方法很重要，它通过三条 go 启动三条协程来处理数据流：

	func (c *conn) connect() error {
		root := newNamespaceConn(c, "/", c.broadcast)
		c.namespaces[""] = root
		header := parser.Header{
			Type: parser.Connect,
		}

		if err := c.encoder.Encode(header, nil); err != nil {
			return err
		}
		handler, ok := c.handlers[header.Namespace]

		go c.serveError()
		go c.serveWrite()
		go c.serveRead()

		if ok {
			handler.dispatch(root, header, "", nil)
		}

		return nil
	}

在 serveRead() 方法中，解码模块会执行 decoder.DecodeHeader() 获得数据流对应的事件，再通过 dispatch() 分配执行。 类似，serveWrite() 方法中，编码模块会执行 c.encoder.Encode() 将数据写入连接对象数据流中。注意一下，编码解码模块在 `serveConn()` 被实例化时已经获取了连接对象的引用，所以可以直接在内部读写连接对象的数据流。 方法参考：

	func (e *Encoder) Encode(h Header, args []interface{}) (err error)
	func (e *Encoder) writePacket(w io.WriteCloser, h Header, args []interface{}) ([][]byte, error)
	func (e *Encoder) writeUint64(w byteWriter, i uint64) error
	func (e *Encoder) attachBuffer(v reflect.Value, index *uint64) ([][]byte, error)
	func (e *Encoder) writeBuffer(w io.WriteCloser, buffer []byte) error

	func (d *Decoder) Close() error
	func (d *Decoder) DiscardLast() (err error)
	func (d *Decoder) DecodeHeader(header *Header, event *string) error
	func (d *Decoder) DecodeArgs(types []reflect.Type) ([]reflect.Value, error)
	func (d *Decoder) readUint64FromText(r byteReader) (uint64, bool, error)
	func (d *Decoder) readString(r byteReader, until byte) (string, error)
	func (d *Decoder) readHeader(header *Header) (uint64, error)
	func (d *Decoder) readEvent(event *string) error
	func (d *Decoder) readBuffer(ft engineio.FrameType, r io.ReadCloser) ([]byte, error)
	func (d *Decoder) detachBuffer(v reflect.Value, buffers []Buffer) error


## go-engine.io 架构 & Websocket

go-engine.io 定义了以下几个重要的对象：

- `Server` 实现了 http.Handler 接口的服务器，协调 transport 连接方式，通过 http.Handle("/socket.io/", server) 方式引入连接；
- `session` 表示一个会话连接，管理底层的 base.Conn 连接，；
- `manager` 用来来管理会话标识 SID 与相关的 `session` 会话连接，也就是服务器对象的 sessions 属性，通过它可以获取 SID 关联的会话连接对象，如果找到会话连接，就执行 `session.serveHTTP()` 来响应客户端，底层数据还是通过 Tranport 来处理的；
- `transport.Manager` 协调 transport 连接方式；
- `base`、 `packet`、 `payload`、 `transport` 这些子包是 Engine.io 的服务端即客户端都需要的底层实现。

go-engine.io 定义了 `FrameString`、 `FrameBinary` 两种数据帧，还有帧的读写操作接口对象 `FrameReader`、 `FrameWriter`，与连接相关的对象如 `session`、 `client` 等都会实现这两个接口。对于 `decoder`、 `encoder` 对象，只需分别实现各自需要的帧读写接口，但最终读写操还是要回到连接对象上的数据流上。

在 Websocket 服务端核心方式是 upgrader.Upgrade()，将 HTTP 请求连接升级位 Websocket 长连接，然后通过 ReadMessage() 阻塞方法读取客户端数据。

来看看 go-engine.io 的 `Server` 对象的实例化过程：

	// NewServer returns a server.
	func NewServer(opts *Options) (*Server, error) {
		t := transport.NewManager(opts.getTransport())
		return &Server{
			transports:     t,
			pingInterval:   opts.getPingInterval(),
			pingTimeout:    opts.getPingTimeout(),
			requestChecker: opts.getRequestChecker(),
			connInitor:     opts.getConnInitor(),
			sessions:       newManager(opts.getSessionIDGenerator()),
			connChan:       make(chan Conn, 1),
		}, nil
	}

这里为服务器对象实例化了一个 `manager` 对象来管理 `session`，还有默认的底层连接方式 polling.Default、 websocket.Default，如果没有在配置项 Transports 中指定的话。

	func newManager(g SessionIDGenerator) *manager {
		if g == nil {
			g = &defaultIDGenerator{}
		}
		return &manager{
			SessionIDGenerator: g,
			s:                  make(map[string]*session),
		}
	}

	func (c *Options) getTransport() []transport.Transport {
		if c != nil && len(c.Transports) != 0 {
			return c.Transports
		}
		return []transport.Transport{
			polling.Default,   // polling.Transport
			websocket.Default, // websocket.Transport
		}
	}

go-engine.io 定义 `Server` 对象则实现了 http.Handler 接口，通过 `ServeHTTP(w http.ResponseWriter, r *http.Request)` 方法为 HTTP 连接提供服务，连接的建立是在 `Accept()` 方法。客户端的连接请求入口是主程序中设置的：

	server, err := socketio.NewServer(nil)
	// ...
	http.Handle("/socket.io/", server)
	http.Handle("/", http.FileServer(http.Dir("../")))

	log.Println("Serving at localhost:8000...")
	log.Fatal(http.ListenAndServe(":8000", nil))

也就是所有请求 `/socket.io/` 地址的连接都交给 engine.io 的服务器来处理。Engin.io Server 会读取来自客户端的会话标识 sid、 连接方式 transport 等信息，调用配置项提供的方法 `RequestChecker()` 对请求进行检查，如果没有配置，默认提供一个什么也不做的检查方法：

	func defaultChecker(*http.Request) (http.Header, error) {
		return nil, nil
	}

go-engine.io 定义了`session` 表示一个会话连接，通过 `manager` 来管理会话标识 SID 与相关的连接，也就是服务器对象的 sessions 属性，通过它可以获取 SID 关联的会话连接对象，如果找到会话连接，就执行 `session.serveHTTP()` 来响应客户端。如果没有找到相应的 session 对象，则实例化一个，并将响应流程转接到底层的 `Transport.Accept()`: 

	// Transport is a transport which can creates base.Conn
	type Transport interface {
		Name() string
		Accept(w http.ResponseWriter, r *http.Request) (base.Conn, error)
		Dial(u *url.URL, requestHeader http.Header) (base.Conn, error)
	}

如果使用的 Websocket 方式对应的接管对象就是 websocket.Transport 否则就是 polling.Transport：

	// Transport is websocket transport.
	type Transport struct {
		ReadBufferSize   int
		WriteBufferSize  int
		NetDial          func(network, addr string) (net.Conn, error)
		Proxy            func(*http.Request) (*url.URL, error)
		TLSClientConfig  *tls.Config
		HandshakeTimeout time.Duration
		Subprotocols     []string
		CheckOrigin      func(r *http.Request) bool
	}


go-engine.io 定义了 `FrameString`、 `FrameBinary` 两种数据帧，还有帧的读写操作接口对象 `FrameReader`、 `FrameWriter`，与连接相关的对象如 `session`、 `client` 等都会实现这两个接口。对于 `decoder`、 `encoder` 对象，只需分别实现各自需要的帧读写接口，但最终读写操还是要回到连接对象上的数据流上，也就是 websocket 包中的连接对象提供的 `NextReader()`、 `NextWriter()` 读写能力。

	const (
		FrameString FrameType = iota
		FrameBinary
	)

	// FrameReader reads a frame. It need be closed before next reading.
	type FrameReader interface {
		NextReader() (FrameType, PacketType, io.ReadCloser, error)
	}
	
	// FrameWriter writes a frame. It need be closed before next writing.
	type FrameWriter interface {
		NextWriter(ft FrameType, pt PacketType) (io.WriteCloser, error)
	}

go-engine.io 的 `session.NextReader()` 只需要根据协议读取消息


## 连接对象的 API 封装

此小节主要贴代码，如果不想多做了解，可以直接跳过。

来看看 websocket 包的连接对象是如何层层封装到 go-engine.io 的 sesssion 对象中的，从 ServeHTTP 入口回溯：

- Server.ServeHTTP()

		func (s *Server) ServeHTTP(w http.ResponseWriter, r *http.Request) {
			query := r.URL.Query()
			sid := query.Get("sid")
			session := s.sessions.Get(sid)
			t := query.Get("transport")
			tspt := s.transports.Get(t)
			// ...

			if session == nil {
				// ...
				conn, err := tspt.Accept(w, r) <------------------------------ HERE💨
				// ...
				params := base.ConnParameters{
					PingInterval: s.pingInterval,
					PingTimeout:  s.pingTimeout,
					Upgrades:     s.transports.UpgradeFrom(t),
				}
				session, err = newSession(s.sessions, t, conn, params)  <----- HERE💨
				// ...
				s.connInitor(r, session) // Options.ConnInitor

				go func() {
					w, err := session.nextWriter(base.FrameString, base.OPEN)
					if err != nil {
						session.Close()
						return
					}
					if _, err := session.params.WriteTo(w); err != nil {
						w.Close()
						session.Close()
						return
					}
					if err := w.Close(); err != nil {
						session.Close()
						return
					}
					s.connChan <- session
				}()
			}
			if session.Transport() != t {
				conn, err := tspt.Accept(w, r)
				if err != nil {
					http.Error(w, err.Error(), http.StatusBadGateway)
					return
				}
				session.upgrade(t, conn)
				if handler, ok := conn.(http.Handler); ok {
					handler.ServeHTTP(w, r)
				}
				return
			}
			session.serveHTTP(w, r)
		}

- newSession()

		func newSession(m *manager, t string, conn base.Conn, params base.ConnParameters) (*session, error) {
			params.SID = m.NewID()
			ses := &session{
				transport: t,
				conn:      conn, <----------------------------- HERE💨
				params:    params,
				manager:   m,
			}

			if err := ses.setDeadline(); err != nil {
				ses.Close()
				return nil, err
			}

			m.Add(ses)

			return ses, nil
		}

- Transport.Accept()

		// Accept accepts a http request and create Conn.
		func (t *Transport) Accept(w http.ResponseWriter, r *http.Request) (base.Conn, error) {
			upgrader := websocket.Upgrader{
				ReadBufferSize:  t.ReadBufferSize,
				WriteBufferSize: t.WriteBufferSize,
				CheckOrigin:     t.CheckOrigin,
			}
			c, err := upgrader.Upgrade(w, r, w.Header()) <------ HERE💨
			if err != nil {
				return nil, err
			}

			return newConn(c, *r.URL, r.Header), nil <---------- HERE💨
		}

- transport.newConn()

		func newConn(ws *websocket.Conn, url url.URL, header http.Header) base.Conn {
			w := newWrapper(ws) <------------------------------- HERE💨
			closed := make(chan struct{})
			return &conn{
				url:          url,
				remoteHeader: header,
				ws:           w,
				closed:       closed,
				FrameReader:  packet.NewDecoder(w),
				FrameWriter:  packet.NewEncoder(w),
			}
		}

- transport.newWrapper()

		func newWrapper(conn *websocket.Conn) wrapper {
			return wrapper{
				Conn:        conn, <----------------------------- HERE💨
				writeLocker: new(sync.Mutex),
				readLocker:  new(sync.Mutex),
			}
		}

- websocket Server.go: Upgrade()

		// Upgrade upgrades the HTTP server connection to the WebSocket protocol.
		//
		// The responseHeader is included in the response to the client's upgrade
		// request. Use the responseHeader to specify cookies (Set-Cookie) and the
		// application negotiated subprotocol (Sec-WebSocket-Protocol).
		//
		// If the upgrade fails, then Upgrade replies to the client with an HTTP error
		// response.
		func (u *Upgrader) Upgrade(w http.ResponseWriter, r *http.Request, responseHeader http.Header) (*Conn, error) {
			const badHandshake = "websocket: the client is not using the websocket protocol: "

			// ...
			h, ok := w.(http.Hijacker) <------------------------- HERE💨
			if !ok {
				return u.returnError(w, r, http.StatusInternalServerError, "websocket: response does not implement http.Hijacker")
			}
			var brw *bufio.ReadWriter
			netConn, brw, err := h.Hijack() <-------------------- HERE💨
			if err != nil {
				return u.returnError(w, r, http.StatusInternalServerError, err.Error())
			}

			if brw.Reader.Buffered() > 0 {
				netConn.Close()
				return nil, errors.New("websocket: client sent data before handshake is complete")
			}

			var br *bufio.Reader
			if u.ReadBufferSize == 0 && bufioReaderSize(netConn, brw.Reader) > 256 {
				// Reuse hijacked buffered reader as connection reader.
				br = brw.Reader
			}

			buf := bufioWriterBuffer(netConn, brw.Writer)

			// ... <---------------------------------------------- HERE💨
			c := newConn(netConn, true, u.ReadBufferSize, u.WriteBufferSize, u.WriteBufferPool, br, writeBuf)
			// ...

			// Use larger of hijacked buffer and connection write buffer for header.
			p := buf
			// ...

			p = append(p, "HTTP/1.1 101 Switching Protocols\r\nUpgrade: websocket\r\nConnection: Upgrade\r\nSec-WebSocket-Accept: "...)
			p = append(p, computeAcceptKey(challengeKey)...)
			p = append(p, "\r\n"...)
			// ...

			// Clear deadlines set by HTTP server.
			netConn.SetDeadline(time.Time{})

			if u.HandshakeTimeout > 0 {
				netConn.SetWriteDeadline(time.Now().Add(u.HandshakeTimeout))
			}
			if _, err = netConn.Write(p); err != nil {
				netConn.Close()
				return nil, err
			}
			if u.HandshakeTimeout > 0 {
				netConn.SetWriteDeadline(time.Time{})
			}

			return c, nil <--------------------------------------- HERE💨
		}

- websocket conn.go: ReadMessage()

		// ReadMessage is a helper method for getting a reader using NextReader and
		// reading from that reader to a buffer.
		func (c *Conn) ReadMessage() (messageType int, p []byte, err error) {
			var r io.Reader
			messageType, r, err = c.NextReader()
			if err != nil {
				return messageType, nil, err
			}
			p, err = ioutil.ReadAll(r)
			return messageType, p, err
		}

- websocket conn.go: NextReader()

		// NextReader returns the next data message received from the peer. The
		// returned messageType is either TextMessage or BinaryMessage.
		//
		// There can be at most one open reader on a connection. NextReader discards
		// the previous message if the application has not already consumed it.
		//
		// Applications must break out of the application's read loop when this method
		// returns a non-nil error value. Errors returned from this method are
		// permanent. Once this method returns a non-nil error, all subsequent calls to
		// this method return the same error.
		func (c *Conn) NextReader() (messageType int, r io.Reader, err error) {
			// Close previous reader, only relevant for decompression.
			if c.reader != nil {
				c.reader.Close()
				c.reader = nil
			}

			c.messageReader = nil
			c.readLength = 0

			for c.readErr == nil {
				frameType, err := c.advanceFrame()
				if err != nil {
					c.readErr = hideTempErr(err)
					break
				}
				if frameType == TextMessage || frameType == BinaryMessage {
					c.messageReader = &messageReader{c}
					c.reader = c.messageReader
					if c.readDecompress {
						c.reader = c.newDecompressionReader(c.reader)
					}
					return frameType, c.reader, nil
				}
			}

			// Applications that do handle the error returned from this method spin in
			// tight loop on connection failure. To help application developers detect
			// this error, panic on repeated reads to the failed connection.
			c.readErrCount++
			if c.readErrCount >= 1000 {
				panic("repeated read on failed websocket connection")
			}

			return noFrame, nil, c.readErr
		}

- websocket conn.go: advanceFrame()

		func (c *Conn) advanceFrame() (int, error) {
			// 1. Skip remainder of previous frame.

			if c.readRemaining > 0 {
				if _, err := io.CopyN(ioutil.Discard, c.br, c.readRemaining); err != nil {
					return noFrame, err
				}
			}

			// 2. Read and parse first two bytes of frame header.

			p, err := c.read(2)
			if err != nil {
				return noFrame, err
			}

			final := p[0]&finalBit != 0
			frameType := int(p[0] & 0xf)
			mask := p[1]&maskBit != 0
			c.readRemaining = int64(p[1] & 0x7f)

			...
		}

- websocket conn.go: read(n int)

		func (c *Conn) read(n int) ([]byte, error) {
			p, err := c.br.Peek(n)
			if err == io.EOF {
				err = errUnexpectedEOF
			}
			c.br.Discard(len(p))
			return p, err
		}

- websocket conn.go: WriteMessage()

		// WriteMessage is a helper method for getting a writer using NextWriter,
		// writing the message and closing the writer.
		func (c *Conn) WriteMessage(messageType int, data []byte) error {

			if c.isServer && (c.newCompressionWriter == nil || !c.enableWriteCompression) {
				// Fast path with no allocations and single frame.

				var mw messageWriter
				if err := c.beginMessage(&mw, messageType); err != nil {
					return err
				}
				n := copy(c.writeBuf[mw.pos:], data)
				mw.pos += n
				data = data[n:]
				return mw.flushFrame(true, data)
			}

			w, err := c.NextWriter(messageType)
			if err != nil {
				return err
			}
			if _, err = w.Write(data); err != nil {
				return err
			}
			return w.Close()
		}

- websocket conn.go: NextWriter()

		// NextWriter returns a writer for the next message to send. The writer's Close
		// method flushes the complete message to the network.
		//
		// There can be at most one open writer on a connection. NextWriter closes the
		// previous writer if the application has not already done so.
		//
		// All message types (TextMessage, BinaryMessage, CloseMessage, PingMessage and
		// PongMessage) are supported.
		func (c *Conn) NextWriter(messageType int) (io.WriteCloser, error) {
			var mw messageWriter
			if err := c.beginMessage(&mw, messageType); err != nil {
				return nil, err
			}
			c.writer = &mw
			if c.newCompressionWriter != nil && c.enableWriteCompression && isData(messageType) {
				w := c.newCompressionWriter(c.writer, c.compressionLevel)
				mw.compress = true
				c.writer = w
			}
			return c.writer, nil
		}

- websocket conn.go: beginMessage()

		// beginMessage prepares a connection and message writer for a new message.
		func (c *Conn) beginMessage(mw *messageWriter, messageType int) error {
			// Close previous writer if not already closed by the application. It's
			// probably better to return an error in this situation, but we cannot
			// change this without breaking existing applications.
			if c.writer != nil {
				c.writer.Close()
				c.writer = nil
			}

			if !isControl(messageType) && !isData(messageType) {
				return errBadWriteOpCode
			}

			c.writeErrMu.Lock()
			err := c.writeErr
			c.writeErrMu.Unlock()
			if err != nil {
				return err
			}

			mw.c = c
			mw.frameType = messageType
			mw.pos = maxFrameHeaderSize

			if c.writeBuf == nil {
				wpd, ok := c.writePool.Get().(writePoolData)
				if ok {
					c.writeBuf = wpd.buf
				} else {
					c.writeBuf = make([]byte, c.writeBufSize)
				}
			}
			return nil
		}

- websocket conn.go: write()

		func (c *Conn) write(frameType int, deadline time.Time, buf0, buf1 []byte) error {
			<-c.mu
			defer func() { c.mu <- true }()

			c.writeErrMu.Lock()
			err := c.writeErr
			c.writeErrMu.Unlock()
			if err != nil {
				return err
			}

			c.conn.SetWriteDeadline(deadline)
			if len(buf1) == 0 {
				_, err = c.conn.Write(buf0)
			} else {
				err = c.writeBufs(buf0, buf1)
			}
			if err != nil {
				return c.writeFatal(err)
			}
			if frameType == CloseMessage {
				c.writeFatal(ErrCloseSent)
			}
			return nil
		}


## Deadline HTTP 网络超时机制

Websocket 连接是通过 upgrader.Upgrade() 将 HTTP 连接升级得到的，也就是按 Websocket 协议进行握手的过程。这里很重要的一个环节是通过 http.Hijacker 接口接管 HTTP 连接对象实现长连接的转换。然后通过 Hijack() 方法获得缓存数据流读写对象 bufio.ReadWriter，代码中通过 brw.Reader.Buffered() 来判断客户端是否发送的数据，在握手完成前发数据是不恰当的。底层的读写方法如下，主要是对缓存区 IO 对象的管理，读取或写入后关闭缓存区读写对象：

- `ReadMessage()` 通过 NextReader() 读取数据帧；
- `NextReader()` 管理 bufio.Reader 的关闭，会通过 `advanceFrame()` 丢弃上一帧未读取的数据，如果是压缩数据交给 DecompressionReader 读取；
- `advanceFrame()` 根据 Websocket 协议解析 read() 读取到的数据帧，获取消息类型如 TextMessage、 BinaryMessage 等；
- `read()` 通过 bufio.Reader 对象的 Peek(n)、 Discard(n) 探测数据；
- `WritMessage()` 通过 beginMessage() 写消息数据；
- `NextWriter()` 通过 beginMessage() 写消息数据；
- `beginMessage()` 管理 bufio.Reader 的关闭；

bufio.Reader 对象的 Peek(n) 用来预读 n 字节数据而不移动缓存区的读写头位置，如果 Peek 返回的切片长度比 n 小，它也会返会一个错误说明原因，比如 io.EOF 表示已经到结束位置。如果 n 比缓冲尺寸还大，返回的错误将是 ErrBufferFull。如果 Peek() 读到需要的内容，那么就可以使用 Discard() 更新读写头的位置，这个方法用来丢弃缓存区的数据，配合 Peek() 使用。Read() 则是立即返回的，不考是否有缓存数据。

ReadLine() 方法则会在读取到缓存区的换行符 `\n` 前阻塞，直到超时，返回三个参数，line 表示读取到的数据，isPrefix 表示是否读取到换行符。如果在超时未读取到换行符，则会返回 err 错误对象，isPrefix = false，无论如何，返回数据都是不含换行符的。类似的是 `ReadBytes()` 方法，它可以指定一个标记符作为分割，返回结果中包含分割符，除非出错。

	func (b *Reader) ReadLine() (line []byte, isPrefix bool, err error)
	func (b *Reader) ReadBytes(delim byte) ([]byte, error)

注意 `advanceFrame()` 方法中调用 `read(2)` 即瞄一下缓存区的两个字节， `Peek(n)` 这个方法的使用结合 Deadline 机制会有不同的表现，参考后面的 NTTP 超时机制。在这里，假如没有超时操作，那么方法就会进入阻塞等待缓存区的内容够 2 个字节是返回数据，如果操作超时，那么就根据当前缓存区的数据返回错误信息。和其它方法如 Read() 都是非阻塞方法，执行就立即返回。如果不设置超时限制，那么只要客户端没有发送足够的数据，这里就会一直阻塞。

使用 `bufio.Scanner` 也是如此，通过 NewScanner() 方法实例化使用的缓冲区大小是 64kb MaxScanTokenSize = 64 * 1024。

以下帮助信息通过 go doc bufio.Reader.Peek/Discard 获取：

    Peek returns the next n bytes without advancing the reader. The bytes stop
    being valid at the next read call. If Peek returns fewer than n bytes, it
    also returns an error explaining why the read is short. The error is
    ErrBufferFull if n is larger than b's buffer size.

    Calling Peek prevents a UnreadByte or UnreadRune call from succeeding until
    the next read operation.

    Discard skips the next n bytes, returning the number of bytes discarded.

    If Discard skips fewer than n bytes, it also returns an error. If 0 <= n <=
    b.Buffered(), Discard is guaranteed to succeed without reading from the
    underlying io.Reader.

回到 Upgrade 这个方法中，它主要是进行一些前期的协调配置，主要内容：

- 缓存区设置；
- Sec-WebSocket-Extensions 扩展配置，如消息压缩，如针对数据流的压缩 deflate-stream 或对消息的压缩 permessage-deflate；
- Sec-Websocket-Protocol 子协议支持；
- net.Conn 连接对象的超时机制 Deadline 设置；

网络应用开发过程中，超时机制的处理总是最易犯错和最微妙的地方之一。错误可能来自很多地方，一个错误可能等待很长时间没有结果，直到网络故障或者进程挂起。

HTTP 是一个复杂的、多阶段(multi-stage)协议，所以没有一个放之四海而皆准的超时解决方案，比如一个流服务、一个 JSON API 和一个 Comet 服务对超时的需求都不相同， 往往默认值不是你想要的。

通过 net.Conn 为 Deadline 机制提供的相关方法设置合适的时间才是正确的做法：

- SetDeadline(time.Time)
- SetReadDeadline(time.Time)
- SetWriteDeadline(time.Time)

Deadline 是一个绝对时间值，当到达这个时间的时候，所有的 I/O 操作都会失败，返回超时 timeout 错误。

Deadline 不是超时 timeout 而是一个具体时间节点，一旦设置它们永久生效，直到下一次调用 SetDeadline，不管此时连接是否被使用和怎么用。所以如果想使用 SetDeadline 建立超时机制，你不得不每次在 Read/Write 操作之前调用它。

而设置 timeout 的方式是为了让 net/http 代替你调用 Deadline 方法。但是请记住，所有的超时的实现都是基于 Deadline 机制。

对于 Websocket 服务器来说，为客户端连接设置超时至关重要，否则巨慢的或者隐失的客户端可能导致文件句柄无法释放，或者客户端发送的数据包不能即使处理，导致客户端的操作超时。

http.Server 有两个设置超时的方法: `ReadTimeout` 和 and `WriteTimeout`。你可以显示地设置它们：

	srv := &http.Server{  
	    ReadTimeout: 5 * time.Second,
	    WriteTimeout: 10 * time.Second,
	}
	log.Println(srv.ListenAndServe())

ReadTimeout 的时间计算是从连接被接受 accept 到 request body 完全被读取，如果你不读取 body，那么时间截止到读完 header 为止。内部实现是在 Accept 立即调用 SetReadDeadline 方法。

WriteTimeout 的时间计算正常是从 request header 的读取结束开始，到 response write 结束为止，也就是 ServeHTTP 方法的声明周期, 它是通过在 readRequest 方法结束的时候调用 SetWriteDeadline 实现的。



## go-my-websocket Demo

现在是时候开始写代码造自己的轮子了！

以 Golang 为例，结合 engine.io-protocol、 socket.io-protocol 来实现一个简化版 Websocket 服务，参考 gorilla websocket 的实现：

	go get github.com/gorilla/websocket

以下是 Gorilla WebSocket 与 Golang 内置的包 net 包的功能比较：

| Features	| github.com/gorilla | golang.org/x/net	|
| :-------- | :----------------- | :--------------- |
| Passes Autobahn Test Suite	| Yes	| No	|
| Receive fragmented message	| Yes	| No, see note 1	|
| Send close message			| Yes	| No	|
| Send pings and receive pongs	| Yes	| No	|
| Get the type of a received data message	| Yes	| Yes, see note 2	|
| Compression Extensions		| Experimental	| No	|
| Read message using io.Reader	| Yes	| No, see note 3	|
| Write message using io.WriteCloser	| Yes	| No, see note 3	|

Notes:

1. Large messages are fragmented in [Chrome's new WebSocket implementation](http://www.ietf.org/mail-archive/web/hybi/current/msg10503.html).
2. The application can get the type of a received data message by implementing
   a [Codec marshal](http://godoc.org/golang.org/x/net/websocket#Codec.Marshal)
   function.
3. The go.net io.Reader and io.Writer operate across WebSocket frame boundaries.
  Read returns when the input buffer is full or a frame boundary is
  encountered. Each call to Write sends a single frame message. The Gorilla
  io.Reader and io.WriteCloser operate on a single WebSocket message.


可以使用辅助调试工具 Fiddler 来抓取 Websocket 数据包用于调试分析，在主界面的连接列表中双击 WS 标记的连接即可在右侧数据面板中看到 Websocket 连接传输的数据。

为了简化，这里不能完全实现一个像 Gorilla Websocket 那样功能完整的服务端与客户端，只能挑选基本核心的需求，来实现一个简化的版本，使用 MASK，约定载荷最大为 125 字节，不使用分包发送，不使用压缩扩展，即不返回 Sec-WebSocket-Extensions 的压缩相关扩展如 permessage-deflate。

先来构思以下项目文件结构，主程序按功能划分成三个文件 main.go 作为服务器入口，ws.go 作为 Websocket 协议服务器实现，负责数据的获取与发送，而数据报的解析交给 parser.go 来完成。view 目录下则作为前端测试页面，socket.io.js 由 socket.io-client 提供。

	src
	 ├───go-my-websocket
	 │   ├──main.go
	 │   └──ws
	 │     ├──parser.go
	 │     └──ws.go
	 ├───view
	 │    ├──index.html
	 │    ├──socket.io.js
	 │    └──theme.css
	 └───package.json

入口文件 main.go 主要负责 Web 服务逻辑处理，主要逻辑代码如下，通过 home 提供一个 Websocket 测试页面服务，通过 staticweb 提供一个静态文件服务以使用 view 目录下的测试页面，然后是 `ws.Wsdemo{}` 实例提供核心的 Websocket Server 服务：
	
	package main

	import (
		"./ws"
		"html/template"
		stdLog "log"
		"net/http"
		"os"
	)

	var log = stdLog.New(os.Stderr, "[ws]", stdLog.Ltime)

	func main() {
		staticweb := http.StripPrefix("/socket/", http.FileServer(http.Dir("./src/view/")))

		http.Handle("/socket.io/", ws.Wsdemo{})
		http.Handle("/socket/", staticweb)
		http.HandleFunc("/", home)

		log.SetPrefix("[wsDemo]")
		log.Println("Serving at localhost:8000...")
		log.Fatal(http.ListenAndServe(":8000", nil))
	}

	func home(w http.ResponseWriter, r *http.Request) {
		homeTemplate.Execute(w, "ws://"+r.Host+"/socket.io/")
	}

	var homeTemplate = template.Must(template.New("").Parse(`
		<!DOCTYPE html>
		<html>
		<head>
		<meta charset="utf-8">
		<script>
		...
		ws = new WebSocket("{{.}}");
		...
		`))


在 Websocket 服务端，定义一些常量方便测试输出调试信息。有 MessageType、 EngineioPacket、 SocketioPacket、 ErrorCode 这些，并且为它们都实现了一个 String() 方法来获取相关的文字信息。 这种用来输出数据类型关联信息的 String() 方法可以使用一个 Stringer 模块来自动化生成，但是作为演示 Demo 没有必要引入使用。

	type MessageType byte

	func (s MessageType) String() string {
		cs := map[MessageType]string{
			0xf0: "BrokenMessage",
			0:    "ContinuationFrame",
			1:    "TextMessage",
			2:    "BinaryMessage",
			8:    "CloseMessage",
			9:    "PingMessage",
			10:   "PongMessage",
		}[s]
		if cs > "" {
			return cs
		} else {
			return fmt.Sprintf("<MessageType unknown:%d>", s)
		}
	}

	type EngineioPacket string

	func (s EngineioPacket) Unknown() bool {
		return strings.HasPrefix(s.String(), "<EngineioPacket unknown:")
	}
	func (s EngineioPacket) String() string {
		cs := map[EngineioPacket]string{
			"1": "EIO_Close",
			"2": "EIO_Ping",
			"3": "EIO_Pond",
			"4": "EIO_Message",
			"5": "EIO_Upgrade",
			"6": "EIO_Noop",
		}[s]
		if cs > "" {
			return cs + "[OK]"
		} else {
			return fmt.Sprintf("<EngineioPacket unknown:%q>", string(s))
		}
	}

解析器实现简单的消息包解构，没有提供解压缩能力。解包逻辑分成四步走，先解析数据包的前两个字节获取消息类型和基本的 opcode、 masking、 payload len 信息。然后再解析具体的数据长度以及 masking-key 等数据。最后两步就是读取 payload 数据，以及 unmaking 解码数据如果需要。

	package ws

	import (
		"encoding/binary"
		"fmt"
		"strings"
	)
	...

	type FrameParser struct {
		Raw          []byte
		parsed       bool
		Final        bool
		Rsv1         bool
		Rsv2         bool
		Rsv3         bool
		Opcode       byte
		Maskingkey   []byte
		Masking      bool
		Type         MessageType
		ExHeaderSize uint
		Length       uint64
		Header       []byte
		Data         []byte
	}

	func (c *FrameParser) Detect(header []byte) (msgtype MessageType, exsize uint, err ErrorCode) {
		c.Reset() // ready for a new frame
		if len(header) != 2 {
			return BrokenMessage, 0, ErrorLength
		}
		// 2bytes header
		c.Final = (header[0] | byte(1<<7)) > 0
		c.Rsv1 = (header[0] | byte(1<<6)) > 0
		c.Rsv2 = (header[0] | byte(1<<5)) > 0
		c.Rsv3 = (header[0] | byte(1<<4)) > 0
		c.Opcode = (header[0] & 0x0F)
		c.Type = MessageType(c.Opcode)
		c.Masking = (header[1] & byte(1<<7)) > 0
		c.Length = uint64(header[1] & 0x7f)

		c.ExHeaderSize = 0
		if c.Masking {
			c.ExHeaderSize += 4
		}
		if c.Length == 126 {
			c.ExHeaderSize += 2
		} else if c.Length == 127 {
			c.ExHeaderSize += 8
		}
		c.Raw = append([]byte{}, header...) // copy
		return c.Type, c.ExHeaderSize, ErrorNil
	}

	func (c *FrameParser) DecideLength(ex []byte) (payloadlen uint64, err ErrorCode) {
		if uint(len(ex)) != c.ExHeaderSize {
			return 0, ErrorLength
		}
		if c.Masking {
			c.Maskingkey = ex[len(ex)-4:]
		}
		if c.Length == 126 {
			c.Length = binary.BigEndian.Uint64(ex[0:2])
		} else if c.Length == 127 {
			c.Length = binary.BigEndian.Uint64(ex[0:8])
		}
		c.Raw = append(c.Raw, ex...) // copy
		return c.Length, ErrorNil
	}

	func (c *FrameParser) Load(data []byte) ErrorCode {
		if uint64(len(data)) != c.Length {
			return ErrorLength
		}
		c.Raw = append(c.Raw, data...)     // copy
		c.Data = append([]byte{}, data...) // copy
		c.Mask()
		return ErrorNil
	}

	func (c *FrameParser) Mask() ErrorCode {
		ldata := uint64(len(c.Data))
		lkey := len(c.Maskingkey)
		if !c.Masking && ldata == c.Length {
			return ErrorNil
		} else if !c.Masking && ldata != c.Length {
			return ErrorLength
		} else if c.Masking && lkey != 4 {
			return ErrorKeyLength
		} else if c.Masking {
			for i := uint64(0); i < c.Length; i++ {
				j := i % uint64(lkey)
				b := c.Maskingkey[j] ^ c.Data[i]
				c.Data[i] = b
			}
		}
		return ErrorNil
	}

	func (c *FrameParser) Reset() {
		c.Raw = []byte{}
		c.parsed = false
		c.Final = false
		c.Rsv1 = false
		c.Rsv2 = false
		c.Rsv3 = false
		c.Opcode = 0
		c.Maskingkey = []byte{}
		c.Masking = false
		c.Type = 0
		c.Length = 0
		c.Header = []byte{}
		c.Data = []byte{}
	}


解析器的数据来源由 Wsdemo 提供，它实现的消息层面的逻辑。主要是客户端的接入，ServeHTTP() 调用 Upgrade() 方法对 HTTP 连接进行升级，主要是通过 http.Hijacker 接口来劫持底层 TCP 连接对象 net.Conn。获得底层连接对象后就可以开始进入握手阶段，通过 OpenHandshake() 方法完成，完成这一过程后就可以开始数据通讯，可以通过 read() 方法配合 peek() 提供的阻塞逻辑来读取客户端的数据，对于一个 Engin.io 客户端，首先需要按协议发送初始化连接参数，并且发送一条 Engine.io 的 Open 消息，以告知客户端可以开始进入数据交互。

读取数据后就交由 parser 进行解析，获得相应的消息类型后再进入上层的 API 处理。 Wsdemo 实现了一些 Websocket、 Engine.io、 Socket.io 相关的 API，主要是各种消息的发送和接收处理，API 并不完整，只是作为 Websocket 协议展示用途已经完全够用。

- Websocket
	- TextFrame(payload string)
	- BinaryFrame(payload string)
	- CloseFrame(payload string)
	- PingFrame(payload string)
	- PongFrame(payload string)
- Engine.io
	- EngineioOpen(text string)
	- EngineioClose(text string)
	- EngineioPing(text string)
	- EngineioPond(text string)
	- EngineioMessage(text string)
	- EngineioUpgrade(text string)
	- EngineioNoop(text string)
- Socket.io
	- SocketioEventEmit(event string, text string)


为了输出调试信息，这里定制了一个 log 实例，通过参数选项配置其输出更简洁的日志信息。

	package ws

	import (
		stdLog "log"
		...
	)

	var log = stdLog.New(os.Stderr, "[ws]", stdLog.Ltime)

	type Wsdemo struct {
		w       http.ResponseWriter
		r       *http.Request
		netconn net.Conn
		brw     *bufio.ReadWriter
		who     string
	}

	func (c Wsdemo) read() {
		fm := FrameParser{}
		for {
			p, err := c.peek(2)
			if err != nil {
				break
			} else if len(p) != 2 {
				continue
			}
			log.Printf("Read a 2bytes header: %d [%x] [%x]\n", len(p), p, p)
			// onData...
			msgtype, exsize, ec := fm.Detect(p)
			if ec != ErrorNil {
				continue
			}
			ex, err := c.peek(int(exsize))
			if err != nil {
				break
			} else if uint(len(ex)) != exsize {
				continue
			}
			log.Printf("Read an ex-header [%d] %s: %d [%x] [%x]\n", exsize, msgtype.String(), len(ex), ex, ex)
			payloadlen, _ := fm.DecideLength(ex)
			payload, err := c.peek(int(payloadlen))
			if err != nil {
				break
			}
			log.Printf("Read payload [%d] %s: %d [%x]", payloadlen, msgtype.String(), len(payload), payload)
			fm.Load(payload)
			c.onMessage(fm)
		}
	}

	func (c Wsdemo) ServeHTTP(w http.ResponseWriter, r *http.Request) {
		c.w = w
		c.r = r

		if r.URL.RequestURI() == "/socket.io/socket.io.js" {
			w.Write([]byte(`
			// socket.io.js not provide here, use CDN below:
			// https://cdnjs.com/libraries/socket.io
			// https://cdnjs.cloudflare.com/ajax/libs/socket.io/2.3.0/socket.io.js
			`))
			return
		}

		netConn, brw, _ := c.Upgrade(w, r)
		c.netconn = netConn
		c.brw = brw
		c.who = c.netconn.RemoteAddr().String()

		log.Println("Wsdemo.ServeHTTP()...", r.URL.RequestURI(), r.RequestURI)

		Upgrade := r.Header.Get("Upgrade") == "websocket"
		Connection := r.Header.Get("Connection") == "Upgrade"
		if isWebsocketUpgrade := Upgrade && Connection; isWebsocketUpgrade {
			c.OpenHandshake()
			c.EngineioOpen("Engine.io Open")
			go c.read()
		} else {
			netConn.Write([]byte("HTTP/1.1 200 OK\r\n\r\nThis is an websocket server, use websocket client to connect."))
			netConn.Close()
		}
	}

	func (c Wsdemo) peek(size int) (p []byte, err error) {
		if size == 0 {
			return []byte{}, nil
		}
		c.netconn.SetDeadline(time.Now().Add(30000 * time.Millisecond))
		var brw *bufio.ReadWriter = c.brw
		buf, err := brw.Peek(size)
		brw.Discard(len(buf))
		// buf := []byte{}
		// size, err := brw.Read(buf)
		if err != nil && err == io.EOF { // client disconnect
			c.netconn.Close()
			return buf, err
		} else if err != nil {
			switch err.(type) {
			case *net.OpError:
				var e *net.OpError = err.(*net.OpError)
				log.Printf("Peeking net.OpError [%x] timeout:%t temporary:%t %#+v", p, e.Timeout(), e.Temporary(), e.Err)
				if !(e.Timeout() || e.Temporary()) {
					log.Printf("Client leave %s", c.who)
					c.netconn.Close()
					return buf, err
				}
			default:
				log.Printf("Peeking error %#+v", err)
			}
		}

		return buf, nil
	}

	func (c Wsdemo) onSocketioMessage(data []byte, fm FrameParser) {
		msgtype := SocketioPacket(data[0:1])
		switch msgtype {
		case SIO_Binary_Event:
			packet := []string{}
			err := json.Unmarshal(data[3:], &packet)
			if err != nil {
				log.Printf("onSocketio Event unmarshal error %s raw[%s]", err, string(data[1:]))
				return
			}
			event := packet[0]
			c.SocketioEventDemo(event, packet[1])
			log.Printf("onSocketio BinaryEvent %s %s len[%d]", event, packet[1], len(data))
		case SIO_Event:
			packet := []string{}
			err := json.Unmarshal(data[1:], &packet)
			if err != nil {
				log.Printf("onSocketio Event unmarshal error %s raw[%s]", err, string(data[1:]))
				return
			}
			event := packet[0]
			c.SocketioEventDemo(event, packet[1])
			log.Printf("onSocketio Event %s %s len[%d]", event, packet[1], len(data))
		default:
			log.Printf("onSocketioPacet %s %s len[%d]: %x", msgtype.String(), string(data), len(data), data)
		}
	}
	func (c Wsdemo) onEngineioPacket(data []byte, fm FrameParser) {
		msgtype := EngineioPacket(data[0:1])
		log.Printf("onEnginioMessage %s %s len[%d]: % x", msgtype.String(), string(data), len(data), data)
		if msgtype == EIO_Ping {
			c.EngineioPond("Pong...")
		} else if msgtype == EIO_Message {
			c.onSocketioMessage(data[1:], fm)
		} else if msgtype.Unknown() {
			c.TextFrame("Unknown Type::" + string(data))
		}
	}
	func (c Wsdemo) onMessage(fm FrameParser) {
		if fm.Type == CloseMessage {
			log.Println("Close connection for " + fm.Type.String() + string(fm.Data))
			c.netconn.Close()
		} else if fm.Type == TextMessage {
			c.onEngineioPacket(fm.Data, fm)
		} else {
			log.Printf("onMessage %s data:%s len[%d]: % x", fm.Type.String(), string(fm.Data), len(fm.Raw), fm.Raw)
		}
	}

	func (c Wsdemo) computeAcceptKey(challengeKey string) string {
		var keyGUID = []byte("258EAFA5-E914-47DA-95CA-C5AB0DC85B11")
		sn := append([]byte(challengeKey), keyGUID...)
		h := sha1.New()
		h.Write(sn)
		// hash := sha1.Sum(sn)
		return base64.StdEncoding.EncodeToString(h.Sum(nil))
	}

	func (c Wsdemo) TextFrame(payload string) {
		if len(payload) > 125 {
			payload = payload[0:124-len(TOO_LONG)] + TOO_LONG
		}
		len := byte(len(payload))
		frame := []byte{0x80 | byte(TextMessage), len}
		frame = append(frame, []byte(payload)...)
		c.send(frame)
	}
	func (c Wsdemo) BinaryFrame(payload string) {
		if len(payload) > 125 {
			payload = payload[0:124-len(TOO_LONG)] + TOO_LONG
		}
		len := byte(len(payload))
		frame := []byte{0x80 | byte(BinaryMessage), len}
		frame = append(frame, []byte(payload)...)
		c.send(frame)
	}
	func (c Wsdemo) CloseFrame(payload string) {
		if len(payload) > 125 {
			payload = payload[0:124-len(TOO_LONG)] + TOO_LONG
		}
		len := byte(len(payload))
		frame := []byte{0x80 | byte(CloseMessage), len}
		frame = append(frame, []byte(payload)...)
		c.send(frame)
	}
	func (c Wsdemo) PingFrame(payload string) {
		if len(payload) > 125 {
			payload = payload[0:124-len(TOO_LONG)] + TOO_LONG
		}
		len := byte(len(payload))
		frame := []byte{0x80 | byte(PingMessage), len}
		frame = append(frame, []byte(payload)...)
		c.send(frame)
	}
	func (c Wsdemo) PongFrame(payload string) {
		if len(payload) > 125 {
			payload = payload[0:124-len(TOO_LONG)] + TOO_LONG
		}
		len := byte(len(payload))
		frame := []byte{0x80 | byte(PongMessage), len}
		frame = append(frame, []byte(payload)...)
		c.send(frame)
	}
	func (c Wsdemo) send(frame []byte) {
		c.netconn.SetWriteDeadline(time.Now().Add(30 * time.Second))
		c.brw.Write(frame)
		c.brw.Writer.Flush()
		// c.brw.Flush()
	}

	func (c Wsdemo) OpenHandshake() {
		challengeKey := c.r.Header.Get("Sec-WebSocket-Key")
		Extensions := c.r.Header.Get("Sec-WebSocket-Extensions")
		Protocol := c.r.Header.Get("Sec-WebSocket-Protocol")

		p := []byte{}
		p = append(p, "HTTP/1.1 101 Switching Protocols\r\n"...)
		p = append(p, "Upgrade: websocket\r\n"...)
		p = append(p, "Connection: Upgrade\r\n"...)
		if Protocol > "" {
			p = append(p, ("Sec-WebSocket-Protocol: " + Protocol + "\r\n")...)
		}
		if false && Extensions > "" {
			p = append(p, ("Sec-WebSocket-Extensions: permessage-deflate\r\n")...)
		}
		p = append(p, ("Sec-WebSocket-Accept: " + c.computeAcceptKey(challengeKey) + "\r\n")...)

		p = append(p, "\r\n"...)

		// Clear deadlines set by HTTP server.
		c.netconn.SetDeadline(time.Time{})

		log.Printf("OpenHandshake %s...", c.who)
		c.netconn.Write(p)
	}

	func (c Wsdemo) Upgrade(w http.ResponseWriter, r *http.Request) (net.Conn, *bufio.ReadWriter, error) {
		hj, ok := w.(http.Hijacker)
		if !ok {
			msg := "websocket: response does not implement http.Hijacker"
			http.Error(w, msg, http.StatusInternalServerError)
			return nil, nil, errors.New(msg)
		}
		var brw *bufio.ReadWriter
		netConn, brw, err := hj.Hijack()
		if err != nil {
			http.Error(w, err.Error(), http.StatusInternalServerError)
			return nil, nil, err
		}

		if brw.Reader.Buffered() > 0 {
			netConn.Close()
			msg := "websocket: client sent data before handshake is complete"
			http.Error(w, msg, http.StatusInternalServerError)
			return nil, nil, errors.New(msg)
		}

		return netConn, brw, nil
	}

	// Engine.io API
	func (c Wsdemo) EngineioOpen(text string) {
		// Engine.io Open Message
		mo := `0{"sid":"client_%s","upgrades":[],"pingInterval":%d,"pingTimeout":%d}`
		packet := []byte(fmt.Sprintf(mo, c.who, PingInterval/time.Millisecond, PingTimeout/time.Millisecond))
		c.TextFrame(string(packet))
		c.TextFrame("40")
	}
	func (c Wsdemo) EngineioClose(text string) {
		c.TextFrame("1" + text)
	}
	func (c Wsdemo) EngineioPing(text string) {
		c.TextFrame("2" + text)
	}
	func (c Wsdemo) EngineioPond(text string) {
		c.TextFrame("3" + text)
	}
	func (c Wsdemo) EngineioMessage(text string) {
		c.TextFrame("4" + text)
	}
	func (c Wsdemo) EngineioUpgrade(text string) {
		c.TextFrame("5" + text) // ???
	}
	func (c Wsdemo) EngineioNoop(text string) {
		c.TextFrame("6" + text)
	}

	// Socket.io API
	func (c Wsdemo) SocketioEventDemo(event string, data string) {
		res := fmt.Sprintf("%s received[%d]: %s", event, len(data), data)
		jsontxt := fmt.Sprintf("{%q:%q,%q:%q}", "userId", c.who, "text", res)
		event = "chat"
		c.SocketioEventEmit(event, jsontxt)
	}
	func (c Wsdemo) SocketioEventEmit(event string, text string) {
		// enc := base64.StdEncoding.EncodeToString([]byte(text))
		msg := fmt.Sprintf("2[%q,%s]", event, text)
		c.EngineioMessage(msg)
	}

以上是 go-my-websocket 的基本实现结构，完整代码可以通过 Github 托管页面获取。本文配套的完整电子版 PDF，也一并提供下载。

谢谢阅读！

## 參考
- [王垠 - 如何掌握所有的程序语言](http://www.yinwang.org/blog-cn/2017/07/06/master-pl)
- [RFC 6455 - The WebSocket Protocol](https://tools.ietf.org/html/rfc6455)
- [RFC 791 - IP(Internet Protocol)](https://www.rfc-editor.org/info/rfc791)
- [RFC 793 - TCP(Transmission Control Protocol)](https://www.rfc-editor.org/info/rfc793)
- [RFC 1945 - Hypertext Transfer Protocol -- HTTP/1.0](http://www.rfc-editor.org/info/rfc1945)
- [RFC 2616 - Hypertext Transfer Protocol -- HTTP/1.1](http://www.rfc-editor.org/rfc/rfc2616.html)
- [Golang net/http 超时机制完全手册](http://colobu.com/2016/07/01/the-complete-guide-to-golang-net-http-timeouts/)
- [Filippo Valsorda - The complete guide to Go net/http timeouts](http://colobu.com/2016/07/01/the-complete-guide-to-golang-net-http-timeouts/)
- [Github Demo Code](https://github.com/jimboyeah/demo)
