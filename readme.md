# Demo

Demo 这个仓库原本是坚果用来学 Git 版本管理用的，随着演示项目的增加，觉得有需要通过分支的方式来管理各个演示 DEMO，所以原来的 demo 仓库的 master 只是作为文档来使用，而各个分支则作为演示项目来推进：

	git clone https://github.com/jimboyeah/demo.git

演示项目列表：

- 《造轮子 Websocket 现在就 Go》 https://github.com/jimboyeah/demo/tree/go-my-websocket

		git clone -b go-my-websocket https://github.com/jimboyeah/demo.git

    配套文章已经发往简书 https://www.jianshu.com/p/c44f556de0dd


# 造轮子 Websocket 现在就 Go
MD: 2019‎年‎12‎月17‎日，‏‎03:45:10
https://gitbook.cn/gitchat/activity/5df7ecb85d2ecb0a746047df


笔者坚果有幸从事软件开发，一直都是兴趣驱动的工作。第一次接触计算机是 1999 年后的事，我用来学习的电脑是大哥买来准备学 CAD 的 486 机，当时 CPU 还是威胜的 333MHz 主频，硬盘也只有 4GB，系统是 Windows 98 SE。那时所谓的学电脑纯属拆玩具模式，因为手上可用的资源不多，网络也不发达，也没有太丰富的参考资料，相关的图书也不是太丰富。所以翻查硬盘或系统光盘文件成了日常活动，除此之外，DOS 游戏也和红白机具有一样的可玩性。彼时，BAT 脚本和 Windows 系统光盘中 QBasic 脚本编程工具成了不错的好玩具。后来玩起了 Visual Studio 6.0，主要是 VB 和 VBA 脚本编程，C 语言也开始了解一些，C++ 几乎没有基础可言，所以 Visual C++ 一直玩不动 MFC 什么的更是不知云云。当然了，集成开发工具提供的最大的好处也就体现在这，即使你是个傻瓜也能毫不費力地运行配置好的模板程序，编译成完整的可运行程序。不知不觉，坚果从曾经的傻瓜程序员一路走到今天，没有兴趣带领还真不会有今天。

## 内容提要

这是我二进 GitChat 的创造，距离今年 ‎6 ‎月分‎第一次发布《从 JavaScript 入门到 Vue 组件实践》大谈前端技术全局观、30' JavaScript 入门课，还有 VSCode 和 Sublime 这些好用的开发工具。到如今已经有近半年时间，‎期间经历了较大的工作变动，技术上已经以脚本后端转到 Golang 为主，这是一种我一直期待的语言。期间也学到一些技术领域比较不容易学习到的知识，有项目管理层面的，有职业规划方面的，对知识付费时代也有了更深入的理解。

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


> 从任天堂红白机时代接触单片机，尽管那时不懂却被深深吸引了；从 MS-DOS 时代结缘计算机，就这样一路披荆斩棘前行；很多人说 IT 人是吃青春饭的，对于我，一个 80 后，在乳臭未干的时候就闻到这饭香了，到现在也没觉得吃够吃厌倦了。我只当这是个兴趣，现在这个爱好还能给我带来一份收入而已。
>
> by Jeangowhy 微信同名(jimboyeah◉gmail.com) 
> Tue Dec 17 2019 04:23:08 GMT+0800 (深圳宝安)

![gitchat](https://github.com/jimboyeah/demo/blob/go-my-websocket/go-my-websocket.jpg)
