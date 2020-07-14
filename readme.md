# 10 Best C# Books 
- [10 Best C# Books](http://www.developersfeed.com/10-best-c-books-to-learn-programming/)
- [C# 3.0 Cookbook, Third Edition](https://docs.microsoft.com/en-us/previous-versions/visualstudio/visual-studio-2008/ff518995(v=orm.10))

- C# 5.0 in a Nutshell: The Definitive Reference
- Head First C#
- Pro C# 5.0 and the .NET 4.5 Framework (Expert’s Voice in .NET)
- C# in Depth, 4th Edition https://csharpindepth.com

        Table of Contents (4th edition)
        Part 1: C# in context
        1: Survival of the sharpest
        Part 2: C# 2-5
        2: C# 2
        3: C# 3: LINQ and everything that comes with it
        4: C# 4: Improving interoperability
        5: Writing asynchronous code
        6: Async implementation
        7: C# 5 bonus features
        Part 3: C# 6
        8: Super-sleek properties and expression-bodied members
        9: Stringy features
        10: A smörgåsbord of features for concise code
        Part 4: C# 7 and beyond
        11: Composition using tuples
        12: Deconstruction and pattern matching
        13: Improving efficiency with more pass by reference
        14: Concise code in C# 7
        15: C# 8 and beyond
        Appendix: Language features by version

- Programming C# 5.0: Building Windows 8, Web, and Desktop Applications for the .NET 4.5 Framework
- Adaptive Code via C#: Agile coding with design patterns and SOLID principles (Developer Reference)
- C# 5.0 Unleashed
- The C# Player’s Guide
- MCSD Certification Toolkit (Exam 70-483): Programming in C#
- Murach’s C# 2012

# Getting Started

参考
- https://dotnet.microsoft.com/
- https://docs.microsoft.com/en-us/dotnet/core
- https://docs.microsoft.com/zh-cn/dotnet/api/?view=netcore-3.1
- https://docs.microsoft.com/en-us/dotnet/core/whats-new/dotnet-core-3-0
- https://docs.microsoft.com/en-us/dotnet/csharp/whats-new/csharp-8
- https://www.c-sharpcorner.com/article/what-is-dot-net-core/
- https://docs.microsoft.com/zh-cn/dotnet/standard/library-guidance/
- https://docs.microsoft.com/zh-cn/nuget/
- https://blog.davidebbo.com/2011/01/nuget-versioning-part-1-taking-on-dll.html
- [ASP.NET Core 中的 Kestrel Web 服务器实现](https://docs.microsoft.com/zh-cn/aspnet/core/fundamentals/servers/kestrel?view=aspnetcore-3.0)
- http://docs.libuv.org/en/v1.x/design.html
- https://docs.microsoft.com/en-us/dotnet/core/install/linux-package-manager-ubuntu-1804
- https://docs.microsoft.com/en-us/dotnet/core/install/linux-package-manager-debian10
- https://docs.microsoft.com/en-us/dotnet/core/additional-tools/uninstall-tool?tabs=windows

.Net Core 项目开源地址：

- https://github.com/dotnet/corefx
- https://github.com/dotnet/efcore
- https://github.com/aspnet
- https://github.com/aspnet/EntityFrameworkCore
- https://github.com/aspnet/Configuration
- https://github.com/aspnet/Routing
- https://github.com/aspnet/Security
- https://github.com/aspnet/DependencyInjection
- https://github.com/aspnet/HttpAbstractions
- https://github.com/aspnet/Options
- https://github.com/aspnet/Mvc
- https://github.com/aspnet/Hosting
- https://github.com/aspnet/razor
- https://github.com/dotnet/blazor
- https://source.dot.net/
- https://github.com/dotnet/AspNetCore.Docs


继 .NET Framework 后，微软发行 .NET Core 使得 C#成为跨平台开发语言的首先之一，它带来的新语言特性改进了 C++/Java 的一些缺点。.NET Core 是一个新的开源并且跨平台的用来构建可以所有操作系统，包括 Windows, Mac, and Linux 上面运行的应用的的框架。特性包括开源、跨平台、现代、灵活、轻量级、快速、友好、可共享，以及为未来的软件开发而构建的。

新式 .NET 支持多个操作系统和设备。 .NETNET 开源库支持尽可能多的开发人员，无论是构建 Azure 中托管的 ASP.NET 网站的开发人员，还是在 Unity 中开发 .NET 游戏的开发人员，这一点非常重要。

有两种支持的 .NET 实现可用于生成服务器端应用：.NET Framework 和 .NET Core。 这两者共享许多相同的组件，可在它们之间共享代码。 但两者之间存在根本的差异，可根据需要实现的目标进行选择。 

.NET Core 包含 ASP.NET Core，它是 ASP.NET 4.x 的重新设计，下表比较。

| ASP.NET Core  | ASP.NET 4.x   |
| :-----------  | :-----------  |
| 针对 Windows、macOS、Linux 进行生成   |针对 Windows 进行生成    |
| Razor Pages 是在 ASP.NET Core 2.x 及更高版本中创建 Web UI 时建议使用的方法。 MVC、Web API 和 SignalR。  |使用 Web Forms、SignalR、MVC、Web API、WebHook 或网页   |
| 每个计算机多个版本 |每个计算机一个版本  |
| 使用 C# 或 F# 通过 Visual Studio、Visual Studio for Mac 或 Visual Studio Code 进行开发   |使用 C#、VB 或 F# 通过 Visual Studio 进行开发    |
| 比 ASP.NET 4.x 性能更高    |良好的性能  |
| 使用 .NET Core 运行时  |使用 .NET Framework 运行时  |


.NET Core 是由 Microsoft 开发，目前在 .NET Foundation 非营利开源组织管理。.NET Core 是用 C# 和 C++ 编写的，并采用 MIT 协议作为开源协议。第一个版本的 .NET Core 1.0 是在 2016 年发布的，功能有限。NET Core 2.0 于 2017年8月14日发布，在这个版本中发布的两个核心框架是 ASP.NET Core 2.0 和 Entity Framework Core 2.0。

.NET Core 的当前版本为 2.1.18 LTS/3.1.4 LTS，支持最新的 C# 8.0，以下是 .NET Core 3.0 中的其他功能和增强功能列表，

- Windows 桌面的 MSIX 部署
- MSIX 是一种新的 Windows 应用程序包格式。它可用于将 .NET Core 3.0 桌面应用程序部署到 Windows 10。
- 快速内置 JSON支 持
- IEEE 浮点改进
- .NET 平台依赖内在函数
- 依赖于框架的可执行文件支持
- 构建副本依赖项
- 装配卸载
- Windows Native Interop
- Linux 上的 TLS 1.3 和 OpenSSL 1.1.1
- 改进的密码学
- 适用于 Linux 的 SerialPort
- ARM64 Linux 支持
- GPIO 支持 Raspberry Pi


为开放源代码 .NET 库创建 NuGet 包管理平台，包括在 NuGet.org 上公开发布的所有包的推荐元数据。

NuGet 包 `*.nupkg` 是一个 zip 文件，其中包含 .NET 程序集和关联的元数据。

NuGet 是 .NET 生态系统的包管理器，并且是开发人员用来发现并获取 .NET 开放源代码库的主要方法。 NuGet.org（由托管 NuGet 包的 Microsoft 提供的免费服务）是公共 NuGet 包的主要主机，但可以发布到自定义 NuGet 服务，如 MyGet 和 Azure Artifacts。

创建 NuGet 包有两种主要方式。 较新的推荐方式是从 SDK 样式项目，其内容以 `<Project Sdk="Microsoft.NET.Sdk">` 开头的项目文件创建包。 程序集和目标会自动添加到包，剩余元数据会添加到 MSBuild 文件，如包名称和版本号。 使用 `dotnet pack` 命令编译会输出 `*.nupkg` 文件，而不是程序集。

NuGet 包支持多个元数据属性。 下表包含 NuGet.org 上的每个包应提供的核心元数据：

| MSBuild 属性名称  | Nuspec 名称 | 说明 |
| PackageId         | id            | 包标识符。 如果标识符的前缀满足条件，则可以保留该前缀。 |
| PackageVersion    | version   | NuGet 包版本。 有关详细信息，请参阅 NuGet 包版本。 |
| Title             | title         | 明了易用的包标题。 默认为 PackageId。 |
| Description       | description   | UI 中显示的包的详细说明。 |
| Authors           | authors   | 包创建者的逗号分隔列表，与 nuget.org 上的配置文件名称一致。 |
| PackageTags       | tags          | 描述包的标记和关键字的空格分隔列表。 搜索包时使用标记。 |
| PackageIconUrl    | iconUrl   | 要用作包的图标的图像 URL。 URL 应为 HTTPS，图像应为 64x64 并具有透明背景。 |
| PackageProjectUrl | projectUrl    | 项目主页或源存储库的 URL。 |
| PackageLicenseExpression  | license   | 项目许可证的 SPDX 标识符。 只有获得 OSI 和 FSF 批准的许可证才能使用标识符。 其他许可证应使用 PackageLicenseFile。 详细了解 license 元数据。 |


为了让使用者不必针对各个框架构建，应该尽量获取 .NET Standard 输出以及一个或多个特定于框架的输出。 通过多目标，所有程序集都打包在一个 NuGet 包中。 然后，使用者可以引用同一个包，NuGet 将选择适当的实现。 你的 .NET Standard 库充当在任何地方使用的回退库（NuGet 包提供特定于框架的实现的情况除外）。 通过多目标可以在代码中使用条件编译并调用特定于框架的 API。

    public static class GpsLocation
    {
        // This project uses multi-targeting to expose device-specific APIs to .NET Standard.
        public static async Task<(double latitude, double longitude)> GetCoordinatesAsync()
        {
    #if NET461
            return CallDotNetFramworkApi();
    #elif WINDOWS_UWP
            return CallUwpApi();
    #else
            throw new PlatformNotSupportedException();
    #endif
        }

        // Allows callers to check without having to catch PlatformNotSupportedException
        // or replicating the OS check.
        public static bool IsSupported
        {
            get
            {
    #if NET461 || WINDOWS_UWP
                return true;
    #else
                return false;
    #endif
            }
        }
    }

❌ 如果你的源代码源代码对所有目标都相同，请避免多目标以及面向 .NET Standard，实现会增加 nupkg 大小，不会提供任何好处。
✔️ 请考虑在提供 netstandard2.0 目标时为 net461 添加目标。在 .NET Framework 中使用 .NET Standard 2.0 存在一些问题，在 .NET Framework 4.7.2 中已得到解决。 
✔️ 请使用 NuGet 包分发库。NuGet 将为开发人员选择最佳目标，使他们无需选择适当实现。
✔️ 请务必在使用多目标时使用项目文件的 TargetFrameworks 属性。


    <Project Sdk="Microsoft.NET.Sdk">
      <PropertyGroup>
        <!-- This project will output netstandard2.0 and net461 assemblies -->
        <TargetFrameworks>netstandard2.0;net461</TargetFrameworks>
      </PropertyGroup>
    </Project>


重要的基础类库结构：

    >dotnet --list-runtimes
    Microsoft.AspNetCore.All 2.1.18 [C:\Program Files\dotnet\shared\Microsoft.AspNetCore.All]
    Microsoft.AspNetCore.App 2.1.18 [C:\Program Files\dotnet\shared\Microsoft.AspNetCore.App]
    Microsoft.AspNetCore.App 3.0.0 [C:\Program Files\dotnet\shared\Microsoft.AspNetCore.App]
    Microsoft.AspNetCore.App 3.1.4 [C:\Program Files\dotnet\shared\Microsoft.AspNetCore.App]
    Microsoft.AspNetCore.App 5.0.0-preview.4.20257.10 [C:\Program Files\dotnet\shared\Microsoft.AspNetCore.App]
    Microsoft.NETCore.App 2.1.18 [C:\Program Files\dotnet\shared\Microsoft.NETCore.App]
    Microsoft.NETCore.App 3.0.0 [C:\Program Files\dotnet\shared\Microsoft.NETCore.App]
    Microsoft.NETCore.App 3.1.4 [C:\Program Files\dotnet\shared\Microsoft.NETCore.App]
    Microsoft.NETCore.App 5.0.0-preview.4.20251.6 [C:\Program Files\dotnet\shared\Microsoft.NETCore.App]
    Microsoft.WindowsDesktop.App 3.0.0 [C:\Program Files\dotnet\shared\Microsoft.WindowsDesktop.App]
    Microsoft.WindowsDesktop.App 3.1.4 [C:\Program Files\dotnet\shared\Microsoft.WindowsDesktop.App]
    Microsoft.WindowsDesktop.App 5.0.0-preview.4.20251.1 [C:\Program Files\dotnet\shared\Microsoft.WindowsDesktop.App]

- Microsoft.AspNetCore.App

    ASP.NET Core 共享框架包含由 Microsoft 开发和支持的程序集。 NET Core 3.0 或更高版本 SDK 时，提供安装在计算机上包括运行时组件和目标包的一组程序集 DLL 文件。 面向 Microsoft.NET.Sdk.Web SDK 的项目隐式引用 Microsoft.AspNetCore.App 框架。

    默认的 Web 运行时，提供 Microsoft.NETCore.App，此外增加 HTTP server API，以承载 Kestrel, Mvc, SignalR, Razor, 及 EF Core 的部分功能。

    使用 Microsoft.NET.Sdk 或 Microsoft.NET.Sdk.Razor SDK 的项目必须引用 ASP.NET Core，才能使用共享框架中的 ASP.NET Core API。若要引用 ASP.NET Core，请将以下 <FrameworkReference> 元素添加到项目文件：

        <Project Sdk="Microsoft.NET.Sdk">

            <PropertyGroup>
                <TargetFramework>netcoreapp3.0</TargetFramework>
            </PropertyGroup>

            <ItemGroup>
                <FrameworkReference Include="Microsoft.AspNetCore.App" />
            </ItemGroup>

        </Project>

    仅 .NET Core 3.x 的项目支持使用此方式引用 ASP.NET Core。

- Microsoft.NETCore.App 

    基础的运行时，提供诸如 System.Object, List<T>, string, memory management, file, network IO, threading 等等基础服务。


- Microsoft.AspNetCore.All

    引用共享框架的元包，集成第三方工具，也引入了 Microsoft.AspNetCore.App 基础。添加 EF Core + SQLite, Redis 扩展，Azure Key Vault 配置等。但在 .Net Core 3.0 弃用转而使用 Microsoft.AspNetCore.App，其它用的第三方包另行引入。


# Install .Net SDK or Runtime


利用 .Net SDK 提供的命令行编译工具，可以很方便地结合开源文本编辑器 Visual Studio Code 或 Sublime Text 进行 Windows，Linux 和 Mac OS 跨平台开发。VSCode 还支持 IntelliSense 和 debugging，就像 Sublime, Emacs, and VI 那样。

.NET Core 3.1 支持的 Linux 系统分发版本：

| OS    | Version   | Architectures |
| Red Hat Enterprise Linux  | 6, 7, 8   | x64 |
| CentOS    | 7+    | x64 |
| Oracle Linux  | 7+    | x64 |
| Fedora    | 30+   | x64 |
| Debian    | 9+    | x64, ARM32, ARM64 |
| Ubuntu    | 16.04+    | x64, ARM32, ARM64 |
| Linux Mint    | 18+   | x64 |
| openSUSE  | 15+   | x64 |
| SUSE Enterprise Linux (SLES)  | 12 SP2+   | x64 |
| Alpine Linux  | 3.10+ | x64, ARM64 |


安装 .NET Framework 或 .Net Core SDK 即可以开始编写代码，Windows 系统下载安装包安装。

    >dotnet --list-sdks
    2.1.806 [C:\Program Files\dotnet\sdk]
    3.0.100 [C:\Program Files\dotnet\sdk]
    3.1.300 [C:\Program Files\dotnet\sdk]
    5.0.100-preview.4.20258.7 [C:\Program Files\dotnet\sdk]

Windows 上安装 .NET Framework 可以在以下位置找到：

    C:\Windows\Microsoft.NET\Framework\v2.0.50727\
    C:\Windows\Microsoft.NET\Framework64\v2.0.50727\
    C:\Windows\Microsoft.NET\Framework\v4.0.30319\
    C:\Windows\Microsoft.NET\Framework64\v4.0.30319

安装和移除依赖的方式，以 Xamarin.Forms.theme.base 为例：

    dotnet add package Xamarin.Forms.pages --version 4.6.0.847
    dotnet add package Xamarin.Forms.theme.base --version 1.0.0.43-pre1
    dotnet add package Xamarin.Forms.theme.light --version 1.0.0.43-pre1
    dotnet add package Xamarin.Forms.theme.dark --version 1.0.0.43-pre1
    dotnet add package -s c:\download Xamarin.Forms.theme.base
    dotnet package --package-directory c:\download Xamarin.Forms.Pages
    dotnet remove package Xamarin.Forms.Pages

Ubuntu 18.04 系统安装 .Net SDK 3.1 步骤及命令，其它版本可选 3.0 或 2.1：

    # Add Microsoft repository key and feed

    wget https://packages.microsoft.com/config/ubuntu/18.04/packages-microsoft-prod.deb -O packages-microsoft-prod.deb
    sudo dpkg -i packages-microsoft-prod.deb

    # Install the .NET Core SDK

    sudo add-apt-repository universe
    sudo apt-get update
    sudo apt-get install apt-transport-https
    sudo apt-get update
    sudo apt-get install dotnet-sdk-3.1

    # Install the ASP.NET Core runtime

    sudo add-apt-repository universe
    sudo apt-get update
    sudo apt-get install apt-transport-https
    sudo apt-get update
    sudo apt-get install aspnetcore-runtime-3.1


如何定位不到 .NET Core 依赖包，可以执行以下命令修复：

    sudo dpkg --purge packages-microsoft-prod && sudo dpkg -i packages-microsoft-prod.deb
    sudo apt-get update
    sudo apt-get install {the .NET Core package}

    sudo apt-get install -y gpg
    wget -O - https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor -o microsoft.asc.gpg
    sudo mv microsoft.asc.gpg /etc/apt/trusted.gpg.d/
    wget https://packages.microsoft.com/config/ubuntu/18.04/prod.list
    sudo mv prod.list /etc/apt/sources.list.d/microsoft-prod.list
    sudo chown root:root /etc/apt/trusted.gpg.d/microsoft.asc.gpg
    sudo chown root:root /etc/apt/sources.list.d/microsoft-prod.list

    sudo apt-get install -y apt-transport-https
    sudo apt-get update
    sudo apt-get install {the .NET Core package}


Ubuntu 18.04 和 Debian 10 是同源系统，安装命令相似：

    # Add Microsoft repository key and feed

    wget -O - https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > microsoft.asc.gpg
    sudo mv microsoft.asc.gpg /etc/apt/trusted.gpg.d/
    wget https://packages.microsoft.com/config/debian/10/prod.list
    sudo mv prod.list /etc/apt/sources.list.d/microsoft-prod.list
    sudo chown root:root /etc/apt/trusted.gpg.d/microsoft.asc.gpg
    sudo chown root:root /etc/apt/sources.list.d/microsoft-prod.list

    # Install the .NET Core SDK

    sudo apt-get update
    sudo apt-get install apt-transport-https
    sudo apt-get update
    sudo apt-get install dotnet-sdk-3.1

    # Install the ASP.NET Core runtime

    sudo apt-get update
    sudo apt-get install apt-transport-https
    sudo apt-get update
    sudo apt-get install aspnetcore-runtime-3.1
    
    # Install the .NET Core runtime

    sudo apt-get update
    sudo apt-get install apt-transport-https
    sudo apt-get update
    sudo apt-get install dotnet-runtime-3.1

CentOS 8 / RHEL 8 / Fedora 32 等系统上安装：

    # Install the .NET Core SDK

    sudo dnf install dotnet-sdk-3.1
    
    # Install the ASP.NET Core Runtime

    sudo dnf install aspnetcore-runtime-3.1

    #Install the .NET Core Runtime

    sudo dnf install dotnet-runtime-3.1

openSUSE 15 系统上安装：

    # Add Microsoft repository feed and signing key to trusted list

    sudo zypper install libicu
    sudo rpm --import https://packages.microsoft.com/keys/microsoft.asc
    wget https://packages.microsoft.com/config/opensuse/15/prod.repo
    sudo mv prod.repo /etc/zypp/repos.d/microsoft-prod.repo
    sudo chown root:root /etc/zypp/repos.d/microsoft-prod.repo

    #Install the .NET Core SDK

    sudo zypper install dotnet-sdk-3.1

    #Install the ASP.NET Core runtime

    sudo zypper install aspnetcore-runtime-3.1

    #Install the .NET Core runtime

    sudo zypper install dotnet-runtime-3.1

通常，新版本兼容旧版本，可以另行安装 .NET Core Uninstall 工具 dotnet-core-uninstall  卸载旧版本。 .NET Core 3.0 SDK 前面的版本安装依赖会使用 NuGetFallbackFolder ，如果不考虑回到旧版本的开发，也可以删除 NuGet fallback，使用回复命令及回滚目录位置：

    dotnet restore
    dotnet build /t:Restore

    C:\Program Files\dotnet\sdk on Windows and at 
    /usr/local/share/dotnet/sdk 

编译器与 C# 版本根据 .Net 版本不同使用不同默认值：

| .NET Core | 3.x   | C# 8.0 |
| .NET Core | 2.x   | C# 7.3 |
| .NET Standard | 2.1   | C# 8.0 |
| .NET Standard | 2.0   | C# 7.3 |
| .NET Standard | 1.x   | C# 7.3 |
| .NET Framework    | 全部    | C# 7.3 |


如果必须明确指定 C# 版本，可以通过以下几种方式实现：

- 手动编辑项目文件。
- 为子目录中的多个项目设置语言版本。
- 配置 -langversion 编译器选项。

如果 SDK 版本太低，比如 .NET Framework v4.0.30319 只能通过 -langversion 指定 C# 版本为 ISO-1、ISO-2、3、4、5，其它更高的 C# 版本支持就需要更新 SDK 或 Visual Studio 自带的编译器来获得。Visual Studio 的编译引擎是 MSBuild - Microsoft Build Tools ，它提供了一套 NuGet 项目文件 .csproj , .vbproj , vcxproj 的 XML Schema 用来指定如何处理和编译项目。当然 MSBuild 不依赖于 Visual Studio，完全可以独立安装使用 MSBuild，它是 MIT License 开源软件。 可以下载 Microsoft Build Tools 2013/2015 以支持 C# 6.0。

    https://www.microsoft.com/en-us/download/details.aspx?id=40760#msbuild_tools_2013
    https://www.microsoft.com/en-us/download/details.aspx?id=48159#msbuild_tools_2015

    C:\Program Files (x86)\MSBuild\14.0\Bin

注意，从 .NET Framework 4 开始，所有的 .NET Framework 版本都是升级更新，因此在系统中只能存在一个 4.x 的版本。更新内容安装位置：

    C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\

使用 dotnet 命令测试安装结果：

    >dotnet

    Usage: dotnet [options]
    Usage: dotnet [path-to-application]

    Options:
      -h|--help         Display help.
      --info            Display .NET Core information.
      --list-sdks       Display the installed SDKs.
      --list-runtimes   Display the installed runtimes.

    path-to-application:
      The path to an application .dll file to execute.


    >where dotnet
    C:\Program Files\dotnet\dotnet.exe

    >dotnet --list-sdks
    2.1.806 [C:\Program Files\dotnet\sdk]
    3.0.100 [C:\Program Files\dotnet\sdk]

    >dotnet --list-runtimes
    Microsoft.AspNetCore.All 2.1.18 [C:\Program Files\dotnet\shared\Microsoft.AspNetCore.All]
    Microsoft.AspNetCore.App 2.1.18 [C:\Program Files\dotnet\shared\Microsoft.AspNetCore.App]
    Microsoft.AspNetCore.App 3.0.0 [C:\Program Files\dotnet\shared\Microsoft.AspNetCore.App]
    Microsoft.NETCore.App 2.1.18 [C:\Program Files\dotnet\shared\Microsoft.NETCore.App]
    Microsoft.NETCore.App 3.0.0 [C:\Program Files\dotnet\shared\Microsoft.NETCore.App]
    Microsoft.WindowsDesktop.App 3.0.0 [C:\Program Files\dotnet\shared\Microsoft.WindowsDesktop.App]

    > dotnet new console -o myApp
    > cd myApp

配置你的 Sublime 编译工具，将 Sublime 项目保存到 DotNet 项目中，可以使用 $project_path 引用，在中文系统中指定 "encoding": "cp936" 防止控制台乱码，"quiet": true 在编译出错时不输出当前环境变量信息，file_regex 指定正则表达式以获取错误信息输出的行号、列号和错误提示：

    {
        "env": {
            "path":"C:\\Program Files (x86)\\MSBuild\\14.0\\Bin;C:\\Windows\\Microsoft.NET\\Framework\\v4.0.30319\\;%path%",
            "libs":"/lib:./bin/ /r:a.dll,b.dll,c.dll",
        },
        "working_dir": "$file_path",
        "cmd": "csc.exe $file",
        "file_regex": "^(.[^\\(]*)\\(([0-9]+),([0-9]+)\\):(.*)$",
        "selector": "source.cs, source.xaml, source.csproj",
        "encoding": "cp936",
        "quiet": true,
        "variants": [{
            "name": "Build Exe & Run ...",
            "shell_cmd": "csc.exe $file_name && $file_base_name"
        },{
            "name": "Build DLL",
            "shell_cmd": "csc.exe /target:library $file"
        },{
            "name": "Run",
            "shell_cmd": "$file_base_name"
        },{
            "name": ".Net New",
            "shell_cmd": "dotnet new console -o demo"
        },{
            "name": ".Net Run",
            "shell_cmd": "dotnet run"
        },{
            "name": ".Net Watch",
            "shell_cmd": "dotnet watch run"
        },{
            "name": ".Net Run Project",
            "shell_cmd": "dotnet run --project $project_path"
        },{
            "name": ".Net Watch Project",
            "shell_cmd": "dotnet watch run --project $project_path"
        },{
            "name": "Run with Test Arguments",
            "shell_cmd": "$file_base_name http://baidu.com/ http://golang.org/ http://goproxy.io"
        }]
    }   

默认情况下，ASP.NET Core 项目模板使用 Kestrel Web 服务器，这是一个基于 libuv 库的轻量级高并发跨平台服务器，支持反向代理。 libuv 最先是为 Node.js 开发的，因为其良好的事件驱动的异步 IO 设计而得到广泛的应用， I/O loop 也称为 Event Loop 是其核心设计。

在项目 Program.cs 的 ConfigureWebHostDefaults 方法调用 UseKestrel ：

    public static void Main(string[] args)
    {
        CreateHostBuilder(args).Build().Run();
    }

    public static IHostBuilder CreateHostBuilder(string[] args) =>
        Host.CreateDefaultBuilder(args)
            .ConfigureWebHostDefaults(webBuilder =>
            {
                webBuilder.UseStartup<Startup>();
            });


    webBuilder.UseKestrel((context, serverOptions) =>
    {
        serverOptions.Configure(context.Configuration.GetSection("Kestrel"))
            .Endpoint("HTTPS", listenOptions =>
            {
                listenOptions.HttpsOptions.SslProtocols = SslProtocols.Tls12;
            });
    });


    // using System.Security.Cryptography.X509Certificates;
    webBuilder.UseStartup<Startup>()
        .UseKestrel(options =>
        {
            options.ConfigureHttpsDefaults(i =>
            {
                i.ServerCertificate = new X509Certificate2("ca-test/localhost.pfx", "123456");
            });
        })
        .UseContentRoot(Directory.GetCurrentDirectory())
        .UseUrls("https://*:443");

UseContentRoot 设置的是根目录，wwwroot 才是 Web 访问到的目录。

若要在调用 ConfigureWebHostDefaults 后提供其他配置，请使用 ConfigureKestrel：

    webBuilder.ConfigureKestrel(serverOptions =>
    {
        serverOptions.Limits.MaxConcurrentConnections = 100;
        serverOptions.Limits.MaxConcurrentUpgradedConnections = 100;
        serverOptions.Limits.MaxRequestBodySize = 10 * 1024;
        serverOptions.Limits.MinRequestBodyDataRate =
            new MinDataRate(bytesPerSecond: 100, 
                gracePeriod: TimeSpan.FromSeconds(10));
        serverOptions.Limits.MinResponseDataRate =
            new MinDataRate(bytesPerSecond: 100, 
                gracePeriod: TimeSpan.FromSeconds(10));
        serverOptions.Listen(IPAddress.Loopback, 5000);
        serverOptions.Listen(IPAddress.Loopback, 5001, 
            listenOptions =>
            {
                listenOptions.UseHttps("testCert.pfx", 
                    "testPassword");
            });
        serverOptions.Limits.KeepAliveTimeout = 
            TimeSpan.FromMinutes(2);
        serverOptions.Limits.RequestHeadersTimeout = 
            TimeSpan.FromMinutes(1);
    })




# CSC C# Compiler
- [C# Compiler Options Listed by Category](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/compiler-options/listed-by-category)

基本操作

Compiles File.cs producing File.exe:

    csc File.cs 

Compiles File.cs producing File.dll:

    csc /target:library File.cs

Compiles File.cs and creates My.exe:

    csc /out:My.exe File.cs

Compiles all the C# files in the current directory, with optimizations on and defines the DEBUG symbol. The output is File2.exe:

    csc /define:DEBUG /optimize /out:File2.exe *.cs

Compiles all the C# files in the current directory producing a debug version of File2.dll. No logo and no warnings are displayed:

    csc /target:library /out:File2.dll /warn:0 /nologo /debug *.cs

Compiles all the C# files in the current directory to Something.xyz (a DLL):

    csc /target:library /out:Something.xyz *.cs

生成调试信息

    csc /define:DEBUG /optimize /out:File2.exe *.cs

模块化 DLL 生成和引用

    csc /target:library /out:File2.dll /warn:0 /nologo /debug *.cs
    csc /target:library /out:lib/Class1.dll Class1.cs
    csc /lib:lib_path /reference:Class1.dll /reference:File2.dll HelloWorld.cs

HelloWorld.exe 运行时，需要和 DLL 在同一个目录

Module VS Assembly：Module是编译单元，Assemly是部署单元。

The /reference option causes the compiler to import public type information in the specified file into the current project, thus enabling you to reference metadata from the specified assembly files.

    /reference:[alias=]filename
    /reference:filename

The /lib option specifies the location of assemblies referenced by means of the /reference (C# Compiler Options) option.

    /lib:dir1[,dir2]




输出选项

To create an .exe file for Windows 8.x Store apps.

    /target:appcontainerexe

To create an .exe file.

    /target:exe

To create a code library.

    /target:library

To create a module.

    /target:module

To create a Windows program.

    /target:winexe

To create an intermediate .winmdobj file.

    /target:winmdobj


编译命令有几个个嵌入资源的选项：

-linkresource
-resource
-win32res

在旧 Win32 程序中可以支持 res 协议，比如 CHM HTML Helper 使用在 DLL 或 EXE 中内嵌的 HTML 页面资源：

    res://resource file[/resource type]/resource id

其中 `resource type` 缺省时表示默认的 23 即 HTML，`resource file` 是资源在 EXE or DLL 的路径，`resource id` 就是嵌入资源的名称。

但是 .NET 程序的资源不同处理，C# or VB.NET 工程不直接支持，托管的 Managed C++ project 支持。

.NET 程序或 DLL 可以通过 csc.exe 或 al.exe 提供的 `/win32res` 编译选项编译资源。

有一个工具 Resource Hacker 可以做资源的修改或提取。 
http://www.angusj.com/resourcehacker/

输出文件中创建到 .Net 资源的链接简写是 /linkres，资源文件就是在那些在工程文件中使用到的所有的资源，像图片、声音等。这个选项只是对于资源文件建立链接，这样有助于管理使用同一资源的程序，而不需要多个副本。此选项的具体语法如下：

    /linkresource:filename,identifier,mimetype

/resource 选项和 /linkresource 正好相反，是把资源文件嵌入到输出文件中，参数、用法都和 /linkresource 相同。相应的读取代码：

    using System.Reflection;
    using System.IO;
    using System.Resources;

        // csc media.cs -resource:"surface.wav"
        protected static void ResourceRead()
        {
            Assembly assembly = Assembly.GetExecutingAssembly();
            Stream steam = assembly.GetManifestResourceStream("surface.wav");


CSC: Optimization

    -filealign  Specifies the size of sections in the output file.
    -optimize   Enables/disables optimizations.

CSC: Output Files

    -deterministic  Causes the compiler to output an assembly whose binary content is identical across compilations if inputs are identical.
    -doc    Specifies an XML file where processed documentation comments are to be written.
    -out    Specifies the output file.
    -pathmap    Specify a mapping for source path names output by the compiler
    -pdb    Specifies the file name and location of the .pdb file.
    -platform   Specify the output platform.
    -preferreduilang    Specify a language for compiler output.
    -refout Generate a reference assembly in addition to the primary assembly.
    -refonly    Generate a reference assembly instead of a primary assembly.
    -target Specifies the format of the output file using one of five options: -target:appcontainerexe, -target:exe, -target:library, -target:module, -target:winexe, or -target:winmdobj.
    -modulename:<string>    Specify the name of the source module

CSC:.NET Framework Assemblies

    -addmodule  Specifies one or more modules to be part of this assembly.
    -delaysign  Instructs the compiler to add the public key but to leave the assembly unsigned.
    -keycontainer   Specifies the name of the cryptographic key container.
    -keyfile    Specifies the filename containing the cryptographic key.
    -lib    Specifies the location of assemblies referenced by means of -reference.
    -nostdlib   Instructs the compiler not to import the standard library (mscorlib.dll).
    -publicsign Apply a public key without signing the assembly, but set the bit in the assembly indicating the assembly is signed.
    -reference  Imports metadata from a file that contains an assembly.
    -analyzer   Run the analyzers from this assembly (Short form: /a)
    -additionalfile Names additional files that don't directly affect code generation but may be used by analyzers for producing errors or warnings.
    -embed  Embed all source files in the PDB.
    -embed:<file list>  Embed specific files in the PDB.

CSC: Debugging/Error Checking

    -bugreport  Creates a file that contains information that makes it easy to report a bug.
    -checked    Specifies whether integer arithmetic that overflows the bounds of the data type will cause an exception at run time.
    -debug  Instruct the compiler to emit debugging information.
    -errorreport    Sets error reporting behavior.
    -fullpaths  Specifies the absolute path to the file in compiler output.
    -nowarn Suppresses the compiler's generation of specified warnings.
    -warn   Sets the warning level.
    -warnaserror    Promotes warnings to errors.
    -ruleset:<file> Specify a ruleset file that disables specific diagnostics.

CSC: Preprocessor

    -define Defines preprocessor symbols.

CSC: Resources

    -link   Makes COM type information in specified assemblies available to the project.
    -linkresource   Creates a link to a managed resource.
    -resource   Embeds a .NET Framework resource into the output file.
    -win32icon  Specifies an .ico file to insert into the output file.
    -win32res   Specifies a Win32 resource to insert into the output file.

CSC: Miscellaneous

    @   Specifies a response file.
    -?  Lists compiler options to stdout.
    -baseaddress    Specifies the preferred base address at which to load a DLL.
    -codepage   Specifies the code page to use for all source code files in the compilation.
    -help   Lists compiler options to stdout.
    -highentropyva  Specifies that the executable file supports address space layout randomization (ASLR).
    -langversion    Specify language version: Default, ISO-1, ISO-2, 3, 4, 5, 6, 7, 7.1, 7.2, 7.3, or Latest
    -main   Specifies the location of the Main method.
    -noconfig   Instructs the compiler not to compile with csc.rsp.
    -nologo Suppresses compiler banner information.
    -recurse    Searches subdirectories for source files to compile.
    -subsystemversion   Specifies the minimum version of the subsystem that the executable file can use.
    -unsafe Enables compilation of code that uses the unsafe keyword.
    -utf8output Displays compiler output using UTF-8 encoding.
    -parallel[+|-]  Specifies whether to use concurrent build (+).
    -checksumalgorithm:<alg>    Specify the algorithm for calculating the source file checksum stored in PDB. Supported values are: SHA1 (default) or SHA256.
    Due to collision problems with SHA1, Microsoft recommends SHA256.

CSC: Obsolete Options

    -incremental    Enables incremental compilation.


# dotnet command

    >dotnet --help
    .NET Core SDK (3.0.100)
    使用情况: dotnet [runtime-options] [path-to-application] [arguments]

    执行 .NET Core 应用程序。

    runtime-options:
      --additionalprobingpath <path>   要探测的包含探测策略和程序集的路径。
      --additional-deps <path>         指向其他 deps.json 文件的路径。
      --fx-version <version>           要用于运行应用程序的安装版共享框架的版本。
      --roll-forward <setting>         前滚至框架版本(LatestPatch, Minor, LatestMinor, Major, LatestMajor, Disable)。

    path-to-application:
      要执行的应用程序 .dll 文件的路径。

    使用情况: dotnet [sdk-options] [command] [command-options] [arguments]

    执行 .NET Core SDK 命令。

    sdk-options:
      -d|--diagnostics  启用诊断输出。
      -h|--help         显示命令行帮助。
      --info            显示 .NET Core 信息。
      --list-runtimes   显示安装的运行时。
      --list-sdks       显示安装的 SDK。
      --version         显示使用中的 .NET Core SDK 版本。

    SDK 命令:
      add               将包或引用添加到 .NET 项目。
      build             生成 .NET 项目。
      build-server      与由生成版本启动的服务器进行交互。
      clean             清理 .NET 项目的生成输出。
      help              显示命令行帮助。
      list              列出 .NET 项目的项目引用。
      msbuild           运行 Microsoft 生成引擎(MSBuild)命令。
      new               创建新的 .NET 项目或文件。
      nuget             提供其他 NuGet 命令。
      pack              创建 NuGet 包。
      publish           发布 .NET 项目进行部署。
      remove            从 .NET 项目中删除包或引用。
      restore           还原 .NET 项目中指定的依赖项。
      run               生成并运行 .NET 项目输出。
      sln               修改 Visual Studio 解决方案文件。
      store             在运行时包存储中存储指定的程序集。
      test              使用 .NET 项目中指定的测试运行程序运行单元测试。
      tool              安装或管理扩展 .NET 体验的工具。
      vstest            运行 Microsoft 测试引擎(VSTest)命令。

    捆绑工具中的其他命令:
      dev-certs         创建和管理开发证书。
      fsi               启动 F# 交互/执行 F# 脚本。
      sql-cache         SQL Server 缓存命令行工具。
      user-secrets      管理开发用户密码。
      watch             启动文件观察程序，它会在文件发生更改时运行命令。

    运行 "dotnet [command] --help"，获取有关命令的详细信息。


配置 deps.json, runtimeconfig.json 用于帮助 dotnet 运行 DLL 应用程序。

- deps.json 是用来配置依赖的。
- runtimeconfig.json 对于.NET Core 应用程序来说是用来配置运行时的。

.NET Core 执行 Program.dll 文件必需要先知道 DLL 是什么类型程序，创建名为 Program.runtimeconfig.json 的文件，并使用如下内容：

    {
      "runtimeOptions": {
        "framework": {
          "name": "Microsoft.NETCore.App",
          "version": "3.1.0"
        }
      }
    }

这些设置指示 dotnet 使用 Microsoft.NETCore.App 3.1.0 共享框架。该框架也是最常使用的框架，还有其它的框架，例如 Microsoft.AspNetCore.Web.App。不像 .NET Framework 是装个机器范围生效，可以有多个 .NET Core 共享框架安装在同一台机器上。在 Linux 系统上，dotnet 将读取该 JSON 文件，在 /usr/local/share/dotnet/shared/$FrameworkName/$Version/ 中查找需要的文件并运行应用程序。

对于 .NET Core 应用程序来说，runtime.config.json 文件是必需的。术语 runtime 、shared framework、或者 platform 经常互换，但是，在谈论 .NET Core 的时候，它们是一回事。

deps.json 是一个记录 .NET Core 中依赖清单的文件，参考 deps.json：

    {
      "runtimeTarget": {
        "name": ".NETCoreApp,Version=v2.0"
      },
      "runtimeOptions": {
        "additionalProbingPaths": [ "/Users/packages/" ]
      },
      "targets": {
        ".NETCoreApp,Version=v2.0": {
          "Newtonsoft.Json/10.0.3": {
            "runtime": {
              "lib/netstandard1.3/Newtonsoft.Json.dll": {
                "assemblyVersion": "10.0.0.0",
                "fileVersion": "10.0.3.21018"
              }
            }
          }
        }
      },
      "libraries": {
        "Newtonsoft.Json/10.0.3": {
          "type": "package",
          "serviceable": false,
          "sha512": ""
        }
      }
    }

使用 dotnet new 可创建的项目模板：

    Templates                                         Short Name               Language          Tags
    ----------------------------------------------------------------------------------------------------------------------------------
    Console Application                               console                  [C#], F#, VB      Common/Console
    Class library                                     classlib                 [C#], F#, VB      Common/Library
    WPF Application                                   wpf                      [C#]              Common/WPF
    WPF Class library                                 wpflib                   [C#]              Common/WPF
    WPF Custom Control Library                        wpfcustomcontrollib      [C#]              Common/WPF
    WPF User Control Library                          wpfusercontrollib        [C#]              Common/WPF
    Windows Forms (WinForms) Application              winforms                 [C#]              Common/WinForms
    Windows Forms (WinForms) Class library            winformslib              [C#]              Common/WinForms
    Worker Service                                    worker                   [C#]              Common/Worker/Web
    Unit Test Project                                 mstest                   [C#], F#, VB      Test/MSTest
    NUnit 3 Test Project                              nunit                    [C#], F#, VB      Test/NUnit
    NUnit 3 Test Item                                 nunit-test               [C#], F#, VB      Test/NUnit
    xUnit Test Project                                xunit                    [C#], F#, VB      Test/xUnit
    Razor Component                                   razorcomponent           [C#]              Web/ASP.NET
    Razor Page                                        page                     [C#]              Web/ASP.NET
    MVC ViewImports                                   viewimports              [C#]              Web/ASP.NET
    MVC ViewStart                                     viewstart                [C#]              Web/ASP.NET
    Blazor Server App                                 blazorserver             [C#]              Web/Blazor
    ASP.NET Core Empty                                web                      [C#], F#          Web/Empty
    ASP.NET Core Web App (Model-View-Controller)      mvc                      [C#], F#          Web/MVC
    ASP.NET Core Web App                              webapp                   [C#]              Web/MVC/Razor Pages
    ASP.NET Core with Angular                         angular                  [C#]              Web/MVC/SPA
    ASP.NET Core with React.js                        react                    [C#]              Web/MVC/SPA
    ASP.NET Core with React.js and Redux              reactredux               [C#]              Web/MVC/SPA
    Razor Class Library                               razorclasslib            [C#]              Web/Razor/Library/Razor Class Library
    ASP.NET Core Web API                              webapi                   [C#], F#          Web/WebAPI
    ASP.NET Core gRPC Service                         grpc                     [C#]              Web/gRPC
    dotnet gitignore file                             gitignore                                  Config
    global.json file                                  globaljson                                 Config
    NuGet Config                                      nugetconfig                                Config
    Dotnet local tool manifest file                   tool-manifest                              Config
    Web Config                                        webconfig                                  Config
    Solution File                                     sln                                        Solution
    Protocol Buffer File                              proto                                      Web/gRPC

    Examples:
        dotnet new mvc --auth Individual
        dotnet new classlib --framework netcoreapp3.0
        dotnet new --help


# Web Over HTTPS
- https://docs.microsoft.com/zh-cn/aspnet/core/security/enforcing-ssl?view=aspnetcore-3.1
- https://docs.microsoft.com/en-us/aspnet/core/fundamentals/servers/kestrel?view=aspnetcore-3.1
- https://forums.xamarin.com/discussion/90195/how-can-i-do-https-requests
- https://docs.microsoft.com/en-us/xamarin/cross-platform/app-fundamentals/transport-layer-security?tabs=windows


使用 dotnet dev-certs 创建和管理开发证书，默认的 Web 项目基于 HTTPS 协议，如果不想使用可以使用 --no-https 选项：

    dotnet new webApp -o myWebApp --no-https

也可以去掉 --no-https 启用证书模式，并通过命令信任开发证书。工程模板会为 Web 应用添加一个 localhost 自认证证书，证书名称为 ASP.NET Core HTTPS development certificate。

相关的 Startup 配置：

    app.UseHsts();
    app.UseHttpsRedirection();

    services.AddHsts(options =>
    {
        options.Preload = true;
        options.IncludeSubDomains = true;
        options.MaxAge = TimeSpan.FromDays(60);
        options.ExcludedHosts.Add("example.com");
        options.ExcludedHosts.Add("www.example.com");
    });

    services.AddHttpsRedirection(options =>
    {
        options.RedirectStatusCode = StatusCodes.Status308PermanentRedirect;
        options.HttpsPort = 443;
    });

通过在 appsettings.json 中添加顶级条目：

    {
        "https_port": 443,
        "Logging": {
            "LogLevel": {
                "Default": "Information",
                "Microsoft": "Warning",
                "Microsoft.Hosting.Lifetime": "Information"
            }
        },
        "AllowedHosts": "*"
    }

侦听地址或端口在 launchSetting.json 设置：

    "applicationUrl": "http://*:5001;http://localhost:5000",


配置 Kestrel 服务指定证书文件的几种方式：
    
    webBuilder.ConfigureKestrel(serverOptions =>
    {
        serverOptions.Listen(IPAddress.Loopback, 5001, 
            listenOptions =>
            {
                listenOptions.UseHttps("testCert.pfx", 
                    "testPassword");
            });
    });

    webBuilder.UseStartup<Startup>()
    .UseKestrel(options =>
    {
        // 指定 pfx 文件路径
        options.Listen(IPAddress.Parse("172.16.0.10"), 5002, listenOptions =>
        {
            listenOptions.UseHttps(pfx, "123456");
        });

        options.ConfigureHttpsDefaults(i =>
        {
            i.ServerCertificate = new System.Security.Cryptography.X509Certificates.X509Certificate2("./ssl.pfx", "123456");
        });

    })
    .UseContentRoot(Directory.GetCurrentDirectory())
    .UseUrls("https://*:443");


自认证证书不被信任，即证书不是有正规 CA 机构颁发，由自己通过证书生成工具或命令生成，Chrome 浏览器会提示页面不安全而不会直接访问该页面。

    NET::ERR_CERT_AUTHORITY_INVALID

客户端访问服务器时，服务器提供的这个自签名证书就会有问题。由于 CA 根证书不在受信任的根证书颁发机构存储区中，所以它不受信任。浏览器就会认定是不安全的链接，可以通过浏览器将服务器提供的证书导出，安装到系统的信任列表，Chrome 浏览器可以在隐私设置和安全性管理证书，导入导出等，它管理的是个人账户上的证书。

或者在客户端将服务器证书导入到受信任根证书颁发机构列表中，这样浏览器就会因为这是系统信任的证书而认为链接是安全的。

让 Windows 根据证书类型自动选择存储位置时，通常会将导入到中间证书颁发机构分类下。

Windows 访问凭证证书管理在 控制面板 - 用户帐户和家庭安全 - 凭据管理器。完整的管理运行本地计算机的证书管理工具 certlm.msc 或当前用户的证书管理工具 certmgr.msc。


默认的自签证书的关联主机是 localhost，如果开发需要多台机器访问服务器，可能指定 IP 访问，这会导致客户端链接异常：

    Javax.Net.Ssl.SSLHandshakeException: java.security.cert.CertPathValidatorException

生成自签名证书及清除证书，检查证书是否有效：

    dotnet dev-certs https --trust
    dotnet dev-certs https --clean
    dotnet dev-certs https --check

创建并导出证书，使用密码加密，导出的是个人信息交换格式 pfx 文件：

    dotnet dev-certs https --export-path localhost.pfx --password 123456

导出证书可以通过 OpenSSL 进行格式转换，输入密码操作：

    openssl pkcs12 -in localhost.pfx -out localhost.pem -nodes
    
    >openssl verify localhost.pem
    localhost.pem: /CN=localhost
    error 20 at 0 depth lookup:unable to get local issuer certificate


Windows 提供的开发工具会提供 makecert 命名来生成证书：

    makecert -r -pe -n "CN=localhost" -b 01/01/2000 -e 01/01/2036 -eku 1.3.6.1.5.5.7.3.1 -ss my -sr localMachine -sky exchange -sp "Microsoft RSA SChannel Cryptographic Provider" -sy 12

    makecert.exe –pe -r  –n  "CN=localhost" -ss my -sr LocalMachine -a sha1 -len 2048  MyCA.cer

参数解析：

`-n` 指定主题的名字，固定格式， CN=主题名字 ，CN - Certificate Name 即被认证方名字。这里可以指定一些主题的其它附加信息，例如 O= *** 表示组织信息等等。

`-r` 创建自签署证书，意思就是说在生成证书时，将证书的发布机构设置为 CN。

`-pe` 将所生成的私钥标记为可导出。注意，服务器发送证书给客户端的时候，客户端只能从证书里面获取公钥，私钥是无法获取的。如果我们指定了这个参数，证书在安装在机器上后，我们还可以从证书中导出私钥，默认情况下是不能导出私钥的。正规的途径发布的证书，是不可能让你导出私钥的。

`-b` `–e` 证书的有效期

`-ss` 证书的存储名称，就是 windows 证书存储区的目录名，如果不存在在的话就创建一个。

`-sr` 证书的存储位置，只有currentuser（默认值）或 localmachine两个值。

`-sv` 指定保存私钥的文件，文件里面除了包含私钥外，其实也包含了证书。这个文件是需要保密的，这个文件在服务端配置时是需要用到的。

`-a` 指定签名算法，必须是 md5 或 rsa1。

`-in` 指定证书发布机构的名称

`-len` 这个参数在中文的帮助文档中好像没有提到，但是这个其实很重要，用于指定公钥的位数，越大越安全，默认值是1024，推荐2048。我试了下，这个不为1024的倍数也是可以的。


使用 OpenSSL 工具箱生成自签证书的各步骤，作为被认证方，先要有自己的 RSA 密钥对，再生成相应的证认证请请求文件，再交给 CA 认证。作为自签证证书，首先就是准备自己的证书作为根证书，再用自己的证书去认证。

先为 Root CA 机构生成 RSA 密钥对，需要设置一个密码短语：

    openssl genrsa -des3 -out ca.key

然后生成 CA 的证书请求文件 CSR - Certificate Signing Request：

    openssl req -new -key ca.key -out ca.csr


再按 -x509 格式产生自签名的证书 crt：

    openssl x509 -req -days 731 -sha1 -extensions v3_cs -signkey ca.key -in ca.csr -out ca.crt

接下来，按同样的操作，利用前面生成的 CA 证书来为其它申请者提供证书签名服务，为证书请求方生成 RSA 密钥对，这里使用 2048 位密码长度，前面使用默认 512 位密码。位数太低可能被认为证书是一个无效的数字签名。

然后再生成证书认证请求文件，需要前面设置的密码短语，按要求输入证书申请方信息：

    openssl genrsa -des3 -out server.key 2048
    
    openssl req -new -key server.key -out server.req
    
    openssl x509 -req -days 731 -sha1 -extensions v3_req -CA ca.crt -CAkey ca.key -CAserial ca.srl -CAcreateserial -in server.req -out server.crt

    openssl pkcs12 -export -in server.crt -inkey server.key -out server.pfx


可以通过 -subj 参数传入认证请求方信息，连带密码生成一步操作生成自签证书：

    openssl req -newkey rsa:2048 -nodes -keyout ca.key -x509 -days 731 -out ca.crt -subj "/C=CN/ST=GD/L=HY/O=Xamarin/OU=Tech./CN=Xamware/emailAddress=jeango@gmail.com"

一步生成证书密钥及请求文件，注意给网站使用的证书要确保 CN 为域名或 IP 地址：

    openssl req -newkey rsa:2048 -nodes -keyout server.key -days 731 -out server.csr -subj "/C=CN/ST=GD/L=HY/O=xamarin.com/OU=Tech./CN=xamware.com/emailAddress=jeango@xamware.com"


对证书请进行签名：

    openssl x509 -req -days 731 -in server.csr -CA ca.crt -CAkey ca.key -passin pass:123456 -CAcreateserial -out server.crt

譬如，给本地主机签发证书，并转换格式：

    openssl req -newkey rsa:2048 -nodes -keyout localhost.key -days 731 -out localhost.csr -subj "/C=CN/ST=GD/L=HY/O=xamarin.com/OU=Tech./CN=localhost/emailAddress=jeango@xamware.com"

    openssl x509 -req -days 731 -in localhost.csr -CA ca.crt -CAkey ca.key -passin pass:123456 -CAcreateserial -out localhost.crt

    openssl pkcs12 -export -in localhost.crt -inkey localhost.key -out localhost.pfx

私签证书在 Xamarin Android 应用上，还会引发证书信任链异常：

    CertPathValidatorException: Trust anchor for certification path not found.

需要在 Android 上安装证书，Settings - Security & Location - Advanced - Encryption & credentials。


命令参考：

    >dotnet dev-certs https --help

    Usage: dotnet dev-certs https [options]

    Options:
      -ep|--export-path  Full path to the exported certificate
      -p|--password      Password to use when exporting the certificate with the private key into a pfx file
      -c|--check         Check for the existence of the certificate but do not perform any action
      --clean            Cleans all HTTPS development certificates from the machine.
      -t|--trust         Trust the certificate on the current platform
      -v|--verbose       Display more debug information.
      -q|--quiet         Display warnings and errors only.
      -h|--help          Show help information




# Start Coding

- [ASP.Net Core 类库结构](https://docs.microsoft.com/zh-cn/aspnet/core/fundamentals/target-aspnetcore?view=aspnetcore-3.1)
- [Blazor 应用](https://docs.microsoft.com/zh-cn/aspnet/core/tutorials/build-your-first-blazor-app?view=aspnetcore-3.1)
- [Razor Page Web 应用](https://docs.microsoft.com/zh-cn/aspnet/core/razor-pages/?view=aspnetcore-3.1)
- [ASP.NET Core Razor 文件编译](https://docs.microsoft.com/zh-cn/aspnet/core/mvc/views/view-compilation?view=aspnetcore-3.1)
- [ASP.NET Core MVC Web 应用](https://docs.microsoft.com/zh-cn/aspnet/core/tutorials/first-mvc-app/start-mvc?view=aspnetcore-3.1)
- [ASP.NET documentation](https://docs.microsoft.com/en-us/aspnet/core/?view=aspnetcore-3.1)
- [Windows 应用开发人员文档](https://docs.microsoft.com/zh-cn/windows/apps/)
- [Windows Universal Samples](https://github.com/Microsoft/Windows-universal-samples)
- [Create a Razor Pages web app with ASP.NET Core](https://docs.microsoft.com/en-us/aspnet/core/tutorials/razor-pages/?view=aspnetcore-3.1)
- [Create your first C# app](https://docs.microsoft.com/en-us/visualstudio/get-started/csharp/tutorial-console?view=vs-2019)
- [Create a web app](https://docs.microsoft.com/en-us/visualstudio/get-started/csharp/tutorial-aspnet-core?view=vs-2019)
- [Create a UWP app](https://docs.microsoft.com/en-us/visualstudio/get-started/csharp/tutorial-uwp?view=vs-2019)
- [Create a WPF application](https://docs.microsoft.com/en-us/visualstudio/get-started/csharp/tutorial-wpf?view=vs-2019)
- [Create a Windows Forms app](https://docs.microsoft.com/en-us/visualstudio/ide/create-csharp-winform-visual-studio?view=vs-2019)
- [Create React App](https://create-react-app.dev/docs/getting-started/)

开始你的代码：

    using System;

    namespace myApp
    {
        class Program
        {
            static void Main(string[] args)
            {
                Console.WriteLine("Hello World!");
            }
        }
    }

    csc /lib:"C:\Program Files\dotnet\packs\Microsoft.AspNetCore.App.Ref\3.1.2\ref\netcoreapp3.1" /reference:Microsoft.AspNetCore.dll /reference:Microsoft.AspNetCore.Hosting.dll coding.cs

使用命令创建项目，然后 dotnet run 运行，或者监视改动即重新编译运行 dotnet watch run：

    >dotnet new console -o csdemo
    >dotnet new console -n csdemo -o .

或指定使用已安装的框架版本创建类库：

    >dotnet new classlib --framework netstandard2.1
    >dotnet new classlib --framework netcoreapp3.0

要创建 Web 应用，使用以下命令，然后执行 dotnet run 运行，ASP.NET 可以配合 Razor Pages 这个内置 MVC 框架开发 Web 应用：

    dotnet new webApp -o myWebApp --no-https

    dotnet new webApp -o myWebApp
    dotnet dev-certs https --trust

Web 应用的所有文档都在 ASP.NET 文档，包含教程、示例代码、基础知识、API 参考，可以了解如何使用 ASP.NET Core 创建快速、安全、跨平台和基于云的 Web 应用和服务，以及使用 SignalR 的实时消息推送应用，远程过程调用 (RPC) 应用，RESTful Web API 应用等。

还有组件化的 Blazor 框架结合 WebAssembly 就可以用 C# 来实现交互式客户端 Web UI，它基于 SignalR 即 WebSocket 技术实现消息推送，高效跨平台。


ASP.NET Core 应用提供了便捷的组件化客户端开发模板，如果已安装 ASP.NET Core 2.1，则包含了 Angular 或 React 框架。

更新的 Angular 项目模板为使用 Angular 和 Angular CLI 实现丰富的客户端用户界面 (UI) 的 ASP.NET Core 应用提供了便捷起点。

该模板等同于创建用作 API 后端的 ASP.NET Core 项目，而 Angular CLI 项目用作 UI。 该模板提供在单个应用项目中托管两种项目类型的便利。 因此，应用项目可以作为单个单元来生成和发布。

    dotnet new angular -o netcoreAngular
    cd my-new-app

更新的 React 项目模板为使用 React 和 create-react-app (CRA) 约定实现丰富的客户端用户界面 (UI) 的 ASP.NET Core 应用程序提供了便捷起点。

该模板等同于创建两个项目，即用作 API 后端的 ASP.NET Core 项目和用作 UI 的标准 CRA React 项目，但均可在可以生成并发布为单个单元的单个应用程序项目中进行托管。ClientApp 目录是标准的 CRA React 应用。 

此模板创建的 React 应用与 CRA 自身创建的应用之间存在细微差异；但是，该应用的功能未变。 该模板创建的应用包含基于 Bootstrap 的布局和基本路由示例。

React 项目模板不适用于服务器端呈现 (SSR)。 对于带有 React 和 Node.js 的 SSR，请考虑使用 Next.js 或 Razzle。

    dotnet new react -o netcoreReact
    cd my-new-app

在开发过程中，应用在为开发人员之便而优化的模式下运行。 例如，JavaScript 捆绑包包含源映射，这样在调试时可以查看原始 TypeScript 代码。 该应用监视磁盘上的 TypeScript、HTML 和 CSS 文件更改，并在看到这些文件更改时自动重新编译和重新加载。

在生产中，提供针对性能进行了优化的应用版本。 该操作被配置为自动发生。 发布时，生成配置会发出预先 (AoT) 编译的压缩客户端代码版本。 与开发版本不同，生产版本不需要在服务器上安装 Node.js，除非已启用服务器端呈现 (SSR)。

如果为 Angular 应用全局安装了 ng 工具，则可以运行其任何命令。 例如，你可以运行 ng lint、ng test 或任何其他 Angular CLI 命令。 不过无需运行 ng serve，因为 ASP.NET Core 应用为应用的服务器端和客户端部分提供服务。 在内部，它在开发中使用 ng serve。

如果未安装 ng 工具，请改为运行 npm run ng。 例如，你可以运行 npm run ng lint 或 npm run ng test。


根据客户端项目需要要安装第三方 npm 程序包，安装客户端依赖模块以运行 ClientApp，进入客户端项目目录 ClientApp 执行命令：

    npm install --save
    npm install --save <package_name>


要开发桌面程序可以选择 WPF Application 或 Windows Forms Application。

WPF - Windows Presentation Foundation 为开发人员提供了一个统一的编程模型，用于在 Windows 上构建业务线桌面应用程序，强度于非凡视觉效果。WPF 的核心是一个与分辨率无关且基于矢量的呈现引擎，旨在充分利用现代图形硬件。 WPF 通过一套完善的应用程序开发功能对该核心进行了扩展，这些功能包括可扩展应用程序标记语言 (XAML)、控件、数据绑定、布局、二维和三维图形、动画、样式、模板、文档、媒体、文本和版式。 WPF 属于 .NET，因此可以生成整合 .NET API 其他元素的应用程序。

从发展上来看，封装 WIN32 API 的 MFC - Microsoft Foundation Classes 是最先流行的框架，然后再有 Windows Forms 的封装。

撇开 QT/Electron 等第三方 GUI 框架不谈，UWP 还不支持似乎也是凉凉的，这里 WPF/WinForms 两个 GUI 框架作一个对比：

    dotnet new wpf
    dotnet new winforms

- HTML5 移动互联网兴起，桌面程序份额缩小是事实，ASP.NET Core + TypeScript 可以搞，React/Angular/Vue 选择多；
- WinForm 可以说是 MFC 的下一代框架，从 MFC 角度看很完美，不论是控件的拖动还是 WIN32 的封装；
- WinForm 简单好用启动迅速，不及 WPF 复杂，性能低下；
- WPF 是新概念框架，界面与逻辑分离，3D/2D 界面可以 DX 绘制，XAML 动态布局，还有 MVVM；
- WPF 触控支持较好，矢量组图方便，提供酷炫的控件，自带通用的动画；
- 从用户角度看，桌面程序基本服务生产，用户只在乎好不好用(WinForm)，不管好不好看(WPF)；
- WPF 概念泛滥，比如双向绑定 button 绑定标题，对 VUE 框架就是个字符串绑定，而 WPF 就是内容对象绑定，二者的差距就是 1 vs 10 行代码的差距，这可不是一件好事。同时，高性能的软件不会用.net这种托管语言；

如果使用 Visual Studio 就可以利用可视化的拖拽设计界面，使用 VSCode 或 Sublime 就手写代码。VSCode 本身也支持调试和自动提示功能，这个基于 Electron 开发的工具真的是 Visual Studio 完美替代。

注意，WPF/WinForms 都不是跨平台的框架，要获取跨平台的移动端开发能力，使用哲马林 xamarin 框架。



# WinForm Application Startup
- [Creating Event Handlers in Windows Forms](https://docs.microsoft.com/en-us/dotnet/framework/winforms/creating-event-handlers-in-windows-forms)
- []()

通过命令创建的 WinForms 模板程序：

    dotnet new winforms

Windows Forms 项目结构相对来讲要简单，默认的模板工程有一个入口类 Program.cs 中定义，它定义了一个静态入口函数 Main()，打开程序时就会执行它。默认代码执行 System.Windows.Forms.Application 类的静态方法初始化程序执行：

    Application.SetHighDpiMode(HighDpiMode.SystemAware);
    Application.EnableVisualStyles();
    Application.SetCompatibleTextRenderingDefault(false);
    Application.Run(new Form1());

Windows 系统统一管理 IO 资源，它们产生的数据或事件都以消息的方式通知系统运行的程序，所有程序都有消息队列 Message Loop，在消息队列的 while 循环使用 GetMessage() 获取系统队列里的消息，这是个阻塞方法。也就是队列为空时方法就会被阻塞，从而释放 CPU 时间。这个 while 循环暂时停止以避免程序把 CPU 时间耗尽，让其它程序难以得到响应。某些 3D 游戏或者即时战略游戏中，一般会使用 PeekMessage 这个方法，它不会被 Windows 阻塞，从而保证整个游戏的流畅和比较高的帧速。消息环处理的主线程维护着整个窗体以及上面的子控件的消息分发，当它得到一个消息，就会调用 DispatchMessage 方法派发消息。

典型的消息环如下：

    while(GetMessage( &msg, NULL, 0, 0 ) ){
        TranslateMessage( &msg );
        DispatchMessage( &msg );
    }

原始的 Windows 程序中的窗体对象 WNDCLASS 可以设置一个窗体消息处理函数 lpfnWndProc。当程序中的消息环 GetMessage 获取到消息后就分发出去，系统就会发往窗体消息处理函数进行处理，否则就丢弃消息。当窗体要即出时，可以通过 PostQuitMessage 发出一个退出消息，系统获取后就会告就给消息环返回 false 以退出 while 循环。Windows 消息机制是线程或者进程间通信机制之一，即消息驱动，这种通过消息交流的方式是 Windows 程序的基本结构。到了高级的架构，消息驱动的机制封装成事件，也就是 Form 对象中 OnLoad、 OnClick 等事件处理方法的自动执行能力。或者使用事件处理函数的委托对象，相比消息驱动，这是极方便的一种 GUI 编程方式。

.Net 里面的消息循环处理是通过 Application 对象封装的，通过 Application.Run 方法启动消息环：

    public static void Main(string[] args)
    {
        Form f = new Form();
        Application.Run(f);
    }

在窗口消息处理函数中：

    LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

lParam 和 wParam 是宏定义，它的字面意义，w 表示 word，l 表示 long，对于 32 位系统分别是无符号整数 unsigned int 和长整型 long 。习惯上，使用 LPARAM 传递地址，WPARAM 传递其他参数。它们是 Win16 系统遗留下来的产物，在 Win16 API 中 WndProc 有两个参数，一个 WORD 类型的 16 位整型变量，另一个是 LONG 类型的 32 位整型变量。

到了 Win32 API 中，原来的 16 位变量也被扩展为 32 位，因此 lParam 和 wParam 的大小完全相同。如是从 32 位到 64 位，那么对 WPARAM 采用补零扩展 zero-extended，对 LPARAM 和 LRESULT 采用符号扩展 sign-extended。

    var wp = (IntPtr.Size == 8) ? (int)((long)wParam << 32 >> 32) : (int)wParam;
    var lp = (IntPtr.Size == 8) ? (int)lParam.ToInt64() : lParam.ToInt32();

在 Form 类中，所有以 On 开头的方法都是处理各种消息的 virtual 方法，子类要处理对应的消息事件，可以覆盖实现。一般会使用消息事件处理委托对象：

    public delegate void EventHandler(object sender, EventArgs e);
    public delegate void KeyEventHandler(object sender, KeyEventArgs e);
    public delegate void MouseEventHandler(object sender, MouseEventArgs e);

    this.Click += handler;
    this.Click += new EventHandler(handler);
    this.Click += new MouseEventHandler(handler);
    this.Load += (sender, eventArgs) => Console.WriteLine("Form load");
    this.Load += handler; // also override by OnLoad event handler method
    // private void handler(object sender, EventArgs e)
    // protected override void OnLoad(EventArgs e)

窗体 keyPreview 指示在将键事件传递到具有焦点的控件前，窗体是否将接收此键事件，值设置成 true 后触发按键事件。方向键是作为系统键来处理的，默认方向键的作用是移动焦点，系统处理完了就不会将键盘的键值传递个窗体或获取焦点的控件，也不会触发窗体的KeyDown事件。 覆盖默认的系统键处理方式，这样键值就会被传递到窗体：

    protected override bool ProcessDialogKey(Keys keyData)

主窗体 Form1.cs 中和 WPF 的窗体类似地执行 InitializeComponent 方法来初始化控件，但是它们实现的机制是不同的，主要使用的命名空间也不一样：

- System.ComponentModel 命名空间

    提供用于实现组件和控件的运行时和设计时行为的类，支持 IComponent 接口，都支持可视化设计器操作。

    这些组件都是通过组件窗口 IContainer 管理，实例化组件时传入其归属的容器实例。 IComponent 通过 ISite 关联到组件容器上，ISite 保存组件和其归属容器的引用，组件容器保存组件引用集合。

    .NET 2.0 增加了 INestedContainer，嵌套容器，一般来说，也是被另外一个 IComponent 持有

    还包含通常用到的 DataAnnotations 和 DataAnnotations.Schema 等用于数据操作的特性，各种 Attribute。

- System.Windows.Forms 命名空间

    包含用于创建基于 Windows 窗口的应用程序的类，以充分利用 Microsoft Windows 操作系统中提供的丰富的用户界面功能。


窗体配套的的 Form1.Designer.cs 是为可视化编辑用来保存自动生成代码的，称为设计器代码文件，它包含了一个 IContainer 即组件容器，还有组件初始化方法 InitializeComponent，Dispose 方法用来清理组件。Visual Studio 中的 Windows 窗体设计器提供了用于承载 Windows Presentation Foundation 控件的可视化设计环境。

两个文件合体就是一个完全的 Form1 窗体类。

    namespace winform
    {
        partial class Form1
        {
            /// <summary>
            ///  Required designer variable.
            /// </summary>
            private System.ComponentModel.IContainer components = null;

            /// <summary>
            ///  Clean up any resources being used.
            /// </summary>
            /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
            protected override void Dispose(bool disposing)
            {
                if (disposing && (components != null))
                {
                    components.Dispose();
                }
                base.Dispose(disposing);
            }

            #region Windows Form Designer generated code

            /// <summary>
            ///  Required method for Designer support - do not modify
            ///  the contents of this method with the code editor.
            /// </summary>
            private void InitializeComponent()
            {
                this.components = new System.ComponentModel.Container();
                this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
                this.ClientSize = new System.Drawing.Size(800, 450);
                this.Text = "Form1";
            }

            #endregion
        }
    }

基于 Windows 窗体的应用程序也可以使用 WPF 控件，尽管这是两种不同的视图技术，但它们可以顺畅地互操作。WPF 控件由名为 ElementHost 的特殊 Windows 窗体控件承载，它在 System.Windows.Forms.Integration 命名空间定义。 此控件允许 WPF 控件参与窗体的布局以及接收键盘和鼠标消息。 在设计时，您可以像对任何 Windows 窗体控件一样排列 ElementHost 控件。

- 在 Windows Forms 项目通过 ElementHost 控件来使用 WPF UIElement；
- 在 WPF 项目通过 WindowsFormsHost 来使用 Windows Forms 控件；

需要在项目中引入 System.Windows.Forms.Integration 命名空间，所需文件 WindowsFormsIntegration.dll 和 WPF 框架一并安装： 

    %programfiles%\Reference Assemblies\Microsoft\Framework\v3.0\WindowsFormsIntegration.dll

System.Windows.Controls 命名空间在 PresentationFramework.dll中。
在 .Net Core 3.0 项目中添加本地 DLL 程序集引用，需要修改 csproj 项目配置：

    <Project Sdk="Microsoft.NET.Sdk.WindowsDesktop">

      <PropertyGroup>
        <OutputType>WinExe</OutputType>
        <TargetFramework>netcoreapp3.1</TargetFramework>
        <UseWindowsForms>true</UseWindowsForms>
      </PropertyGroup>

      <ItemGroup>
        <PackageReference Include="Microsoft.Extensions.DependencyInjection" Version="3.1.4" />
          <Reference Include="BabySDK">

            <HintPath>C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\v3.0\WindowsFormsIntegration.dll</HintPath>
        </Reference>
        <Reference Include="PresentationFramework">
            <HintPath>C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\v3.0\PresentationFramework.dll</HintPath>
        </Reference>
        <Reference Include="PresentationFramework">
            <HintPath>C:\Program Files (x86)\Reference Assemblies\Microsoft\Framework\v3.0\PresentationCore.dll</HintPath>
        </Reference>
      </ItemGroup>
    </Project>

示例：

    using System;
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.Data;
    using System.Drawing;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;
    using WPF = System.Windows;
    using Controls = System.Windows.Controls;
    using Media = System.Windows.Media;
    using System.Windows.Forms;
    using System.Windows.Forms.Integration;

    namespace winform
    {
        public partial class Form1 : Form
        {
            public Form1()
            {
                InitializeComponent();
            }

            public Form1(ITextService textSevice)
            {
                InitializeComponent();
                this.Text = textSevice.GetText();
                this.Load += Form1_Load;
            }

            private void Form1_Load(object sender, EventArgs e)
            {
                Button btn = new Button();
                btn.Text ="Exit";
                btn.Top = 200;
                btn.Height = 100;
                btn.Width = 300;

                this.Controls.Add(btn);

                // Use ElementHost control for hosting the WPF UserControl.
                ElementHost host = new ElementHost();
                host.Dock = DockStyle.Fill;

                // Create the WPF UserControl.
                Controls::Button uc = new Controls::Button();

                // Assign the WPF UserControl to the ElementHost control's Child property.
                host.Child = uc;

                // Settings up UserControl
                uc.Background = Media.Brushes.Red;
                uc.Content = "WPF Button";
                uc.Height = 100;
                uc.Width = 300;
                uc.VerticalAlignment = WPF::VerticalAlignment.Center;

                // Add the ElementHost control to the form's collection of child controls.
                this.Controls.Add(host);

                // Events Binddings
                // uc.Click += new RoutedEventHandler((sendrr, eventargs) => Close());
                btn.Click += (sendrr, eventargs) => {
                        try{
                            Close();
                            // Application.Exit();
                            Environment.Exit(0);
                        } catch (System.Runtime.InteropServices.SEHException e) {
                            Console.WriteLine(e);
                        }
                    };
            }

        }
    }




# WPF Application Startup
- [Creating Event Handlers in Windows Forms](https://docs.microsoft.com/en-us/dotnet/framework/winforms/creating-event-handlers-in-windows-forms)
- [Windows Presentation Foundation 路由事件](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/events-wpf)
- [WPF UIElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.uielement?view=netcore-3.1)
- [WPF ContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.contentelement?view=netcore-3.1)
- [WPF FrameworkElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement?view=netcore-3.1)
- [WPF FrameworkContentElement](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement?view=netcore-3.1)
- [XAML in WPF](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/xaml-in-wpf)
- [WPF Data Binding](https://docs.microsoft.com/zh-cn/dotnet/desktop-wpf/data/data-binding-overview)
- [WPF Threading Model](https://docs.microsoft.com/zh-cn/dotnet/framework/wpf/advanced/threading-model)
- [WPF Samples](https://github.com/microsoft/WPF-Samples)
- []()

这里介绍通过命令创建的 WPF 和 WinForms 模板程序：

    dotnet new wpf
    dotnet new winforms

这两种 Windows GUI 项目有相似的 csproj 配置，差别在于使用了不同开发框架和开发模式。 WPF 使用 UI 和代码分享的开发模式，WinForms 是全代码的旧方式。

先来认识 WPF - Windows Presentation Foundation 程序 的核心是一个与分辨率无关且基于矢量的呈现引擎，旨在充分利用现代图形硬件。 WPF 通过一套完善的应用程序开发功能对该核心进行了扩展，这些功能包括可扩展应用程序标记语言 XAML、控件、数据绑定、布局、二维和三维图形、动画、样式、模板、文档、媒体、文本和版式。 WPF 属于 .NET，因此可以生成整合 .NET API 其他元素的应用程序。

WPF 作为大部分位于 System.Windows 命名空间中的 .NET 类型的一个子集存在。你可以使用最喜欢的 .NET 编程语言（如 C# 或 Visual Basic）来完成实例化类、设置属性、调用方法以及处理事件等操作。

WPF 还包括增强属性和事件的其他编程构造： 依赖项属性 和 路由事件。

WPF 有四个关键类，实现了 WPF 编程中可用的大量公共元素功能：

| 基础对象 | 功能要点 |
| :------ | :------ |
| UIElement | WPF 核心级实现的基类，其它 UI 实现是在此元素和基本表示特性上生成的。 |
| ContentElement    | 为内容元素提供 WPF 核心级基类。 内容元素设计用于流样式显示，它们使用面向标记的直观布局模型和精心设计的简单对象模型。 |
| FrameworkElement  | 提供 WPF 元素的属性、事件和方法的 WPF 框架级别集。 此类表示所提供的 WPF 框架级别实现基于 UIElement 定义的 WPF 核心级别 API。 |
| FrameworkContentElement，  | 是 ContentElement 基类的 WPF 框架级别的实现和扩展。 增加了针对下列各项的支持：附加输入 API（包括工具提示和上下文菜单）、演示图板、用于数据绑定的数据上下文、格式支持和逻辑树帮助程序 API。 |


XAML 是一种基于 XML 的标记语言，像 HTML 一样以声明形式实现应用程序的外观。 通常用它创建窗口、对话框、页和用户控件，并填充控件、形状和图形。

模板创建的 App.xaml 和配套的 App.xaml.cs 就是程序的入口，它们对应了一个 System.Windows.Application 实例，其属性 `StartupUri` 指示了程序运行的第一个窗体对象，同时可以设置 `Startup` 指定一个启动时要执行的事件，可以不设置 `StartupUri` 而通过指定的启动事件来实例化窗体。

    <Application x:Class="wpf.App"
                 xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
                 xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
                 xmlns:local="clr-namespace:wpf"
                 StartupUri="MainWindow.xaml">
        <Application.Resources>
             
        </Application.Resources>
    </Application>

`Startup` 指定一个启动事件代码就写在 App.xaml.cs 文件内，比如指定 `Startup="App_OnStartup"`：

    using System;
    using System.Collections.Generic;
    using System.Configuration;
    using System.Data;
    using System.Linq;
    using System.Threading.Tasks;
    using System.Windows;

    namespace wpf
    {
        /// <summary>
        /// Interaction logic for App.xaml
        /// </summary>
        public partial class App : Application
        {
            public IServiceProvider _serviceProvider;

            public App()
            {
                ...
            }

            private void App_OnStartup(object sender, StartupEventArgs e)
            {
                ...
            }
        }
    }

默认的主窗体也一样有两个文件对应 System.Windows.Window 对象。

MainWindow.xaml:

    <Window x:Class="wpf.MainWindow"
            xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
            xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
            xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
            xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
            xmlns:local="clr-namespace:wpf"
            mc:Ignorable="d"
            Title="MainWindow" Height="450" Width="800">
        <Grid>

        </Grid>
    </Window>

MainWindow.xaml.cs:

    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;
    using System.Windows;
    using System.Windows.Controls;
    using System.Windows.Data;
    using System.Windows.Documents;
    using System.Windows.Input;
    using System.Windows.Media;
    using System.Windows.Media.Imaging;
    using System.Windows.Navigation;
    using System.Windows.Shapes;

    namespace wpf
    {
        /// <summary>
        /// Interaction logic for MainWindow.xaml
        /// </summary>
        public partial class MainWindow : Window
        {
            public MainWindow()
            {
                InitializeComponent();
            }
        }
    }

整个 WPF 程序有两种开发模式，XAML 的标签化 UI 编辑模式，可以在 Visual Studio 中拖放对象组件。另一种是代码编写模式，用来实现程序逻辑。WPF 通过 XAML 实现了 UI 和代码的分享。这种软件开发模式明显优于 WinForms 旧式的纯代码开发。

比如，在 MainWindow.xaml 添加一个按钮控件对象:

    <!-- Add button to window -->
    <Button Name="button" Click="button_Click">Click Me!</Button>

在 MainWindow.xaml.cs 添加一个事件处理函数:

    void button_Click(object sender, RoutedEventArgs e)
    {
        // Show message box when button is clicked.
        MessageBox.Show("Hello, Windows Presentation Foundation!");
    }

当构造函数调用 InitializeComponent 方法时，就会将标记定义的 UI 控件与背后的代码合并在一起，它生成应用程序为您正确初始化 UI 组件的实现代码，包括将按钮的 Click 事件与事件处理程序关联。这就是 Markup & Code-Behind，用标记定义控件，用背后的代码自动实现。


接下来就是深入各个编程细节的实现，罗列以下项目，但又不仅限于此：

- 控制
- 输入和命令
- 布局
- 数据绑定
- 图形
- 动画
- 媒体
- 文本和版式
- 自定义 WPF 应用


## WPF Routing Events


## Host WinForms with WindowsFormsHost
- [WindowsFormsHost 元素的布局注意事项](https://docs.microsoft.com/zh-cn/previous-versions/dotnet/netframework-4.0/ms744952(v=vs.100))

WinForms 是第一个 .NET UI 框架，和 WPF 是两个不同的 UI 框架。 双方组件不能直接借用，如果确实需要，那么可以考虑使用 WindowsFormsHost 作为 WinForms 组件寄主。

- 在 Windows Forms 项目通过 ElementHost 控件来使用 WPF UIElement；
- 在 WPF 项目通过 WindowsFormsHost 来使用 Windows Forms 控件；

Windows Forms 中的布局是与设备相关的，很可能是静态的。 通常，使用以硬件像素为单位指定的维度，在窗体上以绝对方式来定位 Windows Forms控件。 不过，Windows Forms不支持某些动态布局功能，如下表汇总所示。

- 自动调整大小

    某些 Windows Forms控件可以调整自身大小，以便恰当地显示内容。 有关更多信息，请参见 AutoSize 属性概述。

- 锚定和停靠

    Windows Forms控件支持基于父容器进行定位和大小调整。 有关更多信息，请参见 Control.Anchor 和 Control.Dock。

- 自动缩放

    容器控件基于输出设备的分辨率或默认容器的字号（单位为像素）来调整自身及其子控件的大小。 有关更多信息，请参见 Windows 窗体中的自动缩放。

- 布局容器

    FlowLayoutPanel 和 TableLayoutPanel 控件根据其内容来排列子控件以及设定自身大小。

通常，无法将 Windows Forms控件缩放及转换到 WPF 中可能的范围。 

某些情况下，Windows Forms 控件无法调整大小，或者大小只能调整为特定的尺寸。 例如，Windows Forms ComboBox 控件仅支持由控件的字号定义的单一高度。 在元素可以垂直拉伸的 WPF 动态布局中，承载的 ComboBox 控件不会如预期那样拉伸。

Windows Forms 控件不能旋转或扭曲。 如果应用扭曲或旋转变换，WindowsFormsHost 元素会引发 LayoutError 事件。 如果未处理 LayoutError 事件，会引发 InvalidOperationException。

某些情况下，Windows Forms 控件不支持按比例缩放。 尽管该控件的整体尺寸将会缩放，但其子控件和组件元素可能不会如预期那样调整大小。 此限制取决于每个 Windows Forms控件支持缩放的程度。 此外，您不能将 Windows Forms 控件缩小至 0 像素大小。

Windows Forms 控件支持自动缩放，其中的窗体会基于字号自动调整自身及其控件的大小。 在 WPF 用户界面中，更改字号不会改变整个布局的大小，不过个别元素可能会动态调整大小。

Z Index 在 WPF 用户界面中，您可以更改元素的 z 顺序以控制重叠行为。 由于承载的 Windows Forms 控件是在单独的 HWND 中绘制的，所以它始终绘制在 WPF 元素的顶部。


MainWindow.cs

    using System.Windows;
    using System.Windows.Forms;
    using System.Windows.Forms.Integration;

    namespace HostingWfInWPF
    {
        public partial class MainWindow : Window
        {
            public MainWindow()
            {
                InitializeComponent();
            }

            private void WindowLoaded(object sender, RoutedEventArgs e)
            {
                // Create the interop host control.
                var host = new WindowsFormsHost();

                // Create the MaskedTextBox control.
                var mtbDate = new MaskedTextBox("00/00/0000");

                // Assign the MaskedTextBox control as the host control's child.
                host.Child = mtbDate;

                // Add the interop host control to the Grid
                // control's collection of child controls.
                grid1.Children.Add(host);


                host = new WindowsFormsHost();

                // Create a Windows Forms tab control.
                var tc = new TabControl();
                tc.TabPages.Add("Tab1");
                tc.TabPages.Add("Tab2");

                // Assign the Windows Forms tab control as the hosted control.
                host.Child = tc;

                // Assign the host element to the parent Grid element.
                grid1.Children.Add(host);
            }
        }
    }

MainWindow.xaml

    <Window x:Class="HostingWfInWPF.MainWindow"
            xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
            xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
            xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
            xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
            xmlns:local="clr-namespace:HostingWfInWPF"
            mc:Ignorable="d"
            Title="MainWindow" Height="350" Width="525" Loaded="WindowLoaded">

        <Grid Name="grid1" >
            <Button VerticalAlignment="Center">Click</Button>
        </Grid>
    </Window>

或者在 XAML 中直接使用：

    <Window x:Class="HostingWfInWPF.MainWindow"
        xmlns:WinFormHost="clr-namespace:System.Windows.Forms.Integration;assembly=WindowsFormsIntegration"
        xmlns:WinFormControls="clr-namespace:System.Windows.Forms;assembly=System.Windows.Forms"
        ...>
        <WindowsFormsHost Height="196" HorizontalAlignment="Left" Margin="104,65,0,0" Name="windowsFormsHost1" VerticalAlignment="Top" Width="286" >

            <WinFormControls:Button Text="WinformButton" Width="150"/>

        </WindowsFormsHost>
    </Window>



# Customize Your CLI Templates
- https://docs.microsoft.com/en-us/dotnet/core/tutorials/cli-templates-create-project-template
- https://docs.microsoft.com/en-us/nuget/reference/msbuild-targets
- https://docs.microsoft.com/en-us/dotnet/core/tools/custom-templates
- https://docs.microsoft.com/en-us/nuget/reference/target-frameworks


## Tutorial: Create an item template

创建自己的 .NET Core 条目模板，学习 install 和 uninstall 命令安装和卸载模板，学习目标：

- Create a class for an item template
- Create the template config folder and file
- Install a template from a file path
- Test an item template
- Uninstall an item template


基本模板目录结构：

    └─── mytemplate
        │   console.cs
        │   readme.txt
        │
        └───.template.config
                template.json

基本模板配置文件 template.json 参考：

    {
      "$schema": "http://json.schemastore.org/template",
      "author": "Travis Chau",
      "classifications": [ "Common", "Console" ],
      "identity": "AdatumCorporation.ConsoleTemplate.CSharp",
      "name": "Adatum Corporation Console Application",
      "shortName": "adatumconsole"
    }

各配置项功能解析：

| Member    | Type  | Description |
| :------   | :------   | :------ |
| $schema   | URI   | 固定的 JSON schema，对支持的编辑器有效，如 Visual Studio Code 使用它实现自动提示 IntelliSense。 |
| author    | string    | 模板作者信息。 |
| classifications   | array(string) | 任意个指定分类关键词，用户可能通过 `dotnet new -l|--list` 搜索到。 |
| identity  | string    | 表示模板的唯一标志。 |
| name  | string    | 模板名称。 |
| shortName | string    | 模板简称，通过是命令行中使用的，一般不在 GUI 中使用简称。|


需要安装 NET Core 2.2 SDK 以上版本，创建以下模板目录结构：

    parent_folder
    ├─── test
    └─── working
        └─── templates

在 templates 模板目录 extensions 下创建一个条目模板：

    working
    └─── templates
        └─── extensions

创建一个类，实现一个 Reverse 方法作为模板文件 Reverse.cs 的代码内容：

    using System;

    namespace System
    {
        public static class StringExtensions
        {
            public static string Reverse(this string value)
            {
                var tempArray = value.ToCharArray();
                Array.Reverse(tempArray);
                return new string(tempArray);
            }
        }
    }

再创建配套的模板配置文件：

    working
    └─── templates
        └─── extensions
            └─── .template.config
                    template.json

配置文件内容类似如下：

    {
      "$schema": "http://json.schemastore.org/template",
      "author": "Me",
      "classifications": [ "Common", "Code" ],
      "identity": "ExampleTemplate.StringExtensions",
      "name": "Example templates: string extensions",
      "shortName": "stringext",
      "tags": {
        "language": "C#",
        "type": "item"
      }
    }

然后，执行命令安装模板，-i 表示 --install 安装，以下命令安装当前目录中的模板：

    On Windows: dotnet new -i .\
    On Linux or macOS: dotnet new -i ./

并测试使用安装，看到输出 Reverse 方法处理结果 `!dlroW olleH` 即完成：
    
    dotnet new console
    dotnet new stringext
    dotnet run

要卸载模板，执行以下命令：

    dotnet new -u C:\working\templates\extensions



## Tutorial: Create an project template

创建项目模板与条目模板类似，使用了 csproj 文件作为 C# 项目文件:

    working
    └─── templates
        └─── consoleasync
                consoleasync.csproj
                Program.cs

编写项目入口文件代码 Program.cs：

    using System;
    using System.Threading.Tasks;

    namespace consoleasync
    {
        class Program
        {
            static async Task Main(string[] args)
            {
                await Console.Out.WriteAsync("Hello World with C# 8.0!");
            }
        }
    }

修改项目文件 consoleasync.csproj 配置项目类型，使用的框架版本和使用的语言版本等。以下指定了输出 .Net Core App 2.0 的 EXE 可执行程序：

    <Project Sdk="Microsoft.NET.Sdk">

      <PropertyGroup>
        <OutputType>Exe</OutputType>
        <TargetFramework>netcoreapp2.2</TargetFramework>

        <LangVersion>8.0</LangVersion>

      </PropertyGroup>
      
    </Project>

然后设置模板配置文件：

    working
    └───templates
        └───consoleasync
            └───.template.config
                    template.json

编辑 template.json 模板配置内容：

    {
      "$schema": "http://json.schemastore.org/template",
      "author": "Me",
      "classifications": [ "Common", "Console", "C#8" ],
      "identity": "ExampleTemplate.AsyncProject",
      "name": "Example templates: async project",
      "shortName": "consoleasync",
      "tags": {
        "language": "C#",
        "type": "project"
      }
    }

设置 tags 方便 NuGet 社区的用户查找到模板。

然后，执行命令安装模板并测试使用，-i 表示 --install 安装，以下命令安装当前目录中的模板。安装项目模板时会创建 consoleasync 目录下的文件，不再条目模板的安装会包含其目录：

    dotnet new -i .\

    dotnet new consoleasync
    dotnet run

    dotnet new -u C:\working\templates\consoleasync

使用模板创建时，extensions 模板条目包括文件夹就会复制到项目根目录下。



## Tutorial: Create a template pack

创建模板打包要实现的目标：

- Create a `*.csproj` project to build a template pack
- Configure the project file for packing
- Install a template from a NuGet package file
- Uninstall a template by package ID

打包以 NuGet package (.nupkg) 文件存储，和其它 NuGet 包一样，可以上传到 NuGet feed 服务器，使用 `dotnet new -i` 命令从服务器上安装，然后中使用。

可以通过修改现有模板开始着手打造自己的模板：

    dotnet new console -n templatepack -o .

创建模板工程，得到一个项目文件，修改它 templatepack.csproj ：

    <Project Sdk="Microsoft.NET.Sdk">

      <PropertyGroup>
        <PackageType>Template</PackageType>
        <PackageVersion>1.0</PackageVersion>
        <PackageId>AdatumCorporation.Utility.Templates</PackageId>
        <Title>AdatumCorporation Templates</Title>
        <Authors>Me</Authors>
        <Description>Templates to use when creating an application for Adatum Corporation.</Description>
        <PackageTags>dotnet-new;templates;contoso</PackageTags>

        <TargetFramework>netstandard2.0</TargetFramework>
        <!-- 
            <OutputType>Exe</OutputType>
            <TargetFramework>netcoreapp2.0</TargetFramework>
         -->

        <IncludeContentInPack>true</IncludeContentInPack>
        <IncludeBuildOutput>false</IncludeBuildOutput>
        <ContentTargetFolders>content</ContentTargetFolders>
      </PropertyGroup>

      <ItemGroup>
        <Content Include="templates\**\*" Exclude="templates\**\bin\**;templates\**\obj\**" />
        <Compile Remove="**\*" />
      </ItemGroup>

    </Project>

留意 `<PropertyGroup>` 设置各种属性，分成三类。

主要是前面配置的 NuGet package 信息，用于确定依赖包在 NuGet feed 的位置， 指定 `<PackageId>` 标志可以在卸载模板时替代目录路径，从 NuGet feed 服务器上安装时也可以使用。其它的 `<Title>` 或 `<PackageTags>` 就是在 NuGet feed 显示的元数据，可以指定标题或作者信息等。 

`<TargetFramework>` 设置 MSBuild 编译工具以合适的框架打包工程，这里指定的 TFM 是 .Net Standard 2.0 库文件输出。要输出可指执行文件，使用注解部分替换即可，但最后还是生成库文件。

后面的部分配置打包 NuGet pack 时，如何包含模板的目录等。

`<ItemGroup>`分成两部分， `<Content>` 设置 Include 使用双星匹配任意层级目录，单星配置任意文件，即包含指定目录的所有内容到模板。设置 Exclude 排除指定目录的所有内容。 第二部分是 `<Compile>` 设置在编译时排除所有代码文件，任何位置，这防止创建模板时将代码编译。

执行打包命令，NuGet package 会输出到 working\bin\Debug 目录下：

    dotnet pack

然后，执行模板安装命令 `dotnet new -i PATH_TO_NUPKG_FILE` 测试安装模板：

    dotnet new -i C:\working\bin\Debug\AdatumCorporation.Utility.Templates.1.0.0.nupkg

如果使用 NuGet Feed，可以使用 `dotnet new -i PACKAGEID` 命令安装模板， PACKAGEID 即 `<PackageId>` 指定的。

使用命令卸载模板：

    Run dotnet new -u AdatumCorporation.Utility.Templates


选择合适的 SDK 和应用类型，决定了编译时生成的文件类型。要生成 Web EXE 可执行程序，配置项目时可以设置工程类型为 Microsoft.NET.Sdk.Web ，netstandard2.0 和 netcoreapp2.0 类库框架除外，其它框架都可以生成 DLL 库和可执行文件。通过设置不同的 SDK 用来生成不同的程序输出：

| .NET Sdk 类型       | 目标应用 |
| :---------------  | :--------------- |
| Microsoft.NET.Sdk | Libraray/Console |
| Microsoft.NET.Sdk.Web | Web/MVC/Razor Page/Blazor/Web API ... |
| Microsoft.NET.Sdk.WindowsDesktop  | WinForm/WPF |


可以使用框架版本选择：

    <TargetFramework>netstandard2.0</TargetFramework>
    <TargetFramework>netcoreapp2.0</TargetFramework>
    <TargetFramework>netcoreapp3.1</TargetFramework>
    <TargetFramework>netcoreapp3.0</TargetFramework>
    <TargetFrameworks>netcoreapp5.0;net4.7.2;net4.6.1;net4.6.2;</TargetFrameworks>

指定了多目标框架时，可以指定运行的目标框架：

    dotnet run --framework netcoreapp5.0
    dotnet run --framework net4.7.2

编译时，会统一生成各目标框架的程序：

    >dotnet build
    Microsoft (R) Build Engine version 16.7.0-preview-20220-01+80e487bff for .NET Core
    Copyright (C) Microsoft Corporation. All rights reserved.

      Determining projects to restore...
      Restored c:\working\async.csproj (in 426 ms).
      You are using a preview version of .NET. See: https://aka.ms/dotnet-core-preview
      async -> c:\working\bin\Debug\netcoreapp5.0\async.dll
      async -> c:\working\bin\Debug\net4.7.2\async.exe
      async -> c:\working\bin\Debug\net4.6.1\async.exe
      async -> c:\working\bin\Debug\net4.6.2\async.exe
      async -> c:\working\bin\Debug\netcoreapp3.1\async.dll
      async -> c:\working\bin\Debug\netcoreapp3.0\async.dll
      async -> c:\working\bin\Debug\netcoreapp2.0\async.dll
      async -> c:\working\bin\Debug\netstandard2.0\async.dll




# Demo Cookbook


## Exit Program

退出一个 Window GUI 程序需要发送终止消息来结束消息环 Message Loop，以下三种方式的差别：

- form.Close();

    调用窗口实例的关闭方法，只是关闭当前窗口，若不是主窗体就无法退出程序，另外若有托管线程（非主线程），也无法干净地退出。

- Application.Exit();

    强制所有消息泵终止，退出所有的窗体，但是若有托管线程（非主线程），也无法干净地退出。 

- Application.ExitThread();

    强制中止调用线程上的所有消息，同样面临其它线程无法正确退出的问题。

- Environment.Exit(exitCode);

    这是最彻底的退出方式，不管什么线程都被强制退出，把程序结束的很干净。 


## Randomize
https://docs.microsoft.com/en-us/dotnet/api/system.random?view=netcore-3.1

    Random rnd = new Random();
    string[] malePetNames = { "Rufus", "Bear", "Dakota", "Fido",
                              "Vanya", "Samuel", "Koani", "Volodya",
                              "Prince", "Yiska" };
    string[] femalePetNames = { "Maggie", "Penny", "Saya", "Princess",
                                "Abby", "Laila", "Sadie", "Olivia",
                                "Starlight", "Talla" };

    // Generate random indexes for pet names.
    int mIndex = rnd.Next(malePetNames.Length);
    int fIndex = rnd.Next(femalePetNames.Length);

    // Display the result.
    Console.WriteLine("Suggested pet name of the day: ");
    Console.WriteLine("   For a male:     {0}", malePetNames[mIndex]);
    Console.WriteLine("   For a female:   {0}", femalePetNames[fIndex]);

    // The example displays the following output:
    //       Suggested pet name of the day:
    //          For a male:     Koani
    //          For a female:   Maggie


    // Instantiate random number generator using system-supplied value as seed.
    var rand = new Random();

    // Generate and display random byte (integer) values.
    var bytes = new byte[5];
    rand.NextBytes(bytes);

    // Generate and display random integers.
    Console.Write("{0,15:N0}", rand.Next());

    // Generate and display random integers between 0 and 100.
    Console.Write("{0,8:N0}", rand.Next(101));

    // Generate and display random integers from 50 to 100.
    Console.Write("{0,8:N0}", rand.Next(50, 101));

    // Generate and display random floating point values from 0 to 1.
    Console.Write("{0,8:N3}", rand.NextDouble());

    // Generate and display random floating point values from 0 to 5.
    Console.Write("{0,8:N3}", rand.NextDouble() * 5);


## RSA Certificate 证书读写
https://docs.microsoft.com/en-us/dotnet/api/system.security.cryptography.x509certificates.x509contenttype?view=netcore-3.1

以下示例使用 X509Certificate2 对象读取 PFX 证书文件，以可导出的方式读取，以使用 Export 再次导出，导出时没有设置密码。

    using System;
    using System.IO;
    using System.Security.Cryptography.X509Certificates;

    public class X509
    {

        public static void Main()
        {
            // The path to the certificate.
            string Certificate = "ca-test/localhost.pfx";

            // Load the certificate into an X509Certificate2 object.
            X509Certificate2 cert = new X509Certificate2(Certificate, "123456",  X509KeyStorageFlags.Exportable);

            cert.FriendlyName = ".Net Core Test";
            byte[] bytes = cert.Export(X509ContentType.Pkcs12);
            File.WriteAllBytes(Certificate.Replace(".pfx", "-friendly.pfx"), bytes);

            byte[] certData = cert.Export(X509ContentType.Cert);

            X509Certificate newCert = new X509Certificate(certData);

            // Get the value.
            string resultsTrue = newCert.ToString(true);

            // Display the value to the console.
            Console.WriteLine(resultsTrue);

            // Get the value.
            string resultsFalse = newCert.ToString(false);

            // Display the value to the console.
            Console.WriteLine(resultsFalse);
        }
    }

创建 X509 证书方法较多，通过CA获取证书， 通过微软提供的 makecert 工具生成用于测试的证书。编程的方法创建最灵活，.Net 提供了 X509Certificate2 类，该类可以用于创建证书，但只能从 RawData 中创建，创建后无法修改除 FriendlyName 以外的任何属性。

X509ContentType 枚举：

| Authenticode  | 6 | An Authenticode X.509 certificate. |
| Cert      | 1 | A single X.509 certificate. |
| Pfx       | 3 | A PFX-formatted certificate, identical to the Pkcs12 |
| Pkcs12    | 3 | A PKCS #12-formatted certificate. |
| Pkcs7     | 5 | A PKCS #7-formatted certificate. |
| SerializedCert    | 2 | A single serialized X.509 certificate. |
| SerializedStore   | 4 | A serialized store. |
| Unknown   | 0 | An unknown X.509 certificate. |



## Concurrency Programming


## STAThread & MTAThread & COM
- [STAThread Attribute](https://docs.microsoft.com/en-us/dotnet/api/system.stathreadattribute?view=netcore-3.1)
- [MTAThread Attribute](https://docs.microsoft.com/en-us/dotnet/api/system.mtathreadattribute?view=netcore-3.1)
- [Understanding and Using COM Threading Models](https://docs.microsoft.com/en-us/previous-versions/ms809971(v=msdn.10))

[STAThread] 是一种线程单元模型，只用在程序的入口方法上，C# 和 VB.NET 里是 Main() 入口方法，来指定当前 COM 线程模型的是单一线程单元线程 STA - Single Thread Apartment，与之对应的是 MTA - Multithreaded Apartment 模式。

    [System.AttributeUsage(System.AttributeTargets.Method)]
    public sealed class STAThreadAttribute : Attribute

    [System.AttributeUsage(System.AttributeTargets.Method)]
    public sealed class MTAThreadAttribute : Attribute

由于很多 COM 组件不能在 .NET 的多线程环境下运行，如果不声明程序为 STAThread 的话，.NET 就会自动使用多线程来提高效率，这样就会导致不可预知的后果。

比如开文件窗口：

    var dialog1 = new OpenFileDialog();
    if (dialog1.ShowDialog() == DialogResult.OK)...

在开始线程前，可以通过以下方法指定线程模型：

    Thread thred = new Thread(new ThreadStart(InvokeMethod));
    thread.SetApartmentState(ApartmentState.STA);
    thread.TrySetApartmentState(ApartmentState.STA);

示例：

    private Thread invokeThread;
    private DialogResult result;
    private OpenFileDialog openDialog;
    private void button1_Click(object sender, /*LinkLabelLinkClicked*/EventArgs e)
    {
        openDialog = new OpenFileDialog();
        // openDialog.InitialDirectory = path;
        openDialog.Filter = "wav files (*.wav)|*.wav|mpeg-3 layer|*.mp3";

        invokeThread = new Thread(new ThreadStart(InvokeMethod));
        invokeThread.SetApartmentState(ApartmentState.STA);
        invokeThread.Start();
        invokeThread.Join();

        if (result == DialogResult.OK)
        {
            if (openDialog.FileName != "")
            {
                PlaySound(openDialog.FileName, new System.IntPtr(), PlaySoundFlags.SND_ASYNC);
            }
        }
    }

    private void InvokeMethod()
    {
        result = openDialog.ShowDialog();
    }


在 .NET Framework 2.0，默认的 COM 线程模型根据不同的语言有不同的默认值：

| Language  | COM apartment model |
| :-------- | :------------------ |
| C#    | Multithreaded apartment |
| C++   | Multithreaded apartment |
| Visual Basic  | Single-threaded apartment |

认识一下线程单元模型的关键点：

- An apartment is not a thread. The one-to-one relationship between threads and single-threaded apartments may lead you to believe that the two terms are interchangeable—they are not.
- An object is not an apartment. Objects are created in apartments.
- A particular instance of an object can belong to only one apartment.
- An apartment's concurrency model, whether it is single-threaded or multi-threaded, cannot be changed after it is created.
- A process can have zero or more single-threaded apartments—one for each thread that calls CoInitialize.
- A process has one multi-threaded apartment or none at all—all threads that call CoInitializeEx with COINIT_MULTITHREADED share the same apartment.

在 COM 组件的 Client 与 Server 间，Object Threading Models 参考：

| Client Model  | Server Model  | Server created in:    | Inter-object communication via: |
| :-----------  | :-----------  | :----------- | :----------- |
| STA   | MTA   | MTA (created if one doesn't already exist)    | Marshaling, unless server implements the free-threaded marshaler and is in the same process |
| MTA   | STA   | A new STA, created by COM | Marshaling |
| STA   | Both  | Client's STA  | Direct access |
| MTA   | Both  | MTA   | Direct access |


System.Diagnostics.Process.Start() 静态方法可以弹窗打开某个链接网址，定位打开某个文件目录，打开系统特殊文件夹，如控制面板等。

| 名称    | 说明 |
| :------ | :------ |
| Start()    | 启动（或重用）此 Process 组件的 StartInfo 属性指定的进程资源，并将其与该组件关联。 |
| Start(ProcessStartInfo)    | 启动由包含进程启动信息（例如，要启动的进程的文件名）的参数指定的进程资源，并将该资源与新的 Process 组件关联。 |
| Start(String)    | 通过指定文档或应用程序文件的名称来启动进程资源，并将资源与新的 Process 组件关联。 |
| Start(String, String)    | 通过指定应用程序的名称和一组命令行参数来启动一个进程资源，并将该资源与新的 Process 组件相关联。 |
| Start(String, String, SecureString, String)    | 通过指定应用程序的名称、用户名、密码和域来启动一个进程资源，并将该资源与新的 Process 组件关联起来。 |
| Start(String, String, String, SecureString, String)    | 通过指定应用程序的名称和一组命令行参数、用户名、密码和域来启动一个进程资源，并将该资源与新的 Process 组件关联起来。 |


WinForms 示例程序：

    using System;
    using System.Drawing;
    using System.Windows.Forms;
    using System.Runtime.InteropServices;
    using System.Threading;

    namespace WinSound
    {
        public partial class Form1 : Form
        {
            private TextBox textBox1;
            private Button button1;

            // [STAThread]
            [MTAThread]
            public static void Main()
            {
                var form = new Form1();
                form.Load += (sender, eventArgs) => Console.WriteLine($"Form load [{sender}] [{eventArgs}]");

                form.Show();
                Application.Run(form); // handle Windows Message Loop
            }

            public Form1()  // Constructor.
            {
                InitializeComponent();
            }

            protected override void OnLoad(EventArgs e)
            {
                Console.WriteLine("On load "+DateTime.Now.ToString("mm:ss-ffff"));
                this.KeyPreview = true;
            }

            [DllImport("winmm.DLL", EntryPoint = "PlaySound", SetLastError = true, CharSet = CharSet.Unicode, ThrowOnUnmappableChar = true)]
            private static extern bool PlaySound(string szSound, System.IntPtr hMod, PlaySoundFlags flags);

            [System.Flags]
            public enum PlaySoundFlags : int
            {
                SND_SYNC = 0x0000,
                SND_ASYNC = 0x0001,
                SND_NODEFAULT = 0x0002,
                SND_LOOP = 0x0008,
                SND_NOSTOP = 0x0010,
                SND_NOWAIT = 0x00002000,
                SND_FILENAME = 0x00020000,
                SND_RESOURCE = 0x00040004
            }

            private void button1_Click_STAThread(object sender, System.EventArgs e)
            {
                var dialog1 = new OpenFileDialog();

                dialog1.Title = "Browse to find sound file to play";
                dialog1.InitialDirectory = @"c:\";
                dialog1.Filter = "Wav Files (*.wav)|*.wav";
                dialog1.FilterIndex = 2;
                dialog1.RestoreDirectory = true;

                if (dialog1.ShowDialog() == DialogResult.OK)
                {
                    textBox1.Text = dialog1.FileName;
                    PlaySound(dialog1.FileName, new System.IntPtr(), PlaySoundFlags.SND_ASYNC );
                }
                Console.WriteLine("On button click "+DateTime.Now.ToString("mm:ss-ffff"));
            }

            private Thread invokeThread;
            private DialogResult result;
            private OpenFileDialog openDialog;
            private void button1_Click(object sender, /*LinkLabelLinkClicked*/EventArgs e)
            {
                openDialog = new OpenFileDialog();
                // openDialog.InitialDirectory = path;
                openDialog.Filter = "wav files (*.wav)|*.wav|mpeg-3 layer|*.mp3";

                invokeThread = new Thread(new ThreadStart(InvokeMethod));
                invokeThread.SetApartmentState(ApartmentState.STA);
                invokeThread.Start();
                invokeThread.Join();

                if (result == DialogResult.OK)
                {
                    if (openDialog.FileName != "")
                    {
                        PlaySound(openDialog.FileName, new System.IntPtr(), PlaySoundFlags.SND_ASYNC);
                    }
                }
            }

            private void InvokeMethod()
            {
                result = openDialog.ShowDialog();
            }

            private Keys _key = Keys.NoName;
            protected override void OnKeyDown(KeyEventArgs e) {
                Console.WriteLine("On key down "+e.KeyCode.ToString());
                base.OnKeyDown(e);
                _key = e.KeyCode;
                Refresh(); // cause paint event
            }
        
            private Point _point = new Point();
            protected override void OnMouseMove(MouseEventArgs e) {
                base.OnMouseDown(e);
                _point = new Point(e.X, e.Y);
                Console.WriteLine($"On mouse move {_point}");
                Refresh();
            }

            protected override void OnPaint(PaintEventArgs e) {
                base.OnPaint(e);
                Console.WriteLine("On paint "+DateTime.Now.ToString("mm:ss-ffff"));
        
                Font font = new Font(this.Font.FontFamily, 24F);

                e.Graphics.DrawString(
                    String.Format("{0} : {1}", _point.X, _point.Y), // Draw Content
                    font, new SolidBrush(Color.Red),
                    _point  // Draw Position
                    );
        
                string showText = _key.ToString();
                font = new Font(this.Font.FontFamily, 16F);
                SizeF size = e.Graphics.MeasureString(showText, font);

                e.Graphics.DrawString(showText, font, new SolidBrush(Color.Green), 
                    (_point.X-this.Width/2)/2 + this.Width/2, (_point.Y-this.Height/2)/2 + this.Height/2);
            }

            private void InitializeComponent()
            {
                this.button1 = new System.Windows.Forms.Button();
                this.textBox1 = new System.Windows.Forms.TextBox();
                this.SuspendLayout();

                this.button1.Location = new System.Drawing.Point(192, 40);
                this.button1.Name = "button1";
                this.button1.Size = new System.Drawing.Size(88, 24);
                this.button1.TabIndex = 0;
                this.button1.Text = "Browse";
                this.button1.Click += new System.EventHandler(this.button1_Click);

                this.textBox1.Location = new System.Drawing.Point(8, 40);
                this.textBox1.Name = "textBox1";
                this.textBox1.Size = new System.Drawing.Size(168, 20);
                this.textBox1.TabIndex = 1;
                this.textBox1.Text = "FIle path";

                this.AutoScaleDimensions = new System.Drawing.SizeF(5, 13);
                this.ClientSize = new System.Drawing.Size(292, 266);
                this.Controls.Add(this.textBox1);
                this.Controls.Add(this.button1);
                this.Name = "Form1";
                this.Text = "Platform Invoke WinSound C#";
                this.ResumeLayout(false);
                this.PerformLayout();       }
        }
    }



## Windows HOOK API
- [EasyHook for Windows API](http://easyhook.github.io/tutorials/createlocalhook.html)

钩子 Hook API 是 Windows 的一个系统服务，利用钩子可以监听系统消息事件，比如其它程序的按键消息等，其它程序调用某函数前进行拦截等。使用 C++ 编写可以获取完整的 Hook API 功能，使用 C# 只能本地进程使用。

    using System;
    using System.Linq;
    using System.Drawing;
    using System.Runtime.InteropServices;
    using System.Windows.Forms;

    public class DiDemo
    {
        [DllImport("user32.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
        public static extern int SetWindowsHookEx(int idHook, HookProc lpfn, IntPtr hInstance, int threadId);

        [DllImport("user32.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
        public static extern bool UnhookWindowsHookEx(int idHook);

        [DllImport("user32.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
        public static extern int CallNextHookEx(int idHook, int nCode, Int32 wParam, IntPtr lParam);

        [DllImport("kernel32.dll")]
        public static extern int GetCurrentThreadId();

        public delegate int HookProc(int nCode, int wParam, IntPtr lParam);


        public struct MSG
        {
             public Point p;
             public IntPtr HWnd;
             public uint wHitTestCode;
             public int dwExtraInfo;
        }
         
        public struct KeyMSG
        {
             public int vkCode;
             public int scanCode;
             public int flags;
             public int time;
             public int dwExtraInfo;
        }
         
        // MSG m = (MSG) Marshal.PtrToStructure(lParam, typeof(MSG));
        // KeyMSG m = (KeyMSG) Marshal.PtrToStructure(lParam, typeof(KeyMSG));

        private static Form form;
        private static void Main(string[] args)
        {
            form = new Form();
            form.KeyPreview = true;
            form.Text = "Press H or X to use KeyBoardHook";
            form.Click += (o, e) => {
                Console.WriteLine("Click");
            };
            form.KeyPress += (o, e) => {
                Console.WriteLine("KeyPress "+e.KeyChar);
                if (e.KeyChar == 'h')
                {
                    HookStart();
                }
                else if(e.KeyChar == 'x')
                {
                    HookStop();
                }
            };
            Application.Run(form);
        }

        static int KeyboardHook = 0;

        private static int KeyboardHookProcedure(int nCode, Int32 wParam, IntPtr lParam)
        {
            Keys keyData = (Keys)wParam;
            var wp = (IntPtr.Size == 8) ? (int)((long)wParam << 32 >> 32) : (int)wParam;
            var lp = (IntPtr.Size == 8) ? (int)lParam.ToInt64() : lParam.ToInt32();
            
            if(keyData == Keys.X) HookStop();
            
            string keystate = (lp>0? "Key down ":"Key up")+ $"... {keyData} ";
            Console.WriteLine( keystate );
            Console.WriteLine($" {lp:N} {lParam:X} {lParam.ToInt64():X}");
            form.Text = (KeyboardHook==0? "Hook Uninstalled ":"Hook Installed ") + keystate;

            if (nCode >= 0)
            {
                return 1;
            }
            return CallNextHookEx(KeyboardHook, nCode, wParam, lParam);
        }

        // SetWindowsHookEx( 13,KeyboardHookProcedure,
        // Marshal.GetHINSTANCE(Assembly.GetExecutingAssembly().GetModules()[0]),0)
        public static void HookStart()
        {
            if (KeyboardHook == 0)
            {
                // KeyboardHookHandler = new HookProc(KeyboardHookProcedure);
                KeyboardHook = SetWindowsHookEx(2, KeyboardHookProcedure, IntPtr.Zero, GetCurrentThreadId());

                if (KeyboardHook == 0)
                {
                    throw new Exception("安装钩子失败");
                }
                form.Text = "Hook Install";
            }
        }

        public static void HookStop()
        {
            bool retKeyboard = true;
            if (KeyboardHook != 0)
            {
                retKeyboard = UnhookWindowsHookEx(KeyboardHook);
                KeyboardHook = 0;
            }
            if (!retKeyboard) 
            {
                throw new Exception("钩子卸载失败");
            }
            form.Text = "Hook Uninstall";
        }
    }


## SoundPlayer /resource 资源流播放
- [MediaSource 搭建流式播放器](https://zhuanlan.zhihu.com/p/26374202)
- https://archive.codeplex.com/?p=naudio
- [IE Media Source Extensions](https://docs.microsoft.com/en-us/previous-versions/windows/internet-explorer/ie-developer/samples/dn551369(v=vs.85)
- [Firefox Media Source Extensions](https://developer.mozilla.org/en-US/docs/Web/API/MediaSource)
- [The 'Codecs' and 'Profiles' Parameters for "Bucket" Media Types](https://tools.ietf.org/html/rfc6381)

Code:

    using System;
    using System.ComponentModel;
    using System.Reflection;
    using System.IO;
    using System.Resources;
    using System.Media;
    using System.Diagnostics;

    namespace ResourcePlayer
    {
        public partial class Demo
        {
            public static void Main(string[] args)
            {
                if(args.Length == 0 )
                {
                    Console.WriteLine(@"usage: meidia your.wav");
                    ResourcePlay();
                    return; 
                }
                SoundPlayer player = new SoundPlayer();
                SetEventHandler(player);
                // Set file's path 
                player.SoundLocation = args[0];
                player.LoadAsync();
                player.Play(); // PlaySync() PlayLooping() Stop();
                Console.ReadKey();
            }

            private static void SetEventHandler(SoundPlayer player)
            {
                // Listen events
                player.LoadCompleted += new AsyncCompletedEventHandler(player_LoadCompleted);
                // player.OnStreamChanged += new EventHandler(player_StreamChange);
                player.SoundLocationChanged += new EventHandler(player_LocationChanged);
            }
            static private void player_LoadCompleted(object s, AsyncCompletedEventArgs e){
                Console.WriteLine($"LoadCompleted {((SoundPlayer)s).SoundLocation}"); 
            }
            static private void player_StreamChange(object s, EventArgs e){
                Console.WriteLine("StreamChange"); 
            }
            static private void player_LocationChanged(object s, EventArgs e){
                Console.WriteLine($"LocationChanged {e}"); 
            }

            // csc media.cs -resource:"surface.wav"
            protected static void ResourcePlay()
            {
                Assembly assembly = Assembly.GetExecutingAssembly();
                Stream steam = assembly.GetManifestResourceStream("surface.wav");
                // player.Stream = Resources.ResourceManager.GetStream("mySound");
                try
                {
                    Console.WriteLine($"{steam}:{steam.Length}");
                } catch (Exception ex)
                {
                    Console.WriteLine(ex.Message);
                }
                SoundPlayer player = new SoundPlayer(steam);
                SetEventHandler(player);
                player.Play(); 
                Console.ReadKey();
                player.Stream = assembly.GetManifestResourceStream("sub_snare01.wav");
                player.Play();
                Console.ReadKey();
            }
        }
    }

    /*SoundPlayer sp = new SoundPlayer(global::WindowsApplication1.Properties.Resources.yoursoundfilename); */


## InteropServices DllImport 导入 Win32 API
- [Building a cross-platform C++ library to call from .NET Core](https://www.olegtarasov.me/build-cross-platform-c-library/)
- [Calling a cross-platform C++ library from .NET Core](https://www.olegtarasov.me/call-native-lib-from-net-core/)
- [.Net Source](https://source.dot.net/#System.IO.FileSystem/Interop.CopyFile.cs)
- [C# .Net Interoperablity with Native C Library](https://www.codeproject.com/Tips/709270/Csharp-NET-Interoperability-with-Native-C-Librarie)
- [C# 预处理器指令](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/preprocessor-directives/)
- [DllImportAttribute 特性](https://docs.microsoft.com/en-us/dotnet/api/system.runtime.interopservices.dllimportattribute?view=netcore-3.1)
- [Interoperating with unmanaged code](https://docs.microsoft.com/en-us/dotnet/framework/interop/)
- [Interoperability (C# Programming Guide)](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/interop/)
- [平台调用 (P/Invoke)](https://docs.microsoft.com/zh-cn/dotnet/standard/native-interop/pinvoke)

C# 与 Windows 系统 C++ API 或 COM 互操作使用 InteropServices 命令空间，非托管的 DLL 通过 DllImport 属性特性导入：

    using System;
    using System.Runtime.InteropServices;

    public class Win32 {
         [DllImport("user32.dll", CharSet=CharSet.Auto)]
         public static extern IntPtr MessageBox(int hWnd, String text,
                         String caption, uint type);
    }
    public class HelloWorld {
        public static void Main() {
           Win32.MessageBox(0, "Hello World", "Platform Invoke Sample", 0);
        }
    }

上面演示如何调用系统消息窗口 API，调用非托管 API 的步骤：

- 确定 DLL 的函数，至少函数名和 DLL 文件要知道；
- 创建一个封装类来托管这个 API；
- 使用 DllImportAttribute 在托管代码中编写 API 的原型；
- 传入参数调用 API;


以下代码来源 .Net Core ，Libraries.SystemNative 应该是一个宏定义，会用系统所用的 API 文件替换，可以使用 shell32.dll：

    // Licensed to the .NET Foundation under one or more agreements.
    // The .NET Foundation licenses this file to you under the MIT license.
    // See the LICENSE file in the project root for more information.
     
    using Microsoft.Win32.SafeHandles;
    using System;
    using System.Runtime.InteropServices;
     
    internal static partial class Interop
    {
        internal static partial class Sys
        {
            [DllImport(Libraries.SystemNative, EntryPoint = "SystemNative_CopyFile", SetLastError = true)]
            internal static extern int CopyFile(SafeFileHandle source, string srcPath, string destPath, int overwrite);
        }
    }


例如以下 C++ 代码导出一个 API：

    #include <stdio.h>
    #include <string.h>
    #include <malloc.h>
     
    #ifdef __cplusplus    // If used by C++ code, 
    extern "C" {          // we need to export the C interface
    #endif
            typedef struct Temp
            {       int * iVal;
                   char * chVal;
            }MyTemp;
     
            /*___________________PLATFORM BASED EXPORT DECLARATION STARTS_____*/
                   #ifdef UNIX 
                           #define EXPORT extern
                   #elif (defined (_WINDOWS))
                           #define EXPORT extern __declspec( dllexport )
                   #endif
            /*___________________PLATFORM BASED EXPORT DECLARATION ENDS________*/
            
            EXPORT void ctestFreeResource (void * ptr)
            {
                   if(ptr) free(ptr);
                   ptr = NULL;
            }
     
            EXPORT void ctestFillStructure(MyTemp *iTempVal)
            {
                   iTempVal->iVal = (int*) malloc(sizeof(int));
                   iTempVal->chVal = (char*) malloc(5);  
                   *((*iTempVal).iVal) = 500;
                   strcpy(iTempVal->chVal,"Moh"); 
                   return;
            }
    #ifdef __cplusplus
    }
    #endif

编译命令：

    LINUX BUILD:
     COMPILE       :       gcc -c -Wall -Werror -fpic ./ctest.c -DUNIX
     LINK          :       gcc -shared -o libctest.so ctest.o

交互调用的 C# 代码：

    using System;
    using System.Runtime.InteropServices;
    using System.Collections;
     
    namespace UseSharedObject
    {
            [StructLayout(LayoutKind.Sequential)] 
            public  struct Temp
            {
                   public IntPtr  m_iVal;
                   public  string m_strVal;
            }
     
            class MainClass
            {              
            #if (UX_PLATFORM)      
                   [DllImport ("./assembly/libctest.so", EntryPoint="ctestFillStructure")]
                    private static extern void ctestFillStructure(ref Temp i);
                           
                   [DllImport ("./assembly/libctest.so", EntryPoint="ctestFreeResource")]
                   private static extern void ctestFreeResource(IntPtr ptr);    
     
            #elif (WINDOWS)
                   [DllImport ("./assembly/libctest.dll", EntryPoint="ctestFillStructure")]
                    private static extern void ctestFillStructure(ref Temp i);
                           
                   [DllImport ("./assembly/libctest.dll", EntryPoint="ctestFreeResource")]
                   private static extern void ctestFreeResource(IntPtr ptr);     
            #endif
                   
                   public static  void Main (string[] args)
                   {
                           Temp valTemp = new Temp();                    
                           ctestFillStructure(ref valTemp);                      
                           Console.WriteLine ("RETURN VALUES FROM NATIVE LIBRARIES: valTemp.m_iVal = {0} valTemp.m_strVal = {1} ",
                               Marshal.ReadInt32( valTemp.m_iVal), valTemp.m_strVal);
                           Console.WriteLine ("CURRENT  PLATFORM = {0}", 
                               Environment.OSVersion.Platform.ToString());                  
                           ctestFreeResource( (IntPtr) (valTemp.m_iVal));                       
                           valTemp.m_iVal = (IntPtr)0;                   
                   }
            }
    }


## System.IO 文件读写
https://docs.microsoft.com/en-us/dotnet/api/system.io?view=netcore-3.1

- 基本对象

    - 文件流       System.IO.FileStream
    - 读写流       System.IO.StreamReader/StreamWriter
    - 编码        System.Text.Encoding
    - 处理异常  System.IO.Exception
    - 共享锁       System.IO.FileShare
    - 文件监视  System.IO.FileSystemWatcher
    - 文件信息  System.IO.FileInfo

- FileMode 指定操作系统打开文件的方式

    - 0x06 Append 追加或则创建，读写头寻址到结束位异常 IOException，读取异常  NotSupportedException；
    - 0x02 Create 创建新文件覆盖为 0 字节，写失败异常 UnauthorizedAccessException；
    - 0x01 CreateNew 创建新文件，文件存在异常 IOException。
    - 0x03 Open 指定模式打开文件，文件不存在异常 FileNotFoundException。
    - 0x04 OpenOrCreate 打开文件，如果不存在，则创建；
    - 0x05 Truncate 打开文件写入内容为 0 字节，文件将被清空为零字节。 ArgumentException 没有写权限异常。

- FileAccess

    - 0x01 Read     读文件
    - 0x02 ReadWrite    读写文件
    - 0x03 Write    写文件

- FileShare 枚举，定义常量，控制其他FileStream对于同一个文件所能具有的访问权。这些值可以按位与操作。

    - 0x04 Delete 允许删除文件
    - 0x10 Inheritable 使文件句柄可以有子进程继承，不支持Win32
    - 0x00 None 拒绝共享当前文件
    - 0x01 Read 允许后面的进程打开文件来读
    - 0x02 ReadWrite 允许后面的进程打开文件读或写
    - 0x03 Write 允许后面的进程打开文件来写

- FileOptions 枚举，创建 FileStream 的高级选项

    - Asynchronous 异步读取和写入
    - DeleteOnClose 关闭即删除
    - Encrypted 文件是加密的
    - None 没有附加条件
    - RandomAccess 随机访问文件
    - SequentialAccess 顺序访问文件
    - WriteThrough 指示系统通过任何中间缓存、直接写入磁盘

- FielInfo 常用方法

    - OpenText 返回 UTF8 编码 StreamReader
    - OpenRead 返回只读流 FileStream
    - OpenWrite 返回只写流 FileStream

标准输入输出 Console.ReadLine(), WriteLine()

    using System;
    using System.IO;

    class Test
    {
        
        public static void Main()
        {
            string path = Path.GetTempFileName();
            var fi1 = new FileInfo(path);

            // Create a file to write to.
            using (StreamWriter sw = fi1.CreateText())
            {
                sw.WriteLine("Hello");
                sw.WriteLine("And");
                sw.WriteLine("Welcome");
            }

            // Open the file to read from.
            using (StreamReader sr = fi1.OpenText())
            {
                var s = "";
                while ((s = sr.ReadLine()) != null)
                {
                    Console.WriteLine(s);
                }
            }

            try
            {
                string path2 = Path.GetTempFileName();
                var fi2 = new FileInfo(path2);

                // Ensure that the target does not exist.
                fi2.Delete();

                // Copy the file.
                fi1.CopyTo(path2);
                Console.WriteLine($"{path} was copied to {path2}.");

                // Delete the newly created file.
                fi2.Delete();
                Console.WriteLine($"{path2} was successfully deleted.");
            }
            catch (Exception e)
            {
                Console.WriteLine($"The process failed: {e.ToString()}");
            }
        }
    }


## MemoryStream 内存流

构造函数

| MemoryStream() | 初始化 0 容量，可自动扩展 |
| MemoryStream(Byte[]) | 初始化自 buffer 容量，不可扩展  |
| MemoryStream(Byte[], Boolean) | 初始化自 buffer 容量，不可扩展，指定 CanWrite |
| MemoryStream(Byte[], Int32, Int32) | 初始化自 buffer 容量，不可扩展，指定 buffer 区域 |
| MemoryStream(Byte[], Int32, Int32, Boolean) | 初始化自 buffer 容量，不可扩展，指定 buffer 区域和 CanWrite |
| MemoryStream(Byte[], Int32, Int32, Boolean, Boolean) | 初始化自 buffer 容量，不可扩展，指定 buffer 区域和 CanWrite，指定 GetBuffer() 能力 |
| MemoryStream(Int32) | 指定初始化容量，可自动扩展 |

示例：

    using System;
    using System.IO;
    using System.Text;

    class MemStream
    {
        static void Main()
        {
            int count;
            byte[] byteArray;
            char[] charArray;
            UnicodeEncoding uniEncoding = new UnicodeEncoding();

            // Create the data to write to the stream.
            byte[] firstString = uniEncoding.GetBytes(new String('v', 1000).ToCharArray());
            byte[] secondString = uniEncoding.GetBytes(
                Path.GetInvalidPathChars());
            // byte[] buf = new byte[256]; // with fixed capacity
            // using(MemoryStream memStream = new MemoryStream(buf))
            using(MemoryStream memStream = new MemoryStream(100))
            {
                // Write the first string to the stream.
                memStream.Write(firstString, 0 , firstString.Length);

                // Write the second string to the stream, byte by byte.
                count = 0;
                while(count < secondString.Length)
                {
                    memStream.WriteByte(secondString[count++]);
                }

                // Write the stream properties to the console.
                Console.WriteLine(
                    "Capacity = {0}, Length = {1}, Position = {2}\n",
                    memStream.Capacity.ToString(),
                    memStream.Length.ToString(),
                    memStream.Position.ToString());

                // Set the position to the beginning of the stream.
                memStream.Seek(0, SeekOrigin.Begin);

                // Read the first 20 bytes from the stream.
                byteArray = new byte[memStream.Length];
                count = memStream.Read(byteArray, 0, 20);

                // Read the remaining bytes, byte by byte.
                while(count < memStream.Length)
                {
                    byteArray[count++] =
                        Convert.ToByte(memStream.ReadByte());
                }

                // Decode the byte array into a char array
                // and write it to the console.
                charArray = new char[uniEncoding.GetCharCount(
                    byteArray, 0, count)];
                uniEncoding.GetDecoder().GetChars(
                    byteArray, 0, count, charArray, 0);
                Console.WriteLine(charArray);
            }
        }
    }



## StreamRead & StreamWriter

StreamReader (Stream stream);
StreamReader (string path);
StreamReader (Stream stream, bool detectEncodingFromByteOrderMarks);
StreamReader (Stream stream, Encoding encoding);
StreamReader (string path, bool detectEncodingFromByteOrderMarks);
StreamReader (String, Encoding) 
StreamReader (Stream, Encoding, Boolean)    
StreamReader (String, Encoding, Boolean)    
StreamReader (Stream stream, Encoding encoding, bool detectEncodingFromByteOrderMarks, int bufferSize);
StreamReader(String, Encoding, Boolean, Int32)  
StreamReader (Stream stream, Encoding encoding = default, bool detectEncodingFromByteOrderMarks = true, int bufferSize = -1, bool leaveOpen = false);

    using System.IO;
    using System.Text;
    namespace CSharpConvertString2Stream
    {    
     class Program    
     {               
           static void Main( string[] args )
            {            
                string str = "Testing 1-2-3";             //convert string 2 stream            
                byte[] array = Encoding.ASCII.GetBytes(str);            
                MemoryStream stream = new MemoryStream(array);             //convert stream 2 string      
                StreamReader reader = new StreamReader(stream);
                string text = reader.ReadToEnd();
                Console.WriteLine(text); 
                Console.ReadLine(); 
           }  
      }
    }

StreamWriter(Stream)    
StreamWriter(String)    
StreamWriter(Stream, Encoding)  
StreamWriter(String, Boolean)   
StreamWriter(Stream, Encoding, Int32)   
StreamWriter(String, Boolean, Encoding) 
StreamWriter(Stream, Encoding, Int32, Boolean)  
StreamWriter(String, Boolean, Encoding, Int32)

    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.IO;

    namespace StreamReadWrite
    {
        class Program
        {
            static void Main(string[] args)
            {
                DirectoryInfo[] cDirs = new DirectoryInfo(@"c:\").GetDirectories();

                using (StreamWriter sw = new StreamWriter("CDriveDirs.txt"))
                {
                    foreach (DirectoryInfo dir in cDirs)
                    {
                        sw.WriteLine(dir.Name);
                    }
                }

                string line = "";
                using (StreamReader sr = new StreamReader("CDriveDirs.txt"))
                {
                    while ((line = sr.ReadLine()) != null)
                    {
                        Console.WriteLine(line);
                    }
                }
            }
        }
    }


## BinaryRead & BinaryWriter

    using System;
    using System.IO;

    class ConsoleApplication
    {
        const string fileName = "AppSettings.dat";

        static void Main()
        {
            WriteDefaultValues();
            DisplayValues();
        }

        public static void WriteDefaultValues()
        {
            using (BinaryWriter writer = new BinaryWriter(File.Open(fileName, FileMode.Create)))
            {
                writer.Write(1.250F);
                writer.Write(@"c:\Temp");
                writer.Write(10);
                writer.Write(true);
            }
        }

        public static void DisplayValues()
        {
            float aspectRatio;
            string tempDirectory;
            int autoSaveTime;
            bool showStatusBar;

            if (File.Exists(fileName))
            {
                using (BinaryReader reader = new BinaryReader(File.Open(fileName, FileMode.Open)))
                {
                    aspectRatio = reader.ReadSingle();
                    tempDirectory = reader.ReadString();
                    autoSaveTime = reader.ReadInt32();
                    showStatusBar = reader.ReadBoolean();
                }

                Console.WriteLine("Aspect ratio set to: " + aspectRatio);
                Console.WriteLine("Temp directory is: " + tempDirectory);
                Console.WriteLine("Auto save time set to: " + autoSaveTime);
                Console.WriteLine("Show status bar: " + showStatusBar);
            }
        }
    }

输出 Binary 文件内容，二个字节一组分开显示，浮点值占 5 个字节，整数 10 占四个字节，可以看到小有效位放内存开头，即 Little-Endian，是典型的 Intel CPU 行为。对于单字节类型的数据，不存在字节序这个说法。：

    0000 a03f 0763 3a5c 5465 6d70 0a00 0000 01

两种字节存储顺序大端序和小端序 Big-Endian 和 Little-Endian，字节序只针对于多字节类型的数据处理，比如对于 int 整数 0x12345678，它占有 4 个字节的存储空间：

- 0x12 0x34 0x56 0x78 Big-Endian 高位存于低地址端，低位字节排放在内存的高地址端；
- 0x78 0x56 0x34 0x12 Little-Endian 低位存于低地址端，高位字节排放在内存的高地址端。

Big-endian 的内存顺序和数字的书写顺序是一致的，方便阅读理解。
Little-endian 在变量指针转换的时候地址保持不变，比如 int64* 转到 int32*

## System.IO.Pipelines
https://devblogs.microsoft.com/dotnet/system-io-pipelines-high-performance-io-in-net/
https://github.com/davidfowl/TcpEcho/tree/master/src
https://docs.microsoft.com/zh-cn/dotnet/api/system.io.pipelines
https://www.cnblogs.com/robertyao/p/9930195.html
https://www.dazhuanlan.com/2019/09/04/94848bdbb334/

System.IO.Pipelines 是一个新的库，旨在简化在 .NET 中执行高性能 IO 的过程。它是一个依赖 .NET Standard 的库，适用于所有 .NET 实现。

System.IO.Pipelines 命名空间提供了用于执行复杂的高性能输入输出 (IO) 操作的类型。

| 类型    | 功能    |
| :---- | :---- |
| Pipe  | 默认的 PipeWriter 和 PipeReader 实现。 |
| PipeOptions   | 表示一组 Pipe 选项。 |
| PipeReader    | 定义提供对管道读取端的访问权限的类。 |
| PipeScheduler | 用于运行 PipeReader 和 PipeWriter 回调和延续的抽象。 |
| PipeWriter    | 定义提供可将数据写入到的管道的类。 |
| StreamPipeExtensions  | 为 Stream 提供扩展方法，这些方法支持直接对管道进行的读取和写入操作。 |
| StreamPipeReaderOptions   | 表示一组用于控制 PipeReader 创建的选项。 |
| StreamPipeWriterOptions   | 表示一组用于控制 PipeWriter 创建的选项。 |


| 结构    | 作用    |
| :---- | :---- |
| FlushResult   | FlushAsync(CancellationToken) 调用返回的结果。 |
| ReadResult    | 表示 ReadAsync(CancellationToken) 调用的结果。 |


| 接口    | 用途    |
| :---- | :---- |
| IDuplexPipe | 定义提供可从中读取并写入数据的双工管道的类。 |


Pipelines 诞生于 .NET Core 团队，为使 Kestrel 成为业界最快的 Web 服务器之一。最初从作为 Kestrel 内部的实现细节发展成为可重用的 API，它在 .Net Core 2.1 中作为可用于所有 .NET 开发人员的最高级 BCL API（System.IO.Pipelines）提供。

为了正确解析 Stream 或 Socket 中的数据，代码有固定的样板，并且有许多极端情况，为了处理他们，不得不编写难以维护的复杂代码。
实现高性能和正确性，同时也难以处理这种复杂性。Pipelines 旨在解决这种复杂性。

它没有分配显式缓冲区。这是管道的核心功能之一。所有缓冲区管理都委托给 PipeReader/PipeWriter 实现。

除了处理内存管理之外，其他核心管道功能还包括能够在 Pipe 不实际消耗数据的情况下查看数据。

PipeReader 有 ReadAsync 和 AdvanceTo 两个核心 API。ReadAsync 获取 Pipe 数据，AdvanceTo 告诉 PipeReader 不再需要这些缓冲区，以便可以丢弃它们（例如返回到底层缓冲池）。

ReadOnlySequence<T> 
该实现存储了在 PipeWriter 和 PipeReader 之间传递的缓冲区的链接列表。ReadAsync 暴露一个 ReadOnlySequence<T> 新的 BCL 类型，它表示一个或多个 ReadOnlyMemory<T> 段的视图，类似于 Span<T> 和 Memory<T> 提供数组和字符串的视图。


编写网络程序的时候，经常会进行如下操作：

- 申请一个缓冲区
- 从数据源中读入数据至缓冲区
- 解析缓冲区的数据
- 重复第2步

表面上看来这是一个很常规而简单的操作，但实际使用过程中往往存在如下痛点：

- 数据读不全

    可能不能在一次read操作中读入所有需要的数据，因此需要在缓冲区中维护一个游标，记录下次读取操作的起始位置，这个游标带了了不小的复杂度：

    从缓冲区读数据时，要根据游标计算缓冲区起始写位置，以及剩余空间大小。增加了读数据的复杂度。
    
    解析数据也是复用这个缓冲区的，解析的时候也要判断游标起始位置，剩余空间大小。同时增加了解析数据的复杂度。

    解析后还要移动游标，重新标记缓冲区起始位置，再次增加了复杂度。
 

- 缓冲区容量有限

    由于缓冲区有限，可能申请的缓冲区不够用，需要引入动态缓冲区。这也大幅加大了代码的复杂度。

    如果每次都申请更大的内存，一方面带来的内存申请释放开销，另一方面需要将原来的数据移动，并更新游标，带来更复杂的逻辑。

    如果靠多段的内存组成一个逻辑整理，数据的读写方式都比较复杂。
    使用完后的内存要释放，如果需要更高的效率还要维持一个内存池。
 

- 读和用没有分离

    我们的业务本身只关心使用操作，但读和用操作没有分离，复杂的都操作导致用操作也变得复杂，并且严重干扰业务逻辑。

 
System.IO.Pipelines 解决了这些痛点，它主要包含一个 Pipe 对象，它有一个 Writer 和 Reader 属性。

    var pipe   = new Pipe();
    var writer = pipe.Writer;
    var reader = pipe.Reader;

Writer对象用于从数据源读取数据，将数据写入管道中；它对应业务中的"读"操作。

    var content = Encoding.Default.GetBytes("hello world");
    var data    = new Memory<byte>(content);
    var result  = await writer.WriteAsync(data);

另外，它也有一种使用 Pipe 申请 Memory 的方式

    var buffer = writer.GetMemory(512);
    content.CopyTo(buffer);
    writer.Advance(content.Length);
    var result = await writer.FlushAsync();

 
Reader 对象用于从管道中获取数据源，它对应业务中的取用数据的操作。

    var result = await reader.ReadAsync();
    var buffer = result.Buffer;

这个 Buffer 是一个 `ReadOnlySequence<byte>`对象，它是一个相当好的动态内存对象，并且相当高效。它本身由多段 `Memory<byte>` 组成，查看 Memory 段的方法有：

- IsSingleSegment   判断是否只有一段
- First 获取第一段
- GetEnumerator 获取分段的

它从逻辑上也可以看成一段连续的段，也有类似的方法：

- Length    整个数据缓冲区长度
- Slice 分割缓冲区
- CopyTo    将内容复制到Span中
- ToArray   将内容复制到byte[]中

另外，它还有一个类似游标的位置对象 SequencePosition，可以从其 Position 相关函数中使用，这里就不多介绍了。

这个缓冲区解决了数据没读够的问题，一次读取的不够下次可以接着读，不用缓冲区的动态分配，高效的内存管理方式带来了良好的性能，好用的接口是我们能更关注业务。

获取到缓冲区后，就是使用缓冲区的数据

    var data = buffer.ToArray();

使用完后，告诉PIPE当前使用了多少数据，下次接着从结束位置后读起

    reader.AdvanceTo(buffer.GetPosition(4));

这是一个相当实用的设计，它解决了"读了就得用"的问题，不仅可以将不用的数据下次再使用，还可以实现Peek的操作，只读但不改变游标。


除了"读"和"用"操作外，它们之间还需要一些交互，例如：

读过程中数据源不可用，需要停止使用。 使用过程中业务结束，需要中止数据源。 Reader 和 Writer 都有一个 Complete 函数，用于通知结束：

    reader.Complete();
    writer.Complete();

在 Writer 写入和 Reader 读取时，会获得一个结果

    FlushResult result = await writer.FlushAsync();
    ReadResult result = await reader.ReadAsync();

它们都有一个 IsComplete 属性，可以根据它是否为true判断是否已经结束了读和写的操作。

 

取消

在写入和读取的时候，也可以传入一个 CancellationToken，用于取消相应的操作。

    writer.FlushAsync(CancellationToken.None);
    reader.ReadAsync(CancellationToken.None);

如果取消成功，对应的 Result 的 IsCanceled 则为 true（没有验证过）


使用示范 Client.cs：

    using System;
    using System.Diagnostics;
    using System.Linq;
    using System.Net;
    using System.Net.Sockets;
    using System.Text;
    using System.Threading.Tasks;

    namespace TcpEcho
    {
        class Program
        {
            static async Task Main(string[] args)
            {
                var clientSocket = new Socket(SocketType.Stream, ProtocolType.Tcp);

                Console.WriteLine("Connecting to port 8087");

                clientSocket.Connect(new IPEndPoint(IPAddress.Loopback, 8087));
                var stream = new NetworkStream(clientSocket);

                await Console.OpenStandardInput().CopyToAsync(stream);
            }
        }
    }

Server.cs：

    using System;
    using System.Buffers;
    using System.IO.Pipelines;
    using System.Net;
    using System.Net.Sockets;
    using System.Text;
    using System.Threading.Tasks;

    namespace Server
    {
        class Program
        {
            static async Task Main(string[] args)
            {
                var listenSocket = new Socket(SocketType.Stream, ProtocolType.Tcp);
                listenSocket.Bind(new IPEndPoint(IPAddress.Loopback, 8087));

                Console.WriteLine("Listening on port 8087");

                listenSocket.Listen(120);

                while (true)
                {
                    var socket = await listenSocket.AcceptAsync();
                    _ = ProcessLinesAsync(socket);
                }
            }

            private static async Task ProcessLinesAsync(Socket socket)
            {
                Console.WriteLine($"[{socket.RemoteEndPoint}]: connected");

                // Create a PipeReader over the network stream
                var stream = new NetworkStream(socket);
                var reader = PipeReader.Create(stream);

                while (true)
                {
                    ReadResult result = await reader.ReadAsync();
                    ReadOnlySequence<byte> buffer = result.Buffer;

                    while (TryReadLine(ref buffer, out ReadOnlySequence<byte> line))
                    {
                        // Process the line.
                        ProcessLine(line);
                    }

                    // Tell the PipeReader how much of the buffer has been consumed.
                    reader.AdvanceTo(buffer.Start, buffer.End);

                    // Stop reading if there's no more data coming.
                    if (result.IsCompleted)
                    {
                        break;
                    }
                }

                // Mark the PipeReader as complete.
                await reader.CompleteAsync();

                Console.WriteLine($"[{socket.RemoteEndPoint}]: disconnected");
            }

            private static bool TryReadLine(ref ReadOnlySequence<byte> buffer, out ReadOnlySequence<byte> line)
            {
                // Look for a EOL in the buffer.
                SequencePosition? position = buffer.PositionOf((byte)'\n');

                if (position == null)
                {
                    line = default;
                    return false;
                }

                // Skip the line + the \n.
                line = buffer.Slice(0, position.Value);
                buffer = buffer.Slice(buffer.GetPosition(1, position.Value));
                return true;
            }

            private static void ProcessLine(in ReadOnlySequence<byte> buffer)
            {
                foreach (var segment in buffer)
                {
    #if NETCOREAPP2_1
                    Console.Write(Encoding.UTF8.GetString(segment.Span));
    #else
                    Console.Write(Encoding.UTF8.GetString(segment));
    #endif
                }
                Console.WriteLine();
            }
        }
    }


提供扩展方法 SocketExtensions.cs：

    #if NET461
    using System;
    using System.Net.Sockets;
    using System.Runtime.InteropServices;
    using System.Text;
    using System.Threading.Tasks;

    namespace Server
    {
        internal static class SocketExtensions
        {
            public static Task<int> ReceiveAsync(this Socket socket, Memory<byte> memory, SocketFlags socketFlags)
            {
                var arraySegment = GetArray(memory);
                return SocketTaskExtensions.ReceiveAsync(socket, arraySegment, socketFlags);
            }

            public static string GetString(this Encoding encoding, ReadOnlyMemory<byte> memory)
            {
                var arraySegment = GetArray(memory);
                return encoding.GetString(arraySegment.Array, arraySegment.Offset, arraySegment.Count);
            }

            private static ArraySegment<byte> GetArray(Memory<byte> memory)
            {
                return GetArray((ReadOnlyMemory<byte>)memory);
            }

            private static ArraySegment<byte> GetArray(ReadOnlyMemory<byte> memory)
            {
                if (!MemoryMarshal.TryGetArray(memory, out var result))
                {
                    throw new InvalidOperationException("Buffer backed by array was expected");
                }

                return result;
            }
        }
    }
    #endif



## BufferStream

Example 1: Code that runs on the client

    using System;
    using System.IO;
    using System.Globalization;
    using System.Net;
    using System.Net.Sockets;

    public class Client
    {
        const int dataArraySize    =   100;
        const int streamBufferSize =  1000;
        const int numberOfLoops    = 10000;

        static void Main(string[] args)
        {
            // Check that an argument was specified when the
            // program was invoked.
            if(args.Length == 0)
            {
                Console.WriteLine("Error: The name of the host computer" +
                    " must be specified when the program is invoked.");
                return;
            }

            string remoteName = args[0];

            // Create the underlying socket and connect to the server.
            Socket clientSocket = new Socket(AddressFamily.InterNetwork,
                SocketType.Stream, ProtocolType.Tcp);

            clientSocket.Connect(new IPEndPoint(
                Dns.Resolve(remoteName).AddressList[0], 1800));

            Console.WriteLine("Client is connected.\n");

            // Create a NetworkStream that owns clientSocket and
            // then create a BufferedStream on top of the NetworkStream.
            // Both streams are disposed when execution exits the
            // using statement.
            using(Stream
                netStream = new NetworkStream(clientSocket, true),
                bufStream =
                      new BufferedStream(netStream, streamBufferSize))
            {
                // Check whether the underlying stream supports seeking.
                Console.WriteLine("NetworkStream {0} seeking.\n",
                    bufStream.CanSeek ? "supports" : "does not support");

                // Send and receive data.
                if(bufStream.CanWrite)
                {
                    SendData(netStream, bufStream);
                }
                if(bufStream.CanRead)
                {
                    ReceiveData(netStream, bufStream);
                }

                // When bufStream is closed, netStream is in turn
                // closed, which in turn shuts down the connection
                // and closes clientSocket.
                Console.WriteLine("\nShutting down the connection.");
                bufStream.Close();
            }
        }

        static void SendData(Stream netStream, Stream bufStream)
        {
            DateTime startTime;
            double networkTime, bufferedTime;

            // Create random data to send to the server.
            byte[] dataToSend = new byte[dataArraySize];
            new Random().NextBytes(dataToSend);

            // Send the data using the NetworkStream.
            Console.WriteLine("Sending data using NetworkStream.");
            startTime = DateTime.Now;
            for(int i = 0; i < numberOfLoops; i++)
            {
                netStream.Write(dataToSend, 0, dataToSend.Length);
            }
            networkTime = (DateTime.Now - startTime).TotalSeconds;
            Console.WriteLine("{0} bytes sent in {1} seconds.\n",
                numberOfLoops * dataToSend.Length,
                networkTime.ToString("F1"));

            // Send the data using the BufferedStream.
            Console.WriteLine("Sending data using BufferedStream.");
            startTime = DateTime.Now;
            for(int i = 0; i < numberOfLoops; i++)
            {
                bufStream.Write(dataToSend, 0, dataToSend.Length);
            }
            bufStream.Flush();
            bufferedTime = (DateTime.Now - startTime).TotalSeconds;
            Console.WriteLine("{0} bytes sent in {1} seconds.\n",
                numberOfLoops * dataToSend.Length,
                bufferedTime.ToString("F1"));

            // Print the ratio of write times.
            Console.WriteLine("Sending data using the buffered " +
                "network stream was {0} {1} than using the network " +
                "stream alone.\n",
                (networkTime/bufferedTime).ToString("P0"),
                bufferedTime < networkTime ? "faster" : "slower");
        }

        static void ReceiveData(Stream netStream, Stream bufStream)
        {
            DateTime startTime;
            double networkTime, bufferedTime = 0;
            int bytesReceived = 0;
            byte[] receivedData = new byte[dataArraySize];

            // Receive data using the NetworkStream.
            Console.WriteLine("Receiving data using NetworkStream.");
            startTime = DateTime.Now;
            while(bytesReceived < numberOfLoops * receivedData.Length)
            {
                bytesReceived += netStream.Read(
                    receivedData, 0, receivedData.Length);
            }
            networkTime = (DateTime.Now - startTime).TotalSeconds;
            Console.WriteLine("{0} bytes received in {1} seconds.\n",
                bytesReceived.ToString(),
                networkTime.ToString("F1"));

            // Receive data using the BufferedStream.
            Console.WriteLine("Receiving data using BufferedStream.");
            bytesReceived = 0;
            startTime = DateTime.Now;

            int numBytesToRead = receivedData.Length;

            while (numBytesToRead > 0)
            {
                // Read may return anything from 0 to numBytesToRead.
                int n = bufStream.Read(receivedData,0, receivedData.Length);
                // The end of the file is reached.
                if (n == 0)
                    break;
                bytesReceived += n;
                numBytesToRead -= n;
            }

            bufferedTime = (DateTime.Now - startTime).TotalSeconds;
            Console.WriteLine("{0} bytes received in {1} seconds.\n",
                bytesReceived.ToString(),
                bufferedTime.ToString("F1"));

            // Print the ratio of read times.
            Console.WriteLine("Receiving data using the buffered network" +
                " stream was {0} {1} than using the network stream alone.",
                (networkTime/bufferedTime).ToString("P0"),
                bufferedTime < networkTime ? "faster" : "slower");
        }
    }

Example 2: Code that runs on the server

    using System;
    using System.Net;
    using System.Net.Sockets;

    public class Server
    {
        static void Main()
        {
            // This is a Windows Sockets 2 error code.
            const int WSAETIMEDOUT = 10060;

            Socket serverSocket;
            int bytesReceived, totalReceived = 0;
            byte[] receivedData = new byte[2000000];

            // Create random data to send to the client.
            byte[] dataToSend = new byte[2000000];
            new Random().NextBytes(dataToSend);

            IPAddress ipAddress =
                Dns.Resolve(Dns.GetHostName()).AddressList[0];
                // Dns.GetHostEntry("127.0.0.1").AddressList[0];

            IPEndPoint ipEndpoint = new IPEndPoint(ipAddress, 1800);

            // Create a socket and listen for incoming connections.
            using(Socket listenSocket = new Socket(
                AddressFamily.InterNetwork, SocketType.Stream,
                ProtocolType.Tcp))
            {
                listenSocket.Bind(ipEndpoint);
                listenSocket.Listen(1);

                // Accept a connection and create a socket to handle it.
                serverSocket = listenSocket.Accept();
                Console.WriteLine("Server is connected.\n");
            }

            try
            {
                // Send data to the client.
                Console.Write("Sending data ... ");
                int bytesSent = serverSocket.Send(
                    dataToSend, 0, dataToSend.Length, SocketFlags.None);
                Console.WriteLine("{0} bytes sent.\n",
                    bytesSent.ToString());

                // Set the timeout for receiving data to 2 seconds.
                serverSocket.SetSocketOption(SocketOptionLevel.Socket,
                    SocketOptionName.ReceiveTimeout, 2000);

                // Receive data from the client.
                Console.Write("Receiving data ... ");
                try
                {
                    do
                    {
                        bytesReceived = serverSocket.Receive(receivedData,
                            0, receivedData.Length, SocketFlags.None);
                        totalReceived += bytesReceived;
                    }
                    while(bytesReceived != 0);
                }
                catch(SocketException e)
                {
                    if(e.ErrorCode == WSAETIMEDOUT)
                    {
                        // Data was not received within the given time.
                        // Assume that the transmission has ended.
                    }
                    else
                    {
                        Console.WriteLine("{0}: {1}\n",
                            e.GetType().Name, e.Message);
                    }
                }
                finally
                {
                    Console.WriteLine("{0} bytes received.\n",
                        totalReceived.ToString());
                }
            }
            finally
            {
                serverSocket.Shutdown(SocketShutdown.Both);
                Console.WriteLine("Connection shut down.");
                serverSocket.Close();
            }
        }
    }


## Timer Demo

    using System;
    using System.Threading;

    class TimerExample
    {
        static void Main()
        {
            // Create an AutoResetEvent to signal the timeout threshold in the
            // timer callback has been reached.
            var autoEvent = new AutoResetEvent(false);
            
            var statusChecker = new StatusChecker(10);

            // Create a timer that invokes CheckStatus after one second, 
            // and every 1/4 second thereafter.
            Console.WriteLine("{0:h:mm:ss.fff} Creating timer.\n", 
                              DateTime.Now);
            var stateTimer = new Timer(statusChecker.CheckStatus, 
                                       autoEvent, 1000, 100);

            // When autoEvent signals, change the period to every half second.
            autoEvent.WaitOne();
            stateTimer.Change(0, 500);
            Console.WriteLine("\nChanging period to .5 seconds.\n");

            Console.WriteLine("\nChanging period to 0 for one tick & delay .3 seconds.\n");
            statusChecker.maxCount = 1;
            stateTimer.Change(300, 0);

            // When autoEvent signals the second time, dispose of the timer.
            autoEvent.WaitOne();
            stateTimer.Dispose();
            Console.WriteLine("\nDestroying timer.");
        }
    }

    class StatusChecker
    {
        public int invokeCount;
        public int  maxCount;

        public StatusChecker(int count)
        {
            invokeCount  = 0;
            maxCount = count;
        }

        // This method is called by the timer delegate.
        public void CheckStatus(Object stateInfo)
        {
            AutoResetEvent autoEvent = (AutoResetEvent)stateInfo;
            Console.WriteLine("{0} Checking status {1,2}.", 
                DateTime.Now.ToString("h:mm:ss.fff"), 
                (++invokeCount).ToString());

            if(invokeCount == maxCount)
            {
                // Reset the counter and signal the waiting thread.
                invokeCount = 0;
                autoEvent.Set();
            }
        }
    }



## Console 控件台程序
https://docs.microsoft.com/en-us/dotnet/api/system.console?view=netcore-3.1
https://docs.microsoft.com/en-us/dotnet/api/system.text.utf8encoding?view=netcore-3.1

控制台程序默认使用标准输入输出，即在控制台窗口通过 System.IO. & TextWriter 完成字符输入输出行为，通过 Console 静态类实现，调用 SetIn(TextReader) 和 SetOut(TextWriter) 方法可以改变输入输出行为。

    using System;

    public class Example {
        public static void Main()
        {
            Console.Write("Hello ");
            Console.WriteLine("World!");
            Console.Write("Enter your name: ");
            String name = Console.ReadLine();
            Console.Write("Good day, ");
            Console.Write(name);
            Console.WriteLine("!");
        }
    }

WriteLine 方法中，参数逗号后指定的格式数字表示右对齐 32 个字符空间，逗号后可以有空格，负号 - 表示左对齐：

    Console.WriteLine("{0, 32} {1, -32}", "WriteLine", "format {{index, wide}}...");


格式设置有两个三个部分，数据来源，宽度和左右对齐，数据类型和小数点位数，格式任何一个部分都是可选的。以 `"{0,-16:C4}"` 为例，第一个 0 表数据来源自紧跟格式字符串后的变量，再后面一个变量参数就是 `{1}` 等等。然后，是逗号后面指定的宽度 16 个字符和负号指定左对齐，默认不使用负号右对齐，只要宽度足够。最后是冒号后面指定的数据类型 C - Currency 货币，E - Scientific 科学计数法。数据类型后面的数字指定小数点后的位数，默认为 2 位小数。对于不同的数据来源，比如 D 表示十进制数值格式，或者表示日期的长格式。

可以使用 PC 蜂鸣器 Beep() 或者 Beep(frequency, duration) 来提醒用户。Beep 函数封装的是 Windows Beep API，它是否能发出声音取决 8254 可编程定时器芯片。

十二平均律，八度 Octave 分成十二个半音音程的律制，各相邻两律之间的振动数之比完全相等，钢琴即是根据十二平均律来定音的。每一等份称为一个半音小二度，一个大二度则是两等份。将一个八度分成 12 等份有着惊人的一些凑巧，它的纯五度音程的两个音的频率比，即 2 的 7/12 次方 与 1.5 非常接近，人耳基 本上听不出五度相生律和十二平均律的五度音程的差别。

彼此的关系很简单，自然音阶 7 个音的 do-re、re-mi、fa-so、so-la、la-si 之间的频率比都是 9:8，约为 1.12，这个比例被称为全音 Tone；mi-fa、si-do 之间的频率比都是 256:243 约为 1.06，也就是 2 的 12 次方根，这个比例被称为半音 Semitone。标准音 Standard Pitch A1 = 440Hz。

    using System;
    using System.Threading;

    class Sample
    {
        public static void Main()
        {
            // Declare the first few notes of the song, "Mary Had A Little Lamb".
            Note[] Mary =
                {
                new Note(Tone.B1, Duration.QUARTER),
                new Note(Tone.A1, Duration.QUARTER),
                new Note(Tone.G2, Duration.QUARTER),
                new Note(Tone.A1, Duration.QUARTER),
                new Note(Tone.B1, Duration.QUARTER),
                new Note(Tone.B1, Duration.QUARTER),
                new Note(Tone.B1, Duration.HALF),
                new Note(Tone.A1, Duration.QUARTER),
                new Note(Tone.A1, Duration.QUARTER),
                new Note(Tone.A1, Duration.HALF),
                new Note(Tone.B1, Duration.QUARTER),
                new Note(Tone.D1, Duration.QUARTER),
                new Note(Tone.D1, Duration.HALF)
                };
            Note[] melody = {
                new Note(Tone.e, Duration.QUARTER),
                new Note(Tone.f, Duration.EIGHTH),
                new Note(Tone.a, Duration.EIGHTH),
                new Note(Tone.b, Duration.HALF),
                new Note(Tone.e, Duration.QUARTER),
                new Note(Tone.f, Duration.EIGHTH),
                new Note(Tone.b, Duration.EIGHTH),
                new Note(Tone.a, Duration.HALF),
                new Note(Tone.c, Duration.HALF),
                new Note(Tone.A, Duration.WHOLE),
            };

            Play(melody);
            Play(Mary);
        }

        protected static void Play(Note[] tune)
        {
            foreach (Note n in tune)
            {
                if (n.NoteTone == Tone.REST)
                    Thread.Sleep((int)n.NoteDuration);
                else
                    Console.Beep((int)n.NoteTone, (int)n.NoteDuration);
            }
        }

        // Define the frequencies of notes in an octave, as well as silence (rest).
        protected enum Tone
        {
            REST   = 0,
            G3      = 196,
            A3      = 220,
            A3sharp = 233,
            B3      = 247,
            C2      = 262,
            C2sharp = 277,
            D2      = 294,
            D2sharp = 311,
            E2      = 330,
            F2      = 349,
            F2sharp = 370,
            G2      = 392,
            G2sharp = 415,
            A2      = 220,
            B2      = 247,
            C1      = 262,
            D1      = 294,
            E1      = 330,
            F1      = 350,
            G1      = 392,
            A1      = 440,
            B1      = 494,
            C       = 524,
            D       = 588,
            E       = 660,
            F       = 699,
            Gsharp  = 736,
            G       = 784,
            A       = 880,
            B       = 988,
            c       = 1047,
            d       = 1175,
            e       = 1319,
            f       = 1397,
            g       = 1568,
            a       = 1761,
            b       = 1976,

        }

        // Define the duration of a note in units of milliseconds.
        protected enum Duration
        {
            WHOLE     = 1000,
            HALF      = WHOLE/2,
            QUARTER   = HALF/2,
            EIGHTH    = QUARTER/2,
            SIXTEENTH = EIGHTH/2,
        }

        // Define a note as a frequency (tone) and the amount of
        // time (duration) the note plays.
        protected struct Note
        {
            Tone     toneVal;
            Duration durVal;

            // Define a constructor to create a specific note.
            public Note(Tone frequency, Duration time)
            {
                toneVal = frequency;
                durVal  = time;
            }

            // Define properties to return the note's tone and duration.
            public Tone NoteTone { get{ return toneVal; } }
            public Duration NoteDuration { get{ return durVal; } }
        }
    }

使用 BackgroundColor & ForegroundColor：

    using System;

    class Example
    {
       public static void Main()
       {
          // Get an array with the values of ConsoleColor enumeration members.
          ConsoleColor[] colors = (ConsoleColor[]) ConsoleColor.GetValues(typeof(ConsoleColor));

          ConsoleColor currentBackground = Console.BackgroundColor;
          ConsoleColor currentForeground = Console.ForegroundColor;

          // Display all foreground colors except the one that matches the background.
          Console.WriteLine("All the foreground colors except {0}, the background color:",
                            currentBackground);
          foreach (var color in colors) {
             if (color == currentBackground) continue;

             Console.ForegroundColor = color;
             Console.WriteLine("   The foreground color is {0}.", color);
          }
          Console.WriteLine();

          Console.ForegroundColor = currentForeground;

          // Display each background color except the one that matches the current foreground color.
          Console.WriteLine("All the background colors except {0}, the foreground color:",
                            currentForeground);
          foreach (var color in colors) {
             if (color == currentForeground) continue;

             Console.BackgroundColor = color;
             Console.WriteLine("   The background color is {0}.", color);
          }

          // Restore the original console colors.
          Console.ResetColor();
          Console.WriteLine("\nOriginal colors restored...");
       }
    }

ConsoleColor Enum：

| Black     | 0 | The color black. |
| Blue      | 9 | The color blue. |
| Cyan      | 11    | The color cyan (blue-green). |
| DarkBlue  | 1 | The color dark blue. |
| DarkCyan  | 3 | The color dark cyan (dark blue-green). |
| DarkGray  | 8 | The color dark gray. |
| DarkGreen | 2 | The color dark green. |
| DarkMagenta   | 5 | The color dark magenta (dark purplish-red). |
| DarkRed   | 4 | The color dark red. |
| DarkYellow    | 6 | The color dark yellow (ochre). |
| Gray      | 7 | The color gray. |
| Green     | 10    | The color green. |
| Magenta   | 13    | The color magenta (purplish-red). |
| Red       | 12    | The color red. |
| White     | 15    | The color white. |
| Yellow    | 14    | The color yellow. |




## FileSystemWatcher 文件监视
https://docs.microsoft.com/en-us/dotnet/api/system.io.filesystemwatcher?view=netcore-3.1

FileSystemWatcher 似乎只能以文件夹为单位检测，事件包括：Changed, Created, Deleted, Disposed, Error, Renamed

Windows 操作系统使用 FileSystemWatcher 创建的一个内存缓冲区通知程序文件的修改信息，如果在很短的时间内有非常多的文件修改，这个缓冲区会溢出， 造成部分追踪丢失，并且 FileSystemWatcher 不会产生异常。加大 InternalBufferSize 属性值可以避免这种情况。

InternalBufferSize 默认值是8K，可以设置的最小值是4K，增加或减小最好用 4K 的整数倍。每一个事件通知需要使用 16 字节，并不包含文件名。InternalBufferSize 使用 non-paged 内存，注意这部分内存资源比较宝贵。

使用 NotifyFilter、IncludeSubdirectories 属性减小 trace 范围，设置 filter 属性并不会影响进入缓冲区的事件通知，另外尽快的完成事件处理，也是避免缓冲区溢出造成事件丢失的一个措施。

隐藏文件也会监控。

有些系统中 FileSystemWatcher 的事件里对长文件名使用 8.3 短文件名方式表示。

如果多个 FileSystemWatcher 在监控同一个对象，在Windows XP SP1 之前，Windows 2000 SP2 或之前的操作系统中，只会有一个 FileSystemWatcher 接收到通知；更新版本的操作系统中所有 FileSystemWatcher 都会收到通知。

一次文件操作产生多个事件通知，某些文件操作可能会引发多个文件更改事件，例如新增文件、拷贝粘贴一个新的文件等。用 Sublime 创建新文件产生一个 Created，一个 Deleted，多个 Changed。微软的解释是文件系统的操作比较复杂，另外还有其它程序的影响，例如杀毒软件等。

文件管理器初步测试，Rename、Delete、New 只会触发一个事件，Save、Paste 时会有多个事件。

可以通过计时器来滤波，在文件事件处理中让计时器延迟一段时间之后，再执行加载新的配置文件操作。这样可以避免对文件做一次操作触发了多个更改事件，而多次加载配置文件。

同时监控多种类型的文件，例如 `*.xml + *.cs` 或 `*.txt; *.cs`，但 Filter 属性只支持 `*.*`，在事件里再进行字符串判断过滤 e.FullPath.EndsWith(".xml") 。

    using System;
    using System.Collections;
    using System.IO;
    using System.Security.Permissions;
    using System.Threading;

    public class Watcher
    {

        public static void Main()
        {
            string[] args = System.Environment.GetCommandLineArgs();
            string filter = args.Length>2? args[2]:"*.txt";

            // If a directory is not specified, exit program.
            if(args.Length < 2)
            {
                show();
                return;
            }
            Setup(args[1], filter);
            
            FileInfo ti = new FileInfo(Watcher._tmp);
            ti.Delete();
        }

        // Display the proper way to call the program.
        private static void show()
        {
            Console.WriteLine("FileSystemWatcher Usage: ");
            Console.WriteLine(" Watcher.exe directory filter");
            Console.WriteLine(" Watcher.exe . *.txt");
        }

        private static Timer _timer;
        private static string _tmp = Path.GetTempFileName();
        private static string tip_exit = "Watching {0} and press \"Alt + X\" to exit.";

        [PermissionSet(SecurityAction.Demand, Name="FullTrust")]
        public static void Setup(string path, string filter)
        {
            // Timer(TimerCallback, state_4_callback, dueTime, period)
            Watcher._timer = new Timer(new TimerCallback(OnTimerTick), null, Timeout.Infinite, Timeout.Infinite);

            // Create a new FileSystemWatcher and set its properties.
            FileSystemWatcher watcher = new FileSystemWatcher();

            /* Watch for changes in LastAccess and LastWrite times, and
               the renaming of files or directories. */
            watcher.NotifyFilter = NotifyFilters.LastAccess | NotifyFilters.LastWrite
               | NotifyFilters.FileName | NotifyFilters.DirectoryName;

            // Only watch text files.
            watcher.Filter = filter;

            // Add event handlers.
            watcher.Changed += new FileSystemEventHandler(OnChanged);
            watcher.Created += new FileSystemEventHandler(OnChanged);
            watcher.Deleted += new FileSystemEventHandler(OnChanged);
            watcher.Renamed += new RenamedEventHandler(OnRenamed);

            try
            {
                // Begin watching.
                watcher.Path = path;
                watcher.EnableRaisingEvents = true;
            } catch (ArgumentException e) {
                Console.WriteLine(e.Message);
                show();
                return;
            }

            // Wait for the user to quit the program.
            Console.WriteLine(Watcher.tip_exit, filter);
            ConsoleKeyInfo ki;
            bool suspress = true, Alt_X;
            do
            {
                ki = Console.ReadKey(suspress);
                Alt_X = ki.Key == ConsoleKey.X && (ki.Modifiers & ConsoleModifiers.Alt) > 0;
            } while (!Alt_X);
        }

        // Define the event handlers.
        private static void OnChanged(object source, FileSystemEventArgs e)
        {
            // Specify what is done when a file is changed, created, or deleted.
            string msg = string.Concat(new string[]{"File ", e.ChangeType.ToString(), ": ",  e.FullPath});
            loginfo(e.FullPath, msg);
        }

        private static void OnRenamed(object source, RenamedEventArgs e)
        {
            // Specify what is done when a file is renamed.
            string msg = string.Format("File Renamed: {0} renamed to {1}", e.OldFullPath, e.FullPath);
            loginfo(e.FullPath, msg);
        }

        private static ArrayList files = new ArrayList();
        private static void OnTimerTick(object state)
        {
            files.Clear();
        }

        private static void loginfo(string path, string msg)
        {
            Console.WriteLine(msg);
            FileInfo ti = new FileInfo(Watcher._tmp);

            // set timer filters 
            if (files.Contains(path)) return;
            files.Add(path);
            Watcher._timer.Change(300, 0);

            Console.WriteLine("Log to " + ti.FullName);
            using(StreamWriter sw = ti.AppendText()) // CreateText()/
            {
                FileInfo fi = new FileInfo(path);
                sw.WriteLine(msg);
                sw.WriteLine("Time ticks of {0}: ", path);
                sw.WriteLine("  {0:10} {1}", "Creation: ", fi.CreationTimeUtc.Ticks.ToString());
                sw.WriteLine("  {0:10} {1}", "Last Access: ", fi.LastAccessTimeUtc.Ticks.ToString());
                sw.WriteLine("  {0:10} {1}", "Last Write: ", fi.LastWriteTimeUtc.Ticks.ToString());
            }
        }
    }

## C# 当前程序路径信息

1. ASP.Net webform 

用 Request.PhysicalApplicationPath 获取站点所在虚拟目录的物理路径，最后包含“\”；
 
2. C# Winform

- Application.StartupPath 获取当前应用程序所在目录的路径，最后不包含“\”；
- Application.ExecutablePath  获取当前应用程序文件的路径，包含文件的名称；
- AppDomain.CurrentDomain.BaseDirectory 获取当前应用程序所在目录的路径，最后包含“\”；
- System.Threading.Thread.GetDomain().BaseDirectory 获取当前应用程序所在目录的路径，最后包含“\”；
- Environment.CurrentDirectory 获取当前应用程序的路径，最后不包含“\”；
- System.IO.Directory.GetCurrentDirectory 获取当前应用程序的路径，最后不包含“\”；
 
3. C# windows service 服务中用

AppDomain.CurrentDomain.BaseDirectory 或 System.Threading.Thread.GetDomain().BaseDirectory；

用 Environment.CurrentDirectory 和 System.IO.Directory.GetCurrentDirectory 将得到 system32 目录的路径；

如果要使用 Application.StartupPath 或 Application.ExecutablePath ，需要手动添加对 System.Windows.Forms.dll  的引用，并在程序开头用 using   System.Windows.Forms 声明该引用；
 
4.在卸载程序获取系统安装的目录：

    System.Reflection.Assembly curPath = System.Reflection.Assembly.GetExecutingAssembly();
    string path=curPath.Location;
    //得到安装程序类SetupLibrary文件的路径，获取这个文件路径所在的目录即得到安装程序的目录;
 
    System.Diagnostics.StackFrame f = new System.Diagnostics.StackFrame(1);
    MethodBase mb = f.GetMethod();

    System.Web.HttpContext.Current.Response.Write(mb.DeclaringType.ToString()); 

获取调用类的信息,可以从父类知道子类的情况



## win32icon 图标编译

基本属性

标题 Form.Text
大小 Form.Size
位置 Form.StartPosition
图标 Form.Icon
总是最前 Form.TopMost


    using System;
    using System.ComponentModel;
    using System.Drawing;
    using System.Windows.Forms;

    /**
     * coding.cs
     * csc /target:winexe /win32icon:favicon.ico coding.cs
     */
    namespace demo
    {
        public class DemoForm : Form
        {
            public DemoForm()
            {
                // set caption
                this.Text = "窗口的标题";
                // CenterParent, CenterScreen, Manual, WindowsDefaultBounds, WindowsDefaultLocation
                this.StartPosition = FormStartPosition.CenterScreen;
                // weight, height
                this.Size = new Size(500, 600);
                // icon
                this.Icon = new System.Drawing.Icon("favicon.ico");
            }

            [STAThread]
            static void Main()
            {
                Application.EnableVisualStyles();
                Application.Run(new DemoForm());
            }
        }
    }


## Diagnostics.Process 

提供对本地和远程进程的访问权限，并使你能够启动和停止本地系统进程。

Process 组件提供对计算机上运行的进程的访问。 最简单的过程是正在运行的应用程序。 线程是操作系统向其分配处理器时间的基本单元。 线程可以执行进程的任何代码部分，包括当前由另一个线程执行的部分。

Process 组件是用于启动、停止、控制和监视应用程序的有用工具。 您可以使用 Process 组件获取正在运行的进程的列表，也可以启动新的进程。 Process 组件用于访问系统进程。 初始化 Process 组件后，可以使用它来获取有关正在运行的进程的信息。 此类信息包括一组线程、已加载的模块（.dll 和 .exe 文件）以及性能信息，如进程正在使用的内存量。

    using System;

    public class demo : Form
    {

        [STAThread]
        static void Main()
        {
            string str = Console.ReadLine();

            System.Diagnostics.Process p = new System.Diagnostics.Process();
            p.StartInfo.FileName = "cmd.exe";
            p.StartInfo.UseShellExecute = false;    //是否使用操作系统shell启动
            p.StartInfo.RedirectStandardInput = true;//接受来自调用程序的输入信息
            p.StartInfo.RedirectStandardOutput = true;//由调用程序获取输出信息
            p.StartInfo.RedirectStandardError = true;//重定向标准错误输出
            p.StartInfo.CreateNoWindow = true;//不显示程序窗口
            p.Start();

            // 向cmd窗口发送输入信息
            p.StandardInput.WriteLine(str + "&exit");
            p.StandardInput.AutoFlush = true;
            // 这里使用&是批处理命令的符号，表示前面一个命令不管是否执行成功都执行后面(exit)命令，如果不执行exit命令，后面调用ReadToEnd()方法会假死
            //同类的符号还有&&和||前者表示必须前一个命令执行成功才会执行后面的命令，后者表示必须前一个命令执行失败才会执行后面的命令


            //获取cmd窗口的输出信息
            string output = p.StandardOutput.ReadToEnd();

            //StreamReader reader = p.StandardOutput;
            //string line=reader.ReadLine();
            //while (!reader.EndOfStream)
            //{
            //    str += line + "  ";
            //    line = reader.ReadLine();
            //}

            p.WaitForExit();
            p.Close();


            Console.WriteLine(output);
        }
    }


关于 rundll32.exe 的用途 

- 系统重启关闭

    - rundll32.exe user.exe,restartwindows 
    - rundll32.exe user.exe,exitwindows

- 显示控制面板 

    - rundll32.exe shell32.dll,Control_RunDLL 
    - rundll32.exe shell32.dll,Control_RunDLL access.cpl,,1 
    - rundll32.exe shell32.dll,Control_RunDLL telephon.cpl 




## Drag&Drop 拖放

    using System;
    using System.Collections;
    using System.ComponentModel;
    using System.Drawing;
    using System.Windows.Forms;

    namespace coding
    {
        public class DemoForm : Form
        {
            public DemoForm()
            {
                // set caption
                this.Text = "试试拖动文字到窗口";
                // CenterParent, CenterScreen, Manual, WindowsDefaultBounds, WindowsDefaultLocation
                this.StartPosition = FormStartPosition.CenterScreen;
                // weight, height
                this.Size = new Size(500, 600);
                this.Icon = new System.Drawing.Icon("favicon.ico");

                // drap and drop settings
                this.AllowDrop = true;
                this.DragEnter += this.OnDragEnter;
                this.DragDrop += this.OnDragDrop;
            }

            [STAThread]
            static void Main()
            {
                Application.EnableVisualStyles();
                Application.Run(new DemoForm());
            }

            private void OnDragDrop(object sender, DragEventArgs e)
            {
                if(Formats.Contains(DataFormats.Html))
                {
                    string sa = (string)e.Data.GetData(DataFormats.Html);
                    Console.WriteLine(sa);
                    return;
                }else if(Formats.Contains(DataFormats.Text)){
                    string sa = (string)e.Data.GetData(DataFormats.Text);
                    Console.WriteLine(sa);
                    return;
                }

                // Ensure that the list item index is contained in the data.
                string[] s=(string[])e.Data.GetData(DataFormats.FileDrop, false);

                for (int i = 0; i < s.Length; i++)
                {
                    Console.WriteLine(s[i]);
                }
            }

            private ArrayList Formats = new ArrayList(); 
            private void OnDragEnter(object sender, DragEventArgs e)
            {
                // get formats from IDataObject.GetFormats()
                Formats.Clear();
                Formats.AddRange(e.Data.GetFormats());
                Console.WriteLine("GetFormats "+String.Join(",", Formats.ToArray()));
                if (e.Data.GetDataPresent(DataFormats.FileDrop) || Formats.Contains(DataFormats.Text))
                {
                    e.Effect = DragDropEffects.All;
                } else {
                    e.Effect = DragDropEffects.None;
                }
            }
        }
    }




## NotifyIcon 最小化至任务栏

    csc /target:winexe /win32icon:favicon.ico coding.cs

最小化至任务栏 System.Windows.Forms.NotifyIcon，编译加入图标资源：


    using System;
    using System.Drawing;
    using System.Windows.Forms;

    public class Form1 : Form
    {
        private NotifyIcon notifyIcon;
        private ContextMenu contextMenu;
        private MenuItem menuItem;
        private System.ComponentModel.IContainer components;

        [STAThread]
        static void Main()
        {
            Application.Run(new Form1());
        }

        public Form1()
        {
            this.components = new System.ComponentModel.Container();
            this.contextMenu = new ContextMenu();
            this.menuItem = new MenuItem();

            // Initialize contextMenu
            this.contextMenu.MenuItems.AddRange(
                        new MenuItem[] {this.menuItem});

            // Initialize menuItem
            this.menuItem.Index = 0;
            this.menuItem.Text = "E&xit";
            this.menuItem.Click += new System.EventHandler(this.menuItem_Click);

            // Set up how the form should be displayed.
            this.ClientSize = new System.Drawing.Size(292, 266);
            this.Text = "Notify Icon Example";

            // Create the NotifyIcon.
            this.notifyIcon = new NotifyIcon(this.components);

            // The Icon property sets the icon that will appear
            // in the systray for this application.
            notifyIcon.Icon = new Icon("favicon.ico");

            // The ContextMenu property sets the menu that will
            // appear when the systray icon is right clicked.
            notifyIcon.ContextMenu = this.contextMenu;

            // The Text property sets the text that will be displayed,
            // in a tooltip, when the mouse hovers over the systray icon.
            notifyIcon.Text = "Form1 (NotifyIcon example)";

            // Handle the DoubleClick event to activate the form.
            notifyIcon.DoubleClick += new System.EventHandler(this.notifyIcon_DoubleClick);

            this.SizeChanged += new System.EventHandler(this.Form1_SizeChanged);
        }

        protected override void Dispose( bool disposing )
        {
            // Clean up any components being used.
            if( disposing && components != null)
            {
                components.Dispose();
            }

            base.Dispose( disposing );
        }

        #region 最小化隐藏任务栏图标、显示托盘图标
        private void Form1_SizeChanged(object sender, EventArgs e)
        {
            if (WindowState == FormWindowState.Minimized)
            {
                this.ShowInTaskbar = false;
                notifyIcon.Visible = true;
            }
        }
        #endregion

        private void notifyIcon_DoubleClick(object Sender, EventArgs e)
        {
            // Show the form when the user double clicks on the notify icon.

            // Set the WindowState to normal if the form is minimized.
            if (this.WindowState == FormWindowState.Minimized)
            {
                this.WindowState = FormWindowState.Normal;
            }

            this.Activate();

            this.ShowInTaskbar = true;
            notifyIcon.Visible = false;
        }

        private void menuItem_Click(object Sender, EventArgs e) {
            this.Close();
        }
    }



# IoC & Dependence Injection 依赖注入
- [Microsoft DependencyInjection Source](https://github.com/aspnet/DependencyInjection)
- [WPF and IOC on .NET Core 3.0](https://laurentkempe.com/2019/04/18/WPF-and-IOC-on-NET-Core-3-0/)
- [IoC 依赖倒置原则](https://www.cnblogs.com/gaochundong/p/dependency_inversion_principle.html)
- [Inversion of Control Containers and the Dependency Injection pattern](https://www.martinfowler.com/articles/injection.html)
- [Microsoft.Extensions.DependencyInjection API](https://docs.microsoft.com/en-us/dotnet/api/microsoft.extensions.dependencyinjection?view=dotnet-plat-ext-3.1)
- [ASP.NET Core 3.0 框架揭秘 ServicePrvider 实现](https://www.cnblogs.com/artech/p/asp-net-core-di-service-provider-1.html)
- [ASP.NET Core 框架 7 个核心对象](https://www.cnblogs.com/artech/p/inside-asp-net-core-framework.html)

Microsoft DependencyInjection 作为一个开源的依赖注入实现，它在 .Net Core 里被广泛的使用，完全可以扩展支持其它第三方的 IoC 容器。


在 .NET Core 应用程序里，你会发现在 Startup 类中大量使用了依赖注入方法向应用程序中注册组件模块，如：

- services.AddMvc();
- services.AddSignalR();
- services.AddControllersWithViews();
- services.AddServerSideBlazor();
- services.AddRazorPages()
- services.AddDbContext<UserDC>();

- services.Add(new ServiceDescriptor(typeof(dbContext), new dbContext(cons)));
- services.AddSingleton(typeof(ILogger), typeof(ApiLogger));
- services.AddDistributedMemoryCache();
- services.AddSingleton<MainWindow>();

示例，假定 ApiLogger 类型实现 ILogger 接口：

    ApiLoggerConfig config = new ApiLoggerConfig();
    services.AddSingleton(config);
    services.AddSingleton(typeof(ILogger), typeof(ApiLogger));

代码中以单例模式注册配置对象 config，它会在 DependencyInjection 实例化 ILogger 接口类型对象时注入其构造方法。

注册好的服务，要使用时，可以通过各种方法获取服务实例：

    HttpContext.RequestServices.GetService(typeof(dbContext)) as dbContext;
    ServiceProvider.GetService<MainWindow>();

还可以在控制器类的构造函数的参数中通过依赖注入，在实例化时填充进来：

    public class Hello : Controller
    {
        private readonly UserDC _context;

        public Hello(UserDC context)
        {
            _context = context;
        }
    }


DependencyInjection 解耦了整个 .NET Core 程序使用的组件，这样在维护和 NuGet 包升级时都更灵活，各自模块自己有问题就自己解决，而不影响其它模块。


通常模块化组件会需要用到控制反转模式 IoC - Inversion of Control，它最先跟随 Java 的 Spring 框架流行，通过反转依赖关系，可以有效解耦模块化的代码。IoC 的基本思想是等通知：配置好，等依赖方呼叫。有两种实现方式：

- 依赖查找 Dependency Lookup，已经被抛弃，因为他需要用户自己去是使用 API 进行查找资源和组装对象，即有侵入性。

- 依赖注入 Dependency Injection，是 Spring 使用的方式，容器负责组件的装配。Spring 作者 Rod Johnson 设计了两个接口 BeanFactory 和 ApplicationContext 用以表示容器。

Robert Martin 《The Dependency Inversion Principle》 有清楚的解釋，其中提到两条重要概念： 高层模块不应该依赖于低层模块，它们二者都应该依赖于抽象； 抽象不应该依赖于细节，细节应该依赖于抽象。

依賴注入在 Martin Fowler 的文章有三种实现方式：

- Type 1 IoC: Interface injection
- Type 2 IoC: Setter injection
- Type 3 IoC: Constructor injection

Setter 和 Constructor 两种方式区别在于后者通过构造函数实现依赖注入，前者则使用专用方法来实现。Spring 框架鼓励使用 Type 2 IoC 即 Setter injection 方式。


依赖反转原则 Dependency Inversion Principle 是很多面向对象技术的根基，它特别适合应用于构建可复用的软件框架，其对于构建弹性地易于变化的代码也特别重要。并且，因为抽象和细节已经彼此隔离，代码也变得更易维护。

举实例说明，现在有个程序需求是实现一个记录写入的组件，目前只有软盘作记录，那么组件实现可能会有这样一个方法

    public function saveToFloppy(String content){
        ...
    }

但这不是一个好的实现，因为依赖了具象，组件的实现依赖了存储介质，这就是高耦合的 Type 1 IoC，具有強的侵入性，使用它來實現依賴注入會使得組件相依於容器（框架），降低組件的重用性。

如果需求进一步变化了，现在需要写入 USB 移动磁盘了，那么程序逻辑就不能很好满足了，必需修改现有代码匹配新需求。但更好的的方法是按前面提到的两条依赖原则来实现，组件不应该依赖具体的存储介质。

把涉及存储介质的高耦合部分拆解出去，组件只关心高层次的抽象功能。即组件只关心如果实现实现定稿记录的动作，而至于写入到什么介质则交由具体底层去实现，那么这些底层可以叫做 FloppyWriter、UsbDiskWriter，它们关心写的动作。而抽象后的组件则将重心转移到如何协调这些底层的调用，这就需要进行一个抽象接口的统一。可以规定接口为 IDeviceWriter，实现一个 saveToDevice 方法，调用这个方法来实现写入动作，那么抽象后的组件应该这这样实现：

    public class FloppyWriter implements IDeviceWriter { 
        public void saveToDevice() { 
            .... 
        } 
    } 

    public class UsbDiskWriter implements IDeviceWriter { 
        public void saveToDevice() { 
            .... 
        } 
    }


在一个应用框架中，通常需要使用各种各样的服务，有必要将它们集中管理，需要什么服务就向 IoC 容器注册什么服务，在使用服务时向 IoC 容器获取相应的服务实例。在使用 Java Spring 框架中，提供两个核心容器，BeanFactory 和 ApplicationContext，这两个容器的就是 Spring 依赖管理的核心所在。


IoC 容器的一般的使用流程：

- 实例化一个服务容器 ServiceCollection 并注册需要使用的服务；
- 通过 ServiceCollection 的 BuildServiceProvider 方法返回一个服务供应者实例；
- 通过服务供应者的 GetService 方法获取相应的服务实例；
- 使用服务实例。

服务的生命周期管理决定 ServiceProvider 采用怎样的方式创建和回收服务实例，枚举类型 ServiceLifetime 指定三个方式：

- Singleton 表示以单例的方式管理服务实例，即在每次获取服务时，服务实例是同一个；
- Transient 则完全相反，对于每次服务提供请求，总会创建一个新的实例。
- Scoped 方式指定一个 ServiceScope 来圈定服务的作用域，它继承自 IDisposable 接口，执行 Dispose 方法回收服务实例。



以下是几个重要的类或接口：

- ServiceCollection

    用来注册服务的 IoC 容器，服务注册后，可以在任意类型的构造方法中使用它，而不是只能在控制器中使用。

    各种注册服务的 C# 扩展方法基本按 LifeTime 方式分成三类，Singleton/Transient/Scoped。定义在 ServiceCollectionServiceExtensions 其它更多的是重载方法，注册方法都会返回服务容器，可以链式调用。泛型注册方法会间接调用非泛型注册方法，比如 `AddSingleton<TService>()` 等价 `AddSingleton(typeof(TService))`。获取服务时，也要用对应的方式 `GetService<TService>()`。

    - AddScoped<TService>()     服务域方式添加指定类型的服务
    - AddSingleton<TService>()  单例模式添加指定类型的服务
    - AddTransient<TService>()  按临时态生命周期添加指定类型的服务

    - Add(ServiceDescriptor)    通过服务描述符对象添加服务
    - Add(IEnumerable<ServiceDescriptor>)   通过多个服务描述符对象添加服务

    - RemoveAll(Type)   移除指定类型的服务
    - RemoveAll<T>()    移除指定类型的服务
    - Replace(ServiceDescriptor)    根据服务描述符对象移除服务

    - AddSingleton(Type)    单例模式添加指定类型的服务
    - AddSingleton(Type, Func<IServiceProvider,Object>) 单例模式添加指定类型的服务并指定工厂函数
    - AddSingleton(Type, Object)    单例模式添加指定类型的服务并指定实现实例
    - AddSingleton(Type, Type)  单例模式添加指定类型的服务和相应实现的类型

- ServiceDescriptor

    服务描述符类型记录以下信息：

    - 服务类型 `ServiceType`
    - 实现类型 `ImplementationType`
    - 服务对象实例 `ImplementationInstance`
    - 实例化工厂函数 `ImplementationFactory`
    - 服务的生命周期 `Lifetime`

    在 ServiceCollection 中注册的服务都会记录在一个 List<ServiceDescriptor>。

- ServiceProvider

    服务供应者，它仅提供了唯一个 GetService 方法从服务容器获取服务类型实例。

- ServiceScope & ServiceScopeFactory
- DynamicServiceProviderEngine
- CompiledServiceProviderEngine
- ServiceProviderEngine

    是依赖注入的核心，它定义了 GetService() 方法被 IServiceProvider 调用。


为了在性能与开销中获取平衡，DependencyInjection 在初次请求时使用反射实例化目标服务，再次请求时异步使用表达式树替换了目标实例化委托，使得后续请求将得到性能提升。DependencyInjection 并非是银弹，它的便利性是一种空间换时间的典型，我们需要对以下情况有所了解：

- 重度使用依赖注入的大型项目启动过程相当之慢；
- 如果单次请求需要实例化的目标服务过多，前期请求的内存开销不可轻视；
- 由于实例化伴随着递归调用，过深的依赖将不可避免地导致堆栈溢出；

可以使用 Visual Studio 2017 自带的诊断工具 Diagnostic Tools 进行性能分析。


其它使用 Microsoft.Extensions.DependencyInjection 的 IoC 容器：

- Autofac https://autofac.readthedocs.org/en/latest/integration/aspnetcore.html
- DryIoc https://www.nuget.org/packages/DryIoc.Microsoft.DependencyInjection
- Grace https://www.nuget.org/packages/Grace.DependencyInjection.Extensions
- LightInject https://github.com/seesharper/LightInject.Microsoft.DependencyInjection
- StructureMap https://github.com/structuremap/StructureMap.Microsoft.DependencyInjection
- Stashbox https://github.com/z4kn4fein/stashbox-extensions-dependencyinjection
- Unity https://www.nuget.org/packages/Unity.Microsoft.DependencyInjection/


## DependenceInjection WPF Demo

接下来通过一个 WPF 程序演示如何使用各种依赖注入方式的使用。执行命令创建 WPF 程序工程模板，并安装 DependencyInjection 模块：

    dotnet new wpf -o WPF-DI
    dotnet add package Microsoft.Extensions.DependencyInjection  -version 3.1.4

创建字符串服务类型，只提供文字服务以演示：

    public interface ITextService
    {
        string GetText();
    }

    class TextService : ITextService
    {
        private string _text;

        public TextService(string text)
        {
            _text = text;
        }
        
        public string GetText()
        {
            return _text;
        }
    }

然后，主窗体类代码 MainWindow.xaml.cs，主要是提供两个构造函数以演示依赖注入如何填充参数：

    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            Console.WriteLine($"MainWindow()");
        }
        
        public MainWindow(ITextService textService)
        {
            InitializeComponent();
            Console.WriteLine($"MainWindow(ITextService)");
            Label.Content = textService.GetText();
        }

        private void button_click(object sendr, RoutedEventArgs e)
        {
            // MessageBox.Show("Hello WPF!");
            // Application.Current.Shutdown();
            Close();
        }
    }

可以在 MainWindow.xaml 文件中添加一个按钮这是可选的：

    <Button Name="button" Click="button_click">Click</Button>

接下来是主程序代码 App.xaml.cs：

    using System;
    using System.Collections.Generic;
    using System.Configuration;
    using System.Data;
    using System.Linq;
    using System.Threading.Tasks;
    using System.Windows;
    using Microsoft.Extensions.DependencyInjection;

    namespace wpf
    {
        /// <summary>
        /// Interaction logic for App.xaml
        /// </summary>
        public partial class App : Application
        {
            public IServiceProvider _serviceProvider;

            public App()
            {
                var serviceCollection = new ServiceCollection();
                ConfigureServices(serviceCollection);

                _serviceProvider = serviceCollection.BuildServiceProvider();

                var mainWindow = _serviceProvider.GetService<MainWindow>();
                Console.WriteLine($"GetService {mainWindow}");
                mainWindow?.Show();
            }

            private void ConfigureServices(IServiceCollection services)
            {

                var ts = new TextService("Hi WPF .NET Core 1.0!");
                services.AddSingleton(typeof(ITextService), ts);

                services.AddSingleton<ITextService, TextService>(provider =>{
                    Console.WriteLine($"Provider {provider}");
                    return new TextService("Hi WPF .NET Core 3.0!");
                    });

                services.AddSingleton<MainWindow>(provider => {
                    // Microsoft.Extensions.DependencyInjection.ServiceLookup.ServiceProviderEngineScope
                    // Console.WriteLine($"Provider {provider.GetType()}");
                    // MessageBox.Show("Lambada ImplementationFactory");
                    return new MainWindow(new TextService("Hi WPF!"));
                    });

                services.AddSingleton<MainWindow>();
            }
        }
    }

注意，服务这个概念并不局限于 TextService 这个对象，注意 `GetService<MainWindow>()` 这句代码的隐含意思就是将 MainWindow 类形当服务，所以这个示例代码存在 TextService 和 MainWindow 两种服务类型。

这里使用了四种服务注册方式，第一、二种分别使用的是以下形式：

    services.AddSingleton(ImplementationType, ImplementationInstance)
    services.AddSingleton<ServiceType, ImplementationType>(ImplementationFactory)

两种都使用了对象实例，第二种通过 Lambada 方式实现的 ImplementationFactory 工厂函数返回实例。因为这两个服务是要作为其它服务的构造函数参数使用的，通过依赖注入填充到 MainWindow 的第二个构造函数中，填充时选择最后注册的服务实例。如果不注册这两个服务实例，那么 DependencyInjection 在实例化其它服务时，不会以有依赖注入行为。即执行服务类型的默认构造函数，而不是使用依赖注入的构造函数。

第三、四种使用以下注册方式：

    services.AddSingleton<ImplementationType>(ImplementationFactory)
    services.AddSingleton<ImplementationType>()

它们都没有使用 ImplementationInstance，第三种注册方式直接在 ImplementationFactory 中注入了服务依赖的对象。第四种注册方式会根据已经注册过的服务决定如何调用构造函数，假如没有第一、二种注册好的服务实例，那么就会执行默认的构造函数。如果又没有提供默认构造函数，那么就会抛出异常，无法解决依赖注入的参数。

只有在第一、二、四种服务都没有注册的情况下，`GetService<MainWindow>()` 才会触发第三种注册方式中的工厂函数，去实例化一个 MainWindow 对象。









# Razor Page 框架
- [ASP.NET Core Razor Pages](https://docs.microsoft.com/zh-cn/aspnet/core/razor-pages/?view=aspnetcore-3.1)
- [ASP.NET 主机配置](https://docs.microsoft.com/zh-cn/aspnet/core/fundamentals/host/generic-host?view=aspnetcore-3.1)

Razor Pages 是 ASP.NET Core MVC 的一个新特性，使用 Razor 模板语法，使用 cshtml 视图模板文件，它可以使基于页面的编码方式更简单高效，简化了传统的 MVC 模式。

要创建基本 Web 应用，使用以下命令，然后执行 dotnet run 运行，ASP.NET 可以配合 ：

    dotnet new webApp -o myWebApp --no-https

    dotnet new webApp -o myWebApp
    dotnet dev-certs https --trust

项目结构：

- Pages 文件夹

    包含 Razor 页面和支持文件，每个 Razor 页面都由两部分组件，`.cshtml` 和一个包含处理页面事件的 C# 代码文件 `.cshtml.cs`。

    支持文件的名称以下划线开头。 例如，`_Layout.cshtml` 文件可配置所有页面通用的 UI 元素，可以是 HTML 标签，也可以是类似 HTML 标签的 ASP.NET Core 助手标签，还可以包含 Razor 语法的 C＃ 代码。

    助手标签和 HTML 标签的区别在于 `asp-` 前缀，

        <a class="nav-link text-dark" asp-area="" asp-page="/Index">Home</a>
        <a class="nav-link text-dark" href="/Index/Session">Session</a>

- wwwroot 文件夹

    包含静态文件，如 HTML 文件、JavaScript 文件和 CSS 文件。可以通过 Startup 配置来启用静态文件服务：

        app.UseDefaultFiles();
        app.UseStaticFiles();

- appSettings.json

    包含配置数据，如连接字符串。

- Program.cs

    包含程序的入口点，构造 .NET 通用主机提供 HTTP 服务。

- Startup.cs

    包含配置应用行为的代码。 ASP.NET Core 中的应用启动配置都是在此设置，通过依赖注入，可以激活路由，MVC/Blazor 等等框架服务。


没有打开热加载开发体验并不那么好，热加载是基本的开发需求，修改后要在浏览器上看到更新。有两种方法可以实现，一是使用 Razor Page 的运行时编译模块，另一种就是使用 dotnet watch 启动开发模式下的文件监视功能，只要文件改动，就自动重新编译。

要使用运行时文件编译，就要配置 ASP.NET Core 中的 Razor 文件编译功能。或者创建 Razor Pages 项目模板时使用 -rrc 或 --razor-runtime-compilation 模板选项，它会自动修改好 LaunchSettings 配置：

    dotnet new webapp --razor-runtime-compilation

在现有项目中启用运行时编译，要安装 Microsoft.AspNetCore.Mvc.Razor.RuntimeCompilation 包：

    dotnet add package Microsoft.AspNetCore.Mvc.Razor.RuntimeCompilation --version 3.1.4

更新项目的 Startup.ConfigureServices 方法以包含对 AddRazorRuntimeCompilation 的调用。

    public void ConfigureServices(IServiceCollection services)
    {
        services.AddRazorPages()
            .AddRazorRuntimeCompilation();

        // code omitted for brevity
    }

如果仅在开发环境中启用运行时编译，添加运行时编译包后，修改 LaunchSettings 的 environmentVariables 启动设置，其它配置如监听端口可以自行修改：

    "environmentVariables": {
      "ASPNETCORE_ENVIRONMENT": "Development",
      "ASPNETCORE_HOSTINGSTARTUPASSEMBLIES": "Microsoft.AspNetCore.Mvc.Razor.RuntimeCompilation"
    }


在 Startup.cs 中调用 AddRazorPages 和 MapRazorPages 启用 Razor 页面。MapRazorPages 负责建立 Razor Pages 与路由的映射。默认情况下，运行时在 Pages 文件夹中查找 Razor 页面文件。URL 未包含页面时，Index 为默认页面。

    public class Startup
    {
        ...
        public void ConfigureServices(IServiceCollection services)
        {
            services.AddRazorPages();
        }

        public void Configure(IApplicationBuilder app, IWebHostEnvironment env)
        {
        ...
            app.UseEndpoints(endpoints =>
            {
                endpoints.MapRazorPages();
            });
        }
    }

AddRasorPage 方法激活 MVC 框架，会返回依赖注入的 Microsoft.Extensions.DependencyInjection.MvcBuilder 对象以进行配置，比如路由的配置。


ASP.NET Core 模板配置会创建一个 .NET Core 泛型主机 HostBuilder。

启动主机时，它对它在 DI 容器中找到的 IHostedService 的每个实现调用 IHostedService.StartAsync。 在 web 应用中，其中一个 IHostedService 实现是启动 HTTP 服务器实现的 web 服务。

`CreateDefaultBuilder` 方法：

- 将内容根目录设置为由 GetCurrentDirectory 返回的路径。
- 通过以下项加载主机配置：
    - 前缀为 DOTNET_ 的环境变量。
    - 命令行参数。
- 通过以下对象加载应用配置：
    - appsettings.json 。
    - appsettings.{Environment}.json 。
    - 密钥管理器 当应用在 Development 环境中运行时。
    - 环境变量。
    - 命令行参数。
- 添加以下日志记录提供程序：
    - 控制台
    - 调试
    - EventSource
    - EventLog（仅当在 Windows 上运行时）
- 当环境为“开发”时，启用范围验证和依赖关系验证。

`ConfigureWebHostDefaults` 方法：

- 从前缀为 ASPNETCORE_ 的环境变量加载主机配置。
- 使用应用的托管配置提供程序将 Kestrel 服务器设置为 web 服务器并对其进行配置。 有关 Kestrel 服务器默认选项，请参阅 ASP.NET Core 中的 Kestrel Web 服务器实现。
- 添加主机筛选中间件。
- 如果 ASPNETCORE_FORWARDEDHEADERS_ENABLED 等于 true，则添加转接头中间件。
- 支持 IIS 集成。 有关 IIS 默认选项。


在默认模板配置 Program.cs，或者从 LaunchSettings.json 设置：

    Host.CreateDefaultBuilder(args)
        .UseContentRoot("c:\\content-root")
        .UseEnvironment("Development")

        .UseShutdownTimeout(TimeSpan.FromSeconds(10))

        .ConfigureHostConfiguration(configHost =>
        {
            configHost.SetBasePath(Directory.GetCurrentDirectory());
            configHost.AddJsonFile("hostsettings.json", optional: true);
            configHost.AddEnvironmentVariables(prefix: "PREFIX_");
            configHost.AddCommandLine(args);
        });

    Host.CreateDefaultBuilder(args)
        .ConfigureWebHostDefaults(webBuilder =>
        {
            webBuilder.UseStartup<Startup>()
                .ConfigureLogging(builder => builder.AddFile());
        });

    webBuilder.UseUrls("http://*:5000;http://localhost:5001;https://hostname:5002");
    webBuilder.UseWebRoot("public");
    webBuilder.UseStartup("StartupAssemblyName");
    webBuilder.UseStartup<Startup>();
    webBuilder.UseSetting("https_port", "8080");


## Razor Page Basic
- [Razor Page Class](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.aspnetcore.mvc.razorpages.page?view=aspnetcore-3.1)
- [Razor PageModel Class](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.aspnetcore.mvc.razorpages.pagemodel?view=aspnetcore-3.1)
- [ASP.Net Core HttpContext Class](https://docs.microsoft.com/en-us/dotnet/api/microsoft.aspnetcore.http.httpcontext?view=aspnetcore-3.1)
- [ASP.Net Core Controller Class](https://docs.microsoft.com/en-us/dotnet/api/microsoft.aspnetcore.mvc.controller?view=aspnetcore-3.1)

每个 Razor Page 包含视图文件和代码文件两个部分，以下两个文件演示如何使用 PageModel 基类生成 Razor Page 页面。 按照惯例，PageModel 类文件的名称追加 .cs，基本名与 Razor 视图页面文件名称相同。

Pages/Index.cshtml.cs 页面模型 ：

    using Microsoft.AspNetCore.Mvc.RazorPages;
    using Microsoft.Extensions.Logging;
    using System;

    namespace RazorPagesIntro.Pages
    {
        public class IndexModel : PageModel
        {
            public string Message { get; private set; } = "PageModel in C#";

            public void OnGet()
            {
                Message += $" Server time is { DateTime.Now }";
            }
        }
    }

Pages/Index.cshtml 视图文件：

    @page
    @using RazorPagesIntro.Pages
    @model IndexModel

    <h2>Separate page model</h2>
    <p>
        @Model.Message
    </p>

Razor Pages 文件名有 .cshtml 后缀，它最终都经过编译生成对应的 C# 类，继承 Microsoft.AspNetCore.Mvc.RazorPages.Page，可以在 obj 目录下检查为视图生成的 Razor C# 类。

Page 和 PageModel 的关系就像其名字暗示那样，分别对应了 MVC 模式的 View 和 Model。而 Page 对象要引引用 PageMode 就通过 `@model IndexModel` 来注入，它会生成相应的初始化代码，其中最明了的就是这两句类型声明，这种语法很奇怪，但它们都是用来定义只读属性的方式，即仅提供 get 的属性：

    public global::Microsoft.AspNetCore.Mvc.ViewFeatures.ViewDataDictionary<IndexModel> ViewData => (global::Microsoft.AspNetCore.Mvc.ViewFeatures.ViewDataDictionary<IndexModel>)PageContext?.ViewData;
    public IndexModel Model => ViewData.Model;

所以可以注入其它定义好的 PageMode，在视图后面的 @Model.Message 访问已加载的模型类实例成员。



前面的代码与具有控制器和视图的 ASP.NET Core MVC 应用中使用的 Razor 视图文件非常相似。 不同之处在于 @page 指令。 @page 使文件转换为一个 MVC 操作 ，这意味着它将直接处理请求，而无需通过控制器处理。 @page 必须是页面上的第一个 Razor 指令, @page 会影响其他 Razor 构造的行为。 

Razor Component 组件或 Razor Page 可以通过命令生成模板，-na 给 Razor Page 指定命名空间：

    dotnet new razorcomponent -o=. -n="View"
    dotnet new page -o=. -na="Razor.Pages" -n="Home"


Razor 支持在 cshtml 模板文件使用 @ 符号来编写 C# 代码。 Razor 会负责解析 C# 代码还有 Razor 的助手标签，生成对应的 HTML 标签。当 @ 符号后跟 Razor 保留关键字时如 @if，它会转换为 Razor 特定标记，否则会转换为纯 C#。若要对 Razor 标记中的 @ 符号进行转义，请使用 @@ 符号。


隐式 Razor 表达式以 @ 开头，后跟 C# 代码，显式 Razor 表达式由 @ 符号和平衡圆括号组成。

    <p>@DateTime.Now</p>
    <p>@DateTime.IsLeapYear(2016)</p>
    <p>Last week this time: @(DateTime.Now - TimeSpan.FromDays(7))</p>

隐式表达式不能包含空格，但 C# await 关键字除外。 如果该 C# 语句具有明确的结束标记，则可以混用空格：

    <p>@await DoSomething("hello", "world")</p>

隐式表达式不能包含 C# 泛型，因为尖括号内的字符会被解释为 HTML 标记。 以下想要使用泛型的代码无效：

    <p>@GenericMethod<int>()</p>

计算结果为字符串的 C# 表达式采用 HTML 编码。 计算结果为 IHtmlContent 的 C# 表达式直接通过 IHtmlContent.WriteTo 呈现。 计算结果不为 IHtmlContent 的 C# 表达式通过 ToString 转换为字符串，并在呈现前进行编码。

    @("<span>Hello World</span>")

该代码呈现以下 HTML：

    &lt;span&gt;Hello World&lt;/span&gt;

使用 HtmlHelper.Raw 输出不进行编码，但呈现为 HTML 标记。对未经审查的用户输入使用 HtmlHelper.Raw 会带来安全风险。 用户输入可能包含恶意的 JavaScript 或其他攻击。 

    @Html.Raw("<span>Hello World</span>")

该代码呈现以下 HTML：

    <span>Hello World</span>

Razor 代码块以 @ 开头，并括在 {} 中。 代码块内的 C# 代码不会呈现，这点与表达式不同。 一个视图中的代码块和表达式共享相同的作用域并按顺序进行定义。代码块中的默认语言为 C#，不过，Razor 页面可以隐式转换回 HTML：

    @{
        var inCSharp = true;
        <p>Now in HTML, was in C# @inCSharp</p>
    }

细节在 Razor 模板指令参考部分。


Tag Helpers 助手标签很像原生的 HTML 标签，只是 Razor 赋予功能化，跟 ASP.Net Code MVC 框架结合得很密切。

以锚点标签 Anchor Tag Helper 为例，可以设置以下基本的属性：

| 属性    | 说明    |
| :-----    | :-----    |
| asp-controller    | 控制器的名称，用于生成 URL 的控制器部分。   |
| asp-action    | 操作方法的名称。  |
| asp-area  | 区域名称，用于目录分级。  |
| asp-page  | Razor Page 的名称。   |
| asp-page-handler  | Razor Page 处理程序的名称。   |
| asp-route | 指定路由的名称，用于创建直接链接到命名路由的 URL。   |
| asp-route-{value} | 单个 URL 路由值。 例如，asp-route-id="1234"。   |
| asp-all-route-data    | 所有路由值。支持创建键值对字典， 键是参数名称，值是参数值。    |
| asp-fragment  | URL 片段，即地址 # 号后面的部分。  |
| asp-protocol  | 用于在 URL 中指定协议（比如 https）。  |
| asp-host  | 在 URL 中指定主机名，如 asp-host="microsoft.com"。  |

那么 HTML 标签写法看起来跟 Razor 助手标签是一样的，除了属性区别：

    <a href="/Index.html">HTML TAG</a>

    <a asp-area="" asp-page="/form">Form</a>
    <a asp-area="" asp-controller="api" asp-action="hello" asp-route-id="1" asp-route-name="x">API</a>

asp-area 用来指定区域级的 Pages 目录，比如有一套页面，但需要不同的语言的差异化表达，懂么就会在多个作为语言管理的目录下放置 Pages 页面文件夹，这时就可以通过 asp-area 属性来指定页面所在的区域目录。

另外 controller 和 action 指定了 MVC 框架中的控制器及其响应处理的方法，后面两个就是路由数据 asp-route-xxx。asp-page 和 asp-page-handler 是和控制器加 action 的方式类似，但是它们是两套不同的路由方式，它们指定了 Razor 页面和处理函数来响应这种助手标签生成的 URL。

助手标签生成的 HTML 标签：

    <a url="/form">Form</a>
    <a href="/api/hello?id=1&name=x">API</a>

数据参数的处理细节，参考 ASP.NET Core 助手标签 Tag Helpers。

HttpRequest.RouteValues 这个属性保存的就是和路由有关的数据，包括助手标签设置的以下几个属性：

- asp-area 区域目录
- asp-controller 控制器
- asp-action 动作
- asp-page 页面
- asp-handler 处理函数

参考 MVC 路由。

Razor 页面路由自定义设置的方式：

- 使用页面路由
- 应用模型提供程序约定来控制 Razor 页面应用中的页面路由、发现和处理。
- 需要为各个页面配置自定义页面路由时，可使用 AddPageRoute 约定配置页面路由。
- 若要指定页面路由、添加路由段或向路由添加参数，请使用页面的 @page 指令自定义路由。
- 有些保留字不能用作路由段或参数名称。 有关详细信息，请参阅路由：保留的路由名称。


使用 @page 指令自定义路由，执行以下操作：

- 指定页面的自定义路由。 例如 @page "/Some/Other/Path"。
- 将段追加到页面的默认路由。 例如 @page "item" 将 item 段添加到页面的默认路由。
- 将参数追加到页面的默认路由。 例如 @page "{id}" 页面需要 ID 参数 id。
- 支持开头处以波形符指定的相对于根目录的路径。 例如，`@page "~/Some/Other/Path"` 和 `@page "/Some/Other/Path"` 相同。

使用 asp-page 指向 Razor Page 时，直接填写目录即可，Razor 会自动找到 Index.cshtml 页面。 

Razor Page 框架逻辑比 MVC 要更清晰，是因为 Razor Page 通过在助手标签中使用 `asp-page-handler` 指定处理函数，这样可以使用多种处理函数来响应对应的表单提交动作或响应页面请求。asp-page-handler 指定的处理函数会通过 URL 中的查询字符串 `?handler=JoinList` 回传到服务器。如果你不喜欢这种方式，请更改路由 `@page "{handler?}"`，将处理函数名称放在 URL 的 PATH 路径部分，后面的 ? 表示路由参数为可选，这种设置对于参数，比如 `{Name?}` 是不起作用的。

    @page "{handler?}/{Name?}"
    @model FormModel
    @{
    }

    <html>
    <body>
        <div class="jumbotron bg-success text-white">
            <p> Enter your name: @Model.Name @Model.Age</p>
            <p> Model Class: @Model </p>
            <p asp-validation-summary="All"></p>
            <form method="POST">
                <p>Name: <input asp-for="Name" /></p>
                <p> Age: <input asp-for="Age" /></p>
                <input type="submit" asp-page-handler="JoinList" value="Join" />
                <input type="submit" asp-page-handler="JoinListUC" value="JOIN UC" />
            </form>
        </div>
    </body>
    </html>

Razor 页面的基本处理请求的函数是 On[Verb] 或 On[Verb]Async 这样的格式命名。Verb 可以各种 HTTP 谓词，比如常见 Get/Post/Head/Option/Put/Delete 等，也可以自定义的。带 Async 后缀的是定义异步处理函数时的一种约定习惯，同一个谓词的方法只能使用有 Async 后缀或没有后缀的其中一种，不能两种同时出现。

页面点击两个提交按钮对应的处理函数：

- OnPostJoinList 对应 URL 为 https://localhost:5001/form/JoinList
- OnPostJoinListUC 对应 URL 为 https://localhost:5001/form/JoinListUC

PageModel 类型代码参考如下，注意表单使用 POST 方法提交。如果改用 GET 方式，就会执行 OnGetJoinList 或 OnGetJoinListUC 或带 Async 后缀的方法。但是没有相应定义就会执行默认的 OnGet[Async] 方法，没关系，也不会以出错，而是直接忽略 handler 的存在。 

    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Threading.Tasks;
    using Microsoft.AspNetCore.Components.Web;
    using Microsoft.AspNetCore.Http;
    using Microsoft.AspNetCore.Mvc;
    using Microsoft.AspNetCore.Mvc.RazorPages;
    using Microsoft.Extensions.Logging;

    public class MyModel {

        [BindProperty(SupportsGet = true)] 
        public string Name {get; set;} = "anonymous";

        [BindProperty] 
        public int Age {get; set;} = 18;

    }

    public class FormModel : PageModel
    {
        [BindProperty(SupportsGet = true)] 
        public string Name {get; set;} = "anonymous";

        [BindProperty]
        public int Age {get; set;} = 18;

        public void OnHead()
        {
            HttpContext.Response.Headers.Add("Head Test", "Handled by OnHead!");
        }

        public async Task<IActionResult> OnPostJoinListAsync()
        {
            Console.WriteLine($"OnPost JoinListAsync [IsValid: {ModelState.IsValid}]...");
            await Task.Delay(3000);

            if (ModelState.IsValid)
            {
                return RedirectToPage("/Home/Welcome");
            }
            return Page();
        }

        // public void OnPost()
        public void OnPostAsync()
        {
            HttpRequest req = HttpContext.Request;
            Console.WriteLine("OnPost [{0}|{1}|{2}] [Path: {3}] [QueryString: {4}]", 
                string.Join(",", req.RouteValues.Keys), req.Form["Age"], req.Query["Age"], req.Path, req.QueryString);
        }

        // public void OnGet()
        public void OnGetAsync()
        {
            HttpRequest req = HttpContext.Request;
            string testForm = req.HasFormContentType ? req.Form["Age"].ToString():"NO";
            Console.WriteLine("OnGet [{0}|{1}|{2}] [Path: {3}] [QueryString: {4}]", 
                string.Join(",", req.RouteValues.Keys), testForm, req.Query["Age"], req.Path, req.QueryString);
        }
    }


和 MVC 控制器中返回 return View() 的不再，在 Razor 中默认返回 return Page()， Razor Page 没有重载这个方法，相比 MVC 控制器，确实精简多了。但是像分部视图、视图组件这些功都具备，参考布局 Layout 内容：

- Partial View 页面片断渲染

    - Partial(String)   创建 PartialViewResult 渲染分部视图；
    - Partial(String, Object)   创建 PartialViewResult 渲染分部视图；

- View Comoponent 视图组件渲染

    - ViewComponent(String) 创建 ViewComponentResult，指定组件文件名渲染；
    - ViewComponent(Type)   创建 ViewComponentResult，指定组件类型；
    - ViewComponent(String, Object) 创建 ViewComponentResult，指定组件文件名及参数对象；
    - ViewComponent(Type, Object)   创建 ViewComponentResult，指定组件类型和参数对象；


## Layout & UI Reuse 页面布局与重用
- [ASP.NET Core 十种方式扩展你的 Views](https://blog.51cto.com/zhanglida66/1921544)
- [View Components in ASP.​NET 5](http://asp.net-hacker.rocks/2015/11/25/viewcomponents-aspnet5.html)
- [使用 Razor 类库项目创建可重用 UI](https://docs.microsoft.com/zh-cn/aspnet/core/razor-pages/ui-class?view=aspnetcore-3.1)
- [Partial View 分部视图](https://docs.microsoft.com/zh-cn/aspnet/core/mvc/views/partial?view=aspnetcore-3.1)
- [ASP.NET Core 中的布局](https://docs.microsoft.com/zh-cn/aspnet/core/mvc/views/layout?view=aspnetcore-3.1)
- [ASP.NET Core MVC 中的视图](https://docs.microsoft.com/zh-cn/aspnet/core/mvc/views/overview?view=aspnetcore-3.1)
- []()

从平面设计上来讲，视图的布局就是页面的区域划分设计，比如页面的菜单栏、内容主体区域等。从代码实现上讲，布局就是配合设计实现的视图重组。将页面不同的区域划分为不同的视图文件，再通过逻辑重组生成完整的页面，呈现给用户。

每一个视图都是使用 Layout 属性来指定它的布局，如果多个视图使用同一个布局，就会产生冗余，并且很难维护。
ViewStart 页面可用来消除这种冗余，这个文件中的代码先于同目录下任何视图代码的执行。这个文件也可以递归地应用到任何视图子目录下，也就是说没个视图都可以设置自己的 ViewImports & ViewStart。

项目有两个特殊的页面对象 ViewImports & ViewStart，分别作为引入命名空间和页面起点使用，在渲染任何视图时都会先行载入。

配置全局视图可以在 `_ViewImports.cshtml` 文件中，来配置你其他视图中使用的一些比较公用的 using 引用，依赖注入等。

MVC 或 Razor Page 项目有两个特殊的页面对象 MVC ViewImports & ViewStart，分别作为引入命名空间和页面起点使用，MVC 框架在渲染任何视图时都会先行载入。对于一个视图文件，同文件夹下的 `_ViewImports.cshtml` 和 `_ViewStart.cshtml` 优先于上级目录的加载。同时，ViewImports 文件中的标签不会被解析输出到页面。

每一个视图都是使用 Layout 属性来指定它的布局，如果多个视图使用同一个布局，就会产生冗余，并且很难维护。 ViewStart 页面可用来消除这种冗余，这个文件中的代码先于同目录下任何视图代码的执行。这个文件也可以递归地应用到任何视图子目录下，也就是说没个视图都可以设置自己的 ViewImports & ViewStart。

因为这个代码先于任何视图运行，所以一个视图可以重写 Layout 属性的默认值，从而重新选择一个不同的布局。如果一组视图拥有共同的设置，那么 ViewStart 文件就有了用武之地，因为我们可以在它里面对共同的视图配置进行统一设置。

注意，要在布局视图中执行渲染方法 @RenderBody()，通常还会访问视图中设置的数据集 @ViewData。

当创建一个默认的 ASP.NET 项目时，会自动在 Views 目录下添加一个 `_ViewStart.cshtml` 文件，它指定了一个默认布局，两种方式都可以。属性支持省略写法，会自行到 /Views/Shared 目录下查找布局页，如果在当前目录下没有相应的文件：

    @{
        Layout = "~/Views/Shared/_Layout.cshtml";
        Layout = "_Layout";
    }

加载一个视图文件，至少以下三个目录会被搜索：

    - /Pages/_Layout.cshtml
    - /Pages/Shared/_Layout.cshtml
    - /Views/Shared/_Layout.cshtml

这和 ASP.NET MVC 项目的视图加载位置有些差别：

    - /Views/controller/_Layout.cshtml
    - /Views/Shared/_Layout.cshtml
    - /Pages/Shared/_Layout.cshtml

一般在 `_Layout.cshtml` 有一个方法法叫 RenderBody()，它就是用来渲染详细的视图页到模板布局视图中：

    @RenderBody()

在此方法的位置，详情视图就会被渲染到这里。


依赖注入 Dependency Injection 这也是ASP.NET Core的新特性。在扩展你的视图的时候，通过 @inject 指令使用依赖注入，这是一个非常大改进。

函数 @Functions 或 @code 都可以在一个 ASP.NET MVC 项目中定义一些功能函数，@code 用来插入代码块或定义视图类的成员方法：

    @functions
    {
        public string ReverseString(string input)
        {
            return String.Join("", input.Reverse());
        }
    }



### Sections 区块

有时候子视图中想在主视图中显示一部分 html 代码，比如 javascript 代码或者是 css，这个时候就可以使用 Sections， 通常情况下在页面的结尾部分。

在主视图中 `_Layout.cshtml` 定义一个 Javascripts Section：

    @RenderSection("scripts", required: false)

有一个 required 参数来声明这个 Section 是否必须的，然后你就可以在子视图中这样使用：

    @section scripts
    {
        <script>
            $(function() {
                // some more js code here;
            });
        </script>
    }

如果你使用嵌套的布局，你可能需要嵌套这个区域。意思就是你在Section里面嵌套调用RenderSection():

    @section scripts
    {
        @RenderSection("scripts", required: false)
    }


### Partial View 定制

Partial View 顾名思义就是 Html 代码片段，可以用 Partial View 把部分的 HTML 或显示逻辑包装起来，方便复用。

Partial View 需要放在特定目录下，任何 Controlller 下的 Action 或 View 都可以载入。运行时对视图搜索路径如下，视图组件默认名称为 Default.cshtml，如果按名称（无文件扩展名）引用分部视图，则按所述顺序搜索以下位置：

- Razor Page 项目：

    - 当前正在执行页面的文件夹
    - 该页面文件夹上方的目录图
    - /Shared
    - /Pages/Shared
    - /Views/Shared

- MVC 项目：

    - /Areas/<Area-Name>/Views/<Controller-Name>
    - /Areas/<Area-Name>/Views/Shared
    - /Views/Shared
    - /Pages/Shared

当分部视图位于不同的文件夹中时，允许使用具有相同文件名的不同分部视图。

当按名称（无文件扩展名）引用分部视图且分部视图出现在调用方文件所在的文件夹中时，调用方文件夹中的分部视图会提供分部视图。 如果调用方文件夹中不存在分部视图，则会从 Shared 文件夹中提供共享分部视图或默认分部视图。

分部视图可以链接到分部视图，如果不是由调用形成循环引用，则可以调用另一个分部视图。 相对路径始终相对于当前文件，而不是相对于文件的根视图或父视图。

分部助手标签会异步呈现内容并使用类似 HTML 的语法：

    <partial name="_PartialName" />
    <partial name="_PartialName.cshtml" />

当存在文件扩展名时，助手标签会引用分部视图，该视图必须与调用分部视图的标记文件位于同一文件夹中。

以下示例从应用程序根目录引用分部视图。 以波形符斜杠或斜杠开头的路径指代应用程序根目录，Razor Page 或 MVC 中使用：

    <partial name="~/Views/Folder/_PartialName.cshtml" />
    <partial name="/Views/Folder/_PartialName.cshtml" />

以下示例引用使用相对路径的分部视图：

    <partial name="../Account/_PartialName.cshtml" />


需要从父视图中获取用户列表的数据，然后在需要使用它的地方，通过相关方法输出：

    @{ await Html.RenderPartialAsync("Users", Model.Users);}

如果你的分部视图没有定义用户模型，你就不需要传第二个参数。

    @Html.Partial("_Partial.cshtml", new ViewDataDictionary { { "VariableName", "some value" } })

    @{
        string valuePassedIn = this.ViewData.ContainsKey("VariableName") ? this.ViewData["VariableName"].ToString() : string.Empty;
    }

要异步使用，最佳做法是使用 PartialAsync, 返回包含在 Task<TResult> 中的 IHtmlContent 类型。 通过 @await 字符前缀来引用该方法：

    @await Html.PartialAsync("_PartialName")

当存在文件扩展名时，HTML 帮助程序会引用分部视图，该视图必须与调用分部视图的标记文件位于同一文件夹中：

    @await Html.PartialAsync("_PartialName.cshtml")



### View Components 视图组件

视图组件 ViewComponents 是 ASP.NET Core 一个特色，类似于以前的用户控件。


有时候你需要做一些分部视图的事情，但是又包含一些业务逻辑在里面。在过去，你可以使用 ChildAction 渲染结果到一个视图中，但是，在 ASP.NET Core 改进了新方式来做这件事情。它类似于在 MVC 中的一种迷你的 MVC，也就是说他们可以有自己的 Controller，和单个的 Action 及 view。ViewComponents 是完全独立于你的当前视图的，但是可以通过你当前的视图传输数据。

    public class Top20TagsViewComponent : ViewComponent 
    { 
        private readonly ITagService _tagService; 

        public Top20TagsViewComponent(ITagService tagService) 
        { 
            _tagService = tagService; 
        } 

        public IViewComponentResult Invoke() 
        { 
             var tags = _tagService.LoadTop20Tags(); 
             var models = tags.Select( 
                new TagViewModel 
                { 
                    Id = tag.Id, 
                    Name = tag.Name 
                }); 
            return View(models); 
        } 
    }

留意构造函数中的 TTagService，它会由默认 IoC 容器执行依赖注入填充，不用自己去管。

然后，给视图组件一个配套的模板文件，保存在特定的目录中：

    /Views/Shared/Components/
    /Shared/Components/Top20Tags/Default.cshtml

模板内容如下：

    @model IEnumerable<DotNetFn.ViewComponents.TagViewModel>

    @if (Model.Any()) 
    { 
        <ul> 
            @foreach (var tag in Tags) 
            { 
                <li> 
                    [@tag.Id] @tag.Name 
                </li> 
            } 
        </ul> 
    }

在其它页面中调用它，来渲染一个 ViewComponents:

    @Component.Invoke("Top10Articles");

可以给视图组件文件好听的改名，而不一定要用默认的名字，可以在控制器中使用视图方法调用，还有给组件模板传送数据：

    return View("TheNicerName", models);


组件 Invoke 方法还可以接收参数，在 @Component.Invoke() 调用时，带上数据就可以：

    public IViewComponentResult Invoke(int count)     
    { 
        var tags = _tagService.LoadTopTags().Take(count);     
        var models = tags.Select(tag => 
            new TagViewModel 
            { 
                Id = tag.Id, 
                Name = tag.Name 
            }); 
         return View(models); 
    } 

像这样调用：

    @await Component.InvokeAsync("TopTags", 10);



### Helpers 助手标签定制


使用 HtmlHelpers 可以创建你自己的扩展方法来扩展 Razor 语法：

    public static class HtmlHelperExtensions
    {
        public static HtmlString MyOwnHtmlHelper(this HtmlHelper helper, string message)
        {
            return new HtmlString($"<span>{message}<span>");
        }
    }

在你的视图中，创建一个可重用的部分是非常有用的，它比分部视图多包含了一些业务逻辑。比 HTMLHelpers 扩展更好的是助手标签 TagHelpers，但是在扩展你视图的时候，HTMLHelpers 仍然有它自己的一些适用的地方。


标签助手 TagHelper 这是 ASP.NET Core 非常好的一个新特性。系统自带的助手标签基本满足大量的应用场景，但是可以扩展自己小助手，它看起来像一个原生的HTML标签一样。 在 ASP.NET Core MV C中你应该使用 TagHelpers 来替换 HtmlHelpers，因为它们更加的简洁和容易使用。另一个巨大的好处就是依赖注入，在 HtmlHelpers 中是使用不了的，因为 HtmlHelpers 扩展的都是静态内容。 但 TagHelpers 是一个公共类，我们可以很容易的在它的构造函数中注入服务。

下面是一个很简单的小示例，来展示怎么样定义一个TagHelper：

    [TargetElement("hi")] 
    public class HelloTagHelper : TagHelper 
    { 
        public override void Process(TagHelperContext context, TagHelperOutput output) 
        { 
            output.TagName = "p"; 
            output.Attributes.Add("id", context.UniqueId); 

            output.PreContent.SetContent("Hello "); 
            output.PostContent.SetContent(string.Format(", time is now: {0}",  
                    DateTime.Now.ToString("HH:mm"))); 
        } 
    }

这里定义了一个叫做 hi 的标签，它以 HTML 标记来呈现当前时间到 p 标签，使用参考:

    <hi>John Smith</hi>

    <p>Hello John Smith, time is now: 18:55</p>

ASP.NET Core MVC 已经默认提供了很多 TagHelpers 来替换以前的 HtmlHelpers。例如 ActionLink 已经被新的 TagHelper 所替换：

    @Html.ActionLink(“About me”, “About”, “Home”)

新的 TagHelper 像这样来创建一个 link：

    <a asp-controller=”Home” asp-action=”About”>About me</a>

以上两种方式来创建一个同样的 a 标签：

    <a href=”/Home/About”>About me</a>

可以看到，TagHelpers 看起来更像原生的HTML，他们在视图中更加的直观，更高的可读性，并且更容易使用。





## Razor Page Filter 页面筛选器
-[Razor Page Filter 页面筛选器](https://docs.microsoft.com/zh-cn/aspnet/core/mvc/controllers/filters?view=aspnetcore-3.1)

通过使用 ASP.NET Core 中的筛选器，可在请求处理管道中的特定阶段之前或之后运行代码。**
内置筛选器处理任务，例如：

- 授权（防止用户访问未获授权的资源）。
- 响应缓存（对请求管道进行短路出路，以便返回缓存的响应）。

可以创建自定义筛选器，用于处理横切关注点。 横切关注点的示例包括错误处理、缓存、配置、授权和日志记录。 筛选器可以避免复制代码。 例如，错误处理异常筛选器可以合并错误处理。

本文档适用于 Razor Pages、API 控制器和具有视图的控制器。 筛选器无法直接与 Razor 组件一起使用。 筛选器只能在以下情况下间接影响组件：

- 该组件嵌入在页面或视图中。
- 页面或控制器/视图使用此筛选器。

每种筛选器类型都在筛选器管道中的不同阶段执行：

- Authorization filters 

    授权筛选器最先运行，用于确定是否已针对请求为用户授权。 如果请求未获授权，授权筛选器可以让管道短路。

- Resource filters 

    资源筛选器：

    - 授权后运行。
    - OnResourceExecuting 在筛选器管道的其余阶段之前运行代码。 例如，OnResourceExecuting 在模型绑定之前运行代码。
    - OnResourceExecuted 在管道的其余阶段完成之后运行代码。

- Action filters 

    操作筛选器：

    - 在调用操作方法之前和之后立即运行代码。
    - 可以更改传递到操作中的参数。
    - 可以更改从操作返回的结果。
    - 不可在 Razor Pages 中使用。

- Exception filters 

    异常筛选器在向响应正文写入任何内容之前，对未经处理的异常应用全局策略。

- Result filters 

    结果筛选器在执行操作结果之前和之后立即运行代码。 仅当操作方法成功执行时，它们才会运行。 对于必须围绕视图或格式化程序的执行的逻辑，它们很有用。

Razor 页面筛选器 IPageFilter 和 IAsyncPageFilter 允许 Razor Pages 在运行 Razor 页面处理程序的前后运行代码。 Razor 页面筛选器与 ASP.NET Core MVC 操作筛选器类似，但它们不能应用于单个页面处理程序方法。

Razor 页面筛选器：

- 在选择处理程序方法后但在模型绑定发生前运行代码。
- 在模型绑定完成后，执行处理程序方法前运行代码。
- 在执行处理程序方法后运行代码。
- 可在页面或全局范围内实现。
- 无法应用于特定的页面处理程序方法。
- 可以用依赖项注入 (DI) 填充构造函数依赖项。 请参阅 ServiceFilterAttribute 和 TypeFilterAttribute。

虽然页构造函数和中间件允许在处理程序方法执行之前执行自定义代码，但只有 Razor 页面筛选器允许访问 HttpContext 和页面。 中间件可以访问 HttpContext，但不能访问“页面上下文”。 筛选器具有 FilterContext 派生参数，该参数提供对 HttpContext 的访问权限。

Razor 页面筛选器提供的同步方法/异步方法可在全局或页面级应用：

同步方法：

- OnPageHandlerSelected 在选择处理程序方法后，但在模型绑定发生之前调用。
- OnPageHandlerExecuting    在模型绑定完成后，执行处理程序方法之前调用。
- OnPageHandlerExecuted 在执行处理器方法后，生成操作结果前调用。

异步方法：

- OnPageHandlerSelectionAsync   在选择处理程序方法后，但在模型绑定发生前，进行异步调用。
- OnPageHandlerExecutionAsync   在调用处理程序方法前，但在模型绑定结束后，进行异步调用。

筛选器接口的同步和异步版本任意实现一个，而不是同时实现 。 该框架会先查看筛选器是否实现了异步接口，如果是，则调用该接口。 如果不是，则调用同步接口的方法。 如果两个接口都已实现，则只会调用异步方法。 对页面中的替代应用相同的规则，同步替代或异步替代只能任选其一实现，不可二者皆选。


全局实现 Razor 页面筛选器 IAsyncPageFilter：


    public class SampleAsyncPageFilter : IAsyncPageFilter
    {
        private readonly IConfiguration _config;

        public SampleAsyncPageFilter(IConfiguration config)
        {
            _config = config;
        }

        public Task OnPageHandlerSelectionAsync(PageHandlerSelectedContext context)
        {
            var key = _config["UserAgentID"];
            context.HttpContext.Request.Headers.TryGetValue("user-agent",
                                                            out StringValues value);
            ProcessUserAgent.Write(context.ActionDescriptor.DisplayName,
                                   "SampleAsyncPageFilter.OnPageHandlerSelectionAsync",
                                   value, key.ToString());

            return Task.CompletedTask;
        }

        public async Task OnPageHandlerExecutionAsync(PageHandlerExecutingContext context,
                                                      PageHandlerExecutionDelegate next)
        {
            // Do post work.
            await next.Invoke();
        }
    }

在前面的代码中，ProcessUserAgent.Write 是用户提供的与用户代理字符串一起使用的代码。

以下代码启用 Startup 类中的 SampleAsyncPageFilter：

    public void ConfigureServices(IServiceCollection services)
    {
        services.AddRazorPages()
            .AddMvcOptions(options =>
            {
                options.Filters.Add(new SampleAsyncPageFilter(Configuration));
            });
    }

以下代码调用 AddFolderApplicationModelConvention，将 SampleAsyncPageFilter 仅应用于 /Movies 中的页面 ：

    public void ConfigureServices(IServiceCollection services)
    {
        services.AddRazorPages(options =>
        {
            options.Conventions.AddFolderApplicationModelConvention(
                "/Movies",
                model => model.Filters.Add(new SampleAsyncPageFilter(Configuration)));
        });
    }

以下代码实现同步的 IPageFilter：

    public class SamplePageFilter : IPageFilter
    {
        private readonly IConfiguration _config;

        public SamplePageFilter(IConfiguration config)
        {
            _config = config;
        }

        public void OnPageHandlerSelected(PageHandlerSelectedContext context)
        {
            var key = _config["UserAgentID"];
            context.HttpContext.Request.Headers.TryGetValue("user-agent", out StringValues value);
            ProcessUserAgent.Write(context.ActionDescriptor.DisplayName,
                                   "SamplePageFilter.OnPageHandlerSelected",
                                   value, key.ToString());
        }

        public void OnPageHandlerExecuting(PageHandlerExecutingContext context)
        {
            Debug.WriteLine("Global sync OnPageHandlerExecuting called.");
        }

        public void OnPageHandlerExecuted(PageHandlerExecutedContext context)
        {
            Debug.WriteLine("Global sync OnPageHandlerExecuted called.");
        }
    }

以下代码启用 SamplePageFilter：

    public void ConfigureServices(IServiceCollection services)
    {
        services.AddRazorPages()
            .AddMvcOptions(options =>
            {
                options.Filters.Add(new SamplePageFilter(Configuration));
            });
    }


通过重写筛选器方法实现 Razor 页面筛选器，参考以下代码替代异步 Razor 页面筛选器：

    public class IndexModel : PageModel
    {
        private readonly IConfiguration _config;

        public IndexModel(IConfiguration config)
        {
            _config = config;
        }

        public override Task OnPageHandlerSelectionAsync(PageHandlerSelectedContext context)
        {
            Debug.WriteLine("/IndexModel OnPageHandlerSelectionAsync");
            return Task.CompletedTask;
        }

        public async override Task OnPageHandlerExecutionAsync(PageHandlerExecutingContext context, 
                                                               PageHandlerExecutionDelegate next)
        {
            var key = _config["UserAgentID"];
            context.HttpContext.Request.Headers.TryGetValue("user-agent", out StringValues value);
            ProcessUserAgent.Write(context.ActionDescriptor.DisplayName,
                                   "/IndexModel-OnPageHandlerExecutionAsync",
                                    value, key.ToString());

            await next.Invoke();
        }
    }


实现筛选器属性
基于属性的内置筛选器 OnResultExecutionAsync 可以进行子类化。 以下筛选器向响应添加标头：

    using System.Threading.Tasks;
    using Microsoft.AspNetCore.Mvc.Filters;

    namespace PageFilter.Filters
    {
        public class AddHeaderAttribute  : ResultFilterAttribute
        {
            private readonly string _name;
            private readonly string _value;

            public AddHeaderAttribute (string name, string value)
            {
                _name = name;
                _value = value;
            }

            public override void OnResultExecuting(ResultExecutingContext context)
            {
                context.HttpContext.Response.Headers.Add(_name, new string[] { _value });
            }
        }
    }

以下代码应用 AddHeader 属性：

    using Microsoft.AspNetCore.Mvc.RazorPages;
    using PageFilter.Filters;

    namespace PageFilter.Movies
    {
        [AddHeader("Author", "Rick")]
        public class TestModel : PageModel
        {
            public void OnGet()
            {

            }
        }
    }

使用浏览器开发人员工具等工具来检查标头。 在响应标头下，将显示 author: Rick 。有关将筛选器管道与筛选器短路的说明，请参阅取消和设置短路。


授权筛选器属性 [Authorize] 可应用于 PageModel，可以设置 string policy 参数：

    using Microsoft.AspNetCore.Authorization;
    using Microsoft.AspNetCore.Mvc;
    using Microsoft.AspNetCore.Mvc.RazorPages;

    namespace PageFilter.Pages
    {
        [Authorize]
        public class ModelWithAuthFilterModel : PageModel
        {
            public IActionResult OnGet() => Page();
        }
    }




## Razor Form 数据绑定特性
- [Razor Page 介绍](https://docs.microsoft.com/zh-cn/aspnet/core/razor-pages/?view=aspnetcore-3.1)
- [ASP.NET Core 中的会话和状态管理](https://docs.microsoft.com/zh-cn/aspnet/core/fundamentals/app-state?view=aspnetcore-3.1#tempdata)

再来看看一个功能完整一点的表单页面：



透过 PageModel 暴露的 ViewData 和 TempData 两个字典属性，结合 ViewDataAttribute 和 TempDataAttribute 属性特性，可以很方便地将前端页面表单回传的数据绑定到 PageModel 的属性中。


透过 ViewData 特性结合 ViewDataAttribute 属性特性将数据传递到页面，PageModel 中具有 `[ViewData]` 特性的属性将从 ViewDataDictionary 保存和加载数据。

在下面的示例中，AboutModel 将 [ViewData] 特性应用于 Title 属性：

    public class AboutModel : PageModel
    {
        [ViewData]
        public string Title { get; } = "About";

        public void OnGet()
        {
        }
    }

在页面中，以模型属性的形式访问 Title 属性：

    <h1>@Model.Title</h1>

在布局中，从 ViewData 字典读取标题：

    <!DOCTYPE html>
    <html lang="en">
    <head>
        <title>@ViewData["Title"] - WebApplication</title>
        ...

ASP.NET Core 公开 Razor Pages TempData 或控制器 TempData。 在另一个请求读取数据之前，此属性将读取此数据。 Keep(String) 和 Peek(string) 方法可用于检查数据，而无需在请求结束时删除。 Keep 将标记字典中的所有项以进行保留。

下面的代码使用 TempData 设置 Message 的值：

    public class CreateDotModel : PageModel
    {
        private readonly AppDbContext _db;

        public CreateDotModel(AppDbContext db)
        {
            _db = db;
        }

        [TempData]
        public string Message { get; set; }

        [BindProperty]
        public Customer Customer { get; set; }

        public async Task<IActionResult> OnPostAsync()
        {
            if (!ModelState.IsValid)
            {
                return Page();
            }

            _db.Customers.Add(Customer);
            await _db.SaveChangesAsync();
            Message = $"Customer {Customer.Name} added";
            return RedirectToPage("./Index");
        }
    }

Index.cshtml 文件中的以下标记使用 TempData 显示 Message 的值。

    <h3>Msg: @Model.Message</h3>

Index.cshtml.cs 页面模型将 [TempData] 属性应用到 Message 属性 。
    
    [TempData]
    public string Message { get; set; }


基于 cookie 的 TempData 提供程序 CookieTempDataProvider 是默认用于存储 cookie 中的 TempData。
使用由 Base64UrlTextEncoder 编码的 IDataProtector 对 Cookie 数据进行加密，然后进行分块。 由于加密和分块，最大 Cookie 大小小于 4096 个字节。 未压缩 Cookie 数据，因为压缩加密的数据会导致安全问题，如 CRIME 和 BREACH 攻击。 

大多数 Web 客户端（如 Web 浏览器）针对每个 Cookie 的最大大小和 Cookie 总数强制实施限制。 使用 Cookie TempData 提供程序时，请验证应用未超过这些限制。 考虑数据的总大小。 解释加密和分块导致的 Cookie 大小增加。

默认情况下启用基于 Cookie 的 TempData 提供程序。 若要启用基于会话的 TempData 提供程序，请配置 Startup 使用相应扩展方法，调用 AddSessionStateTempDataProvider：

    services.AddControllersWithViews()
        .AddSessionStateTempDataProvider();
    services.AddRazorPages()
        .AddSessionStateTempDataProvider();

    app.UseSession();





## Logging 日志

默认提供日志服务，记录 Information 级别消息，在 Windows 系统的应用程序日志上可以查看。

Trace -> Debug->  Information -> Warning->  Error->  Critical

日志组件拓展

- 文件文本日志 Huanent.Logging.File
- 文件文本日志 UI 插件 Huanent.Logging.File.UI
- 自定义介质日志 Huanent.Logging.Abstract

Microsoft.Extensions.Logging.File 文件文本日志基础类
Microsoft.Extensions.Logging.File.UI 文件文本日志 UI 插件基础类
Microsoft.Extensions.Logging.Abstract 自定义介质日志


按需要安装日志服务包：

    dotnet add package Huanent.Logging.File
    dotnet add package Huanent.Logging.File.UI
    dotnet add package Huanent.Logging.Abstract


- 配置 File 日志

    在 Program.cs 文件中添加：

         .UseStartup<Startup>()
             .ConfigureLogging(builder => builder.AddFile()) 

    appsettings.json 文件添加 File 节点，如果忽略会将所有类别日志都输出到文本文件：

          "Logging": {
            "LogLevel": {
              "Default": "Trace",
              "Microsoft": "Trace",
              "Microsoft.Hosting.Lifetime": "Trace"
            }
          },
          "File": {
            "LogLevel": {
              "Default": "Trace",
              "Microsoft": "Trace",
              "Microsoft.Hosting.Lifetime": "Trace"
            }
          },

- 配置 File UI 插件

    修改 Startup.cs:

            services.AddLoggingFileUI();

            app.UseStaticFiles();
            app.UseMvc();

    启动网站，访问页面 http://xxxxx:xx/logging 即可打开页面查看日志

- Abstract 自定义介质日志

    可以通过实现 ILoggerWriter 来自定义日志输出保存的介质。
    注意！MyLogWriter 对象在 DI 容器中以 Singleton 单例形式存在！
    注意！请勿在 MyLogWriter 中进行会日志输出的操作，那可能会导致循环递归，栈溢出！

        public class MyLogWriter : ILoggerWriter
        {
            public void WriteLog(LogLevel level, string message, string name, Exception exception, EventId eventId)
            {
                // 在此处自定义日志的保存方式，保存到数据库，云等
            }
        }

    在Program.cs文件中添加：

        .UseStartup<Startup>()
            .ConfigureLogging(builder => builder.AddAbstract<MyLogWriter>()) 

    配置 appsettings.json 文件，添加 Abstract 节点，如果忽略会将所有类别日志都输出：

        "Logging": {
            "IncludeScopes": false,
            "Debug": {
                "LogLevel": {
                    "Default": "Warning"
                }
            },
            "Console": {
                "LogLevel": {
                    "Default": "Warning"
                }
            },
            "Abstract": {
                "LogLevel": {
                    "Default": "Warning"
                }
            }
        }



## Tag Helpers & HtmlHelper 助手标签
- https://docs.microsoft.com/en-us/aspnet/core/mvc/views/tag-helpers/built-in/?view=aspnetcore-3.1
- https://docs.microsoft.com/en-us/dotnet/api/microsoft.aspnetcore.mvc.rendering.ihtmlhelper-1?view=aspnetcore-3.1
- https://docs.microsoft.com/zh-cn/aspnet/core/mvc/views/working-with-forms?view=aspnetcore-3.1

助手标签使服务器端代码参与 Razor 页面的创建和呈现 HTML 元素。

助手标签将减少视图中 Razor HTML 和 C# 之间的显式转换。 在很多情况下，HTML 标签为特定助手标签提供了一种替代方法，但助手标签不会替代 HTML 标签，且并非每个 HTML 标签都有对应的助手标签，认识到这点也很重要。


使用 HtmlHelper 和助手标签一样，都是用来生成 HTML 标签的工具，但是助手标签设计更合理，推荐使用。

@Html.Raw 输出不进行编码，但呈现为 HTML 标记。

警告： 对未经审查的用户输入使用 HtmlHelper.Raw 会带来安全风险。 用户输入可能包含恶意的 JavaScript 或其他攻击。 审查用户输入比较困难。 应避免对用户输入使用 HtmlHelper.Raw。

    @Html.Raw("<span>Hello World</span>")

    <span>Hello World</span>

假设模型定义如下，使用 @Html.DisplayNameFor 与 @Html.DisplayFor 生成 HTML 标签：

    [Table("View_Product")]
    [DisplayName("Course")]
    public partial class Courses
    {
        [DisplayName("Major Course")]   
        public bool IsMajor { get; set; }
        ...
    }   

那么以下 HtmlHelper 和对应 HTML 标签生成如下，@Html.DisplayFor 会根据数据类型生成不同的 HTML 标签：

    <th>@Html.DisplayNameFor(model => model.Courses[0].IsMajor)</th>

    <th>Major Course</th>

    @Html.DisplayFor(modelItem => model.Courses[0].IsMajor)

    <select class="tri-state list-box" disabled="disabled">
        <option selected="selected" value="">
            Not Set
        </option>
        <option value="true">
            True
        </option>
        <option value="false">
            False
        </option>
    </select>


列如，使用 LabelTagHelper 助手标签，以下两种写法等价，Razor 会将它们转换成对应的 HTML 标签输出到客户端：

    @Html.Label("FirstName", "First Name:", new {@class="caption"})

    <label class="caption" asp-for="FirstName"></label>

@ 符号指示 Razor 解析器这是代码的开头，接下来的两个参数是字符串，最后一个参数是用于表示属性的匿名对象。 由于 class 是 C# 中的保留关键字，因此要使用 @ 符号强制 C# 将 @class= 解释为符号，HTML 标签属性名称。 

HTML 友好的开发体验大多数情况下，Razor 使用助手标签的标记看起来像标准 HTML。 熟悉 HTML/CSS/JavaScript 的前端，可以直接使用 Razor C# 语法进行编辑而不用特别学习。

助手标签使用仅在服务器上可用的信息，可提高生产力，并能生成更稳定、可靠和可维护的代码。

例如，过去更新图像时，必须在更改图像时更改图像名称。 出于性能原因，要主动缓存图像，而若不更改图像的名称，客户端就可能获得过时的副本。 以前，编辑完图像后，必须更改名称，而且需要更新 Web 应用中对该图像的每个引用。内置 ImageTagHelper 可以自动执行此操作。 ImageTagHelper 可将版本号追加到图像名称，这样每当图像出现更改时，服务器都会自动为该图像生成新的唯一版本。 

大多数内置助手标签以标准 HTML 元素为目标，为该元素提供服务器端属性。 例如，`<input>` 用于包含 `asp-for` 特性，经常用于带有数据模型的视图文件中。 此特性将指定模型属性的名称，并提取至所呈现的 HTML。 请考虑 Razor Page 具有以下数据模型：

    public class Movie
    {
        public int ID { get; set; }
        public string Title { get; set; }
        public DateTime ReleaseDate { get; set; }
        public string Genre { get; set; }
        public decimal Price { get; set; }
    }

以下 Razor 标记：

    <label asp-for="Movie.Title"></label>

则会生成以下 HTML：

    <label for="Movie_Title">Title</label>

通过 LabelTagHelper 中的 For 属性，可使用 asp-for 特性。


助手标签有三个相关指令，还有感叹号用于临时禁止助手标签。

- @addTagHelper 向视图提供助手标签。
- @removeTagHelper  从视图中删除以前添加的助手标签。
- @tagHelperPrefix  指定前缀使用助手标签。

通过助手标签的引用统一设置在 `_ViewImports.cshtml` 公共模板文件中。

    @using AuthoringTagHelpers
    @addTagHelper *, Microsoft.AspNetCore.Mvc.TagHelpers
    @addTagHelper *, AuthoringTagHelpers

退出字符 ! 可在元素级别禁用助手标签，例如，在 `<span>` 中禁用 Email 验证：

    <!span asp-validation-for="Email" class="text-danger"></!span>

@tagHelperPrefix 指令可指定一个标记前缀字符串，以启用助手标签支持并阐明助手标签用途。 例如:

    @tagHelperPrefix th:

    <th:label for="Movie_Title">Title</th:label>


不允许在元素的属性外区域中出现 C#，例如，以下代码第一行无效：

    <input asp-for="LastName" @(Model?.LicenseId == null ? "disabled" : string.Empty) />

    <input asp-for="LastName" disabled="@(Model?.LicenseId == null)" />


内置助手标签，Built-in ASP.NET Core Tag Helpers


### Anchor Tag Helper

| 属性    | 说明    |
| :-----    | :-----    |
| asp-controller    | 控制器的名称，用于生成 URL 的控制器部分。   |
| asp-action    | 操作方法的名称。  |
| asp-area  | 区域名称，用于目录分级。  |
| asp-page  | Razor Page 的名称。   |
| asp-page-handler  | Razor Page 处理程序的名称。   |
| asp-route | 指定路由的名称，用于创建直接链接到命名路由的 URL。   |
| asp-route-{value} | 单个 URL 路由值。 例如，asp-route-id="1234"。   |
| asp-all-route-data    | 所有路由值。支持创建键值对字典， 键是参数名称，值是参数值。    |
| asp-fragment  | URL 片段，即地址 # 号后面的部分。  |
| asp-protocol  | 用于在 URL 中指定协议（比如 https）。  |
| asp-host  | 在 URL 中指定主机名，如 asp-host="microsoft.com"。  |


需要注意，以下三类属性不能同时出现，因为它们是三种冲突的路由规则：

- asp-route
- asp-controller, asp-action
- asp-page, asp-page-handler

示例均使用 SpeakerController：

    using Microsoft.AspNetCore.Mvc;
    using System.Collections.Generic;
    using System.Linq;

    public class SpeakerController : Controller
    {
        private List<Speaker> Speakers =
            new List<Speaker>
            {
                new Speaker {SpeakerId = 10},
                new Speaker {SpeakerId = 11},
                new Speaker {SpeakerId = 12}
            };

        [Route("Speaker/{id:int}")]
        public IActionResult Detail(int id) =>
            View(Speakers.FirstOrDefault(a => a.SpeakerId == id));

        [Route("/Speaker/Evaluations", 
               Name = "speakerevals")]
        public IActionResult Evaluations() => View();

        [Route("/Speaker/EvaluationsCurrent",
               Name = "speakerevalscurrent")]
        public IActionResult Evaluations(
            int speakerId,
            bool currentYear) => View();

        public IActionResult Index() => View(Speakers);
    }

    public class Speaker
    {
        public int SpeakerId { get; set; }
    }

asp-controller 属性可分配用于生成 URL 的控制器部分，如果指定了 asp-controller 而未指定 asp-action 属性，则默认的 asp-action 值为与当前正在执行的视图关联的控制器操作。

    <a asp-controller="Speaker" asp-action="Index">All Speakers</a>

    <a href="/Speaker">All Speakers</a>

asp-action 属性值表示生成的 href 属性中包含的控制器操作名称。 如果未指定 asp-controller 属性，则使用默认控制器，该控制器调用执行当前视图的视图。 如果 asp-action 属性值为 Index，则不向 URL 追加任何操作，从而导致调用默认的 Index 操作。 asp-controller 引用的控制器中必须存在指定的（或默认的）操作。

    <a asp-controller="Speaker" asp-action="Evaluations">Speaker Evaluations</a>

    <a href="/Speaker/Evaluations">Speaker Evaluations</a>

asp-route 属性用于创建直接链接到命名路由的 URL。 使用路由属性，路由可以按控制器中所定义的命名路由建立映射关系：

    [Route("/Speaker/Evaluations", Name="speakerevals")]
    public IActionResult Evaluations() => View();

在相应的助手标签 asp-route 属性引用命名路由，就会生成指定上面定义的命名路由：

    <a asp-route="speakerevals">Speaker Evaluations</a>

    <a href="/Speaker/Evaluations">Speaker Evaluations</a>

如果除了 asp-route，还指定了 asp-controller 或 asp-action，则可能不会生成预期的路由。 为了避免发生路由冲突，不应将 asp-route 与 asp-controller 和 asp-action 属性结合使用。


asp-page 和 asp-page-handler 是用于 Razor 页面的路由属性，使用它生成指向 Razor Page 的路由地址。 使用正斜杠 / 作为前缀，再跟着页面，可创建 URL。

以下示例指向 "与会者Razor " 页：

    <a asp-page="/Attendee">All Attendees</a>

    <a href="/Attendee">All Attendees</a>

asp-page 与 asp-route、asp-controller、asp-action 三者互斥，但是，asp-page 可与 asp-route-{value} 和  asp-controller 结合使用以控制路由，如以下标记所示：

    <a asp-page="/Attendee" asp-route-attendeeid="10">View Attendee</a>

    <a href="/Attendee?attendeeid=10">View Attendee</a>

asp-page-handler 设置用于链接到特定的页处理程序

    public void OnGetProfile(int attendeeId)
    {
        ViewData["AttendeeId"] = attendeeId;

        // code omitted for brevity
    }

如果没有相应的页面，那么标签生成时 href 属性中就会在查询字符串中包含 asp-page 指定的值，例如，没有 Delete 这个页面，标签设置和生成的 URL 如下：

    <a asp-page="/Delete">All Attendees</a>

    <a href="/Home?page=%2FDelete">All Attendees</a>

页模型的关联标记链接到 OnGetProfile 页处理程序。 注意，asp-page-handler 属性值中省略了页处理程序方法名称的 On<Verb> 前缀。 如果方法是异步的，也省略 Async 后缀。

    <a asp-page="/Attendee"
       asp-page-handler="Profile"
       asp-route-attendeeid="12">Attendee Profile</a>

    <a href="/Attendee?attendeeid=12&handler=Profile">Attendee Profile</a>


asp-fragment 属性可定义要追加到 URL 的片段，链接标签会添加哈希字符 (#)。 请考虑以下标记：

    <a asp-controller="Speaker"
       asp-action="Evaluations"
       asp-fragment="SpeakerEvaluations">Speaker Evaluations</a>

    <a href="/Speaker/Evaluations#SpeakerEvaluations">Speaker Evaluations</a>

生成客户端应用时，哈希标记很有用。 它们可用于在 JavaScript 中轻松地执行标记和搜索等操作。



对于区域目录 asp-area，考虑以下这样的目录结构：

    + wwwroot
    + Areas
    |   - Sessions
    |       - Pages页
    |           _Viewstart.cshtml
    |           Index.cshtml
    |           Index.cshtml.cs
    + Pages

要建立指向 Index.cshtml 页面的标记为：

    <a asp-area="Sessions" asp-page="/Index">View Sessions</a>

    <a href="/Sessions">View Sessions</a>




asp-route-{value} 属性可实现通配符路由前缀， {value} 占位符的所有值都解释为潜在的路由参数。 如果找不到默认路由，则将此路由前缀作为请求参数和值追加到生成的 href 属性。 否则，将在路由模板中替换它。
考虑以下控制器操作：

    public IActionResult AnchorTagHelper(int id)
    {
        var speaker = new Speaker
        {
            SpeakerId = id
        };

        return View(speaker);
    }

在 Startup.Configure 中定义 MapRoute 默认路由模板，添加上 `{id?}`：

    app.UseMvc(routes =>
    {
        // need route and attribute on controller: [Area("Blogs")]
        routes.MapRoute(
            name: "mvcAreaRoute",
            template: "{area:exists}/{controller=Home}/{action=Index}");

        // default route for non-areas
        routes.MapRoute(
            name: "default",
            template: "{controller=Home}/{action=Index}/{id?}");
    });

MVC 视图就可以使用 `asp-route-id` 向路由提供参数，如下所示：

    @model Speaker
    <!DOCTYPE html>
    <html>
    <body>
        <a asp-controller="Speaker"
           asp-action="Detail"
           asp-route-id="@Model.SpeakerId">SpeakerId: @Model.SpeakerId</a>
    </body>
    </html>

默认路由的 `{id?}` 占位符得以匹配，生成的 URL 中 id 参数就不会以查询字符串的形式表达：

    <a href="/Speaker/Detail/12">SpeakerId: 12</a>

对于其它没有在路由配置的参数，比如 asp-route-speakerid：

    <a asp-controller="Speaker"
       asp-action="Detail"
       asp-route-speakerid="@Model.SpeakerId">SpeakerId: @Model.SpeakerId</a>

生成以下 HTML，因为路由设置中匹配不到 speakerid 而生成的参数就以查询字符串的形式出现：

    <a href="/Speaker/Detail?speakerid=12">SpeakerId: 12</a>

如果 asp-controller 或 asp-action 均未指定，则会执行与 asp-route 属性中相同的默认处理。



asp-all-route-data 属性支持创建键值对字典。 键是参数名称，值是参数值。
在下面的示例中，将对字典进行初始化并传递给视图。 或者，也可以使用模型传入数据。

    @{
        var parms = new Dictionary<string, string>
        {
            { "speakerId", "11" },
            { "currentYear", "true" }
        };
    }

    <a asp-route="speakerevalscurrent"
       asp-all-route-data="parms">Speaker Evaluations</a>

前面的代码生成以下 HTML：

    <a href="/Speaker/EvaluationsCurrent?speakerId=11&currentYear=true">Speaker Evaluations</a>

平展 asp-all-route-data 字典，以生成满足重载 Evaluations 操作要求的查询字符串：

    [Route("/Speaker/EvaluationsCurrent", Name="speakerevalscurrent")]
    public IActionResult Evaluations(
        int speakerId,
        bool currentYear) => View();

如果字典中的任何键匹配路由参数，则将根据需要在路由中替换这些值。 其他不匹配的值作为请求参数生成。




- Cache Tag Helper

- Component Tag Helper

- Distributed Cache Tag Helper

- Environment Tag Helper

### Form Tag Helper

表单标记助手为 MVC 控制器操作或命名路由生成 HTML 表单的 action 特性值。

生成隐藏的请求验证令牌，防止跨站点请求伪造，在 HTTP Post 操作方法中与 [ValidateAntiForgeryToken] 属性配合使用。

提供 asp-route-<Parameter Name> 属性，其中 <Parameter Name> 添加到路由值。 Html.BeginForm 和 Html.BeginRouteForm 的 routeValues 参数提供类似的功能。

    <form asp-controller="Demo" asp-action="Register" method="post">
        <!-- Input and Submit elements -->
    </form>

上述表单助手标签生成以下 HTML：

    <form method="post" action="/Demo/Register">
        <!-- Input and Submit elements -->
        <input name="__RequestVerificationToken" type="hidden" value="<removed for brevity>">
    </form>

Form Action Tag Helper

| 属性    | 说明    |
| :---  | :---  |
| asp-controller    | 控制器的名称，用于生成 URL 的控制器部分。   |
| asp-action    | 操作方法的名称。  |
| asp-area  | 区域名称，用于目录分级。  |
| asp-page  | Razor Page 的名称。   |
| asp-page-handler  | Razor Page 处理程序的名称。   |
| asp-route | 指定路由的名称，用于创建直接链接到命名路由的 URL。   |
| asp-route-{value} | 单个 URL 路由值。 例如，asp-route-id="1234"。   |
| asp-all-route-data    | 所有路由值。支持创建键值对字典， 键是参数名称，值是参数值。    |
| asp-fragment  | URL 片段，即地址 # 号后面的部分。  |


提交到控制器示例，选中输入或按钮时，下面的标记将窗体提交到 HomeController 的 Index 操作：

    <form method="post">
        <button asp-controller="Home" asp-action="Index">Click Me</button>
        <input type="image" src="..." alt="Or Click Me" asp-controller="Home" 
                                    asp-action="Index">
    </form>

生成 HTML：

    <form method="post">
        <button formaction="/Home">Click Me</button>
        <input type="image" src="..." alt="Or Click Me" formaction="/Home">
    </form>
    提交到页示例

以下标记将窗体提交到 About Razor Page：

    <form method="post">
        <button asp-page="About">Click Me</button>
        <input type="image" src="..." alt="Or Click Me" asp-page="About">
    </form>

生成 HTML：

    <form method="post">
        <button formaction="/About">Click Me</button>
        <input type="image" src="..." alt="Or Click Me" formaction="/About">
    </form>
    提交到路由示例


使用命名路由 asp-route，请考虑使用 /Home/Test 终结点：

    public class HomeController : Controller
    {
        [Route("/Home/Test", Name = "Custom")]
        public string Test()
        {
            return "This is the test page";
        }
    }

以下标记将窗体提交到 /Home/Test 终结点。

    <form method="post">
        <button asp-route="Custom">Click Me</button>
        <input type="image" src="..." alt="Or Click Me" asp-route="Custom">
    </form>

生成 HTML：

    <form method="post">
        <button formaction="/Home/Test">Click Me</button>
        <input type="image" src="..." alt="Or Click Me" formaction="/Home/Test">
    </form>


### Image Tag Helper

若要激活图像标记助手，`<img>` 元素需要有 src 属性，必须指向服务器上的物理静态文件。 如果 src 是一个远程 URI，则不会生成缓存破坏查询字符串参数。

如果使用 true 值和 src 属性指定 asp-append-version，则会调用图像助手标签。
下面的示例使用图像助手标签：

    <img src="~/images/asplogo.png" asp-append-version="true">

如果目录 /wwwroot/images/** 中存在静态文件，则生成的 html 与下面类似（哈希有所不同）：

    <img src="/images/asplogo.png?v=Kl_dqr9NVtnMdsM2MUg4qthUnWZm5T1fCEimBPWDNgM">


### Input Tag Helper

将 HTML `<input>` 元素绑定到 razor 视图中的模型表达式。

    <input asp-for="<Expression Name>">

为 asp-for 属性中指定的表达式名称生成 HTML 属性，包括 id 和 name。asp-for 属性值是 ModelExpression，并且是 lambda 表达式的右侧。 因此，asp-for="Property1" 在生成的代码中变成 m => m.Property1，这也是无需使用 Model 前缀的原因。 @ 字符可用作内联表达式的开头，并移到 m. 前面：

    @{
      var joe = "Joe";
    }

    <input asp-for="@joe">

生成以下 HTML：

    <input type="text" id="joe" name="joe" value="Joe">

使用集合属性时，asp-for="CollectionProperty[23].Member" 在 i 具有值 23 时生成与 asp-for="CollectionProperty[i].Member" 相同的名称。

在 ASP.NET Core MVC 计算 ModelExpression 的值时，它会检查多个源，包括 ModelState。 以 `<input type="text" asp-for="@Name">` 为例。 计算出的 value 属性是第一个非 null 值，属于：

- 带有 Name 键的 ModelState 条目。
- Model.Name 表达式的结果。

Html.TextBox、Html.TextBoxFor、Html.Editor 和 Html.EditorFor 与助手标签的功能存在重叠。 

Html.TextBox 和 Html.TextBoxFor 不会自动设置 type 属性，而助手标签会。 
Html.Editor 和 Html.EditorFor 处理集合、复杂对象和模板，而助手标签不会。
助手标签、Html.EditorFor 和 Html.TextBoxFor 是强类型（使用 lambda 表达式），而 Html.TextBox 和 Html.Editor 不是（使用表达式名称）。

@Html.Editor() 和 @Html.EditorFor() 在执行其默认模板时使用名为 htmlAttributes 的特殊 ViewDataDictionary 条目。 此行为可选择使用 additionalViewData 参数增强。 键 htmlAttributes 区分大小写。 键 htmlAttributes 的处理方式与传递到助手标签,例如 @Html.TextBox() 的 htmlAttributes 对象的处理方式类似。

    @Html.EditorFor(model => model.YourProperty, 
      new { htmlAttributes = new { @class="myCssClass", style="Width:100px" } })


Input 助手标签根据 .NET 类型设置 HTML type 属性。 下表列出一些常见的 .NET 类型和生成的 HTML 类型（并未列出每个 .NET 类型）。

| .NET 类型   | 输入类型 |
| :-------- | :------ |
| Bool  | type="checkbox" |
| String    | type="text" |
| DateTime  | type="datetime-local" |
| Byte  | type="number" |
| Int   | type="number" |
| Single、Double | type="number" |

下表显示助手标签会映射到特定输入类型的一些常见数据注释属性（并未列出每个验证属性）：

| Attribute | 输入类型 |
| :-------- | :------ |
| [EmailAddress]    | type="email" |
| [Url] | type="url" |
| [HiddenInput] | type="hidden" |
| [Phone]   | type="tel" |
| [DataType(DataType.Password)] | type="password" |
| [DataType(DataType.Date)] | type="date" |
| [DataType(DataType.Time)] | type="time" |

示例：

    using System.ComponentModel.DataAnnotations;

    namespace FormsTagHelper.ViewModels
    {
        public class RegisterViewModel
        {
            [Required]
            [EmailAddress]
            [Display(Name = "Email Address")]
            public string Email { get; set; }

            [Required]
            [DataType(DataType.Password)]
            public string Password { get; set; }
        }
    }

    @model RegisterViewModel

    <form asp-controller="Demo" asp-action="RegisterInput" method="post">
        Email:  <input asp-for="Email" /> <br />
        Password: <input asp-for="Password" /><br />
        <button type="submit">Register</button>
    </form>

上述代码生成以下 HTML：

    <form method="post" action="/Demo/RegisterInput">
        Email:
        <input type="email" data-val="true"
            data-val-email="The Email Address field is not a valid email address."
            data-val-required="The Email Address field is required."
            id="Email" name="Email" value=""><br>
        Password:
        <input type="password" data-val="true"
            data-val-required="The Password field is required."
            id="Password" name="Password"><br>
        <button type="submit">Register</button>
        <input name="__RequestVerificationToken" type="hidden" value="<removed for brevity>">
    </form>

应用于 Email 和 Password 属性的数据注释在模型中生成元数据，助手标签使用模型元数据并生成 HTML5 data-val-* 属性，应用于模型验证。 这样可以提供非介入式 HTML5 和 jQuery 验证。 不引人注目的特性格式 `data-val-rule="Error Message"`，其中 rule 是验证规则的名称，例如 data-val-required、 data-val-email data-val-maxlength、等。如果属性中提供错误消息，则该消息将显示为该data-val-rule属性的值。 还有表单 data-val-ruleName-argumentName="argumentValue" 的属性，这些属性提供有关规则的其他详细信息，例如，data-val-maxlength-max="1024"。


使用集合，以下包含 Colors 数组的模型示例：

    public class Person
    {
        public List<string> Colors { get; set; }

        public int Age { get; set; }
    }

操作方法：

    public IActionResult Edit(int id, int colorIndex)
    {
        ViewData["Index"] = colorIndex;
        return View(GetPerson(id));
    }

以下 Razor 显示如何访问特定 Color 元素：

    @model Person
    @{
        var index = (int)ViewData["index"];
    }

    <form asp-controller="ToDo" asp-action="Edit" method="post">
        @Html.EditorFor(m => m.Colors[index])
        <label asp-for="Age"></label>
        <input asp-for="Age" /><br />
        <button type="submit">Post</button>
    </form>





- Label Tag Helper

- Link Tag Helper

- Partial Tag Helper

- Script Tag Helper

- Select Tag Helper

- Textarea Tag Helper

- Validation Message Tag Helper

- Validation Summary Tag Helper


## TagHelper 自定义

来，我给大家讲个笑话：

    TagHelper TagHelperComponent TagHelperComponentTagHelper 

ASP.Net 引入的 TagHelper 助手标签是一个好东西，比 HtmlHelper 是不同一个年代的东西。

ASP.NET Core 2 带来的`TagHelperComponent` 组件是动态地向 HTML 中添加内容最完美的选择。为了能像助手标签一样使用助手标签组件，需要通过 `TagHelperComponentTagHelper` 来实现，都知道，这个命名非常令人困惑。

ASP.NET Core 在 Microsoft.AspNetCore.Mvc.Razor.TagHelpers 提供了两个内置助手标签组件 `TagHelperComponent` ， 即 HeadTagHelper 和 BodyTagHelper 来将内容插入 `<head>` 或  `<body>`。并且可在 MVC 和 Razor 页面中使用，组件不需要在 `_ViewImports.cshtml` 中注册应用。

继承自 `TagHelperComponentTagHelper` 的类型也就是一个 Tag Helper，不过它将执行与之匹配的 `TagHelperComponent`组件。官方文档只有一句说明，按指定顺序将 `TagHelperComponent` 添加到组件集合并初始化：

    Initializes and processes the ITagHelperComponents added to the Components in the specified order.

标签组件采用 Pascal 大小写格式将类和属性名将转换为各自相应的短横线连接格式。 比如，要使用 MailTo 属性，请使用 `<email mail-to="value"/>` 等效项。

未显式标识 [HtmlTargetElement] 属性的助手标签，按 Pascal 大小写格式转换，EmailToTagHelper 对应 `<email-to />`，后缀 TagHelper 是可选的，只要继承 TagHelper 基类即可 。 特性 NormalOrSelfClosing 和
WithoutEndTag 分别指明 HTML 的自闭合，或无终结标记。

    using System;
    using System.ComponentModel;
    using System.Threading.Tasks;
    using Microsoft.AspNetCore.Mvc.Razor.TagHelpers;
    using Microsoft.AspNetCore.Razor.TagHelpers;
    using Microsoft.Extensions.Logging;

    namespace AppWeb.TagHelpers
    {
        [HtmlTargetElement("me")] // <me asp-href="demo.css">Test Me</me>
        [EditorBrowsable(EditorBrowsableState.Never)]
        public class MyTagComponentTagHelper : TagHelperComponentTagHelper
        {
            public MyTagComponentTagHelper(
                ITagHelperComponentManager manager, 
                ILoggerFactory loggerFactory) : base(manager, loggerFactory) 
            {
                //...
            }

            public override async Task ProcessAsync(TagHelperContext context,
                                              TagHelperOutput output)
            {
                TagHelperContent childContent = await output.GetChildContentAsync();
             
                output.TagName = "b";
                var text = childContent.GetContent().ToUpper()+DateTime.Now.ToString(" ss-fff");
                output.Content.AppendHtml(text);
                Console.WriteLine("TagHelperComponentTagHelper....{0}", context.TagName);
            }
        }
        
        public class LinkStyleTagComponent : TagHelperComponent
        {
            private string _style = 
                @"<link rel=""stylesheet"" href=""@"" />";

            public override int Order => 1;

            public LinkStyleTagComponent()
            {
                // ...
            }

            public override async Task ProcessAsync(TagHelperContext context,
                                              TagHelperOutput output)
            {
                TagHelperContent childContent = await output.GetChildContentAsync();
             
                if (string.Equals(context.TagName, "head", // body or head
                    StringComparison.OrdinalIgnoreCase))
                {
                    var style = _style.Replace("@", "/css/demo.css");
                    output.PostContent.AppendHtml(style);
                }
                // Console.WriteLine("TagHelperComponent....{0}", context.TagName);
            }
        }

        // [HtmlTargetElement("email", TagStructure = TagStructure.NormalOrSelfClosing)]
        // [HtmlTargetElement("email", TagStructure = TagStructure.WithoutEndTag)] 
        [HtmlTargetElement("email")]
        public class EmailTagHelper : TagHelper
        {
            // passed by <email to="name@domain.com" />
            public string To { get; set; }

            public EmailTagHelper()
            {
                //...
            }

            public override void Process(TagHelperContext context, TagHelperOutput output)
            {
                output.TagName = "a";    // Replaces <email> with <a> tag

                string href = "mailto:"+To;
                output.Attributes.SetAttribute("href", href);
                // string inner = output.Content.GetContent();
                output.Content.SetContent($"<i>{To}</i>");
                output.TagMode = TagMode.StartTagAndEndTag; // SelfClosing or StartTagOnly
                // output.SuppressOutput();
            }

            public override async Task ProcessAsync(TagHelperContext context, TagHelperOutput output)
            {
                output.TagName = "a"; // Replaces <email> with <a> tag
                var childContent = await output.GetChildContentAsync();
                string content = childContent.GetContent();
                output.Attributes.SetAttribute("href", "mailto:" + To);
                output.Content.SetHtmlContent($"<b>{content}</b>");
                // foreach(var a in output.Attributes)
                // {
                //     Console.WriteLine("TagHelper {0}:{1}", a.Name, a.Value);
                // }
            }
        }

    }

如果多个自定义助手标签处理同一种标签时，可以通过 IsModified 来判断内容是否经过修改，如果是则从输出缓冲区获取内容：

    var childContent = output.Content.IsModified ? output.Content.GetContent() : 
         (await output.GetChildContentAsync()).GetContent();

输出流可用的方法：

    output.Attributes.RemoveAll("bold");
    output.PreContent.SetHtmlContent("<strong>"); 在本体前附加
    output.Content.SetHtmlContent("REPLACE"); 替换本体
    output.PostContent.SetHtmlContent("</strong>"); 在本体后附加
    output.SuppressOutput();


有三种方法注册助手组件，可以在 Startup 中注册组件服务：

    using System.ComponentModel;
    using Microsoft.AspNetCore.Razor.TagHelpers;
    using Microsoft.AspNetCore.Mvc.Razor.TagHelpers;

    services.AddTransient<ITagHelperComponentTagHelper, MyTagComponentTagHelper>();
    services.AddTransient<ITagHelperComponent, LinkStyleComponent>();

在 cshtml 中注册助手标签，或者在 `_Imports.cshtml` 文件中，注意格式指定 * 表示引入后面程序集的所有助手标签，**注意是程序集不是命名空间，注意不要在 @addTagHelper 末尾加分号**：

    @using Microsoft.AspNetCore.Mvc.Razor.TagHelpers
    @inject ITagHelperComponentManager manager

    @addTagHelper *, AppWeb
    @addTagHelper AppWeb.TagHelpers.EmailTagHelper, AppWeb

    @{
        ViewData["Title"] = "Edit";

        manager.Components.Add(new LinkStyleComponent());
    }

在 PageMode 中注册助手标签：

    using System.ComponentModel;
    using Microsoft.AspNetCore.Mvc.Razor.TagHelpers;
    using Microsoft.AspNetCore.Razor.TagHelpers;
    using Microsoft.Extensions.Logging;

    private readonly ITagHelperComponentManager _tagHelperComponentManager;

    public EditModel(
        ITagHelperComponentManager tagHelperComponentManager,
        ILoggerFactory loggerFactory)
    {
        _tagHelperComponentManager = tagHelperComponentManager;
        _tagHelperComponentManager.Components.Add(new LinkStyleComponent());
    }


## MVC Route 路由
- [Razor Page 页面和路由约定](https://docs.microsoft.com/zh-cn/aspnet/core/razor-pages/razor-pages-conventions?view=aspnetcore-3.1)
- [Web Apps MVC Routing](https://docs.microsoft.com/en-us/aspnet/core/mvc/controllers/routing?view=aspnetcore-3.1)
- [MVC 路由设置](https://docs.microsoft.com/zh-cn/aspnet/core/mvc/controllers/routing?view=aspnetcore-3.1)
- [ASP.Net Core Controller Class](https://docs.microsoft.com/en-us/dotnet/api/microsoft.aspnetcore.mvc.controller?view=aspnetcore-3.1)
- [ASP.NET Core 中的路由](https://docs.microsoft.com/zh-cn/aspnet/core/fundamentals/routing?view=aspnetcore-3.1)


ASP.NET Core 应用可以混合使用传统路由和属性路由两种路由方式：

- Conventional routing 通常将传统路由用于为浏览器处理 HTML 页面的控制器。
- Attribute routing 属性路由用于处理 REST API 的控制器。

控制器的操作 Action 方法既支持传统路由，也支持属性路由。 通过在控制器或操作上放置路由可实现属性路由。 不能通过传统路由访问定义属性路由的操作，反之亦然。 

Razor Pages 路由和 MVC 控制器路由共享一个实现，以下关键字为保留路由参数名称，这些关键字会在请求时匹配出现在 URL 的 Path 部分，比如 `/MyController/doAction/2`，那么匹配的内容就保存在 HttpRequest.RouteValues 属性中，键值对中的 Key 就是以下这些关键字：

| 关键字   | 对应助手标签属性 |
| :------   | :------ |
| action    | asp-action |
| area      | asp-area |
| controller| asp-controller |
| handler   | asp-handler |
| page      | asp-page |

URL 生成使用特殊参数名称来确定 URL 生成操作是指 Razor 页面还是引用控制器。使用这些关键字作为属性路由的路由参数是一个常见错误，这样做会导致在 URL 生成时出现不一致的行为，如以下使用 page 作为参数就会导致潜在问题：

    public class MyDemo2Controller : Controller
    {
        [Route("/articles/{page}")]
        public IActionResult ListArticles(int page)
        {
            return ControllerContext.MyDisplayRouteInfo(page);
        }
    }


### Conventional routing 传统路由

Startup.Configure 使用传统路由时，通常具有如下所示的代码：

    app.UseEndpoints(endpoints =>
    {
        endpoints.MapControllerRoute(
            name: "default",
            pattern: "{controller=Home}/{action=Index}/{id?}");
    });

以下简便方法方法等价：

    endpoints.MapDefaultControllerRoute();
    endpoints.MapControllerRoute("default", "{controller=Home}/{action=Index}/{id?}");

它被称为传统路由，因为它建立了一个 URL 路径约定：

- 第一个路径段 {controller=Home} 映射到控制器名称，默认值表示 URL 没有指定 Action 时使用 Home。
- 第二段 {action=Index} 映射到操作名称，默认值表示 URL 没有指定 Action 时使用 Index。
- 第三段 {id?} 用于可选参数 id 。问号使 {id?} 成为可选的参数。

使用此 default 路由，URL 路径映射示范：

- /Products/List 映射到 ProductsController.List 操作。
- /Blog/Article/17 映射到 BlogController.Article 和通常将参数绑定 id 为 17。

传统路由的映射仅基于控制器和操作名称，不基于命名空间、源文件位置或方法参数。

通过使用传统路由和默认路由，可以创建应用，而无需为每个操作都提供新的 URL 匹配模式。 对于具有 CRUD - Create & Retrieve & Update & Delete 样式操作的应用，跨控制器的 url 保持一致有助于简化代码，使 UI 更具可预测性。默认的传统路由是许多 web UI 应用程序所需的唯一路由模板，对于较大的 web UI 应用，如果需要，则使用区域的其他路由。

- MapControllerRoute
- MapDefaultControllerRoute
- MapAreaRoute
- MapAreaControllerRoute

MapControllerRoute 和 MapAreaRoute 根据在 Startup 中配置调用的顺序，自动将 Order 顺序值分配给其终结点 EndPoint。

ASP.NET Core 3.0 及更高版本中的终结点没有路由的概念，不为执行扩展性提供排序保证，同时处理所有终结点。启用日志记录以查看内置路由实现（如 Route）如何匹配请求。

UseEndpoints 配置中可以添加多个传统路由，可添加专用于特定操作的传统路由，例如：

    app.UseEndpoints(endpoints =>
    {
        endpoints.MapControllerRoute(
            name: "blog",
            pattern: "blog/{*article}",
            defaults: new { controller = "Blog", action = "Article" });
        endpoints.MapControllerRoute(
            name: "default",
            pattern: "{controller=Home}/{action=Index}/{id?}");
    });

上述代码中的 blog 路由是专用的传统路由，这称为专用的传统路由，因为它使用传统路由，专用于特定的操作。更因为 controller 和 action 不会以参数形式出现在路由模板中。它们只能具有默认值 { controller = "Blog", action = "Article" } 。

此路由始终映射到操作 BlogController.Article，/Blog、 /Blog/Article 和 /Blog/{any-string} 是唯一与路由匹配的 URL 路径。

blog 路由具有比默认路由 default 更高的优先级，因为它是首先添加的。

在 ASP.NET Core 3.0 及更高版本中，路由不会：

- 定义名为 route 的概念。 UseRouting 向中间件管道添加路由匹配。 UseRouting 中间件会查看应用中定义的终结点集，并根据请求选择最佳的终结点匹配。
- 提供可扩展性（如或）的执行 IRouteConstraint 顺序 IActionConstraint 。

在视图模板文件中，可以使用助手标签来生成 HTML 链接标签：

    <a asp-area="" asp-controller="hello" asp-action="Edit">Edit</a>

需要注意，以下三类属性不能同时出现，因为它们是三种冲突的路由规则。同时，如果没有指定 asp-action，那么 URL 会根据当前的 action 作为默认值，在使用 asp-route-[value] 设置参数后也会影响 URL 的生成，根据控制器中最匹配的 action 方法来设置 ：

- asp-route
- asp-controller, asp-action
- asp-page, asp-page-handler



### Attribute Routine 属性路由

REST Api 应使用属性路由将由 ApiController 中的操作方法指定的 HTTP 谓词表示。
属性路由使用一组属性将操作直接映射到路由模板。 下面 StartUp.Configure 中 MapControllers 调用以映射属性路由控制器，这是 REST API 的典型配置代码：

    public void ConfigureServices(IServiceCollection services)
    {
        services.AddControllers();
    }

    public void Configure(IApplicationBuilder app, IWebHostEnvironment env)
    {
        if (env.IsDevelopment())
        {
            app.UseDeveloperExceptionPage();
        }

        app.UseHttpsRedirection();

        app.UseRouting();

        app.UseAuthorization();

        app.UseEndpoints(endpoints =>
        {
            endpoints.MapControllers(); // use [Route] attributes
        });
    }

例如 HomeController 匹配一组与默认传统路由 `{controller=Home}/{action=Index}/{id?}` 匹配的 Url ，虽然不强调统一大小写，但保持一致是个好习惯。

    public class HomeController : Controller
    {
        [Route("")]
        [Route("Home")]
        [Route("Home/Index")]
        [Route("Home/Index/{id?}")]
        public IActionResult Index(int? id)
        {
            return ControllerContext.MyDisplayRouteInfo(id);
        }

        [Route("Home/About")]
        [Route("Home/About/{id?}")]
        public IActionResult MyAbout(int? id)
        {
            return ControllerContext.MyDisplayRouteInfo(id);
        }
    }

此示例突出显示了属性路由与传统路由之间的主要编程区别。 属性路由需要更多输入才能指定路由。 传统的默认路由会更简洁地处理路由。 但是，特性路由允许和要求精确控制哪些路由模板适用于每个操作。


助手标签属性 asp-route 使用命名路由，可以和带有同名的属性路由 action 匹配，如下，具有名为 [Route(name="register")] 属性路由的 Action 方法可将以下标记生成的 URL 匹配：

    <form asp-route="register" method="post">
        <!-- Input and Submit elements -->
    </form>

在新建使用个人用户帐户身份验证的 Web 应用，会需要包含 asp-route-returnurl 属性：

    <form asp-controller="Account" asp-action="Login"
         asp-route-returnurl="@ViewData["ReturnUrl"]"
         method="post" class="form-horizontal" role="form">


使用属性路由时，控制器和操作名称不会对路由起任何影响，比如上面的 MyAbout 操作方法还是按照路由属性设置起作用，除非使用令牌替换。

在属性路由中使用令牌替换，可以用控制的 Action 方法名称替换生成路由，标记替换发生在属性路由生成的最后一步。 

为方便起见，特性路由支持为保留路由参数替换标记，方法是将令牌括在以下其中一项：

- 方括号：[]，如控制器令牌 [action] 、 [area] 和 [controller]
- 大括号：{}，如参数令牌 {id}

以下代码中的令牌将替换为自定义路由的操作方法名称、区域名称和控制器名称：

    [Route("[controller]/[action]")]
    public class Products0Controller : Controller
    {
        [HttpGet]
        public IActionResult List()
        {
            return ControllerContext.MyDisplayRouteInfo();
        }


        [HttpGet("{id}")]
        public IActionResult Edit(int id)
        {
            return ControllerContext.MyDisplayRouteInfo(id);
        }
    }

前面的示例与下面的代码具有相同的行为：

    public class Products20Controller : Controller
    {
        [HttpGet("[controller]/[action]")]  // Matches '/Products20/List'
        public IActionResult List()
        {
            return ControllerContext.MyDisplayRouteInfo();
        }
    
        [HttpGet("[controller]/[action]/{id}")]   // Matches '/Products20/Edit/{id}'
        public IActionResult Edit(int id)
        {
            return ControllerContext.MyDisplayRouteInfo(id);
        }
    }

通常 HTTP 谓词属性用来定义参数映射，而不设置路由，列如以下 [HttpGet] 指定了 [action] 就会让路由难以琢磨，它会和控制器类对象或控制器方法设置的 [Route] 进行结合： 

    [HttpGet("/[action]/{id}")]


区域目录分组管理是一项 MVC 功能，用于将相关功能作为一个单独的组组织到一个目录组中：

- 控制器操作的路由命名空间。
- 视图的文件夹结构。

通过使用区域，应用可以有多个具有相同名称的控制器，只要它们具有不同的区域即可。 通过向 controller 和 action 添加另一个路由参数 area，可使用区域为路由创建层次结构。 本部分讨论路由如何与区域交互。 有关如何将区域与视图结合使用的详细信息，请参阅区域。
下面的示例将 MVC 配置为使用默认传统路由，并为 area 命名的 area 指定路由 Blog ：

    app.UseEndpoints(endpoints =>
    {
        endpoints.MapAreaControllerRoute("blog_route", "Blog",
            "Manage/{controller}/{action}/{id?}");
        endpoints.MapControllerRoute("default_route", "{controller}/{action}/{id?}");
    });

在前面的代码中， MapAreaControllerRoute 将调用来创建 "blog_route" 。 第二个参数 "Blog" 为区域名称。

当匹配 URL 路径（如 /Manage/Users/AddUser ）时， "blog_route" 路由将生成路由值 { area = Blog, controller = Users, action = AddUser } 。 area路由值由的默认值生成 area 。 创建的路由 MapAreaControllerRoute 等效于以下内容：

    app.UseEndpoints(endpoints =>
    {
        endpoints.MapControllerRoute("blog_route", "Manage/{controller}/{action}/{id?}",
            defaults: new { area = "Blog" }, constraints: new { area = "Blog" });
        endpoints.MapControllerRoute("default_route", "{controller}/{action}/{id?}");
    });



默认情况下，Razor 页面位于 /Pages 目录的根位置, WithRazorPagesAtContentRoot 以指定 Razor Pages 位于应用的内容根 ContentRootPath 中。配置 WithRazorPagesRoot 以指定 Razor 页面位于应用中自定义根目录位置（提供相对路径）：

    public void ConfigureServices(IServiceCollection services)
    {            
        services.AddRazorPages()
            .AddRazorPagesOptions(options =>
            {
                options.Conventions.AuthorizeFolder("/MyPages/Admin");
            })
            .WithRazorPagesAtContentRoot();
            // .WithRazorPagesRoot("/path/to/razor/pages");
    }




大多数应用不需要通过模型约定来配置路由，要配置高级选项，请使用扩展方法 AddRazorPagesOptions 添加 PagesOption 配置：

    public void ConfigureServices(IServiceCollection services)
    {
        services.
            .AddRazorPagesOptions(options =>
            {
                options.RootDirectory = "/MyPages";
                options.Conventions.AuthorizeFolder("/MyPages/Admin");
            });
    }

AddRazorPages() 返回 Microsoft.Extensions.DependencyInjection.IMvcBuilder 实例，通过它来配置 MVC。


通过模型约定将路由模板和标头添加到应用的页面。

- Conventions.Add
- IPageRouteModelConvention
- IPageApplicationModelConvention
- IPageHandlerModelConvention

通过页面路由操作约定将路由模板添加到某个文件夹中的页面以及单个页面。

- AddFolderRouteModelConvention
- AddPageRouteModelConvention
- AddPageRoute

通过页面模型操作约定将标头添加到某个文件夹中的多个页面，将标头添加到单个页面，以及配置筛选器工厂以将标头添加到应用的页面。

- AddFolderApplicationModelConvention
- AddPageApplicationModelConvention
- ConfigureFilter（筛选器类、Lambda 表达式或筛选器工厂）

使用 AddRazorPagesOptions 扩展方法向 Startup 添加和配置 Razor Pages 约定。 

    public void ConfigureServices(IServiceCollection services)
    {
        services.AddRazorPages()
            .AddRazorPagesOptions(options =>
            {
                options.Conventions.Add( ... );
                options.Conventions.AddFolderRouteModelConvention(
                    "/OtherPages", model => { ... });
                options.Conventions.AddPageRouteModelConvention(
                    "/About", model => { ... });
                options.Conventions.AddPageRoute(
                    "/Contact", "TheContactPage/{text?}");
                options.Conventions.AddFolderApplicationModelConvention(
                    "/OtherPages", model => { ... });
                options.Conventions.AddPageApplicationModelConvention(
                    "/About", model => { ... });
                options.Conventions.ConfigureFilter(model => { ... });
                options.Conventions.ConfigureFilter( ... );
            });
    }

按 order 约定建立路由处理：

- 按顺序处理路按 order 的值由小到大（-1、0、1、2 … n）。
- 当路由具有相同 Order 时，首先匹配最具体的路由，然后匹配不太具体的路由。
- 当具有相同 Order 和相同数量参数的路由与请求 URL 匹配时，会按添加到 PageConventionCollection 的顺序处理路由。

如果可能，请避免依赖于建立的路由处理顺序。 通常，路由会通过 URL 匹配选择正确路由。 如果必须设置路由 Order 属性以便正确路由请求，则应用的路由方案可能会使客户端感到困惑并且难以维护。 应设法简化应用的路由方案。 示例应用需要显式路由处理顺序以使用单个应用来演示几个路由方案。 但是，在生产应用中应尝试避免设置路由 Order 的做法。




使用 AddPageRoute 配置路由，该路由指向指定页面路径中的页面。 生成的页面链接使用指定的路由。 AddPageRoute 使用 AddPageRouteModelConvention 建立路由。

示例应用为 Contact.cshtml 创建指向 /TheContactPage 的路由：

    options.Conventions.AddPageRoute("/Contact", "TheContactPage/{text?}");

还可在 /Contact 中通过默认路由访问页面。

示例应用页面自定义路由允许使用可选的 text 路由段 ({text?})。 该页面还在其 @page 指令中包含此可选段，以便访问者在 /Contact 路由中访问该页面：

    @page "{text?}"
    @model ContactModel
    @{
        ViewData["Title"] = "Contact";
    }

    <h1>@ViewData["Title"]</h1>
    <h2>@Model.Message</h2>
    ...
    <p>@Model.RouteDataTextTemplateValue</p>



## Sessions 会话管理

HTTP 是无状态的协议。 默认情况下，HTTP 请求是不保留用户值的独立消息。 利用不同的存储机制，可以保留用户在活动期间的会话状态。 

    存储方法    存储机制
    Cookie  HTTP Cookie。 可能包括使用服务器端应用代码存储的数据。
    Session State   HTTP Cookie 和服务器端应用代码
    TempData    HTTP Cookie 或会话状态
    Query Strings   HTTP 查询字符串
    Hidden Fields   HTTP 窗体字段
    HttpContext.Items   服务器端应用代码
    Cache   服务器端应用代码

Cookie 存储所有请求的数据。 因为 Cookie 是随每个请求发送的，所以它们的大小应该保持在最低限度。 理想情况下，仅标识符应存储在 Cookie 中，而数据则由应用存储。 大多数浏览器 Cookie 大小限制为 4096 个字节。 每个域仅有有限数量的 Cookie 可用。

由于 Cookie 易被篡改，因此它们必须由服务器进行验证。 客户端上的 Cookie 可能被用户删除或者过期。 但是，Cookie 通常是客户端上最持久的数据暂留形式。

Cookie 通常用于个性化设置，其中的内容是为已知用户定制的。 大多数情况下，仅标识用户，但不对其进行身份验证。 Cookie 可以存储用户名、帐户名或唯一的用户 ID（例如 GUID）。 Cookie 可用于访问用户的个性化设置，例如首选的网站背景色。

发布 Cookie 和处理隐私问题时，请参阅欧盟一般数据保护条例 (GDPR)。 有关详细信息，请参阅 ASP.NET Core 中的一般数据保护条例 (GDPR) 支持。


会话状态是在用户浏览 Web 应用时用来存储用户数据的 ASP.NET Core 方案。 会话状态使用应用维护的存储来保存客户端所有请求的数据。 会话数据由缓存提供支持，并被视为临时数据。 站点应在没有会话数据的情况下继续运行。 关键应用程序数据应存储在用户数据库中，并仅作为性能优化缓存在会话中。

SignalR 应用不支持会话，因为 SignalR 中心可能独立于 HTTP 上下文执行。 例如，当中心打开的长轮询请求超出请求的 HTTP 上下文的生存期时，可能发生这种情况。

ASP.NET Core 通过向客户端提供包含会话 ID 的 Cookie 来维护会话状态。 Cookie 会话 ID：

- 会随每个请求发送到应用。
- 由应用用于提取会话数据。

会话状态具有以下行为：

- 会话 Cookie 特定于浏览器。 会话不会跨浏览器进行共享。
- 浏览器会话结束时删除会话 Cookie。
- 如果收到过期的会话 Cookie，则创建使用相同会话 Cookie 的新会话。
- 不会保留空会话。 会话中必须设置了至少一个值以保存所有请求的会话。 会话未保留时，为每个新的请求生成新会话 ID。
- 应用在上次请求后保留会话的时间有限。 应用设置会话超时，或者使用 20 分钟的默认值。 在以下情况下，会话状态适合存储用户数据：
- 特定于某个特定会话。
- 数据不需要跨会话永久存储。
- 调用 ISession.Clear 实现或者会话过期时，会删除会话数据。
- 没有默认机制告知客户端浏览器已关闭或者客户端上的会话 Cookie 被删除或过期的应用代码。
- 默认情况下，会话状态 Cookie 不标记为“基本”。 除非站点访问者允许跟踪，否则会话状态不起作用。 有关详细信息，请参阅 ASP.NET Core 中的一般数据保护条例（GDPR）支持。

请勿将敏感数据存储在会话状态中。 用户可能不会关闭浏览器并清除会话 Cookie。 某些浏览器会保留所有浏览器窗口中的有效会话 Cookie。 会话可能不限于单个用户。 下一个用户可能继续使用同一会话 Cookie 浏览应用。

内存中缓存提供程序在应用驻留的服务器内存中存储会话数据。 在服务器场方案中：

- 使用粘性会话将每个会话加入到单独服务器上的特定应用实例 。 默认情况下，Azure 应用服务使用应用程序请求路由 (ARR) 强制实施粘性会话。 然而，粘性会话可能会影响可伸缩性，并使 Web 应用更新变得复杂。 更好的方法是使用 Redis 或 SQL Server 分布式缓存，它们不需要粘性会话。 有关详细信息，请参阅 ASP.NET Core 中的分布式缓存。
- 通过 IDataProtector 加密会话 Cookie。 必须正确配置数据保护，以在每台计算机上读取会话 Cookie。 有关详细信息，请参阅 ASP.NET Core 数据保护 和密钥存储提供程序。


配置会话状态，Microsoft.AspNetCore.Session 包由框架隐式包含，它提供用于管理会话状态的中间件。若要启用会话中间件，Startup 必须包含：

- 任一 IDistributedCache 实现内存缓存用作会话后备存储。
- 对 ConfigureServices 中 AddSession 的调用。
- 对 Configure 中 UseSession 的调用。

以下代码演示如何使用 IDistributedCache 的默认内存中实现设置内存中会话提供程序：

    public class Startup
    {
        public Startup(IConfiguration configuration)
        {
            Configuration = configuration;
        }

        public IConfiguration Configuration { get; }

        public void ConfigureServices(IServiceCollection services)
        {
            services.AddDistributedMemoryCache();

            services.AddSession(options =>
            {
                options.IdleTimeout = TimeSpan.FromSeconds(10);
                options.Cookie.HttpOnly = true;
                options.Cookie.IsEssential = true;
            });

            services.AddControllersWithViews();
            services.AddRazorPages();
        }

        public void Configure(IApplicationBuilder app, IWebHostEnvironment env)
        {
            if (env.IsDevelopment())
            {
                app.UseDeveloperExceptionPage();
            }
            else
            {
                app.UseExceptionHandler("/Home/Error");
                app.UseHsts();
            }

            app.UseHttpsRedirection();
            app.UseStaticFiles();

            app.UseRouting();

            app.UseAuthentication();
            app.UseAuthorization();

            app.UseSession();

            app.UseEndpoints(endpoints =>
            {
                endpoints.MapDefaultControllerRoute();
                endpoints.MapRazorPages();
            });
        }
    }

中间件的顺序很重要。 在 UseRouting 之后和 UseEndpoints 之前调用 UseSession。 配置会话状态后，HttpContext.Session 可用，调用 UseSession 以前无法访问 HttpContext.Session。

在应用已经开始写入到响应流之后，不能创建有新会话 Cookie 的新会话。 此异常记录在 Web 服务器日志中但不显示在浏览器中。


使用 HttpContext.Session 从 Razor Pages PageModel 类或 MVC 控制器类访问会话状态。 此属性是 ISession 实现，提供用于设置和检索整数和字符串值的若干扩展方法。

ISession 扩展方法位于 Microsoft.AspNetCore.Http 命名空间中：

- Get(ISession, String)
- GetInt32(ISession, String)
- GetString(ISession, String)
- SetInt32(ISession, String, Int32)
- SetString(ISession, String, String)

以下示例在 Razor Pages 页中检索 IndexModel.SessionKeyName 键的会话值：

    @page
    @using Microsoft.AspNetCore.Http
    @model IndexModel

    ...

    Name: @HttpContext.Session.GetString(IndexModel.SessionKeyName)

以下示例显示如何设置和获取整数和字符串：


    public class IndexModel : PageModel
    {
        public const string SessionKeyName = "_Name";
        public const string SessionKeyAge = "_Age";
        const string SessionKeyTime = "_Time";

        public string SessionInfo_Name { get; private set; }
        public string SessionInfo_Age { get; private set; }

        public void OnGet()
        {
            // Requires: using Microsoft.AspNetCore.Http;
            if (string.IsNullOrEmpty(HttpContext.Session.GetString(SessionKeyName)))
            {
                HttpContext.Session.SetString(SessionKeyName, "The Doctor");
                HttpContext.Session.SetInt32(SessionKeyAge, 773);
            }

            var name = HttpContext.Session.GetString(SessionKeyName);
            var age = HttpContext.Session.GetInt32(SessionKeyAge);

必须对所有会话数据进行序列化以启用分布式缓存方案，即使是在使用内存中缓存的时候。 字符串和整数序列化程序由 ISession 的扩展方法提供。 用户必须使用另一种机制（例如 JSON）序列化复杂类型。

使用以下示例代码序列化对象：

    public static class SessionExtensions
    {
        public static void Set<T>(this ISession session, string key, T value)
        {
            session.SetString(key, JsonSerializer.Serialize(value));
        }

        public static T Get<T>(this ISession session, string key)
        {
            var value = session.GetString(key);
            return value == null ? default : JsonSerializer.Deserialize<T>(value);
        }
    }

以下示例演示如何使用 SessionExtensions 类设置和获取可序列化的对象：

    // Requires SessionExtensions from sample download.
    if (HttpContext.Session.Get<DateTime>(SessionKeyTime) == default)
    {
        HttpContext.Session.Set<DateTime>(SessionKeyTime, currentTime);
    }


## HttpContext 数据访问
https://docs.microsoft.com/en-us/dotnet/api/microsoft.aspnetcore.http.httpcontext
https://gunnarpeipman.com/aspnet-core-request-body/
https://www.cnblogs.com/savorboard/p/aspnetcore-mvc-startup.html
https://www.cnblogs.com/savorboard/p/aspnetcore-mvc-routing-action.html
https://www.cnblogs.com/savorboard/p/aspnetcore-identity.html
https://blog.51cto.com/kiujyhgt/1916908


ASP.NET Core 应用通过 IHttpContextAccessor 接口及其默认实现 HttpContextAccessor 访问 HttpContext。 只有在需要访问服务内的 HttpContext 时，才有必要使用 IHttpContextAccessor。

注意，有两个 HttpRequest，这里指的时 ASP.Net Core 命名空间下的：

- System.Web.HttpRequest
- Microsoft.AspNetCore.Http.HttpRequest

HttpContext 归属于 ASP.NET Core API，不是 .Net Core API，使用官方 API 参考文档需要注意。

ASP.NET MVC Web API 控制器中，HttpRequest 经过一整套逻辑预处理，首先是 RouteContext 路由处理，然后再流向具体的控制器。在控制器方法执行前，经由依赖注入的前期对象就先处理好数据，匹配好控制器方法的参数列表再转送过来。

试分析，客户端往服务器发送一条 JSON 信息，MVC 首先可以根据 URL 和 路由设置判断所对应的控制器，但是，在控制器方法 Action 执行前还需要经过其它 Filter 层层过滤，包括 AuthorizationFilter、ActionFilter 等，然后再有 ActionInvoker 去执行。

控制器中 Action 参数可以通过特性修饰来实现数据处理：

- [FromQuery]   从查询字符串获取值。
- [FromRoute]   从路由数据中获取值。
- [FromForm]    从已发布的表单字段中获取值。
- [FromBody]    从请求正文中获取值。
- [FromHeader]  从 HTTP 标头中获取值。

假如使用了 `[FromBody]` 特性修饰参数列表，那么 Body 数据就会被消费掉，或者通过定义中间件，在数据消费前进行处理。所以直接在控制器方法中 Request.Body 读不到数据，Position 或 Length 属性也不可用，可以试试 curl 发送测试数据，再修改参数列表的特性修饰：

    curl -H "Content-Type:application/json" -d "{""Id"":""122"", ""Text"":""name"", ""Description"":""anything""}" -X POST "http://127.0.0.1:5001/api/item?Text=name&Description=xyz"

另外，根据使用的控制器类型不同，读取数据的方式也有差异：

- ApiController.Request 访问 HttpRequestMessage.ReadAsStringAsync()；
- ControllerBase.Request 访问 HttpRequest 对象；

以下是数据读取参考：

    var sr = new StreamReader(HttpContext.Request.Body);
    string body = await sr.ReadToEndAsync();

    Request.EnableBuffering();
    Request.Body.Seek(0, SeekOrigin.Begin);
    Request.Body.Position = 0;
    Request.Body.CopyToAsync(Console.OpenStandardOutput());

执行 ControllerBae.EnableBuffering 方法激活回读， ASP.NET Core 2.0 旧版本是 EnableRewind 方法：

    Request.EnableRewind();
    using (var reader = new StreamReader(Request.Body))
    {
        var body = reader.ReadToEnd();
        ...
        Request.Body.Seek(0, SeekOrigin.Begin);
        body = reader.ReadToEnd();
    }
 
利用 MemoryStream 重复读取

    using (var mem = new MemoryStream())
    using (var reader = new StreamReader(mem))
    {
        Request.Body.CopyTo(mem);
        var body = reader.ReadToEnd();
        ...
        mem.Seek(0, SeekOrigin.Begin);
        body = reader.ReadToEnd();
    }


通过 Razor Pages 使用 HttpContext
Razor Pages PageModel 公开 HttpContext 属性：

    public class AboutModel : PageModel
    {
        public string Message { get; set; }

        public void OnGet()
        {
            Message = HttpContext.Request.PathBase;
        }
    }

通过 Razor 视图使用 HttpContext
Razor 视图通过视图上的 RazorPage.Context 属性直接公开 HttpContext。 下面的示例使用 Windows 身份验证检索 Intranet 应用中的当前用户名：

    @{
        var username = Context.User.Identity.Name;
        
        ...
    }

通过控制器使用 HttpContext
控制器公开 ControllerBase.HttpContext 属性：

    public class HomeController : Controller
    {
        public IActionResult About()
        {
            var pathBase = HttpContext.Request.PathBase;

            ...

            return View();
        }
    }

通过中间件使用 HttpContext
使用自定义中间件组件时，HttpContext 传递到 Invoke 或 InvokeAsync 方法，在中间件配置后可供访问：

    public class MyCustomMiddleware
    {
        public Task InvokeAsync(HttpContext context)
        {
            ...
        }
    }

通过自定义组件使用 HttpContext
对于需要访问 HttpContext 的其他框架和自定义组件，建议使用内置的依赖项注入容器来注册依赖项。 依赖项注入容器向任意类提供 IHttpContextAccessor，以供类在自己的构造函数中将它声明为依赖项：

    public void ConfigureServices(IServiceCollection services)
    {
         services.AddControllersWithViews();
         services.AddHttpContextAccessor();
         services.AddTransient<IUserRepository, UserRepository>();
    }

如下示例中，UserRepository 声明自己对 IHttpContextAccessor 的依赖。当依赖项注入容器解析依赖链并创建 UserRepository 实例时，就会注入依赖项。

    public class UserRepository : IUserRepository
    {
        private readonly IHttpContextAccessor _httpContextAccessor;

        public UserRepository(IHttpContextAccessor httpContextAccessor)
        {
            _httpContextAccessor = httpContextAccessor;
        }

        public void LogCurrentUser()
        {
            var username = _httpContextAccessor.HttpContext.User.Identity.Name;
            service.LogAccessRequest(username);
        }
    }


从后台线程访问 HttpContext
HttpContext 不是线程安全型。 在处理请求之外读取或写入 HttpContext 的属性可能会导致 NullReferenceException。

如果应用生成偶发的 NullReferenceException 错误，请评审启动后台处理的部分代码，或者在请求完成后继续处理的部分代码。 查找诸如将控制器方法定义为 async void 的错误。
要使用 HttpContext 数据安全地执行后台工作，请执行以下操作：

- 在请求处理过程中复制所需的数据。
- 将复制的数据传递给后台任务。

要避免不安全代码，请勿将 HttpContext 传递给执行后台工作的方法。 而是传递所需要的数据。 在以下示例中，调用 SendEmailCore，开始发送电子邮件。 将 correlationId 传递到 SendEmailCore，而不是 HttpContext。 代码执行不会等待 SendEmailCore 完成：

    public class EmailController : Controller
    {
        public IActionResult SendEmail(string email)
        {
            var correlationId = HttpContext.Request.Headers["x-correlation-id"].ToString();

            _ = SendEmailCore(correlationId);

            return View();
        }

        private async Task SendEmailCore(string correlationId)
        {
            ...
        }
    }

Blazor 和共享状态

Blazor 服务器应用位于服务器内存中。 这意味着同一进程中托管了多个应用。 对于每个应用会话，Blazor 会启动具有其自己的 DI 容器作用域的线路。 这意味着，每个 Blazor 会话的作用域内服务都是唯一的。

我们不建议同一服务器上的应用共享使用单一实例服务的状态，除非采取了极其谨慎的措施，因为这可能会带来安全漏洞，如跨线路泄露用户状态。

如果有状态的单一实例服务是专门为 Blazor 应用设计的，则可以在该应用中使用这些服务。 例如，假设用户无法控制使用哪些缓存密钥，则可以将内存缓存用作单一实例，因为它需要一个密钥来访问给定的条目。

另外，出于安全原因，不得在 Blazor 应用中使用 IHttpContextAccessor。 Blazor 应用在 ASP.NET Core 管道的上下文之外运行，并且不保证 HttpContext 在 IHttpContextAccessor 内可用，也不能保证保存启动 Blazor 应用的上下文。

若要向 Blazor 应用传递请求状态，建议在初次呈现应用时通过传递到根组件的参数进行传递：

- 使用要传递到 Blazor 应用的所有数据定义类。
- 使用目前可用的 HttpContext 在 Razor 页中填充该数据。
- 将数据作为传递给根组件（应用）的参数传递给 Blazor 应用。
- 在根组件中定义一个参数，用于保存即将传递给应用的数据。
- 在应用中使用用户特定的数据；或者，将该数据复制到 OnInitializedAsync 中的作用域内的服务，以便可以跨应用使用该数据。


## Middleware 中间件

中间件是一种装配到应用管道以处理请求和响应的软件。 ASP.NET Core 提供了一组丰富的内置中间件组件，但在某些情况下，你可能需要写入自定义中间件。

中间件 Middleware 是 ASP.NET Core 一个重要特性。所谓中间件就是嵌入到应用管道中用于处理请求和响应的一段代码，客户端请求送达服务器后就进入一条长长的处理管道中，可以给管道注册中间件以处理客户的请求，多个中间通过一条调用链依次执行，以下的 next 方法就是用来调用管道中其它中间件的方法。

中间件在请求处理流程中体现为 `IApplicationBuilder.Use(Func<RequestDelegate,RequestDelegate>)` ， 即一个 Func 泛型委托对象，这个委托出现了两个 RequestDelegate 代表传入委托方法的参数，只有最后一个是委托函数的返回类型。也就是说 Use 方法注册的的是一个委托对象，被委托的函数接收一个 RequestDelegate 作为传入参数，同时它又返回一个 RequestDelegate 对象：

    public delegate System.Threading.Tasks.Task RequestDelegate(HttpContext context);

根据 Microsoft.AspNetCore.Http 定义，RequestDelegate 委托的是传入 HttpContext 且返回 Task 的函数,这是异步操作的任务，这里有点绕。重新理一下， `IApplicationBuilder.Use()` 注册一个委托对象，这个委托对象的入参出参都是 `RequestDelegate` 委托对象。

以下参考代码展示了中间件的委托实现，使用异步 lambda ，即 `new RequestDelegate(async (context) => {...})` 实现 middleware 返回的 RequestDelegate 委托对象。同时，app.Use(middleware) 比另一个委中间件注册要早，有优先执行，可以通过 Headers.Append() 方法添加响应头测试。 middler 这里先执行了 `await next(context)` 这是因为后面要往 Response.Body 写数据，一旦执行后面的中间件就不能写响应头信息，包括默认的 StatusCode 都写不了。可以注解掉 next() 的执行，看看后面注册的中间件是否会执行：


    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Threading.Tasks;
    using Microsoft.AspNetCore; // WebHost
    using Microsoft.AspNetCore.Hosting; // IWebHost IHostBuilder
    using Microsoft.AspNetCore.Http; // Extension Methods: WriteAsync

    public class ASPNET
    {
        // IApplicationBuilder.Use( Func<RequestDelegate,RequestDelegate> )
        // public delegate Task RequestDelegate(HttpContext context);
        static Func<RequestDelegate,RequestDelegate> middleware = delegate (RequestDelegate next)
            {
                return new RequestDelegate(async (context) =>
                {
                    // Call the next delegate/middleware in the pipeline
                    await next(context);
                    context.Response.Headers.Append("Request-Delegate", DateTime.Now.ToString("hh:mm:ss ffff"));
                    if (!context.Request.Path.ToString().StartsWith("/welcome"))
                    {
                        await context.Response.WriteAsync(@"
                            <script>alert(""Now server will redirect to /welcome "");location=""/welcome"";</script>
                            ");
                        // context.Response.Redirect("/welcome/Hi!");
                    }
                    await context.Response.WriteAsync("<h1>Hello World!</h1>");
                });
            };

        public static void Main()
        {
            using (IWebHost host = WebHost.StartWith("http://localhost:8080", app => {

                app.Use(middleware);

                app.Use(next => async (context) =>
                {
                    await next(context);
                    context.Response.StatusCode = 200;
                    var cultureQuery = context.Request.Query["culture"];
                    Console.WriteLine($"culture test {cultureQuery}");
                    await context.Response.WriteAsync($"<p>Hi! {cultureQuery}</p>");
                });

                }))
            {
                Console.WriteLine("Use Ctrl-C to shut down the host...");
                host.WaitForShutdown();
            }
        }

    }

使用 curl 工具测试，使用选项 -I 单独显示响应头，-i 响应头加内容：

    curl -I http://localhost:8080/?culture=zh-CN
    curl -i http://localhost:8080/?culture=zh-CN
    curl http://localhost:8080/?culture=zh-CN

尝试使用 MSBuild 的 CSC 编译器，需要指定 ASP.Net Core 各个依赖包，没条 using 指令基本对应一个 DLL 引用：

    csc /lib:"C:\Program Files\dotnet\sdk\3.1.300"  /lib:"C:\Program Files\dotnet\sdk\3.1.300\Microsoft\Microsoft.NET.Build.Extensions\net471\lib" /lib:"C:\Program Files\dotnet\shared\Microsoft.NETCore.App\3.1.4" /lib:"C:\Program Files\dotnet\packs\Microsoft.AspNetCore.App.Ref\3.1.2\ref\netcoreapp3.1" /reference:Microsoft.AspNetCore.dll /reference:Microsoft.AspNetCore.Hosting.dll /reference:Microsoft.AspNetCore.Hosting.Abstractions.dll /reference:Microsoft.AspNetCore.Http.Abstractions.dll /reference:System.Runtime.dll /reference:System.Net.Http.dll coding.cs


通常，中间件封装在类中，并且通过扩展方法公开。 请考虑以下中间件示例代码，用于演示创建中间件组件，该中间件通过查询字符串设置当前请求的区域性：

    using System.Globalization;
    using Microsoft.AspNetCore.Http;
    using Microsoft.AspNetCore.Builder;

    public class Startup
    {
        public void Configure(IApplicationBuilder app)
        {
            app.Use(async (context, next) =>
            {
                var cultureQuery = context.Request.Query["culture"];
                if (!string.IsNullOrWhiteSpace(cultureQuery))
                {
                    var culture = new CultureInfo(cultureQuery);

                    CultureInfo.CurrentCulture = culture;
                    CultureInfo.CurrentUICulture = culture;
                }

                // Call the next delegate/middleware in the pipeline
                await next();
            });

            app.Run(async (context) =>
            {
                await context.Response.WriteAsync(
                    $"Hello {CultureInfo.CurrentCulture.DisplayName}");
            });

        }
    }

通过 URL 传入区域性测试中间件：

    https://localhost:5001/?culture=no
    https://localhost:5001/?culture=es-ES
    https://localhost:5001/?culture=zh-CN

将上面的中间件托管示例代码转换为类实现：

    using Microsoft.AspNetCore.Http;
    using System.Globalization;
    using System.Threading.Tasks;

    namespace Culture
    {
        public class RequestCultureMiddleware
        {
            private readonly RequestDelegate _next;

            public RequestCultureMiddleware(RequestDelegate next)
            {
                _next = next;
            }

            public async Task InvokeAsync(HttpContext context)
            {
                var cultureQuery = context.Request.Query["culture"];
                if (!string.IsNullOrWhiteSpace(cultureQuery))
                {
                    var culture = new CultureInfo(cultureQuery);

                    CultureInfo.CurrentCulture = culture;
                    CultureInfo.CurrentUICulture = culture;
                    context.Response.Redirect($"/lang/{cultureQuery}");

                }

                // Call the next delegate/middleware in the pipeline
                await _next(context);
            }
        }
    }

中间件类必须包括：

- 具有类型为 RequestDelegate 的参数的公共构造函数。
- 名为 Invoke 或 InvokeAsync 的公共方法。 此方法必须：
    - 返回 Task。
    - 接受类型 HttpContext 的第一个参数。

构造函数和 Invoke/InvokeAsync 的其他参数由依赖关系注入 (DI) 填充。

中间件应通过在其构造函数中公开其依赖项来遵循显式依赖项原则。 在每个应用程序生存期 构造一次中间件。 如果需要与请求中的中间件共享服务，请参阅按请求中间件依赖项部分。

中间件组件可通过构造函数参数从依赖关系注入 (DI) 解析其依赖项。 UseMiddleware<T> 也可直接接受其他参数。

由于中间件是在应用启动时构造的，而不是按请求构造的，因此在每个请求过程中，中间件构造函数使用的范围内 生存期服务不与其他依赖关系注入类型共享。 如果必须在中间件和其他类型之间共享 IServiceScope 作用域服务，请将这些服务添加到 Invoke 方法的签名。 Invoke 方法可接受由依赖注入填充的其他参数：

    public class CustomMiddleware
    {
        private readonly RequestDelegate _next;

        public CustomMiddleware(RequestDelegate next)
        {
            _next = next;
        }

        // IMyScopedService is injected into Invoke
        public async Task Invoke(HttpContext httpContext, IMyScopedService svc)
        {
            svc.MyProperty = 1000;
            await _next(httpContext);
        }
    }

HttpContext 对象包含了当前 HHTP 请求的双方的上下文数据，中间件可以通过控制 `_next()` 的调用来决定 HTTP 请求的流程终止与否。


以下扩展方法通过 IApplicationBuilder 公开中间件，参考 C# 扩展方法语法：

    using Microsoft.AspNetCore.Builder;

    namespace Culture
    {
        public static class RequestCultureMiddlewareExtensions
        {
            public static IApplicationBuilder UseRequestCulture(
                this IApplicationBuilder builder)
            {
                return builder.UseMiddleware<RequestCultureMiddleware>();
            }
        }
    }

以下代码通过 Startup.Configure 调用中间件：


    public class Startup
    {
        public void Configure(IApplicationBuilder app)
        {
            app.UseRequestCulture();

            app.Run(async (context) =>
            {
                await context.Response.WriteAsync(
                    $"Hello {CultureInfo.CurrentCulture.DisplayName}");
            });
        }
    }


## Model Binding 模型绑定

控制器和 Razor 页面处理来自 HTTP 请求的数据。 例如，路由数据可以提供一个记录键，而表单域可以为模型的属性提供一个值。 编写代码以检索这些值，并将其从字符串转换为 .NET 类型不仅繁琐，而且还容易出错。 模型绑定会自动化该过程。 模型绑定系统：

- 从各种源（如路由数据、表单域和查询字符串）中检索数据。
- 在方法参数和公共属性Razor中向控制器和页面提供数据。
- 将字符串数据转换为 .NET 类型。
- 更新复杂类型的属性。

示例，假设 Model 类有以下操作方法：

    [HttpGet("{id}")]
    public ActionResult<Pet> GetById(int id, bool dogsOnly)

它就可以处理带有以下 URL 的请求：

    http://contoso.com/api/pets/2?DogsOnly=true

在路由系统选择该操作方法之后，模型绑定执行以下步骤：

- 查找 GetByID 的第一个参数，该参数是一个名为 id 的整数。
- 查找 HTTP 请求中的可用源，并在路由数据中查找 id =“2”。
- 将字符串“2”转换为整数 2。
- 查找 GetByID 的下一个参数，该参数是一个名为 dogsOnly 的布尔值。
- 查找源，并在查询字符串中查找“DogsOnly=true”。 名称匹配不区分大小写。
- 将字符串“true”转换为布尔值 true。

然后，该框架会调用 GetById 方法，依赖注入为 id 参数传入 2，并为 dogsOnly 参数传入 true。

在前面的示例中，模型绑定目标是简单类型的方法参数。 目标也可以是复杂类型的属性。 成功绑定每个属性后，将对属性进行模型验证。 有关绑定到模型的数据以及任意绑定或验证错误的记录都存储在 ControllerBase.ModelState 或 PageModel.ModelState 中。 为查明该过程是否已成功，应用会检查 ModelState.IsValid 标志。


模型绑定尝试查找以下类型目标的值：

- 将请求路由到的控制器操作方法的参数。
- 请求路由到 Razor 的页处理程序方法的参数。
- 控制器或 PageModel 类的公共属性（若由特性指定）。

[BindProperty] 属性

可应用于控制器或 PageModel 类的公共属性，从而使模型绑定以该属性为目标：

    public class EditModel : InstructorsPageModel
    {
        [BindProperty]
        public Instructor Instructor { get; set; }

[BindProperties] 属性
可在 ASP.NET Core 2.1 及更高版本中获得。 可应用于控制器或 PageModel 类，以使模型绑定以该类的所有公共属性为目标：

    [BindProperties(SupportsGet = true)]
    public class CreateModel : InstructorsPageModel
    {
        public Instructor Instructor { get; set; }

HTTP GET 请求的模型绑定
默认情况下，不绑定 HTTP GET 请求的属性。 通常，GET 请求只需一个记录 ID 参数。 记录 ID 用于查找数据库中的项。 因此，无需绑定包含模型实例的属性。 在需要将属性绑定到 GET 请求中的数据的情况下，请将 SupportsGet 属性设置为 true：

    [BindProperty(Name = "ai_user", SupportsGet = true)]
    public string ApplicationInsightsCookie { get; set; }


默认情况下，模型绑定以键值对的形式从 HTTP 请求中的以下源中获取数据：

- 表单域
- 请求正文（对于具有 [ApiController] 属性的控制器。）
- 路由数据
- 查询字符串参数
- 上传的文件

对于每个目标参数或属性，按照之前列表中指示的顺序扫描源。 有几个例外情况：

- 路由数据和查询字符串值仅用于简单类型。
- 上传的文件仅绑定到实现 IFormFile 或 IEnumerable<IFormFile> 的目标类型。

如果默认源不正确，请使用下列属性之一来指定源：

- [FromQuery]   从查询字符串获取值。
- [FromRoute]   从路由数据中获取值。
- [FromForm]    从已发布的表单字段中获取值。
- [FromBody]    从请求正文中获取值。
- [FromHeader]  从 HTTP 标头中获取值。

假如使用了 `[FromBody]` 特性修饰参数列表，那么 Body 数据就会被消费掉，或者通过定义中间件，在数据消费前进行处理。所以直接在控制器方法中 Request.Body 读不到数据，Position 或 Length 属性也不可用。


分别添加到模型属性（而不是模型类），如以下示例所示：

    public class Instructor
    {
        public int ID { get; set; }

        [FromQuery(Name = "Note")]
        public string NoteFromQueryString { get; set; }

选择性地在构造函数中接受模型名称值。 提供此选项的目的是应对属性名称与请求中的值不匹配的情况。 例如，请求中的值可能是名称中带有连字符的标头，如以下示例所示：

    public void OnGet([FromHeader(Name = "Accept-Language")] string language)


将 [FromBody] 特性应用于一个参数，以便从一个 HTTP 请求的正文填充其属性。 ASP.NET Core 运行时将读取正文的责任委托给输入格式化程序。 输入格式化程序的解释位于本文后面部分。

将 [FromBody] 应用于复杂类型参数时，应用于其属性的任何绑定源属性都将被忽略。 例如，以下 Create 操作指定从正文填充其 pet 参数：

    public ActionResult<Pet> Create([FromBody] Pet pet)

Pet 类指定从查询字符串参数填充其 Breed 属性：

    public class Pet
    {
        public string Name { get; set; }

        [FromQuery] // Attribute is ignored.
        public string Breed { get; set; }
    }

在上面的示例中：

- [FromQuery] 特性被忽略。
- Breed 属性未从查询字符串参数进行填充。

输入格式化程序只读取正文，不了解绑定源特性。 如果在正文中找到合适的值，则使用该值填充 Breed 属性。
不要将 [FromBody] 应用于每个操作方法的多个参数。 输入格式化程序读取请求流后，无法再次读取该流以绑定其他 [FromBody] 参数。


源数据由值提供程序 Provider 提供给模型绑定系统。 你可以编写并注册自定义值提供程序，以从其他源中获取用于模型绑定的数据。 例如，你可能需要来自 Cookie 或会话状态的数据。 要从新的源中获取数据，请执行以下操作：

- 创建用于实现 IValueProvider 的类。
- 创建用于实现 IValueProviderFactory 的类。
- 在 Startup.ConfigureServices 中注册工厂类。

示例应用包括从 Cookie 中获取值的 值提供程序和工厂示例。 以下是 Startup.ConfigureServices 中的注册代码：

    services.AddRazorPages()
        .AddMvcOptions(options =>
    {
        options.ValueProviderFactories.Add(new CookieValueProviderFactory());
        options.ModelMetadataDetailsProviders.Add(
            new ExcludeBindingMetadataProvider(typeof(System.Version)));
        options.ModelMetadataDetailsProviders.Add(
            new SuppressChildValidationMetadataProvider(typeof(System.Guid)));
    })
    .AddXmlSerializerFormatters();

所示代码将自定义值提供程序置于所有内置值提供程序之后。 要将其置于列表中的首位，请调用 Insert(0, new CookieValueProviderFactory()) 而不是 Add。


对不存在模型属性的源，默认情况下，如果找不到模型属性的值，则不会创建模型状态错误。 该属性设置为 NULL 或默认值：

- 可以为 Null 的简单类型设置为 null。
- 不可以为 Null 的值类型设置为 default(T)。 例如，参数 int id 设置为 0。
- 对于复杂类型，模型绑定使用默认构造函数来创建实例，而不设置属性。
- 数组设置为 Array.Empty<T>()，但 byte[] 数组设置为 null。

如果在模型属性的窗体字段中未找到任何内容时模型状态应失效，请 [BindRequired] 使用特性。

请注意，此 [BindRequired] 行为适用于发布的表单数据中的模型绑定，而不适用于请求正文中的 JSON 或 XML 数据。 请求正文数据由输入格式化程序进行处理。


类型转换错误，如果找到源，但无法将其转换为目标类型，则模型状态将被标记为无效。 目标参数或属性设置为 NULL 或默认值，如上一部分所述。

在具有 [ApiController] 属性的 API 控制器中，无效的模型状态会导致自动 HTTP 400 响应。
在Razor页面中，重新显示页面并显示一条错误消息：

    public IActionResult OnPost()
    {
        if (!ModelState.IsValid)
        {
            return Page();
        }

        _instructorsInMemoryStore.Add(Instructor);
        return RedirectToPage("./Index");
    }

客户端验证将捕获大多数提交到 Razor 页面窗体的错误数据。 此验证使得先前突出显示的代码难以被触发。 

如果要在表单域中重新显示错误数据，可以考虑将模型属性设置为字符串并手动执行数据转换。 如果不希望发生类型转换错误导致模型状态错误的情况，建议使用相同的策略。 在这种情况下，将模型属性设置为字符串。



## validate 验证
- [ModelStateDictionary](https://docs.microsoft.com/en-us/dotnet/api/microsoft.aspnetcore.mvc.modelbinding.modelstatedictionary?view=aspnetcore-3.1)
- [ASP.NET Core MVC 和 Razor 模型验证](https://docs.microsoft.com/zh-cn/aspnet/core/mvc/models/validation?view=aspnetcore-3.1)
- [DataAnnotations Sources Code](https://github.com/dotnet/runtime/tree/master/src/libraries/System.ComponentModel.Annotations/src/System/ComponentModel/DataAnnotations)
- [JQuery 验证文档](https://jqueryvalidation.org/documentation/)


DataAnnotations 命名空间提供一组内置验证特性，可通过声明方式应用于类或属性。 DataAnnotations 还包含 [DataType] 等格式特性，有助于格式设置但不提供任何验证。
请考虑 Customer 模型：

    using System.ComponentModel.DataAnnotations;

    namespace RazorPagesContacts.Models
    {
        public class Customer
        {
            public int Id { get; set; }

            [Required, StringLength(10)]
            public string Name { get; set; }
        }
    }

使用以下 Create.cshtml 视图文件 ：

    @page
    @model RazorPagesContacts.Pages.Customers.CreateModel
    @addTagHelper *, Microsoft.AspNetCore.Mvc.TagHelpers

    <p>Validation: customer name:</p>

    <form method="post">
        <div asp-validation-summary="ModelOnly"></div>
        <span asp-validation-for="Customer.Name"></span>
        Name:
        <input asp-for="Customer.Name" />
        <input type="submit" />
    </form>

    <script src="~/lib/jquery/dist/jquery.js"></script>
    <script src="~/lib/jquery-validation/dist/jquery.validate.js"></script>
    <script src="~/lib/jquery-validation-unobtrusive/jquery.validate.unobtrusive.js"></script>

客户端验证将阻止提交，直到表单变为有效为止。 jQuery Validate 验证要么提交表单要么显示错误消息。表单上存在输入错误时，客户端验证会避免到服务器的不必要往返。


服务器端验证：


    public async Task<IActionResult> OnPostAsync()
    {
        if (!ModelState.IsValid)
        {
            return Page();
        }

        if (!TryValidateModel(Movie, nameof(Movie)))
        {
            return Page();
        }

        _context.Movies.Add(Movie);
        await _context.SaveChangesAsync();

        return RedirectToPage("./Index");
    }



以下是一些内置验证特性：

- `[CreditCard]` 验证属性是否具有信用卡格式。 需要JQuery 验证其他方法。
- `[Compare]` 验证模型中的两个属性是否匹配。
- `[EmailAddress]` 验证属性是否具有电子邮件格式。
- `[Phone]` 验证属性是否具有电话号码格式。
- `[Range]` 验证属性值是否在指定的范围内。
- `[RegularExpression]` 验证属性值是否与指定的正则表达式匹配。
- `[Required]` 验证字段是否不为 null。
- `[StringLength]` 验证字符串属性值是否不超过指定长度限制。
- `[Url]` 验证属性是否具有 URL 格式。
- `[Remote]` 通过在服务器上调用操作方法来验证客户端上的输入。

通过验证特性可以指定要为无效输入显示的错误消息。 例如：

    [StringLength(8, ErrorMessage = "Name length can't be more than 8.")]
    [StringLength(8, ErrorMessage = "{0} length must be between {2} and {1}.", MinimumLength = 6)]

在内部，特性使用用于字段名的某个占位符调用 String.Format，有时还使用额外占位符。上述代码创建的错误消息定义名称长度必须介于 6 到 8 之间。错误消息如何递给 String.Format 的参数，请参阅 DataAnnotations 源代码。


验证规则的使用：

    [StringLength(60, MinimumLength = 3)]
    [Required]
    public string Title { get; set; }

    [Display(Name = "Release Date")]
    [DataType(DataType.Date)]
    public DateTime ReleaseDate { get; set; }

    [Range(1, 100)]
    [DataType(DataType.Currency)]
    [Column(TypeName = "decimal(18, 2)")]
    public decimal Price { get; set; }

    [RegularExpression(@"^[A-Z]+[a-zA-Z""'\s-]*$")]
    [Required]
    [StringLength(30)]
    public string Genre { get; set; }

    [RegularExpression(@"^[A-Z]+[a-zA-Z0-9""'\s-]*$")]
    [StringLength(5)]
    [Required]
    public string Rating { get; set; }

验证特性指定要对应用这些特性的模型属性强制执行的行为：

- `Required` 和 MinimumLength 特性表示属性必须有值；但用户可输入空格来满足此验证。
- `RegularExpression` 正则表达式特性，用于限制可输入的字符。 

    在上述代码中，即分类 Genre 属性要求：
    
    - 只能使用字母。
    - 第一个字母必须为大写。 不允许使用空格、数字和特殊字符。

    分级 Rating 属性要求：

    - 要求第一个字符为大写字母。 
    - 允许在后续空格中使用特殊字符和数字。 例如 PG-13 是有效分级，但对于分类无效。

- `Range` 特性限制在指定范围内取值。
- `StringLength` 特性使你能够设置字符串属性的最大长度，以及可选的最小长度。
- 指定值类型，如 decimal、int、float、DateTime，可以不需要 [Required] 特性。



DataType 特性仅提供相关提示来帮助视图引擎设置数据格式， DataType 特性不是验证特性。 可为 DataType.EmailAddress 创建 mailto: 链接。 可在支持 HTML5 的浏览器中为 DataType.Date 提供日期选择器。 DataType 特性发出 HTML 5 data- 特性供览器使用。

DisplayFormat 特性用于显式指定日期格式：

    [DisplayFormat(DataFormatString = "{0:yyyy-MM-dd}", ApplyFormatInEditMode = true)]
    public DateTime ReleaseDate { get; set; }

ApplyFormatInEditMode 设置用于指定在显示值进行编辑时需应用格式。 可能不希望某些字段具有此行为。 例如，在货币值中，可能不希望编辑 UI 中存在货币符号。


注意：jQuery 验证不适用于 Range 属性和 DateTime。 例如，以下代码将始终显示客户端验证错误，即便日期在指定的范围内：

    [Range(typeof(DateTime), "1/1/1966", "1/1/2020")]

通常，在模型中编译固定日期是不恰当的，因此不推荐使用 Range 特性和 DateTime。

    [StringLength(60, MinimumLength = 3)]
    public string Title { get; set; }

    [Display(Name = "Release Date"), DataType(DataType.Date)]
    public DateTime ReleaseDate { get; set; }

    [RegularExpression(@"^[A-Z]+[a-zA-Z""'\s-]*$"), Required, StringLength(30)]
    public string Genre { get; set; }

    [Range(1, 100), DataType(DataType.Currency)]
    [Column(TypeName = "decimal(18, 2)")]
    public decimal Price { get; set; }

    [RegularExpression(@"^[A-Z]+[a-zA-Z0-9""'\s-]*$"), StringLength(5)]
    public string Rating { get; set; }


让 ASP.NET Core 强制自动执行验证规则有助于提升你的应用的可靠性。 同时它能确保你无法忘记验证某些内容，并防止你无意中将错误数据导入数据库。

在浏览器中禁用 JavaScript 后，提交出错表单将发布到服务器，提交包含无效数据的表单。可以禁用浏览器有脚本功能，或在页面的 OnPostAsync 方法中设置断点以测试服务端验证模型状态是否无效，也可以使用 Fiddler 等工具：

    if (!ModelState.IsValid)
    {
        return Page();
    }

在助手标签中使用 DataAnnotations 特性并在客户端生成 jQuery 验证所需的 HTML 特性。 验证标记用于显示验证错误。

    <div asp-validation-summary="All"> validation? </div>
    <div asp-validation-summary="ModelOnly" class="text-danger"></div>
    <div class="form-group">
        <label asp-for="Movie.Title" class="control-label"></label>
        <input asp-for="Movie.Title" class="form-control" />
        <span asp-validation-for="Movie.Title" class="text-danger"></span>
    </div>





## Razor 模板指令参考


- 助手标签有三个相关指令。

    @addTagHelper   向视图提供助手标签。
    @removeTagHelper    从视图中删除以前添加的助手标签。
    @tagHelperPrefix    指定标记前缀，以启用助手标签支持并阐明助手标签的用法。

- @code 

    @code 块允许 Razor 组件将 C# 成员（字段、属性和方法）添加到组件。在 Razor 组件中，请使用 @code 而不是 @functions 来添加 C# 成员。此方案仅适用于 Razor 组件 (.razor)。

- @using 复合语句

    在 C# 中，using 语句用于确保释放对象。 在 Razor 中，可使用相同的机制来创建包含附加内容的 HTML 标签。 

        @using (Html.BeginForm())
        {
            <div>
                Email: <input type="email" id="Email" value="">
                <button>Register</button>
            </div>
        }

- @using 引入命名空间

    用于向视图添加 C# using 指令，如:

        @using System.IO
        @{
            var dir = Directory.GetCurrentDirectory();
        }
        <p>@dir</p>

- @try、catch、finally 异常处理

        @try
        {
            throw new InvalidOperationException("You did something invalid.");
        }
        catch (Exception ex)
        {
            <p>The exception message: @ex.Message</p>
        }
        finally
        {
            <p>The finally statement.</p>
        }

- @lock 使用 lock 语句来保护关键节点

        @lock (SomeLock)
        {
            // Do critical section work
        }

- @functions 

    指令允许将 C# 成员（字段、属性和方法）添加到生成的类中。在 Razor 组件中，请使用 @code 而不是 @functions 来添加 C# 成员。

        @functions {
            private void RenderName(string name)
            {
                <p>Name: <strong>@name</strong></p>
            }
        }

- @implements 指令为生成的类实现接口。

    以下示例实现 System.IDisposable，以便可以调用 Dispose 方法：

        @implements IDisposable

        <h1>Example</h1>

        @functions {
            private bool _isDisposed;

            ...

            public void Dispose() => _isDisposed = true;
        }

- @inherits 指令对视图继承的类提供完全控制。

    @model 和 @inherits 可在同一视图中使用。 @inherits 可位于视图导入的 `_ViewImports.cshtml` 文件中：

        @inherits CustomRazorPage<TModel>

- @inject 指令允许 Razor 页面将服务从服务容器注入到视图。 

- @layout 指令指定 Razor 组件的布局。

    此方案仅适用于 Razor 组件 (.razor)。布局组件用于避免代码重复和不一致。
    
- @model 指令指定传递到视图或页面的模型类型

    此方案仅适用于 MVC 视图和 Razor Pages (.cshtml)。@model 指令指定 Model 属性的类型。 该指令将 RazorPage<T> 中的 T 指定为生成的类，视图便派生自该类。 如果未指定 @model 指令，则 Model 属性的类型为 dynamic。 

- @model IndexModel 加载模块类实例


- @namespace 

    指令设置生成的 Razor 页面、MVC 视图或 Razor 组件的视图类的命名空间。不设置，可能会使用 `AspNetCore` 作为默认值。


- @page 

    @page 指令出现在 .cshtml 文件中表示该文件是 Razor Page。
    @page 指令出现在 Razor 组件，表示直接使用组件处理请求，可以使用路由匹配模板。编译带有 @page 指令的 .razor 文件时，将为生成的类提供指定路由模板的 RouteAttribute。
    
    指定页面的自定义路由 @page "/Some/Other/Path"
    将段追加到页面的默认路由，如 @page "item" 将 item 段添加到页面的默认路由。
    将参数追加到页面的默认路由。 例如，@page "{id}" 页面需要 ID 参数 id。

    还可以指定匹配参数的类型，如 @page "{id:int}" 指令，告诉页面接受包含 int 路由数据的页面请求。 

        @page "{id:int}"
        @page "{id:int?}"

    支持开头处以波形符指定的相对于根目录的路径。 例如，`@page "~/Some/Other/Path"` 和 `@page "/Some/Other/Path"` 相同。

    如果你不喜欢 URL 中的查询字符串 `?handler=JoinList`，请更改路由，将处理程序名称放在 URL 的路径部分。 可以通过在 @page 指令后面添加使用双引号括起来的路由模板来自定义路由。

        @page "{handler?}"
        
    可将多个路由模板应用于一个组件。 以下组件响应对 /BlazorRoute 和 /DifferentBlazorRoute 的请求：

        @page "/BlazorRoute"
        @page "/DifferentBlazorRoute"

        <h1>Blazor routing</h1>

    双星号 catch-all 语法用于捕获跨多个文件夹边界的路径，`@page "/{**path}"`，而无需编码正斜杠。


- @section

    @section 注入区块指令，与 MVC 和 Razor Pages 布局结合使用，允许视图或页面将内容呈现在 HTML 页面的不同部分。 此方案仅适用于 MVC 视图和 Razor Pages (.cshtml)。

    例如， ` _layout.cshtml` 在需要渲染输出的位置设置一条 @RenderSection 指令，然后在页面中，执行情况设置要渲染输出的内容：

        @RenderSection("scripts", required: false)

        @section Scripts {
            @if (Model.CanEdit)
            {
                await Html.RenderPartialAsync("EditorScriptsPartial");
            }
        }

    或者直接输出，不进行其它条件判断：

        @section scripts
        {
            <script>
                $(function() {
                    // some more js code here;
                });
            </script>
        }

    你可能需要嵌套这个区域，意思就是在 @section 里面嵌套调用 @RenderSection():

        @section scripts
        {
            @RenderSection("scripts", required: false)
        }


- @RenderBody() 在布局视图中执行渲染方法
- @RenderSection("Scripts", required: false) 在布局视图中执行区块渲染方法

- @attribute [Authorize] 指令将给定的属性添加到生成的页或视图的类中。
- @Html.ActionLink 调用函数生成链接

    有一些方法用来生成 HTML 元素，当 View 解析的时候这些 C# 代码会被解析成 HTML 元素。

    `<li>@Html.ActionLink("Go Home", "Index", "Home")</li>`
    `<li><a controller="Home" action="Index">Go Home</a></li>`

    以上两行等价，参考文档的链接助手类 anchor-tag-helper 了解如果构造 HTML 链接标记。

- @if/@for/@switch/@while/@do/@dowhile/@foreach (var x in y) 等流程控制代码块

        @if (forecasts == null)
        {
            <p><em>Loading...</em></p>
        }
        else
        {
            @foreach (var forecast in forecasts)
            {
            ...
            }
        }

- 代码块

    例如，给成员初始代块，设置布局或视图数据

        @{
            Layout = "_Layout";
            ViewData["Title"] = "Home Page";
        }

- 指令属性

    指令特性通常会改变元素的分析方式，或实现不同的功能，此方案仅适用于 Razor 组件 (.razor)。

    - @attributes 允许组件呈现未声明的属性。
    - @bind 实现组件中的数据绑定。
    - @on{EVENT} 为 Razor 组件提供事件处理功能，比如 @onclick。
    - @on{EVENT}:preventDefault 禁止事件的默认操作。
    - @on{EVENT}:stopPropagation 停止事件的事件传播。
    - @key 指令属性使组件比较算法保证基于键的值保留元素或组件。
    - @ref 组件引用 (@ref) 提供了一种引用组件实例的方法，以便可以向该实例发出命令。
    - @typeparam 指令声明生成的组件类的泛型类型参数。 


完整的指令参考 ASP.NET Core Documentation - Web Application - Razor syntax reference。


## Data Bindding 数据绑定

Razor 组件通过名为 @bind 的 HTML 元素特性提供了数据绑定功能，该特性具有字段、属性或 Razor 表达式值。

下面的示例将 CurrentValue 属性绑定到文本框的值，当文本框失去焦点时，该属性的值会更新。

可以使用 @bind:event 指定 oninput 事件，在文本框的值更改时激发更新。

数据绑定使用 @bind:format 处理 DateTime 格式字符串。 目前无法使用其他格式表达式，如货币或数字格式。

    <input @bind="CurrentValue" />
    <input @bind="CurrentValue" @bind:event="oninput" />

    @code {
        private string CurrentValue { get; set; }
    }

    <input @bind="StartDate" @bind:format="yyyy-MM-dd" />

    @code {
        [Parameter]
        public DateTime StartDate { get; set; } = new DateTime(2020, 1, 1);
    }

将 @bind 与 CurrentValue 属性结合使用在本质上等效于 @onchange 处理更新：

    <input value="@CurrentValue"
        @onchange="@((ChangeEventArgs __e) => CurrentValue = 
            __e.Value.ToString())" />
            
    @code {
        private string CurrentValue { get; set; }
    }

通过 @bind-{ATTRIBUTE}:event 语法使用 @bind-{ATTRIBUTE} 可绑定除 value 之外的元素属性。 在下面的示例中，当 paragraphStyle 值更改时，段落的样式会更新：

    @page "/binding-example"

    <p>
        <input type="text" @bind="paragraphStyle" />
    </p>

    <p @bind-style="paragraphStyle" @bind-style:event="onchange">
        Blazorify the app!
    </p>

    @code {
        private string paragraphStyle = "color:red";
    }

如果用户向数据绑定元素提供无法分析的值，则在触发绑定事件时，无法分析的值会自动还原为以前的值。

    <input @bind="MyProperty" />

    @code {
        [Parameter]
        public int MyProperty { get; set; } = 123;
    }

用户在页面中将该元素的值更新为 123.45，并更改元素焦点，元素的值会还原为 123。


在组件的绑定中，涉及子级和父级组件的关系时，会涉及事件的处理。在子组件中，可以使用 EventCallback 向父组件公开绑定数据的更改。使用 @bind-{PROPERTY} 可以将属性值从父组件向下绑定到子组件。

以下子组件 ChildComponent 具有 Year 组件参数和配套的 YearChanged 回调：

    <h2>Child Component</h2>

    <p>Year: @Year</p>

    @code {
        [Parameter]
        public int Year { get; set; }

        [Parameter]
        public EventCallback<int> YearChanged { get; set; }
    }

以下父组件使用 ChildComponent 并将 ParentYear 参数通过 @bind-Year 从父级绑定到子组件上的 Year 参数。

利用 onclick 事件用于触发父组件的 ChangeTheYear 方法来更新 ParentYear，然后按 @bind-Year 绑定将更新值传递到子组件，子组件自动执行配套的 YearChanged 更新子组件。

    @page "/ParentComponent"

    <h1>Parent Component</h1>

    <p>ParentYear: @ParentYear</p>

    <ChildComponent @bind-Year="ParentYear" />

    <button class="btn btn-primary" @onclick="ChangeTheYear">
        Change Year to 1986
    </button>

    @code {
        [Parameter]
        public int ParentYear { get; set; } = 1978;

        private void ChangeTheYear()
        {
            ParentYear = 1986;
        }
    }

Year 参数是可绑定的，因为它具有与 Year 参数类型相匹配的配套 YearChanged 事件。按照约定，以下两种写法在本质上等效：

    <ChildComponent @bind-Year="ParentYear" />
    <ChildComponent @bind-Year="ParentYear" @bind-Year:event="YearChanged" />

通常，可以通过包含 @bind-{PROPRETY}:event 特性将属性绑定到对应的事件处理程序。 例如，可以使用以下两个特性将属性 MyProp 绑定到 MyEventHandler：

    <MyComponent @bind-MyProp="MyValue" @bind-MyProp:event="MyEventHandler" />

你需要注意组件名是否正确，是否通过 using 引用的组件所在的目录，检查 `_Imports.razor`，错误可能导致 Razor 无法推断绑定的属性。



Blazor 提供了级联参数组件 CascadingValue 和 CascadingParameter 级联属性注解实现跨多层级的数据传送。CascadingValue 用来激活级联参数，然后在子级使用 CascadingParameter 来注解属性以获取级联传送的参数。

可以通过参数 Name 指定传递过程使用的名称，在 CascadingParameter 指定接收参数时使用相同的 Name 即可以获取到数据。当然 Name 是可选的参数，CascadingParameter 也可以通过类型推导来获取数据。示例中，如果 CascadingValue 不指定 Name，那么，ComponentA 中由 Name 获取数据。

下面示例定义三个组件，ComponentB 只作为跨层展示。

    <!-- ComponentA.razor -->
    <div class="bg-white p-3" style="color: #000;">
        <h3>ComponentA</h3>
        <p @onclick="tick">Value: @Value</p>
        <p>Name: @Name</p>
    </div>

    @code {
        private void tick(){
            Name = DateTime.Now.Millisecond.ToString();
        }

        [CascadingParameter(Name = "Value")]
        string Value { get; set; }
        
        [CascadingParameter]
        string Name { get; set; }
    }


    <!-- ComponentB.razor -->
    <div class="bg-secondary jumbotron text-white">
        <h3>ComponentB</h3>
        <ComponentA />
    </div>


    <!-- ComponentC -->
    <div class="bg-primary alert alert-info text-white">

        <h3>ComponentC</h3>
        <p>Name: @_name</p>
        <CascadingValue Value="@_name" Name="Value">
            <ComponentB />
        </CascadingValue>

    </div>

    @code {
        private string _name = "Abo";
    }

级联参数只能由父级向子级传递数据，要从子级向父级传递数据，还是要通过回调委托。只需要将该回调也通过 CascadingValue 传递出去，需要向上传递数据的子级负责调用即可。传递的方法有多种，但是无论哪种都需要在调用父组件的 StateHasChanged 来强制刷新。


此外，可以利用事件订阅模式设计一个 EventBus 来进行中心化的事件通信。EventBus 需要实现一个注册方法 Add，用来登记那些对某事件感兴的订阅者提供的事件委托，配套 Remove 方法用来移除事件委托。EventBus 还要实现一个分派方法 Dispatch，供事件发起方分发事件。这里实现了一个简化版 EventBus，对每种事件同时只能有一个订阅者可以接收到事件派发，只保留最后注册的事件委托有效。

    using System;
    using System.Collections.Generic;
    using System.Threading.Tasks;

    namespace AppWeb
    {

        public static class EventBus
        {
            private static Dictionary<string, Action<object>> _actions;

            public static Add(string event, Action<object> act)
            {
                Remove(event);
                _actions.Add(event, act);
            }

            public static bool Remove(string event)
            {
                if(_actions.ContainsKey(event))
                {
                    _actions.Remove(event);
                    return true;
                }
                return false;
            }

            public static void Dispatch(string event, object arg)
            {
                if(_actions.ContainsKey(event))
                {
                    var act = _actions[event];
                    act.Invoke(arg);
                }
            }
        }
    }


下面结合多种方法来实现子级到父级的数据传递，修改 ComponentA 和 ComponentC 即可：

    <!-- ComponentA.razor -->
    <div class="bg-white p-3" style="color: #000;">
        <h3>ComponentA</h3>
        <p>Name: @Name</p>
        <p>dp: @dp.value</p>
        <p class="btn btn-primary" @onclick="tick">@cb</p>
    </div>

    @code {

        private void tick(){
            Name = DateTime.Now.Second.ToString();

            EventBus.Dispatch("myevent", "EventBus" + Name);

            cb.Invoke("Callback" + Name);
            dp.StateHasChanged?.Invoke();
            
            System.Threading.Thread.Sleep(1000);
            dp.value = "DataPopup" + Name;
        }

        [CascadingParameter(Name="callback")]
        Action<string> cb {get; set;}

        [CascadingParameter]
        ComponentC.DataPopup dp {get; set;}
        
        [CascadingParameter]
        string Name { get; set; }
        
    }


    <!-- ComponentC -->
    <div class="bg-primary alert alert-info text-white">

        <h3>ComponentC</h3>
        <p>Name: @_name</p>
        <p>dp: @_dp.value</p>
        <CascadingValue Value="@_dp">
            <CascadingValue Value="@_callback" Name="callback">
            <CascadingValue Value="@_name">
                <ComponentB />
            </CascadingValue>
            </CascadingValue>
        </CascadingValue>

    </div>

    @code {
        private string _name = "Abo";
        private DataPopup _dp;
        private Action<object> _callback;

        public void _cb(object v)
        {
            _dp.value = v as string;
        }

        protected override void OnInitialized()
        {
            base.OnInitialized();
            _callback = _cb;
            EventBus.Add("myevent", _callback);
            // EventBus.Add("myevent", e => _name = e as string);
            // EventBus.Add("myevent", delegate(string e){ _cb(e); });
            _dp = new DataPopup(StateHasChanged);
        }

        public class DataPopup
        { 
            public Action StateHasChanged;
            public string value {get; set;}

            public DataPopup( Action shc )
            {
                StateHasChanged += shc;
            }
        }
    }

在 tick() 方法中，虽然有多个途径更新数据，但是由于代码的运行是需要服务端的协同，所以即使使用 Sleep 延时，最终获取到的也是 DataPopup 对象传递的数据。StateHasChanged 的调用顺序也没有什么关系。




# ASP.NET Core MVC 入门
- [ASP.NET Core MVC 入门](https://docs.microsoft.com/zh-cn/aspnet/core/tutorials/first-mvc-app/start-mvc?view=aspnetcore-3.1)
- [Entity Framework Core 数据层框架](https://docs.microsoft.com/en-us/ef/core/)
- [Microsoft.EntityFrameworkCore Namespace](https://docs.microsoft.com/zh-cn/dotnet/api/microsoft.entityframeworkcore?view=efcore-2.1)

MVC - Model-View-Controller 体系结构模式将应用分成 3 个主要组件，有助于创建比传统单片应用更易于测试和更新的应用。 基于 MVC 的应用包含：

- Model 模型 (M)

    表示应用数据的类。 模型类使用验证逻辑来对该数据强制实施业务规则。 通常，模型对象检索模型状态并将其存储在数据库中。 本教程中，Movie 模型将从数据库中检索电影数据，并将其提供给视图或对其进行更新。 更新后的数据将写入到数据库。

- View 视图 (V) 

    视图是显示应用用户界面 (UI) 的组件。 此 UI 通常会显示模型数据。

- Controller 控制器 (C)

    处理浏览器请求的类。 它们检索模型数据并调用返回响应的视图模板。 在 MVC 应用中，视图仅显示信息；控制器处理并响应用户输入和交互。 

例如，控制器处理路由数据和查询字符串值，并将这些值传递给模型，该模型可使用这些值查询数据库。

- `https://localhost:5001/Home/Privacy` 具有 Home 控制器的路由数据，Privacy 为 Home 控制器上调用的操作方法。
- `https://localhost:5001/Movies/Edit/5` 是一个请求，用于通过电影控制器编辑 ID 为 5 的电影。 
- `<a asp-controller="Home" asp-action="Welcome">Welcome</a>` 构造控制器视图 URL 链接。
- `<a asp-controller="Home" asp-action="Welcome" asp-route-name="Rick">Welcome</a>`携带参数，URL 为 /Home/Welcome?name=Rick。


MVC 模式可帮助创建分隔不同应用特性（输入逻辑、业务逻辑和 UI 逻辑）的应用，同时让这些元素之间实现松散耦合。 该模式可指定应用中每种逻辑的位置。 UI 逻辑位于视图中。 输入逻辑位于控制器中。 业务逻辑位于模型中。 这种隔离有助于控制构建应用时的复杂程度，因为它可用于一次处理一个实现特性，而不影响其他特性的代码。 例如，处理视图代码时不必依赖业务逻辑代码。


## View & Controller
- [Web API 应用开发](https://docs.microsoft.com/zh-cn/aspnet/core/web-api/?view=aspnetcore-3.1)
- [Web Apps MVC Routing](https://docs.microsoft.com/en-us/aspnet/core/mvc/controllers/routing?view=aspnetcore-3.1)
- [ASP.Net Core HttpContext Class](https://docs.microsoft.com/en-us/dotnet/api/microsoft.aspnetcore.http.httpcontext?view=aspnetcore-3.1)
- [ASP.Net Core Controller Class](https://docs.microsoft.com/en-us/dotnet/api/microsoft.aspnetcore.mvc.controller?view=aspnetcore-3.1)
- [MVC 路由设置](https://docs.microsoft.com/zh-cn/aspnet/core/mvc/controllers/routing?view=aspnetcore-3.1)

创建 MVC 应用:

    dotnet new mvc -o MvcMovie
    code -r MvcMovie

使用 VS Code 打开项目，提示对话框架会询问是否要为项目添加 build and debug 配置，选择 Yes 生成 .vscode 目录下的配置文件方便开发执行 build/publish/watch 等任务。

MVC 项目有对应的目录结构，方便管理，以及 MVC 核心路逻辑的映射：

- Controllers 存放控制器的目录；
- Models 存放模型的目录；
- Views 存放视图的目录；

MVC 项目的 Startup 配置关键有两点，AddControllersWithViews 激活 MVC，MapControllerRoute 配置 MVC 路由，这里配置一个目标指向 Home 控制器的路由：

    public class Startup
    {
        ...
        public void ConfigureServices(IServiceCollection services)
        {
            services.AddControllersWithViews();
        }

        public void Configure(IApplicationBuilder app, IWebHostEnvironment env)
        {
        ...
            app.UseEndpoints(endpoints =>
            {
                endpoints.MapControllerRoute(
                    name: "default",
                    pattern: "{controller=Home}/{action=Index}/{id?}");
            });
        }
    }

ASP.Net Core 中，控制器有两类，ControllerBase 和 Controller。 

根据惯例，标准控制器类：

- 驻留在项目的 /Controllers 文件夹中。
- 继承自 Microsoft.AspNetCore.Mvc.Controller。

标准控制器是一个可实例化的类，其中下列条件至少某一个为 true：

- 类名称带有 Controller 后缀，文件名不用。
- 该类继承自带有 Controller 后缀的类。
- [Controller] 特性应用于该类。

控制器类不可含有关联的 [NonController] 属性特性。

在指定了 [ApiController] 特性的控制器，即 RESTful API 控制器，也称为 Web API。Web API 中的控制器是派生自 ControllerBase 的类。 

在 Startup 中通过 endpoints.MapControllerRoute 配置好 MVC 路由后，就可以开始控制器的设计：

    using System;
    using Microsoft.AspNetCore.Mvc;
    using Microsoft.Extensions.Logging;

    namespace MvcMovie.Controllers
    {
        [Controller]
        public class HomeController : Controller
        {
            private readonly ILogger<HomeController> _logger;

            public HomeController(ILogger<HomeController> logger)
            {
                _logger = logger;
            }

            public IActionResult Index()
            {
                return View();
            }

            public IActionResult Privacy()
            {
                return View();
            }

            [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
            public IActionResult Error()
            {
                return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
            }

            // GET: /Home/Welcome/ 
            // Requires using System.Text.Encodings.Web;
            public string WelcomePlain(string name, int numTimes = 1)
            {
                return HtmlEncoder.Default.Encode($"Hello {name}, NumTimes is: {numTimes}");
            }

            public IActionResult Welcome(string name, int numTimes = 1)
            {
                ViewData["Message"] = "Hello " + name;
                ViewData["NumTimes"] = numTimes;

                return View();
            }
        }
    }


这个控制器类使用了以下 [Route] 属性特性，来定义控制的路由路径。

    [Route("[controller]")]

控制器上的公共方法均为 Action 操作，除了那些带有 `[NonAction]` 属性特性的方法。 操作上的参数会绑定到请求数据，并使用模型绑定进行验证。 所有模型绑定的内容都会执行模型验证。 ModelState.IsValid 属性值指示模型绑定和验证是否成功。


视图方法可以定义接收参数，参数信息从 URL 传递到控制器。 例如以下助手标签构造和相应 HTML 标签链接：

    <a asp-area="" asp-controller="Home" asp-action="Welcome" asp-route-numtimes="4">Welcome</a>

    <a href="/Home/Welcome?name=Rick&numtimes=4">Welcome</a>

以上使用的助手标签类 tag-helpers，可以在 ViewImports 文件中找到引用，然后就可以使用助手标签来定制 HTML 标记：

    @addTagHelper *, Microsoft.AspNetCore.Mvc.TagHelpers

如果浏览页面时发现助手标签并没有生成相应的 HTML 标签，那么可能就是没有添加 tag-helpers 的引用。


控制器方法，即 Action 通常返回 IActionResult 或 ActionResult 派生类的控制器方法，通过控制器的 View 方法，以约定的配套视图输出到客户端。以便下和控制器方法名称对应的视图文件就会被加载：

- /Views/Home/Index.cshtml
- /Views/Home/Privacy.cshtml
- /Views/Home/Error.cshtml
- /Views/Home/Welcome.cshtml


控制器有三种事件：

- OnActionExecuted  事件会在 Action 执行后触发，传入参数 ActionExecutedContext；
- OnActionExecuting 事件会在 Action 执行前触发，传入参数 ActionExecutingContext；
- OnActionExecutionAsync    执行前事件的异步方式，入参 ActionExecutingContext, ActionExecutionDelegate；


以下是常用返回视图和已格式化的响应，参考页面布局：

- Json(Object)  创建 JsonResult，将参数对象序列化为 JSON；

- Partial View 页面片断渲染

    - PartialView() 创建 PartialViewResult 渲染页面的其中部分；
    - PartialView(String)   创建 PartialViewResult，指定视图文件名；
    - PartialView(Object)   创建 PartialViewResult，指定模型数据参数；
    - PartialView(String, Object)   创建 PartialViewResult，指定视图文件名和模型数据；

- View 基本视图渲染

    - View()    创建 ViewResult 以渲染页面；
    - View(Object)  创建 ViewResult，指定模型对象渲染页面；
    - View(String)  创建 ViewResult，指定视图文件名；
    - View(String, Object)  创建 ViewResult，指定视图文件名和模型对象；

- View Comoponent 视图组件渲染

    - ViewComponent(String) 创建 ViewComponentResult，指定组件文件名渲染；
    - ViewComponent(Type)   创建 ViewComponentResult，指定组件类型；
    - ViewComponent(String, Object) 创建 ViewComponentResult，指定组件文件名及参数对象；
    - ViewComponent(Type, Object)   创建 ViewComponentResult，指定组件类型和参数对象；


当操作返回其它任何数据类型时，就会应用内容协商结果格式化的响应。比如方法返回字符串，那么就直接将字符串返回给客户端。返回其它对象时，就会根据进行内容协商 Content Negotiation，即根据 HTTP 请求头的 Accept 来决定输出，支持 application/json, text/json, text/plain 等，ASP.Net Core 默认为 JSON。 

控制器定义了响应各种 HTTP 状态的方法，它们会设置 HTTP 响应标头的状态码，还有各种用于重定向的方法。 BadRequest 和 Ok 仅在传递了值的时候才执行内容协商，在没有传递值的情况下，它们充当 HTTP 状态码结果类型。 另一方面，CreatedAtRoute 方法始终执行内容协商，因为它的重载均要求传递一个值。

以下部分参考：

    return NoContent(); // HTTP 204
    return Ok(value); // HTTP 200
    return NotFound(); // HTTP 404
    return BadRequest(ModelState); // HTTP 400
    return Redirect(url); // HTTP 302
    return LocalRedirect(localurl);
    return RedirectToPage(string, object);
    return RedirectToAction("Complete", new {id = 123});
    return CreatedAtRoute("routename", values, newobject); 


MVC 的 视图文件和 Razor Page 都是使用 Razor 语法的，只是 @page 指令会将视图转化为 Razor Page 类型，所以在 MVC 视图中不能使用。

    @page
    @model IndexModel
    @{
        ViewData["Title"] = "Home page";
    }


在视图中，使用 ViewData 字典从控制器传递数据，传递数据的视图模型方法通常比 ViewData 字典方法更为优先。 有关详细信息，请参阅何时使用 ViewBag、ViewData 或 TempData。

- ViewData 字典对象，继承自 ViewDataDictionary，如 ViewBag["Product"] = "something";
- ViewBag 封装了 ViewData，允许使用动态属性，如 ViewBag.Product = "something";
- TempData 字典对象，用在临时过程，比如当前这个多个请求间。






### API Controllers
- [MVC 路由设置](https://docs.microsoft.com/zh-cn/aspnet/core/mvc/controllers/routing?view=aspnetcore-3.1)
- [Format Respose data](https://docs.microsoft.com/en-us/aspnet/core/web-api/advanced/formatting?view=aspnetcore-3.1)
- [ASP.NET Core Web API 自定义格式化程序](https://docs.microsoft.com/zh-cn/aspnet/core/web-api/advanced/custom-formatters?view=aspnetcore-3.1)
- [Web API 应用](https://docs.microsoft.com/zh-cn/aspnet/core/web-api/?view=aspnetcore-3.1#apicontroller-attribute)
- [使用 ASP.NET Core 创建 Web API](https://docs.microsoft.com/zh-cn/aspnet/core/web-api/?view=aspnetcore-3.1)


不同的用途的控制器类可以继承不同的基类，标准的 MVC 控制吕继承 Controller 基类，获取视图及数据传递功能。

而用于 RESTful API 的控制器，可以继承更精简的 ControllerBase 基类，其路由注册的方式使用属性特性设置，和标准控制器有差别。

以下是 API 中常用的属性特性：

| 特性    | 说明 |
| :---- | :--- |
| [ApiController]   | 指定控制器为 API 控制行为，如 Model Binding 模型绑定。 |
| [Route]   | 指定控制器或操作的 URL 模式。 |
| [Bind]    | 指定要包含的前缀和属性，以进行模型绑定。 |
| [HttpGet] 标识支持 HTTP GET |操作谓词的操作。 |
| [Consumes]    | 指定某个操作接受的数据类型。 |
| [Produces]    | 指定某个操作返回的数据类型。 |
| [NonAction]   | 指定的控制器方法不响应 Action 动作。 |

在开发控制器时，会需要测试 API 接口，可以使用图形化工具，如 Fiddler 也可以使用像 Curl 这样的命令行工具：

    curl -i -H "Content-Type:application/json" -d "{""Id"":""122"", ""Text"":""name"", ""Description"":""anything""}" -X POST http://127.0.0.1:5001/api/item

[ApiController] 属性可应用于控制器类，以启用下述 API 特定的固定行为：

- 属性路由要求

    不能通过 Startup 中的 UseEndpoints、UseMvc 或 UseMvcWithDefaultRoute 定义的传统路由访问操作。

- 自动 HTTP 400 响应

    使模型验证错误自动触发 HTTP 400 响应。ASP.NET Core MVC 使用 ModelStateInvalidFilter 操作筛选器来执行上述检查。

- 绑定源参数推理

    数据源绑定特性定义可找到操作参数值的位置，，参考数据绑定 Data Binding。

    | [FromBody]    | 请求正文 |
    | :---------    | :------ |
    | [FromForm]    | 请求正文中的表单数据 |
    | [FromHeader]  | 请求标头 |
    | [FromQuery]   | 请求查询字符串参数 |
    | [FromRoute]   | 当前请求中的路由数据 |
    | [FromServices]    | 作为操作参数插入的请求服务 |

- Multipart/form-data 请求推理

    使用 FromFormattribute 属性批注操作参数时，[ApiController] 属性应用推理规则。 将推断 multipart/form-data 请求内容类型。

- 错误状态代码的问题详细信息

    当兼容性版本为 2.2 或更高版本时，MVC 会将错误结果（状态代码为 400 或更高的结果）转换为状态代码为 ProblemDetails 的结果。 ProblemDetails 类型基于 RFC 7807 规范，用于提供 HTTP 响应中计算机可读的错误详细信息。

使用 [Consumes] 属性定义支持的请求内容类型
默认情况下，操作支持所有可用的请求内容类型。 例如，如果应用配置为同时支持 JSON 和 XML 输入格式化程序，那么操作支持多种内容类型，其中包括 application/json 和 application/xml。
使用 [Consumes] 属性，操作可以限制支持的请求内容类型。 将 [Consumes] 属性应用于操作或控制器，同时指定一个或多个内容类型：

    [HttpPost]
    [Consumes("application/xml")]
    public IActionResult CreateProduct(Product product)

在上面的代码中，CreateProduct 操作指定内容类型 application/xml。 路由到此操作的请求必须指定 application/xml 的 Content-Type 头。 如果请求未指定 application/xml 的 Content-Type 头，会生成 415 不支持的媒体类型响应。


下面是 ControllerBase 提供的常用方法。

| 方法    | 说明 |
| :---- | :--- |
| BadRequest    | 返回 400 状态代码。 |
| NotFound  | 返回 404 状态代码。 |
| PhysicalFile  | 返回文件。 |
| TryUpdateModelAsync   | 调用模型绑定。 |
| TryValidateModel  | 调用模型验证。 |


要标记  RESTful API 控制器，可以使用 ApiControllerAttribute 属性标记，RouteAttribute 用来自定义路由，那么 Hello 控制器类对应的访问 URL 就是 /api/hello:

    [Route("api/[controller]")]
    [ApiController]
    public class Hello : Controller
    {
        ...
    }

API 的方法还需要定义 HTTP 谓词，即请求方式的属性标记，都有两个构造器，一个无参数，另一个接收 String 参数作为路由模板以配置 URL 参数，它们定义在 Microsoft.AspNetCore.Mvc 命名空间：

    [HttpGet]
    [HttpGet("{id}")]
    [HttpPut("{id}")]
    [HttpPost]
    [HttpDelete("{id}")]
    [HttpHead]
    [HttpOptions]
    [HttpPatch]

像 {id} 或 {id}/{name?} 这样的模板参数，对应 URL 匹配 `/api/hello/1?name=x` 或者 `/api/hello/1/x`，但不会匹配到 `/api/hello?id=1&name=x`。也就是说只匹配 URL 中的 Path 部分，而不管问号后的查询字符串值。id 参数与默认路由匹配，因此 id 添加到路由数据。要将 name 参数添加到路由数据，就修改 Statup 中控制器路由映射关系：

    endpoints.MapControllerRoute(
        name: "default",
        pattern: "{controller=Hello}/{action=Index}/{id?}/{name?}");

对应的 anchor-tag-helper：

    <a asp-area="" asp-controller="api" asp-action="hello" asp-route-id="1" asp-route-name="x">API</a>

    @Html.ActionLink("API", "hello", "api", new { id = 1, name = "x" })

@Html.ActionLink 完全参数签名如下，要生成一个指向静态页面的地址，不使用 asp- 即可，也可以留空 asp-action，将页面地址传入 controller：

    @Html.ActionLink("linkText", "actionName", "controllerName", routeValues, htmlAttributes)

    <a class="nav-link text-dark" asp-area="" asp-controller="/index.html" asp-action="">static</a>
    <a class="nav-link text-dark" href="/index.html">contoso.com</a>


要允许多个 HTTP 谓词用于某个操作，或允许除 GET、PUT、POST、DELETE、HEAD、OPTIONS 和 PATCH 以外的 HTTP [AcceptVerbs] 谓词，请使用该属性，该属性采用 HTTP 谓词的列表。

    public class ProductsController : ApiController
    {
        [AcceptVerbs("GET", "HEAD")]
        public Product FindProduct(id) { }

        // WebDAV method
        [AcceptVerbs("MKCOL")]
        public void MakeCollection() { }
    }

要防止将方法作为操作调用，请使用属性标记 `[NonAction]`。 这向框架发出信号，说明该方法不是操作，即使它以其他方式与路由规则匹配也是如此。

注意，使用路由属性特性时，在控制器对象及方法上设置的属性路由会叠加生成最终的路由规则，如下：

    [Route("api/[controller]")]
    public class Hello : Controller
    {
        [Route("api/hello/edit", Name="api_edit")]
        [HttpGet("{id}")]
        public object GetUserDTO(int id, string name)

为了看到最后生成的路由规则，可以利用脚手标签的 URL 生成功能。应用可以使用路由 URL 生成功能来生成指向操作的 URL 链接。 生成 URL 可消除硬编码 URL，使代码更可靠和更易于维护。 

通过给 asp-route 来指定一个命名路由，即上面代码中指定的 `Name="api_edit` 这个路由名称，助手标签及生成的 HTML 标签如下：

    <a asp-area="" asp-route="api_edit">Edit</a> |

    <a href="/api/Hello/api/hello/edit"></a>


假如，配置了以下带有自定义前缀的路由：

    [Route("api/[controller]")]

这种路由一般是为 API 控制器使用的，无法通过 asp-controller 和 asp-action 或 asp-page、asp-handler 来生成对应 URL 的。API 控制器中激活了属性路由，一般也不在 URL 指定 Action，直接通过控制器名称加参数列表匹配一个操作，通过属性特性指定 HTTP 谓词。

使用命名路由 asp-route 是一种解决方法。或者使用 HTML 链接标签，注意不能使用 asp- 属性，以免激活 ASP.Net Core 的助手标签。

二是使用 URL 生成，IUrlHelper 接口是 MVC 用于生成 URL 路由的基础元素，IUrlHelper 实例可通过控制器、视图及视图组件中的 Url 属性引用，如下：

    // Generates /UrlGeneration/Destination
    var url = Url.Action("Destination");
    return ControllerContext.MyDisplayRouteInfo("", $" URL = {url}");

三是通过 asp-area 区域机制组织控制器目录结构，使用一个称为 api 区域来解决


### OpenAPI Documentation
- [Swagger/OpenAPI API 自助文档](https://docs.microsoft.com/zh-cn/aspnet/core/tutorials/web-api-help-pages-using-swagger?view=aspnetcore-3.1)

使用 Web API 时，帮助用户了解其各种方法对开发人员来说可能是一项挑战。 Swagger 现在也称为 OpenAPI，解决了为 Web API 生成有用文档和帮助页的问题。 它具有诸如交互式文档、客户端 SDK 生成和 API 可发现性等优点。

Swagger 是一个与语言无关的规范，用于描述 REST API。 Swagger 项目已捐赠给 OpenAPI 计划，现在它被称为 OpenAPI。 这两个名称可互换使用，但 OpenAPI 更常见。 它允许计算机和人员了解服务的功能，而无需直接访问实现（源代码、网络访问、文档）。 其中一个目标是尽量减少连接取消关联的服务所需的工作量，另一个目标是减少准确记录服务所需的时间。

使用开源项目 Swashbuckle.AspNetCore 搭配 NSwag .NET Swagger 实现，用于生成 ASP.NET Core Web API 的 Swagger 文档。

NSwag 是另一个用于生成 Swagger 文档并将 Swagger UI 或 ReDoc 集成到 ASP.NET Core Web API 中的开源项目。 此外，NSwag 还提供了为 API 生成 C# 和 TypeScript 客户端代码的方法。

Swagger UI 提供了基于 Web 的 UI，它使用生成的 Swagger 规范提供有关服务的信息。 Swashbuckle 和 NSwag 均包含 Swagger UI 的嵌入式版本，因此可使用中间件注册调用将该嵌入式版本托管在 ASP.NET Core 应用中。

控制器中的每个公共操作方法都可以从 UI 中进行测试。 单击方法名称可以展开该部分。 添加所有必要的参数，然后单击“试试看!” 。

Swagger 流的核心是 Swagger 规范，默认情况下是名为 swagger.json 的文档 。 它由 Swagger 工具链（或其第三方实现）根据你的服务生成。 它描述了 API 的功能以及使用 HTTP 对其进行访问的方式。 它驱动 Swagger UI，并由工具链用来启用发现和客户端代码生成。 



## Database & Entity Framework Core
- [Entity Framework Core](https://docs.microsoft.com/zh-cn/ef/)
- [ASP.NET Core 和 Entity Framework 6 入门](https://docs.microsoft.com/zh-cn/aspnet/core/data/entity-framework-6?view=aspnetcore-3.1)
- [ASP.NET Core MVC with EF Core](https://docs.microsoft.com/zh-cn/aspnet/core/data/ef-mvc/?view=aspnetcore-3.1)
- [Razor Pages with EF Core](https://docs.microsoft.com/zh-cn/aspnet/core/data/ef-rp/intro?view=aspnetcore-3.1)
- []()

Entity Framework Core 是适用于 .NET 的新式对象数据库映射器。 它支持 LINQ 查询、更改跟踪、更新和架构迁移。 EF Core 适用于很多数据库，包括 SQL 数据库（本地和 Azure）、SQLite、MySQL、PostgreSQL 和 Azure Cosmos DB。

数据库读取的数据以数据模型对象的方式存在，即 MVC 中 Model 部分，ASP.NET Code 使用自带的 Entity Framework Core， EF Core 是对象关系映射 ORM - Object Relation Mapping 框架。同其它 ORM，如，NHibernate，Hibernate 一样，可以简化需要编写的数据访问代码，它可以将关系数据表的记录映射为对象。

若要使用 Entity Framework 6，则项目必须面向 .NET Framework 进行编译，因为 EF6 不支持 .NET Core。 如果需要跨平台功能，需升级到 Entity Framework Core。

在 ASP.NET Core 应用程序中使用 EF6 的推荐方法是：将 EF6 上下文和模型类放入面向 .NET Framework 的类库项目中。 添加对 ASP.NET Core 项目中的类库的引用。

EF6 实现丰富的 ORM 功能，EF Core 则完全进行了重写，包含许多 EF6 没有的新功能，但还是缺少 EF6 中最高级的一些映射功能。

- 不依赖于任何 EF 类型的 POCO (Plain Old CLR Object) 实体类的映射
- 自动更改跟踪
- 标识解析和工作单元
- 预先、延迟和显式加载
- 使用 LINQ（语言集成查询）转换强类型查询
- 丰富的映射功能，可支持：
    - 一对一、一对多和多对多关系
    - 继承（每个层次结构一张表、每个类型一张表和每个具体类一张表）
    - 复杂类型
    - 存储过程
    - 通过可视化设计器创建实体模型。
- 通过编写代码创建实体模型的“Code First”体验。
- 既可从现有数据库生成模型，然后手动编辑，也可从头开始创建模型，然后用于生成新的数据库。
- 与 .NET Framework 应用程序模型（包括 ASP.NET）集成，并通过数据绑定与 WPF 和 WinForms 集成。
- 基于 ADO.NET 的数据库连接和可用于连接到 SQL Server、Oracle、MySQL、SQLite、PostgreSQL、DB2 等的众多提供程序。

DbContext 这个类是 EF Code First 的核心，在高层次上是数据库抽象。数据库包含了表，每个表又包含了行和列。DbContext 有泛型集合属性，每个属性的类型是 DbSet<TRowType>对应于每个表。集合中的每个对象指的是一个实体，代表相应表中的一行。

一旦这个结构布局好了，那么你就能够通过LINQ查询来查询底层的数据库了。如果你将一个全新的 TRowType 类的实例添加到父集合中，然后使用 DbContext API 保存更改，那么这个新的对象就会变成相应表中的一行，该对象的每个属性的值就会变成该行相应的列值。此外，EF 有能力表示其他的数据库工件，比如存储过程和函数。数据库结构的进化是很重要的一个问题，在大多数情况，随着应用程序的变化，你需要添加列和表，EF 是通过 Migration 迁移功能来解决这个问题的。这个能力允许你通过 C# 代码更改数据库结构，除了添加和删除表和列之外，还可以添加索引。Migration 可以没有数据损失地进化数据库模式。你将会看到，EF 会暴露你需要使用 C# 访问的一切数据而不需要编写 SQL，并且像对待你整个应用程序代码的一部分来对待数据库。

Entity Framework 架构构建在 DAO.NET provider 架构之上。当开发者使用 C# 创建一个 LINQ 查询时，EF 框架引擎会连接一个 provider，将它转换成实际的 SQL 语句，最后发往数据库执行。任何给定的 provider 都是连接 Entity Framework 和一个特定的 RDBMS 的桥梁。一旦该 provider 执行了最终的 SQL 命令，结果就被 EF 对象化到 .NET 对象中，Data reader 就是为了这个目。理解 EF 构建于 ADO.NET 之上非常重要，因此，EF 也使用了诸如 connection，command，和 data reader 的概念。

数据持久化，也就是插入，更新和删除功能，插入时，开发者将一个实体类的实例添加到数据库上下文中。相似地，之前添加到上下文中的实例被标记为 changed 或 deleted，就会产生对数据库即将执行更新和删除的语句。EF 会检查上下文中的每个对象，再次使用 provider 来创建 RDBMS 特定的 insert, update 或 delete 命令。

Entity Framework 概念数据模型和持久化，首先来理解 EDM - Entity Data Model 以及 EF 如何使用它管理数据库操作，概念数据模型是 EF 的核心。要使用 EF 必须创建概念数据模型。EDM 定义了我们的概念模型类，这些类之间的关系，以及这些模型到数据库模式之间的映射。

一旦创建了 EDM 就可以对概念模型执行所有的 CRUD 操作，EF 会将所有的这些对象查询翻译成数据库查询 SQL。一旦这些查询执行了，EF 就会将返回的结果转成概念模型对象实例。EF 会使用存储在 EDM 中的映射信息来执行对象查询到 SQL 查询，以及相关的数据到概念模型的翻译。

一旦我创建了 EDM，我就有了应用程序中可以使用的所有的实体。然而，我还需要一个东西来让我在这些实体上执行各种操作。它就是 EF 中的 ObjectContext 类。要执行 CRUD 操作，必须使用 ObjectContext 类。 

ObjectContext 类是 EF 中的主要对象，它负责：

- 管理数据库连接
- 提供执行CRUD操作的支持
- 追踪模型的更改，目的在于在数据库中更新模型

可以理解成管理 EDM 中所有实体的东西，让我们为这些实体执行所有的数据库操作。当我们想要保存一个新的或者更改的对象到数据库时，我们必须调用 ObjectContext 类中的 SaveChanges 方法。

Entity Framework 基本有二种开发模式：

- Database First

    数据库逆向工程，这是一种用于已存在数据库模式的方法，也就是数据库结构的逆向工程，通过数据库结构生成代码。使用这种方法，EDM - Entity Data Model 即实体数据模型对象是从数据库模式中生成的，这种方法最适合于使用了已经存在的数据库的应用。

- Code First 或 Model First

    编写模型代码建立 EDM 或使用 Visual Studio 提供的 EDM 可视化设计器来设计模型，依据这些类定义创建数据库。这种方法最适合于那些高度以领域为中心并且领域模型类创建优先的应用程序。这里需要的数据库只是为了这些领域模型的持久化机制。


### ASP.Net Codegenerator 基架工具

使用 dotnet aspnet-codegenerator 运行 ASP.NET Core 基架引擎，有了这个工具，它只需要从命令行搭建基架，不必使用 Visual Studio 搭建基架。要生成数据库上下文类型实现需要使用 EF CLI 工具，安装相应的 Design 类来生成代码。要使用数据库，还需要安装相应的数据接口，InMemory 是内存数据库，没有数据库服务器时可以它用来做测试用。根据需要安装这些数据库工具和类库：

    dotnet tool install --global dotnet-ef

    dotnet add package Microsoft.EntityFrameworkCore.SQLite
    dotnet add package Microsoft.EntityFrameworkCore.SqlServer
    dotnet add package Microsoft.EntityFrameworkCore.InMemory

    dotnet add package Microsoft.VisualStudio.Web.CodeGeneration.Design
    dotnet add package Microsoft.EntityFrameworkCore.Design

    dotnet add package MySql.Data
    dotnet add package MySql.Data.EntityFrameworkCore
    dotnet add package MySql.Data.EntityFrameworkCore.Design

    dotnet tool install -g dotnet-aspnet-codegenerator
    dotnet tool update -g dotnet-aspnet-codegenerator

命令使用： 

    dotnet ef migrations add InitialCreate
    dotnet ef database update

    dotnet aspnet-codegenerator [arguments] [-p|--project] [-n|--nuget-package-dir] [-c|--configuration] [-tfm|--target-framework] [-b|--build-base-path] [--no-build] 

    dotnet aspnet-codegenerator [-h|--help]

以下是可用的生成器：

- area  搭建区域的基架，即生成按区域组织的 MVC 目录结构，可以属性标记 [Area("xyz")] 将控制器与区域关联
- controller    搭建控制器的基架
- identity  搭建标识的基架
- razorpage 搭建 Razor Pages 的基架
- view  搭建视图的基架

使用生成器来创建控制器或 Razor Page，注意 -m Model 指定的类必需已经存在，而 -dc DbContext 会根据指定的名称生成：

    dotnet aspnet-codegenerator controller -name=Hello --model=MO --dataContext=DBC --layout=_Layout -async -api -sqlite -namespace=myWebApp
    dotnet aspnet-codegenerator razorpage MyEdit Edit -m Movie -dc RazorPagesMovieContext -outDir Pages/Movies


数据模型及生成的的 DbContext 类参考，代码重新组织放一起，使用 Attribute 可以修改映射关系，比如 [Table("users", Schema = "minispro")] 映射指定数据库和表。考虑到数据表中，存在 null 字段，在 C# 中需要设置 nullable 属性以免读取出错：

    using System;
    using Microsoft.EntityFrameworkCore;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;

    namespace myWebApp
    {
        // [Keyless]
        // [NotMapped]
        // [Table("users")]
        [Table("users", Schema = "minispro")]
        public class UserDTO
        {
            [Key]
            public int Id { get; set; }

            // [Column("user_id")]
            // [Column(TypeName = "varchar(200)")]
            // [Column(TypeName = "decimal(5, 2)")]
            // [DataType(DataType.Date)]
            // [Display(Name = "Release Date")]
            [NotMapped]
            public Guid id { get; set; }
            public string name { get; set; } = "";
            public string nickname { get; set; }
            public string email { get; set; }
            #nullable enable
            public string? nickname { get; set; }
            public int? level { get; set; }
            #nullable disable
            public DateTime created_at { get; set; }
        }

        public class UserDC : DbContext
        {
            public UserDC (DbContextOptions<UserDC> options)
                : base(options)
            {
            }

            public DbSet<UserDTO> UserDTO { get; set; }
        }

    }

DbContext 类负责实现数据库读写逻辑，首先，需要在其构造函数或事件函数中处理连接：

    using System.Configuration;

    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
    {
        string cons = ConfigurationManager.ConnectionStrings["BloggingDatabase"].ConnectionString;
        optionsBuilder.UseSqlServer(cons);
        // optionsBuilder.UseSqlite(cons);
        // optionsBuilder.UseMySQL(cons);
    }
    
    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        modelBuilder.Entity<UserDTO>();
        modelBuilder.Query<YourModel>();
        modelBuilder.Query<YourModel>().FromSql()
    }


可以在 Startup 中将 DbContext 通过依赖注入为服务：

    services.AddDbContext<UserDC>();

这样就可以直接在实例化控制器时，通过依赖注入填到构造函数参数中：

    public class Hello : Controller
    {
        private readonly UserDC _context;

        public Hello(UserDC context)
        {
            _context = context;
        }
    }


Universal Windows Platform (UWP) 程序通常使用 Sqlite 数据库，一般硬编码连接字符串：

    var optionsBuilder = new DbContextOptionsBuilder<UserDC>();
    optionsBuilder.UseSqlite("Data Source=blog.db");
    // optionsBuilder.UseLoggerFactory(MyLoggerFactory) ;
    using (var context = new UserDC(optionsBuilder.Options))
    {
      // do stuff
    }


配置连接字符串到 Web.config 或 App.config，根据 ASP.NET 或 WinForms & WPF 程序需要：

    <?xml version="1.0" encoding="utf-8"?>
    <configuration>

      <connectionStrings>
        <add name="BloggingDatabase"
             connectionString="Server=(localdb)\mssqllocaldb;Database=Blogging;Trusted_Connection=True;" />
      </connectionStrings>
    </configuration>

ASP.NET Core 程序可以配置连接字符串到 appsettings.json：

    {
      "ConnectionStrings": {
        "BloggingDatabase": "Server=(localdb)\\mssqllocaldb;Database=EFGetStarted.ConsoleApp.NewDb;Trusted_Connection=True;",
        "Sqlite": "Data Source=blog.db",
        "MySQL": "server=localhost;user=root;database=test;port=3306;password=****;SslMode=None"
      },
    }

通常在 Statup 中由 Microsoft.Extensions.Configuration 读取，也可以自行读取配置文件：

    IConfiguration configuration = new ConfigurationBuilder()
        .SetBasePath(Environment.CurrentDirectory)
        .AddJsonFile("appsettings.json")
        // .AddXmlFile("config.xml");
        // .AddIniFile("appSettings.ini")
        .Build();

    string cons = Configuration.GetConnectionString("BloggingDatabase");



生成的控制器 Hello.cs：

    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Threading.Tasks;
    using Microsoft.AspNetCore.Http;
    using Microsoft.AspNetCore.Mvc;
    using Microsoft.EntityFrameworkCore;

    namespace myWebApp
    {
        [Route("api/[controller]")]
        [ApiController]
        public class Hello : ControllerBase
        {
            private readonly UserDC _context;

            public Hello(UserDC context)
            {
                _context = context;
            }

            // GET: api/Hello
            [HttpGet]
            public async Task<ActionResult<IEnumerable<UserDTO>>> GetUserDTO()
            {
                return await _context.UserDTO.ToListAsync();
            }

            // GET: api/Hello/5
            [HttpGet("{id}")]
            public async Task<ActionResult<UserDTO>> GetUserDTO(int id)
            {
                var userDTO = await _context.UserDTO.FindAsync(id);

                if (userDTO == null)
                {
                    return NotFound();
                }

                return userDTO;
            }

            // PUT: api/Hello/5
            // To protect from overposting attacks, enable the specific properties you want to bind to, for
            // more details, see https://go.microsoft.com/fwlink/?linkid=2123754.
            [HttpPut("{id}")]
            public async Task<IActionResult> PutUserDTO(int id, UserDTO userDTO)
            {
                if (id != userDTO.Id)
                {
                    return BadRequest();
                }

                _context.Entry(userDTO).State = EntityState.Modified;

                try
                {
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!UserDTOExists(id))
                    {
                        return NotFound();
                    }
                    else
                    {
                        throw;
                    }
                }

                return NoContent();
            }

            // POST: api/Hello
            // To protect from overposting attacks, enable the specific properties you want to bind to, for
            // more details, see https://go.microsoft.com/fwlink/?linkid=2123754.
            [HttpPost]
            public async Task<ActionResult<UserDTO>> PostUserDTO(UserDTO userDTO)
            {
                _context.UserDTO.Add(userDTO);
                await _context.SaveChangesAsync();

                return CreatedAtAction("GetUserDTO", new { id = userDTO.Id }, userDTO);
            }

            // DELETE: api/Hello/5
            [HttpDelete("{id}")]
            public async Task<ActionResult<UserDTO>> DeleteUserDTO(int id)
            {
                var userDTO = await _context.UserDTO.FindAsync(id);
                if (userDTO == null)
                {
                    return NotFound();
                }

                _context.UserDTO.Remove(userDTO);
                await _context.SaveChangesAsync();

                return userDTO;
            }

            private bool UserDTOExists(int id)
            {
                return _context.UserDTO.Any(e => e.Id == id);
            }
        }
    }


### dotnet aspnet-codegenerator

    >dotnet aspnet-codegenerator


    Usage: aspnet-codegenerator [arguments] [options]

    Arguments:
      generator  Name of the generator. Check available generators below.

    Options:
      -p|--project             Path to .csproj file in the project.
      -n|--nuget-package-dir
      -c|--configuration       Configuration for the project (Possible values: Debug/ Release)
      -tfm|--target-framework  Target Framework to use. (Short folder name of the tfm. eg. net46)
      -b|--build-base-path
      --no-build

    Available generators:
      area      : Generates an MVC Area.
      controller: Generates a controller.
      identity  : Generates an MVC Area with controllers and
      razorpage : Generates RazorPage(s).
      view      : Generates a view.


下表列出了对于 aspnet-codegenerator controller 的选项：

    >dotnet aspnet-codegenerator controller -h

    Generator Options:
      --controllerName|-name              : Name of the controller
      --useAsyncActions|-async            : Switch to indicate whether to generate async controller actions
      --noViews|-nv                       : Switch to indicate whether to generate CRUD views
      --restWithNoViews|-api              : Specify this switch to generate a Controller with REST style API, noViews is assumed and any view related options are ignored
      --readWriteActions|-actions         : Specify this switch to generate Controller with read/write actions when a Model class is not used
      --model|-m                          : Model class to use
      --dataContext|-dc                   : DbContext class to use
      --referenceScriptLibraries|-scripts : Switch to specify whether to reference script libraries in the generated views
      --layout|-l                         : Custom Layout page to use
      --useDefaultLayout|-udl             : Switch to specify that default layout should be used for the views
      --force|-f                          : Use this option to overwrite existing files
      --relativeFolderPath|-outDir        : Specify the relative output folder path from project where the file needs to be generated, if not specified, file will be generated in the project folder
      --controllerNamespace|-namespace    : Specify the name of the namespace to use for the generated controller
      --useSqlite|-sqlite                 : Flag to specify if DbContext should use SQLite instead of SQL Server.

Razor Page 生成选项：

    >dotnet aspnet-codegenerator razorpage -h

    Selected Code Generator: razorpage

    Generator Arguments:
      razorPageName : Name of the Razor Page
      templateName  : The template to use, supported view templates: 'Empty|Create|Edit|Delete|Details|List'

    Generator Options:
      --model|-m                          : Model class to use
      --dataContext|-dc                   : DbContext class to use
      --referenceScriptLibraries|-scripts : Switch to specify whether to reference script libraries in the generated views
      --layout|-l                         : Custom Layout page to use
      --useDefaultLayout|-udl             : Switch to specify that default layout should be used for the views
      --force|-f                          : Use this option to overwrite existing files
      --relativeFolderPath|-outDir        : Specify the relative output folder path from project where the file needs to be generated, if not specified, file will be generated in the project folder
      --namespaceName|-namespace          : Specify the name of the namespace to use for the generated PageModel
      --partialView|-partial              : Generate a partial view, other layout options (-l and -udl) are ignored if this is specified
      --noPageModel|-npm                  : Switch to not generate a PageModel class for Empty template
      --useSqlite|-sqlite                 : Flag to specify if DbContext should use SQLite instead of SQL Server.




### Code First with EF Core
- [EF workflows](https://docs.microsoft.com/en-us/ef/ef6/modeling/)
- [Creating and configuring a model](https://docs.microsoft.com/en-us/ef/core/modeling/)
- [Getting Started with EF Core](https://docs.microsoft.com/en-us/ef/core/get-started/?tabs=netcore-cli)
- [Razor Pages with Entity Framework Core in ASP.NET Core](https://docs.microsoft.com/en-us/aspnet/core/data/ef-rp/intro?view=aspnetcore-3.1)


在数据库关系模型 ORM 的设计中，Code First 模式中可以由模型生成数据库 即 Model First，也可以由现有的数据库生成上下文和模型，即 Database First。要执行 Database First 任务，从现有的数据库逆向生成上下文及模型，需要通过 dotnet ef dbcontext scaffold 基架工具实现。

Model First 模式先定义模型，再由模型生成数据库结构，流程如下：

- 定义模型对象；
- 设置目标数据库连接，需要一个全新的空数据；
- EF CLI 命令时通过 EnsureCreated() 方法创建数据库结构； 



创建学生实体, Models/Student.cs：

    using System;
    using System.Collections.Generic;

    namespace ContosoUniversity.Models
    {
        public class Student
        {
            public int ID { get; set; }
            public string LastName { get; set; }
            public string FirstMidName { get; set; }
            public DateTime EnrollmentDate { get; set; }

            public ICollection<Enrollment> Enrollments { get; set; }
        }
    }

ID 属性成为此类对应的数据库表的主键列。 默认情况下，EF Core 将名为 ID 或 classnameID 的属性视为主键。 因此，Student 类主键的另一种自动识别的名称是 StudentID。

在本例中，Student 实体的 Enrollments 属性包含与该 Student 相关的所有 Enrollment 实体。 例如，如果数据库中的 Student 行有两个相关的 Enrollment 行，则 Enrollments 关联这两个 Enrollment 实体。

创建入学登记实体, Models/Enrollment.cs：

    namespace ContosoUniversity.Models
    {
        public enum Grade
        {
            A, B, C, D, F
        }

        public class Enrollment
        {
            public int EnrollmentID { get; set; }
            public int CourseID { get; set; }
            public int StudentID { get; set; }
            public Grade? Grade { get; set; }

            public Course Course { get; set; }
            public Student Student { get; set; }
        }
    }

EnrollmentID 属性为主键；此实体使用 classnameID 模式而不是直接使用 ID。 对于生产数据模型，请选择一个模式并一直使用，以方便日后统一管理。

Grade 属性为 enum。 Grade 声明类型后的?表示 Grade 属性可以为 null。 评级为 null 和评级为零是有区别的 — null 意味着评级未知或者尚未分配。如果数据库的字段可以为空，实体就一定要这样设置，否则查询数据记录就会出错。

如果属性命名为 `<navigation property name><primary key property name>`，EF Core 会将其视为外键。 例如，StudentID 是 Student 导航属性的外键，因为 Student 实体的主键为 ID。 还可以将外键属性命名为 `<primary key property name>`。 例如 CourseID，因为 Course 实体的主键为 CourseID。


创建 Course 实体，使用以下代码创建 Models/Course.cs：

    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations.Schema;

    namespace ContosoUniversity.Models
    {
        public class Course
        {
            [DatabaseGenerated(DatabaseGeneratedOption.None)]
            public int CourseID { get; set; }
            public string Title { get; set; }
            public int Credits { get; set; }

            public ICollection<Enrollment> Enrollments { get; set; }
        }
    }

应用可以通过 DatabaseGenerated 特性指定主键，而无需靠数据库生成。


**生成代码及修改配置**


本部分使用 ASP.NET Core 基架工具生成 EF Core 上下文类型定义文件。 上下文是为给定数据模型协调实体框架功能的主类。 它派生自 Microsoft.EntityFrameworkCore.DbContext 类。生成 Razor Page 页面以处理 Student 实体的创建、读取、更新和删除 (CRUD) 操作。

安装基架工具，选用 SQLite 嵌入式数据做测试，创建 Pages/Students 文件夹以保存生成的 Razor Page：

    dotnet add package Microsoft.EntityFrameworkCore.SQLite
    dotnet add package Microsoft.EntityFrameworkCore.Design
    dotnet add package Microsoft.EntityFrameworkCore.Tools
    dotnet add package Microsoft.VisualStudio.Web.CodeGeneration.Design
    dotnet add package Microsoft.Extensions.Logging.Debug

    dotnet tool install --global dotnet-aspnet-codegenerator

    dotnet aspnet-codegenerator razorpage -m Student -dc ContosoUniversity.Data.SchoolContext -udl -outDir Pages\Students --referenceScriptLibraries --useSqlite

执行生成 razorpage 模板后会在 Pages/Students 文件夹中创建以下系列 Razor 页面：

- Create.cshtml & Create.cshtml.cs
- Delete.cshtml & Delete.cshtml.cs
- Details.cshtml & Details.cshtml.cs
- Edit.cshtml & Edit.cshtml.cs
- Index.cshtml & Index.cshtml.cs
- Data/SchoolContext.cs 上下文类型定义


按以下步骤修改配置：

- 在 Startup.cs 中通过注册上下文以启用依赖项注入

    通过调用 DbContextOptions 对象中的一个方法将连接字符串名称传递到上下文。 进行本地开发时， ASP.NET Core 配置系统 在 appsettings.json 文件中读取数据库连接字符串。

        services.AddDbContext<SchoolContext>(options =>
            options.UseSqlServer(Configuration.GetConnectionString("SchoolContext")));

    如果需要使用其它配置读入方式，也可使用以下这种方式：

        services.AddDbContext<SchoolContext>();

    然后在 SchoolContext 类的配置方法中增加配置读入定义，但是这样每次都会加载配置文件，会有较大的消耗：

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            if (!optionsBuilder.IsConfigured)
            {
                IConfiguration Configuration = new ConfigurationBuilder()
                    .SetBasePath(Environment.CurrentDirectory)
                    .AddJsonFile("appSettings.json")
                    .Build();

                cons = Configuration.GetConnectionString("SchoolContext");
                optionsBuilder.UseSqlite(cons);
            }
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            OnModelCreatingPartial(modelBuilder);
        }

- 将数据库连接字符串添加到 appsettings.json

        {
            "Logging": {
                "LogLevel": {
                    "Default": "Information",
                    "Microsoft": "Warning",
                    "Microsoft.Hosting.Lifetime": "Information"
                }
            },
            "AllowedHosts": "*",
            "ConnectionStrings": {
                "SchoolContext": "Data Source=CU.db"
            }
        }

    使用 SqlServer 或者 MySQL 连接字符串：

        "SqlServer": "Server=(localdb)\\mssqllocaldb;Database=SchoolContext6;Trusted_Connection=True;MultipleActiveResultSets=true"
        "MySQL": "server=localhost;user=root;database=test;port=3306;password=****;SslMode=None"

    LocalDB 是轻型版本 SQL Server Express 数据库引擎，专门针对应用开发，而非生产使用。 默认情况下，LocalDB 会在 `C:/Users/<user>` 目录中创建 .mdf 文件 。


更新数据库上下文类定义，数据库上下文类是为给定数据模型协调 EF Core 功能的主类。 上下文派生自 Microsoft.EntityFrameworkCore.DbContext。 上下文指定数据模型中包含哪些实体。 

在此项目中将数据库上下文类命名为 SchoolContext。 使用以下代码更新 SchoolContext.cs ：

    using Microsoft.EntityFrameworkCore;
    using ContosoUniversity.Models;

    namespace ContosoUniversity.Data
    {
        public class SchoolContext : DbContext
        {
            public SchoolContext (DbContextOptions<SchoolContext> options)
                : base(options)
            {
            }

            public DbSet<Student> Students { get; set; }
            public DbSet<Enrollment> Enrollments { get; set; }
            public DbSet<Course> Courses { get; set; }

            protected override void OnModelCreating(ModelBuilder modelBuilder)
            {
                modelBuilder.Entity<Course>().ToTable("Course");
                modelBuilder.Entity<Enrollment>().ToTable("Enrollment");
                modelBuilder.Entity<Student>().ToTable("Student");
            }
        }
    }


DbContext 执行流程有三个重要时机：

- 构造函数执行时机；
- 每次实例化都执行的配置事件，OnConfiguring(DbContextOptionsBuilder)
- 只在可能需要构造数据库结构时执行的 OnModelCreating(ModelBuilder)

一定要指定空数据，即使用数据库无任何数据表也不行。如果有上下文关联的数据库，则 EnsureCreated 方法不执行任何操作。 

代码中 `DbSet` 泛型为每个实体集创建 DbSet<TEntity> 属性。 在 EF Core 术语中：

- 实体类定义对应表定义。
- 实体集通常对应数据库表。
- 实体对应表中的行。

由于实体集包含多个实体，因此 DBSet 属性应为复数名称。 由于基架工具创建了 Student DBSet，为单数形式，建议在此步骤将生成代码中的单数形式更改为复数 Students。

为了使 Razor Pages 代码与新的 DBSet 名称相匹配，请在整个项目中进行全局更改，将 `_context.Student` 更改为 `_context.Students`。共 5 个文件 8 处修改。



如果没有数据库，请更新 Program.cs 以创建数据库，注意引用 DependencyInjection 依赖注入模块：

    using ContosoUniversity.Data;
    using Microsoft.Extensions.DependencyInjection;
    using Microsoft.AspNetCore.Hosting;
    using Microsoft.Extensions.Hosting;
    using Microsoft.Extensions.Logging;
    using System;

    namespace ContosoUniversity
    {
        public class Program
        {
            public static void Main(string[] args)
            {
                var host = CreateHostBuilder(args).Build();
                CreateDbIfNotExists(host);
                host.Run();
            }

            private static void CreateDbIfNotExists(IHost host)
            {
                using (var scope = host.Services.CreateScope())
                {
                    var services = scope.ServiceProvider;

                    try
                    {
                        var context = services.GetRequiredService<SchoolContext>();
                        context.Database.EnsureCreated();
                    }
                    catch (Exception ex)
                    {
                        var logger = services.GetRequiredService<ILogger<Program>>();
                        logger.LogError(ex, "An error occurred creating the DB.");
                    }
                }
            }

            public static IHostBuilder CreateHostBuilder(string[] args) =>
                Host.CreateDefaultBuilder(args)
                    .ConfigureWebHostDefaults(webBuilder =>
                    {
                        webBuilder.UseStartup<Startup>();
                    });
        }
    }

如果有上下文关联的数据库，则 EnsureCreated 方法不执行任何操作。 如果没有数据库，则它将创建数据库和架构。 EnsureCreated 启用以下工作流来处理数据模型更改：

- 删除数据库。 任何现有数据丢失。
- 更改数据模型。 例如，添加 EmailAddress 字段。
- 运行应用。
- 插 EF 提供的 EnsureCreated 创建具有新架构的数据库。

在无需保存数据的情况下，当架构快速发展时，此工作流在早期开发过程中表现良好。 如果需要保存已输入数据库的数据，情况就有所不同了。 如果是这种情况，请使用迁移 Imigreation。

本系列教程的后续部分将删除 EnsureCreated 创建的数据库，转而使用迁移。 无法使用迁移更新 EnsureCreated 创建的数据库。


**设定数据库种子**

EnsureCreated 方法将创建空数据库。 本节添加用测试数据填充数据库的代码。
使用以下代码创建 Data/DbInitializer.cs ：

    using ContosoUniversity.Data;
    using ContosoUniversity.Models;
    using System;
    using System.Linq;

    namespace ContosoUniversity.Data
    {
        public static class DbInitializer
        {
            public static void Initialize(SchoolContext context)
            {
                context.Database.EnsureCreated();

                // Look for any students.
                if (context.Students.Any())
                {
                    return;   // DB has been seeded
                }

                var students = new Student[]
                {
                    new Student{FirstMidName="Carson",LastName="Alexander",EnrollmentDate=DateTime.Parse("2019-09-01")},
                    new Student{FirstMidName="Meredith",LastName="Alonso",EnrollmentDate=DateTime.Parse("2017-09-01")},
                    new Student{FirstMidName="Arturo",LastName="Anand",EnrollmentDate=DateTime.Parse("2018-09-01")},
                    new Student{FirstMidName="Gytis",LastName="Barzdukas",EnrollmentDate=DateTime.Parse("2017-09-01")},
                    new Student{FirstMidName="Yan",LastName="Li",EnrollmentDate=DateTime.Parse("2017-09-01")},
                    new Student{FirstMidName="Peggy",LastName="Justice",EnrollmentDate=DateTime.Parse("2016-09-01")},
                    new Student{FirstMidName="Laura",LastName="Norman",EnrollmentDate=DateTime.Parse("2018-09-01")},
                    new Student{FirstMidName="Nino",LastName="Olivetto",EnrollmentDate=DateTime.Parse("2019-09-01")}
                };

                context.Students.AddRange(students);
                context.SaveChanges();

                var courses = new Course[]
                {
                    new Course{CourseID=1050,Title="Chemistry",Credits=3},
                    new Course{CourseID=4022,Title="Microeconomics",Credits=3},
                    new Course{CourseID=4041,Title="Macroeconomics",Credits=3},
                    new Course{CourseID=1045,Title="Calculus",Credits=4},
                    new Course{CourseID=3141,Title="Trigonometry",Credits=4},
                    new Course{CourseID=2021,Title="Composition",Credits=3},
                    new Course{CourseID=2042,Title="Literature",Credits=4}
                };

                context.Courses.AddRange(courses);
                context.SaveChanges();

                var enrollments = new Enrollment[]
                {
                    new Enrollment{StudentID=1,CourseID=1050,Grade=Grade.A},
                    new Enrollment{StudentID=1,CourseID=4022,Grade=Grade.C},
                    new Enrollment{StudentID=1,CourseID=4041,Grade=Grade.B},
                    new Enrollment{StudentID=2,CourseID=1045,Grade=Grade.B},
                    new Enrollment{StudentID=2,CourseID=3141,Grade=Grade.F},
                    new Enrollment{StudentID=2,CourseID=2021,Grade=Grade.F},
                    new Enrollment{StudentID=3,CourseID=1050},
                    new Enrollment{StudentID=4,CourseID=1050},
                    new Enrollment{StudentID=4,CourseID=4022,Grade=Grade.F},
                    new Enrollment{StudentID=5,CourseID=4041,Grade=Grade.C},
                    new Enrollment{StudentID=6,CourseID=1045},
                    new Enrollment{StudentID=7,CourseID=3141,Grade=Grade.A},
                };

                context.Enrollments.AddRange(enrollments);
                context.SaveChanges();
            }
        }
    }

该代码会检查数据库中是否存在任何学生。 如果不存在学生，它将向数据库添加测试数据。 该代码使用数组创建测试数据而不是使用 List<T> 集合是为了优化性能。

在 Program.cs 中，将 EnsureCreated 调用替换为 DbInitializer.Initialize 调用 ：

    // context.Database.EnsureCreated();
    DbInitializer.Initialize(context);

如果应用正在运行，则停止应用，然后删除 CU.db 文件。或使用 PowerShell 命令 Drop-Database 删除 SqlServer 数据库。


**使用 CRUD 操作**

    using (var db = new SchoolContext())
    {
        // Create
        Console.WriteLine("Inserting a new student");
        db.Add(new Student {
            FirstMidName="Carson",
            LastName="Alexander",
            EnrollmentDate=DateTime.Parse("2019-09-01")
            });
        db.SaveChanges();

        // Read
        Console.WriteLine("Querying for a student");
        var student = db.Students
            .OrderBy(b => b.ID)
            .First();

        // Update
        Console.WriteLine("Updating the student and adding a post");
        student.LastName = "Bob";
        student.Enrollments.Add(new Enrollment{StudentID=1,CourseID=1050,Grade=Grade.A})
        db.SaveChanges();

        // Delete
        Console.WriteLine("Delete the student");
        db.Remove(student);
        db.SaveChanges();
    }


排序 Linq 语法：

    IQueryable<Student> studentsIQ = from s in db.Students select s;

    switch (sortOrder)
    {
        case "name_desc":
            studentsIQ = studentsIQ.OrderByDescending(s => s.LastName);
            break;
        case "Date":
            studentsIQ = studentsIQ.OrderBy(s => s.EnrollmentDate);
            break;
        case "date_desc":
            studentsIQ = studentsIQ.OrderByDescending(s => s.EnrollmentDate);
            break;
        default:
            studentsIQ = studentsIQ.OrderBy(s => s.LastName);
            break;
    }

    Students = await studentsIQ.AsNoTracking().ToListAsync();

IQueryable vs.IEnumerable

该代码对 IQueryable 对象调用 OrderBy/Where 方法，筛选在服务器上处理。 在某些情况下，应用可能会对内存中的集合调用 Where 方法作为扩展方法。 例如，假设 SchoolContext.Students 从 EF Core DbSet 更改为可返回 IEnumerable 集合的存储库方法。 结果通常是相同的，但在某些情况下可能不同。

出于性能考虑，通常首选对 IQueryable 调用 Contains。 数据库服务器利用 IQueryable 完成筛选。 如果先创建 IEnumerable，则必须从数据库服务器返回所有行。



**使用异步代码**

异步编程是 ASP.NET Core 和 EF Core 的默认模式。

Web 服务器的可用线程是有限的，而在高负载情况下的可能所有线程都被占用。 当发生这种情况的时候，服务器就无法处理新请求，直到线程被释放。 使用同步代码时，可能会出现多个线程被占用但不能执行任何操作的情况，因为它们正在等待 I/O 完成。 使用异步代码时，当进程正在等待 I/O 完成，服务器可以将其线程释放用于处理其他请求。 因此，使用异步代码可以更有效地利用服务器资源，并且服务器可以无延迟地处理更多流量。

异步代码会在运行时引入少量开销。 流量较低时，对性能的影响可以忽略不计，但流量较高时，潜在的性能改善非常显著。
在以下代码中，async 关键字和 Task<T> 返回值，await 关键字和 ToListAsync 方法让代码异步执行。

    public async Task OnGetAsync()
    {
        Students = await _context.Students.ToListAsync();
    }

async 关键字让编译器执行以下操作：

- 为方法主体的各部分生成回调。
- 创建返回的 Task 对象。
- 返回类型 Task<T> 表示正在进行的工作。
- await 关键字让编译器将该方法拆分为两个部分。 先以异步方式结束已启动的操作，当操作完成时注入调用 Callback 方法的地方。
- ToListAsync 是 ToList 扩展方法的异步版本。

编写使用 EF Core 的异步代码时需要注意的一些事项：

只有导致查询或发送数据库命令的语句才能以异步方式执行。 这包括 ToListAsync、SingleOrDefaultAsync、FirstOrDefaultAsync 和 SaveChangesAsync。 不包括只会更改 IQueryable 的语句，例如：

    var students = context.Students.Where(s => s.LastName == "Davolio")

EF Core 上下文并非线程安全，请勿尝试并行执行多个操作。
若要利用异步代码的性能优势，请验证在调用向数据库发送查询的 EF Core 方法时，库程序包（如用于分页）是否使用异步。


### Migration & EF CLI 命令行工具
- [EF workflows](https://docs.microsoft.com/en-us/ef/ef6/modeling/)
- [Creating and configuring a model](https://docs.microsoft.com/en-us/ef/core/modeling/)
- [Getting Started with EF Core](https://docs.microsoft.com/en-us/ef/core/get-started/?tabs=netcore-cli)
- [Razor Pages with Entity Framework Core in ASP.NET Core](https://docs.microsoft.com/en-us/aspnet/core/data/ef-rp/intro?view=aspnetcore-3.1)


用于 Entity Framework Core 的命令行接口（CLI）工具执行设计器开发任务。 例如，他们基于现有数据库创建迁移、应用迁移和生成模型的代码。 EF CLI 是跨平台 dotnet 命令的扩展，它是.NET Core SDK的一部分。 这些工具适用于 .NET Core 项目。

使用 EF Migration 迁移自动创建数据库时，Migration 将：

- 根据已有的数据模型定义生成数据库结构，需要指定空数据库，即清空数据表也不行；
- 向数据库添加 `__EFMigrationsHistory` 表格记录各个迁移对象的 ID 和产品版本号，用以跟踪数据库的架构是否与从生成它的模型类同步。
- 如果该模型类未与数据库同步，EF 将引发异常，拒绝执行操作。

例如，应用添加了有两个迁移：

| `MigrationId` | `ProductVersion` |
| :-----------  | :--------------- |
| 20200531105034_InitialCreate  | 3.1.4 |
| 20200531105213_upgrade_1.0    | 3.1.4 |

对应的迁移设计器定 20200531105034_InitialCreate 或 20200531105213_upgrade_10 的设计器定义 Designer.cs 参考如下，它包含迁移后的数据库结构快照：

    [DbContext(typeof(SchoolContext))]
    [Migration("20200531105034_InitialCreate")]
    partial class InitialCreate
    {
        protected override void BuildTargetModel(ModelBuilder modelBuilder)
        {
            modelBuilder
                .HasAnnotation("ProductVersion", "3.1.4")
                .HasAnnotation("Relational:MaxIdentifierLength", 64);

各自定义向上迁移 Up 、向下迁移方法 Down ，执行迁移时 `dotnet ef database update` 命令依次执行：

    DbContext OnModelCreating(ModelBuilder)
    InitialCreate UP ...
    InitialCreate BuildTargetModel ...
    upgrade_10 UP ...
    upgrade_10 BuildTargetModel ...



安装 EF CLI 工具：

    dotnet tool install --global dotnet-ef

可选预安装数据供应接口模块：

    dotnet add package Microsoft.EntityFrameworkCore.SQLite
    dotnet add package Microsoft.EntityFrameworkCore.SqlServer
    dotnet add package Microsoft.EntityFrameworkCore.InMemory

    dotnet add package Microsoft.VisualStudio.Web.CodeGeneration.Design
    dotnet add package Microsoft.EntityFrameworkCore.Design

    dotnet add package MySql.Data
    dotnet add package MySql.Data.EntityFrameworkCore
    dotnet add package MySql.Data.EntityFrameworkCore.Design

    dotnet add package Pomelo.EntityFrameworkCore.MySql

提供三种功能，数据库、上下文、迁移管理：

| 命令        | 子命令 |
| :-------    | :------- |
| database    | drop update 删除或更新数据库 |
| dbcontext   | Commands to manage DbContext types. |
| migrations  | Commands to manage migrations. |

- dbcontext 子命令

  - info      Gets information about a DbContext type.
  - list      Lists available DbContext types.
  - scaffold  Scaffolds a DbContext and entity types for a database.
  - script    Generates a SQL script from migrations.

- migrations 子命令

  - add     Adds a new migration.
  - list    Lists available migrations.
  - remove  Removes the last migration.
  - script  Generates a SQL script from migrations.

查询上下文对象信息：

    >dotnet ef dbcontext list --no-build
    AppWeb.Data.UserDC
    ContosoUniversity.Data.SchoolContext

    >dotnet ef dbcontext info -c SchoolContext --no-build
    Provider name: Microsoft.EntityFrameworkCore.Sqlite
    Database name: main
    Data source: CU.db
    Options: None

基架命令 scaffold 为 DbContext 数据库的和实体类型生成代码，即 Database First 模式下的数据库逆向工程。使用 Sacffold-DbContext EF Core 包管理器控制台（PMC）工具的命令或 dotnet ef dbcontext scaffold .net 命令行接口（CLI）工具的命令来执行该命令。

使此命令生成实体类型，数据库表必须具有主键，-t 或 --table 指定要构造的数据表，数据库供应接口指定 Sqlite、MySql 等。

    dotnet ef dbcontext scaffold "Data Source=CU.db" Microsoft.EntityFrameworkCore.Sqlite -o Data\School --no-build
    
    dotnet ef dbcontext scaffold "Data Source=CU.db" Microsoft.EntityFrameworkCore.Sqlite -o Data\School -t Student -t Course --context-dir Data -c SchoolContext

    dotnet ef dbcontext scaffold -c ReverDBContext -o Data\reverse "server=localhost;user=root;database=school;port=3306;password=12345;SslMode=None" MySql.Data.EntityFrameworkCore --no-build

如果数据按上面小节生成的结构，那么就会在 Data\School 目录下生成 CUContext 上下文还用对应各数据表的模型，命名空间和目录层级对应。

不用担心生成时会覆盖原文件，除非使用 --force 选项！


当数据有数据需要保留时，又要对数据库结构进行修正，就需要使用迁移，每次迁移使用的 SQL 脚本都会有历史记录，保存在 Migrations 目录。更重要的是，向数据库添加 `__EFMigrationsHistory` 表格用以跟踪数据库的架构，当表格记录与迁移对象版本不一致时，就当异常处理，而不执行迁移。

修改模型对象后，执行 migrations add 生成迁移 SQL 脚本，再使用数据库更新命令执行迁移.初次生成迁移对象含有创建数据表的功能，如果创建初始迁移时已存在数据库，但此代码不必运行，因为数据库已与数据库模型相匹配。

将应用部署到其中尚不存在数据库的其他环境时，此代码将运行以创建数据库，因此最好提前进行测试。 这也是提前更改连接字符串中数据库的名称的原因，这样迁移才能从头创建新数据库。

迁移在 Migrations/SchoolContextModelSnapshot.cs 中创建当前数据库架构的快照 。 添加迁移时，EF 会通过将数据模型与快照文件进行对比来确定已更改的内容。

在执行迁移前，可以使用 dotnet ef migrations remove 命令删除迁移，再修改模型，可以确保正确重置快照。 如果删除迁移失败，使用 dotnet ef migrations remove -v 获取失败的详细信息。


    >dotnet ef migrations list -c SchoolContext --no-build
    No migrations were found.

    >dotnet ef migrations add -c SchoolContext InitialCreate --no-build
    Done. To undo this action, use 'ef migrations remove'

    >dotnet ef migrations list -c SchoolContext --no-build
    20200531010213_InitialCreate

    >dotnet ef migrations remove -c SchoolContext  --no-build
    Removing migration '20200531010213_InitialCreate'.
    Removing model snapshot.
    Done.

    >dotnet ef database update --no-build -c SchoolContext
    Done.

需要注意，如果以 --no-build 方式执行，可能会导致工具无法正确识别数据库和模型对象间的差异，并且可能会多次添加同名的迁移对象，导致命名空间冲突。

每次添加的迁移对象至少包含 Up 和 Down 两个方法，向上迁移即更新数据库结构，向下迁移即还原本次向上迁移前的数据库结构，即 migrations remove 要执行的方法：

    using Microsoft.EntityFrameworkCore.Migrations;

    namespace AppWeb.Migrations
    {
        public partial class major : Migration
        {
            protected override void Up(MigrationBuilder migrationBuilder)
            {
                migrationBuilder.DropColumn(
                    name: "IsMajor",
                    table: "Course");

                migrationBuilder.AddColumn<int>(
                    name: "IsMinor",
                    table: "Course",
                    nullable: false,
                    defaultValue: 0);
            }

            protected override void Down(MigrationBuilder migrationBuilder)
            {
                migrationBuilder.DropColumn(
                    name: "IsMinor",
                    table: "Course");

                migrationBuilder.AddColumn<int>(
                    name: "IsMajor",
                    table: "Course",
                    type: "INTEGER",
                    nullable: false,
                    defaultValue: 0);
            }
        }
    }

Dbcontext.Database.EnsureCreated() 可以根据上下文自动创建数据库，以及相关的表。如果有上下文关联的数据库，则 EnsureCreated 方法不执行任何操作。 如果没有数据库，则它将创建数据库和架构。 

使用 Sqlite 可以在删除数据库文件后正常执行，但是如果使用 MySql 数据库时，**即使表已经全部删除，但是数据库还在，这时也是不会进行任何操作的。**

EnsureCreated 启用以下工作流来处理数据模型更改：

- 删除数据库。 任何现有数据丢失。
- 更改数据模型。 例如，添加 EmailAddress 字段。
- 运行应用。
- 插 EF 提供的 EnsureCreated 创建具有新架构的数据库。

在数据库录入有数据，情况就有所不同了，迁移 Imigreation 就是为此准备的。


如果已对数据库应用一个迁移或多个迁移，但需将其复原，则可使用同一命令来应用迁移，并指定回退时的目标迁移名称。LastGoodMigration 指定之前工作正常的迁移对象，可以使用 list 命令查询旧的迁移，完成后，不会删除迁移对象。也就是 EF Core 可以在任意迁移中切换，迁移回撤操作也是通过此方法：

    dotnet ef migrations list
    dotnet ef database update LastGoodMigration


SQL 脚本生成是一很重要的功能，指定使用开始的迁移版本 From 和结束迁移版本 To ，妤可以生成方式它们的差异化 SQL 本。如，下面的两个迁移，只是做了一个字段的删除更新：

    >dotnet ef migrations script InitialCreate upgrade_1.0  -c SchoolContext --no-build
    SchoolContext.cs OnModelCreating
    upgrade_10 UP...
    upgrade_10 BuildTargetModel...
    ALTER TABLE `Course` DROP COLUMN `IsMajor`;

    INSERT INTO `__EFMigrationsHistory` (`MigrationId`, `ProductVersion`)
    VALUES ('20200531105213_upgrade_1.0', '3.1.4');


生成迁移到最新状态 SQL 脚本：

    >dotnet ef migrations script --no-build -c SchoolContext
    CREATE TABLE IF NOT EXISTS "__EFMigrationsHistory" (
        "MigrationId" TEXT NOT NULL CONSTRAINT "PK___EFMigrationsHistory" PRIMARY KEY,
        "ProductVersion" TEXT NOT NULL
    );

    CREATE TABLE "Course" (
        "CourseID" INTEGER NOT NULL CONSTRAINT "PK_Course" PRIMARY KEY,
        "Title" TEXT NULL,
        "Credits" INTEGER NOT NULL
    );
    ...
    INSERT INTO "__EFMigrationsHistory" ("MigrationId", "ProductVersion")
    VALUES ('20200531010213_InitialCreate', '3.1.4');

经过编译运行后，所有迁移对象都编译到 DLL 库里保存，可以使用 --no-build 一直使用，直到下次修改或删除迁移求对象后再次编译。


# SignalR 实时消息推送应用
- https://docs.microsoft.com/en-us/aspnet/core/signalr/introduction?view=aspnetcore-2.2
- https://docs.microsoft.com/zh-cn/aspnet/core/tutorials/signalr?view=aspnetcore-3.1
- https://docs.microsoft.com/zh-cn/aspnet/core/tutorials/signalr-typescript-webpack?view=aspnetcore-3.1
- https://docs.microsoft.com/zh-cn/aspnet/core/tutorials/signalr-blazor-webassembly?view=aspnetcore-3.1
- https://docs.microsoft.com/zh-cn/aspnet/core/signalr/hubs?view=aspnetcore-3.1
- https://docs.microsoft.com/en-us/dotnet/api/microsoft.aspnetcore.signalr.client?view=aspnetcore-2.2


ASP.NET Core SignalR 是一种开放源代码库，可简化将实时 web 功能添加到应用程序的功能。 实时 web 功能使服务器端代码可以立即将内容推送到客户端。SignalR 提供用于创建服务器到客户端远程过程调用（RPC）的 API。 Rpc 通过服务器端 .NET Core 代码，从客户端调用 JavaScript 函数。

下面是的 SignalR 某些功能：

- 自动处理连接管理。
- 将消息同时发送到所有连接的客户端。 例如，聊天室。
- 向特定客户端或客户端组发送消息。
- 可缩放以处理不断增加的流量。

SignalR支持以下用于处理实时通信的技术（按正常回退的顺序）：

- Websocket
- 服务器发送的事件
- 长轮询
- SignalR自动选择服务器和客户端功能内的最佳传输方法。

要获取 SignalR JavaScript 客户端，请通过 LibMan 安装，在集成终端中，运行以下命令以安装 LibMan 以及 SignalR：

    dotnet tool install -g Microsoft.Web.LibraryManager.Cli
    libman install @microsoft/signalr@latest -p unpkg -d wwwroot/js/signalr --files dist/browser/signalr.js --files dist/browser/signalr.min.js

.Net Core 实现的 SignalR 客户端：

    dotnet add package Microsoft.AspNetCore.SignalR.Client --version 3.1.4


先配置 SignalR 服务器，以将 SignalR 请求传递到 SignalR 中心。将以下代码片断添加到 Startup.cs 文件，这些更改将 SignalR 添加到 ASP.NET Core 依赖关系注入和路由系统：

    using SignalRChat.Hubs;

    services.AddSignalR();

    app.UseEndpoints(endpoints =>
    {
        endpoints.MapRazorPages();
        endpoints.MapHub<ChatHub>("/chatHub");
    });


接下来需要实现一个消息中心类作为客户端 - 服务器通信的高级管道，来处理消息推送。既然是其于 WebSocket 的框架，那么就会有服务端和客户端，逻辑基本是和 Socket.io WebSocket 框架一致。

可以在项目文件夹中创建 Hubs 文件夹用于存放中心类，在 Hubs 文件夹中，使用以下代码创建 ChatHub.cs 文件 ：

    using System;
    using System.Threading.Tasks;
    using Microsoft.AspNetCore.SignalR;

    namespace SignalRChat.Hubs
    {
        public class ChatHub : Hub
        {
            public async Task SendMessage(string user, string message)
            {
                await Clients.All.SendAsync("ReceiveMessage", user, message);
            }
        }
    }

ChatHub 类继承自 SignalR Hub 类。 Hub 类管理连接、组和消息。可通过已连接客户端调用 SendMessage，这里会向所有客户端发送消息回显消息。也可以根据用户组 Clients.Group(name) 或给特定用户发送消息 Clients.User(user)，又或者发给回调者 Clients.Caller。SignalR 代码是异步模式，可提供最大的可伸缩性。

使用以下代码替换 Pages\Index.cshtml 中的内容 ：

    @page
        <div class="container">
            <div class="row">&nbsp;</div>
            <div class="row">
                <div class="col-2">User</div>
                <div class="col-4"><input type="text" id="userInput" /></div>
            </div>
            <div class="row">
                <div class="col-2">Message</div>
                <div class="col-4"><input type="text" id="messageInput" /></div>
            </div>
            <div class="row">&nbsp;</div>
            <div class="row">
                <div class="col-6">
                    <input type="button" id="sendButton" value="Send Message" />
                </div>
            </div>
        </div>
        <div class="row">
            <div class="col-12">
                <hr />
            </div>
        </div>
        <div class="row">
            <div class="col-6">
                <ul id="messagesList"></ul>
            </div>
        </div>
    <script src="~/js/signalr/dist/browser/signalr.js"></script>
    <script src="~/js/chat.js"></script>

在 wwwroot/js 文件夹中，使用以下代码创建 chat.js 文件，用于客户端调用 SignalR 执行 WebSocket 通信功能，并连接到前面注入的 /chatHub 路由地址上：

    "use strict";

    var connection = new signalR.HubConnectionBuilder().withUrl("/chatHub").build();

    //Disable send button until connection is established
    document.getElementById("sendButton").disabled = true;

    connection.on("ReceiveMessage", function (user, message) {
        var msg = message.replace(/&/g, "&amp;").replace(/</g, "&lt;").replace(/>/g, "&gt;");
        var encodedMsg = user + " says " + msg;
        var li = document.createElement("li");
        li.textContent = encodedMsg;
        document.getElementById("messagesList").appendChild(li);
    });

    connection.start().then(function () {
        document.getElementById("sendButton").disabled = false;
    }).catch(function (err) {
        return console.error(err.toString());
    });

    document.getElementById("sendButton").addEventListener("click", function (event) {
        var user = document.getElementById("userInput").value;
        var message = document.getElementById("messageInput").value;
        connection.invoke("SendMessage", user, message).catch(function (err) {
            return console.error(err.toString());
        });
        event.preventDefault();
    });


执行 dotnet watch run 测试。


## SignalR with TypeScript 

要在 ASP.NET Core SignalR Web 应用中使用 TypeScript 编写客户端，需要添加 TypeScript 编译器 Microsoft.TypeScript.MSBuild，再作为该应用的客户端配置使用 Webpack，这需要使用到 Node.js 开发环境。

配置步骤：

- ASP.NET Core SignalR 应用基架搭建
- SignalR TypeScript 客户端配置
- Webpack 配置生成管道
- SignalR 服务器配置
- 启用客户端和服务器之间的通信

### TypeScript 客户端配置

首先，执行 dotnet new 命令在 SignalRWebPack 目录中创建一个空的 ASP.NET Core Web 应用。如果，使用 Visual Studio Code 开发工具，code 命令会打开 SignalRWebPack 文件夹。再添加 Microsoft.TypeScript.MSBuild 包，从而在项目中启用 TypeScript 编译。

    dotnet new web -o SignalRWebPack
    code -r SignalRWebPack

    dotnet add package Microsoft.TypeScript.MSBuild

接下来，配置 Webpack 和 TypeScript，涉及内容较多，因为使用到了 Node.js 开发环境，还需要 WebPack 模块化开发基础。跟着以下步骤配置，将 JavaScript 环境转换到 TypeScript。

在项目根目录中运行 npm 命令初始化工程，创建 package.json 配置文件 ：

    npm init -y

将以下 private 属性添加到 package.json 文件并保存文件更改，将 private 属性设置为 true，防止下一步出现包安装警告：

    {
      "name": "SignalRWebPack",
      "version": "1.0.0",
      "private": true,
      "description": "",
      "main": "index.js",
      "scripts": {
        "test": "echo \"Error: no test specified\" && exit 1"
      },
      "keywords": [],
      "author": "",
      "license": "ISC"
    }


安装项目所需的 npm 包，注意，从项目根目录运行以下命令：

    npm i -D -E clean-webpack-plugin@3.0.0 css-loader@3.4.2 html-webpack-plugin@3.2.0 mini-css-extract-plugin@0.9.0 ts-loader@6.2.1 typescript@3.7.5 webpack@4.41.5 webpack-cli@3.3.10

需要注意的一些命令细节，每个包名称中 @ 符号后是版本号，npm 安装这些包的指定版本。
-E 选项禁用 npm 将语义化版本控制范围运算符写到 package.json 的默认行为。 例如，使用 "webpack": "4.41.5" 而不是 "webpack": "^4.41.5"，脱字符号 ^ 表示接受此版本号以上的包，此选项防止意外升级到新的包版本。-D 选项表示依赖包安装后，依赖信息记录到配置文件的 devDependencies 中，即这些包都是开发依赖，发布时不会被打包输出。 安装好的包都会在 node_modules 目录下保存。

客户端还需要引入 SignalR，在项目根目录运行以下命令：

    npm i @microsoft/signalr @types/node

上述的代码会安装 SignalR TypeScript 客户端，它允许客户端向服务器发送消息。@types/node 是用于 node.js 的 TypeScript 类型定义，支持 Node.js 类型的编译时检查。


将 package.json 文件的 scripts 属性替换为以下代码 ：

    "scripts": {
      "start": "webpack --mode=development --watch",
      "release": "webpack --mode=production",
      "publish": "npm run release && dotnet publish -c Release"
    },

这些脚本设置目的是方便执行命令，比如，执行 npm run start 就会执行其设置的脚本：

- start 在开发模式下打包客户端资源并观察文件更改。 --watch 文件监视程序在每次项目文件发生更改时重新生成。 mode 选项可禁用生产优化，以加速开发效率。
- release 在生产模式下打包客户端资源。
- publish 运行 release 脚本，在生产模式下打包客户端资源。 它调用 .NET Core CLI 的 publish 命令发布应用。

再接下来，配置 Webpack，在项目根目录中创建名为 webpack.config.js 的文件，使其包含以下代码 ：

    const path = require("path");
    const HtmlWebpackPlugin = require("html-webpack-plugin");
    const { CleanWebpackPlugin } = require("clean-webpack-plugin");
    const MiniCssExtractPlugin = require("mini-css-extract-plugin");
    module.exports = {
        entry: "./src/index.ts",
        output: {
            path: path.resolve(__dirname, "wwwroot"),
            filename: "[name].[chunkhash].js",
            publicPath: "/"
        },
        resolve: {
            extensions: [".js", ".ts"]
        },
        module: {
            rules: [
                {
                    test: /\.ts$/,
                    use: "ts-loader"
                },
                {
                    test: /\.css$/,
                    use: [MiniCssExtractPlugin.loader, "css-loader"]
                }
            ]
        },
        plugins: [
            new CleanWebpackPlugin(),
            new HtmlWebpackPlugin({
                template: "./src/index.html"
            }),
            new MiniCssExtractPlugin({
                filename: "css/[name].[chunkhash].css"
            })
        ]
    };

这个配置会指导 Webpack 编译流程，注意的一些配置细节：

- output 属性替代 dist 的默认值，打包输出在 wwwroot 目录中。
- resolve.extensions 数组包含 .js，以便导入 SignalR 客户端 JavaScript。

在项目根目录中创建新的 src 目录，以存储项目的客户端资源文件，如样式表文件、TS 脚本等。

创建包含以下 JSON 的 src/tsconfig.json，这个配置文件指导 TypeScript 编译输出 ECMAScript 5 规范的 JavaScript：

    {
      "compilerOptions": {
        "target": "es5"
      }
    }

接下来就可以创建 TypeScript 脚本，创建包含以下代码的 src/index.ts：

    import "./css/main.css";

    const divMessages: HTMLDivElement = document.querySelector("#divMessages");
    const tbMessage: HTMLInputElement = document.querySelector("#tbMessage");
    const btnSend: HTMLButtonElement = document.querySelector("#btnSend");
    const username = new Date().getTime();

    tbMessage.addEventListener("keyup", (e: KeyboardEvent) => {
        if (e.key === "Enter") {
            send();
        }
    });

    btnSend.addEventListener("click", send);

    function send() {
        console.log("send()");
    }

前面的 TypeScript 检索对 DOM 元素的引用并附加两个事件处理程序：

- keyup 用户在 tbMessage 文本框中键入时触发此事件。 用户按 Enter 时调用 send 函数 。
- click 用户单击发送按钮时触发此事件，调用 send 函数。

相应地创建包含以下标记的 src/index.html 。

    <!DOCTYPE html>
    <html>
    <head>
        <meta charset="utf-8" />
        <title>ASP.NET Core SignalR</title>
    </head>
    <body>
        <div id="divMessages" class="messages">
        </div>
        <div class="input-zone">
            <label id="lblMessage" for="tbMessage">Message:</label>
            <input id="tbMessage" class="input-zone-input" type="text" />
            <button id="btnSend">Send</button>
        </div>
    </body>
    </html>


创建包含以下 CSS 的 src/css/main.css ：

    *, *::before, *::after {
        box-sizing: border-box;
    }

    html, body {
        margin: 0;
        padding: 0;
    }

    .input-zone {
        align-items: center;
        display: flex;
        flex-direction: row;
        margin: 10px;
    }

    .input-zone-input {
        flex: 1;
        margin-right: 10px;
    }

    .message-author {
        font-weight: bold;
    }

    .messages {
        border: 1px solid #000;
        margin: 10px;
        max-height: 300px;
        min-height: 300px;
        overflow-y: auto;
        padding: 5px;
    }

到此，TypeScript 的环境配置完成。接下来的工作就是 SignalR 的使用与设置。


**警告** Webpack 打包输出时，clean-webpack-plugin 插件会清空目录，可以禁用此插件。

或者，原有 wwwroot 目录下的静态文件移动到 static 目录下，配置 copy-webpack-plugin 插件，打包时自动复制一份到 wwwroot 目录。

    const CopyPlugin = require('copy-webpack-plugin');

    plugins: [
        new CopyPlugin(
        [{
            from: path.resolve(__dirname, "staic"), 
            to: path.resolve(__dirname, "wwwroot"),
            force:true
        }]),
    ],

可以将 SignalR JavaScript 客户端配置成独立引入 HTML 页面，修改 webpack.config.js，注意键值对中，Key 为包名，后面的值表示前端页面引入使用的对象引用名：

    externals: [
        {"@microsoft/signalr":"signalR" },
    ],

使用 npm 下载好 SignalR 客户端，或者通过 LibMan 安装，在集成终端中，运行以下命令以安装 LibMan 以及 SignalR：

    dotnet tool install -g Microsoft.Web.LibraryManager.Cli
    libman install @microsoft/signalr@latest -p unpkg -d wwwroot/lib/signalr --files dist/browser/signalr.js --files dist/browser/signalr.min.js


### SignalR 服务器配置

为了使用前面编辑好的静态文件，需要在 Startup.Configure 中添加对 UseDefaultFiles 和 UseStaticFiles 的调用。在 Startup.Configure 的末尾，添加 /hub 路由映射到 ChatHub 中心 。再在 Startup.ConfigureServices 中调用 AddSignalR，并在 Startup.cs 文件顶部添加以下 using 语句来解析 ChatHub 所在的命名空间：

    using SignalRWebPack.Hubs;
    
    ...

    public void ConfigureServices(IServiceCollection services)
    {
        ...
        services.AddSignalR();
    }

    public void Configure(IApplicationBuilder app, IWebHostEnvironment env)
    {
        if (env.IsDevelopment())
        {
            app.UseDeveloperExceptionPage();
        }
        
        app.UseRouting();
        app.UseDefaultFiles();
        app.UseStaticFiles();
        
        app.UseEndpoints(endpoints =>
        {
            endpoints.MapRazorPages();
            endpoints.MapHub<ChatHub>("/hub");
        });
            
    }

上述代码 UseDefaultFiles 允许服务器查找和处理 index.html 文件， 无论用户输入完整 URL 还是 Web 应用的根 URL，都会提供该文件。这样就不会使用默认的 endpoints.MapRazorPages() 加载 Razor Page。

在项目根目录中创建名为 Hubs 的新目录，以存储 SignalR 中心，创建包含以下代码的中心 Hubs/ChatHub.cs ：

    using Microsoft.AspNetCore.SignalR;
    using System.Threading.Tasks;

    namespace SignalRWebPack.Hubs
    {
        public class ChatHub : Hub
        {
            public async Task SendMessage(string user, string message)
            {
                Console.WriteLine($"SendMessage {user} {message}");
                await Clients.All.SendAsync("ReceiveMessage", user, message);
                // await Clients.Caller.SendAsync("ReceiveMessage", user, message);
            }
        }
    }

然后修改 src/index.ts 文件代码，使用 SignalR 传输消息：

    import "./css/main.css";
    import * as signalR from "@microsoft/signalr";

    const divMessages: HTMLDivElement = document.querySelector("#divMessages");
    const tbMessage: HTMLInputElement = document.querySelector("#tbMessage");
    const btnSend: HTMLButtonElement = document.querySelector("#btnSend");
    const username = new Date().getTime();

    const connection = new signalR.HubConnectionBuilder()
        .withUrl("/hub")
        .build();

    connection.on("ReceiveMessage", (username: string, message: string) => {
        let messages = document.createElement("div");

        messages.innerHTML =
            `<div class="message-author">${username}</div><div>${message}</div>`;

        divMessages.appendChild(messages);
        divMessages.scrollTop = divMessages.scrollHeight;
    });

    connection.start().catch(err => document.write(err));

    tbMessage.addEventListener("keyup", (e: KeyboardEvent) => {
        if (e.key === "Enter") {
            send();
        }
    });

    btnSend.addEventListener("click", send);

    function send() {
        connection.send("SendMessage", username, tbMessage.value)
            .then(() => tbMessage.value = "");
    }

前面的代码支持从服务器接收消息。 HubConnectionBuilder 类创建新的生成器，用于配置服务器连接。 withUrl 函数配置中心 URL。

SignalR 启用客户端和服务器之间的消息交换，每个消息都有特定的名称。 例如，名为 `messageReceived` 的消息可以运行负责在消息区域显示新消息的逻辑。 可以通过 on 函数完成对特定消息的侦听。 可以侦听任意数量的消息名称。 注意参数类型匹配，消息名称收发对应，否则接收不到消息。

还可以将参数传递到消息，例如所接收消息的作者姓名和内容。 客户端收到一条消息后，会创建一个新的 div 元素并在其 innerHTML 属性中显示作者姓名和消息内容。 它添加到显示消息的主要 div 元素。

客户端可以接收消息后，通过 send 给服务器发送消息。 通过 WebSockets 连接发送消息需要调用 send 方法。 该方法的第一个参数是消息名称，后跟消息数据包含的其他参数。 在此示例中，一条标识为 `SendMessage` 的消息已发送到服务器。 该消息包含用户名和文本框中的用户输入。 如果发送成功，会清空文本框。

客户端消息将通过路由进入 ChatHub.NewMessage，服务器收到消息后，前面的代码会将这些消息播发到所有连接的用户。 没有必要使用泛型 on 方法接收所有消息。 使用以消息名称命名的方法就可以了。

在此示例中，TypeScript 客户端发送一条标识为 `SendMessage` 的消息。客户端消息将通过路由进入 ChatHub.SendMessage 方法，需要向客户端发送的数据，在 Clients.All 上调用 SendAsync 方法会将消息发送到所有连接到中心的客户端。

给指定客户端，如当前回调用户 Clients.Caller 或用户组 Clients.Group(name) 或给特定用户发送消息 Clients.User(user)。


最后，打包项目，或执行测试。

    npm run dev

通过在项目根中执行以下命令以 release 模式运行 Webpack 打包项目：

    npm run release

Webpack 完成了以下任务：

- 清除了 wwwroot 目录的内容 。
- 将 TypeScript 转换为 JavaScript，该过程称为“转译” 。
- 破坏生成的 JavaScript 以降低文件大小，该过程称为缩小 。
- 将已处理的 JavaScript、CSS 和 HTML 文件从 src 复制到 wwwroot 目录 。
- 将以下元素注入 wwwroot/index.html 文件 ：

    一个引用 `wwwroot/main.<hash>.css` 文件的 `<link>` 标记。 此标记紧挨着 `</head>` 结束标记之前。
    一个引用`wwwroot/main.<hash>.js` 文件的 `<script>` 标记。 此标记紧挨着 `</body>` 结束标记之前。

通过在项目根中执行以下命令生成和运行应用：

    dotnet run

Web 服务器启动应用并在 localhost 上提供。打开两个浏览器，转到服务地址，检查服务提供 wwwroot/index.html 文件 。 

选择一个浏览器，在消息文本框中键入任意内容，然后单击发送按钮，两个页面上立即显示唯一的用户名和消息。




# Blazor 交互式客户端框架
- https://docs.microsoft.com/en-us/aspnet/core/blazor/?view=aspnetcore-3.1
- https://github.com/AdrienTorris/awesome-blazor
- https://developer.mozilla.org/zh-CN/docs/Web/Manifest


组件化的 Blazor 框架结合 WebAssembly 就可以用 C# 来实现交互式客户端 Web UI，它基于 SignalR 即 WebSocket 技术实现消息推送，高效跨平台。组件化这很容易联想到 React/Angular/Vue 这些组件化的前端框架，因为它们真的很多类似。

Blazor 是一个使用 .NET 生成交互式客户端 Web UI 的框架：

- 使用 C# 代替 JavaScript 来创建丰富的交互式 UI。
- 共享使用 .NET 编写的服务器端和客户端应用逻辑。
- 将 UI 呈现为 HTML 和 CSS，以支持众多浏览器，其中包括移动浏览器。
- 与新式托管平台（如 Docker）集成。

使用 .NET 进行客户端 Web 开发可提供以下优势：

- 使用 C# 代替 JavaScript 来编写代码。
- 利用现有的 .NET 库生态系统。
- 在服务器和客户端之间共享应用逻辑。
- 受益于 .NET 的性能、可靠性和安全性。
- 始终高效支持 Windows、Linux 和 macOS 上的 Visual Studio。
- 以一组稳定、功能丰富且易用的通用语言、框架和工具为基础来进行生成。


Blazor 使用 Razor 组件，Razor 是一种语法，用于将 HTML 标记与专为提高开发人员工作效率而设计的 C# 代码结合在一起。

Blazor WebAssembly 是一个单页应用框架，可用它通过 .NET 生成交互式客户端 Web 应用。 Blazor WebAssembly 使用开放的 Web 标准，适用于移动浏览器等各种新式 Web 浏览器。通过 WebAssembly，可在 Web 浏览器内运行 .NET 代码。 WebAssembly 是针对快速下载和最大执行速度优化的压缩字节码格式。

Blazor Server 将组件呈现逻辑从 UI 更新的应用方式中分离出来。 Blazor 服务器在 ASP.NET Core 应用中添加了对在服务器上托管 Razor 组件的支持。 可通过 SignalR 连接处理 UI 更新。运行时处理从浏览器向服务器发送 UI 事件，并在运行组件后，将服务器发送的 UI 更新重新应用到浏览器。
Blazor 服务器用于与浏览器通信的连接还用于处理 JavaScript 互操作调用。

对于需要第三方 JavaScript 库和访问浏览器 API 的应用，组件与 JavaScript 进行互操作。 组件能够使用 JavaScript 能够使用的任何库或 API。 C# 代码可以调用到 JavaScript 代码，而 JavaScript 代码可以调用到 C# 代码。 

- 在 ASP.NET Core Blazor 中从 .NET 方法调用 JavaScript 函数
- 从 ASP.NET Core Blazor 中的 JavaScript 函数调用 .NET 方法


若要获得 Blazor Server 体验，请在命令行界面中执行以下命令：

    dotnet new blazorserver -o blazorServerWebApp
    cd blazorServerWebApp
    dotnet run

若要获得 Blazor WebAssembly 体验，请在命令行界面中执行以下命令：

    dotnet new blazorwasm -o blazorWasmWebApp
    cd blazorWasmWebApp
    dotnet run

若要获得 Blazor WebAssembly PWA 体验，请在命令行界面中执行以下命令：

    dotnet new blazorwasm -o MyNewProject --pwa


渐进式 Web 应用 (PWA) 是一种单页应用程序 (SPA)，它使用新式浏览器 API 和功能以表现得如桌面应用。 Blazor WebAssembly 是基于标准的客户端 Web 应用平台，因此它可以使用任何浏览器 API，包括以下功能所需的 PWA API：

- 脱机工作并即时加载（不受网络速度影响）。
- 在自己的应用窗口中运行，而不仅仅是在浏览器窗口中运行。
- 从主机操作系统的开始菜单、扩展坞或主屏幕启动。
- 从后端服务器接收推送通知，即使用户没有在使用该应用。
- 在后台自动更新。

使用渐进式一词来描述此类应用的原因如下 ：

- 用户可能先是在其网络浏览器中发现应用并使用它，就像任何其他单页应用程序一样。
- 过了一段时间后，用户进而将其安装到操作系统中并启用推送通知。

访问使用 PWA 模板创建的应用时，用户可以选择将应用安装到其 OS 的开始菜单、扩展坞或主屏幕。 此选项的显示方式取决于用户的浏览器，和应用部件清单 (manifest) 设置。 使用基于桌面 Chromium 的浏览器（如 Edge 或 Chrome）时，URL 栏中会出现添加按钮 。

默认情况下，使用 PWA 模板选项创建的应用支持脱机运行。 用户首次访问该应用时需要联机访问。 浏览器会自动下载并缓存脱机操作所需的所有资源。


Blazor Server 与 Blazor WebAssembly 这两个 Blazor 托管模型应用的一个最大的区别，在于服务传送的数据通过 SignalR 即 WebSocket 传输，包括 UI 的更新。可以看作是 ASP.NET Core SignalR 和 Blazor WebAssembly 的结合。

通过运行以下命令安装 Blazor WebAssembly 预览版模板：

    dotnet new -i Microsoft.AspNetCore.Components.WebAssembly.Templates::3.2.0-rc1.20223.4


Blazor 是一种 Web 框架，专用于在基于 WebAssembly 的 .NET 运行时 (Blazor WebAssembly) 上的浏览器中运行客户端，或在 ASP.NET Core（Blazor 服务器）中运行服务器端 。 对于任意托管模型，应用和组件模型都相同 。

Blazor WebAssembly 模板包括 blazor.webassembly.js 脚本，可处理以下任务：

- 下载 .NET 运行时、应用和应用依赖项。
- 初始化运行应用的运行时。

Blazor WebAssembly 托管模型具有以下优点：

- 没有 .NET 服务器端依赖项。 应用下载到客户端后即可正常运行。
- 可充分利用客户端资源和功能。
- 工作可从服务器转移到客户端。
- 无需 ASP.NET Core Web 服务器即可托管应用。 无服务器部署方案可行（例如通过 CDN 为应用提供服务的方案）。

Blazor WebAssembly 托管具有以下缺点：

- 应用仅可使用浏览器功能。
- 需要可用的客户端硬件和软件（例如 WebAssembly 支持）。
- 下载项大小较大，应用加载耗时较长。
- .NET 运行时和工具支持不够完善。 例如，.NET Standard 支持和调试方面存在限制。


Blazor Server 托管模型可从 ASP.NET Core 应用中在服务器上执行应用。 UI 更新、事件处理和 JavaScript 调用是通过 SignalR 连接进行处理。浏览器通过 SignalR 实现的 WebSocket 连接与服务器上的应用进行交互，该应用托管在 ASP.NET Core 应用内部。ASP.NET Core 应用会托管 Blazor 服务器应用，并在连接客户端的位置创建 SignalR 终结点。

ASP.NET Core 应用会引用应用的 Startup 类以添加以下内容：

- 服务器端服务。
- 用于请求处理管道的应用。
- blazor.server.js 脚本会建立客户端连接。 应用负责根据需要保存和还原应用状态（例如在网络连接丢失时）。 - blazor.server.js 脚本由 ASP.NET Core 共享框架中的嵌入资源提供。

Blazor Server 托管模型具有以下优点：

- 下载项大小明显小于 Blazor WebAssembly 应用，且应用加载速度快得多。
- 应用可充分利用服务器功能，包括使用任何与 .NET Core 兼容的 API。
- 服务器上的 .NET Core 用于运行应用，因此调试等现有 .NET 工具可按预期正常工作。
- 支持瘦客户端。 例如，Blazor 服务器应用适用于不支持 WebAssembly 的浏览器以及资源受限的设备。
- 应用的 .NET/C# 代码库（其中包括应用的组件代码）不适用于客户端。

Blazor 服务器托管具有以下缺点：

- 通常延迟较高。 每次用户交互都涉及到网络跃点。
- 不支持脱机工作。 如果客户端连接失败，应用会停止工作。
- 如果具有多名用户，则应用扩缩性存在挑战。 服务器必须管理多个客户端连接并处理客户端状态。
- 需要 ASP.NET Core 服务器为应用提供服务。 无服务器部署方案不可行（例如通过 CDN 为应用提供服务的方案）。

理解 Blazor 服务器应用的一种方法是，了解其与使用 Razor 视图或 Razor Pages 在 ASP.NET Core 应用中呈现 UI 的惯用模型之间的差异。 这两种模型都使用 Razor 语言描述 HTML 内容，但两者在标记的呈现方式上差别显著。

呈现 Razor 页面或视图时，每行 Razor 代码都以文本形式发出 HTML。 呈现后，服务器会丢弃页面或视图实例，包括生成的任何状态。 出现另一个对该页面的请求时，例如，服务器验证失败并显示验证摘要时：

- 整个页面将再次重新呈现为 HTML 文本。
- 页面会发送到客户端。

Blazor 应用由 UI 的可重用元素组成，这些元素称为组件 。 组件包含 C# 代码、标记和其他成分。 呈现组件时，Blazor 会生成所含组件的图，类似于 HTML 或 XML 文档对象模型 (DOM)。 此图包含属性和字段中保存的组件状态。 Blazor 会评估组件图，生成二进制形式的标记。 二进制格式可以转换为 HTML 文本，可用于在定期呈现期间高效更新标记。

预呈现 Prerendering 会使应用对用户的响应更加迅速。应用请求的 Razor 组件在服务器上编译为静态 HTML，然后发送到客户端并呈现给用户。 客户端与服务器之间建立连接后，组件的静态预呈现元素会替换为交互式元素。 

Blazor 中的 UI 更新由以下内容触发：

- 用户交互，例如选中按钮。
- 应用触发器，例如计时器。

视图呈现需要经过 UI diff（差异）计算，差异是更新客户端上的 UI 所需的最小一组 DOM 修改。 差异以二进制格式发送到客户端，并由浏览器应用。

用户在客户端上退出组件之后，组件会被丢弃。 用户与组件交互时，组件的状态（服务、资源）必须保存在服务器的内存中。 由于服务器可能同时保存多个组件的状态，因此必须解决内存不足的问题。

Blazor Server apps 采用有状态数据处理模型，其中服务器和客户端保持长期的关系。 持久状态由线路维护，线路可以跨也可能长期生存期的连接。

当用户访问 Blazor 服务器站点时，服务器将在服务器的内存中创建线路。 线路向浏览器指示要呈现的内容并响应事件，例如当用户在 UI 中选择一个按钮时。 若要执行这些操作，线路会在用户的浏览器和服务器上的 .NET 方法中调用 JavaScript 函数。 这种基于 JavaScript 的双向交互称为javascript 互操作（JS 互操作）。

由于在 Internet 上进行 JS 互操作，并且客户端使用远程浏览器，Blazor Server apps 共享大多数 web 应用安全问题。


## Blazor 项目结构

Blazor 项目文件和文件夹构成了基于 Blazor 模板生成的 Blazor 应用：

- Program.cs 是应用的入口点

    设置 ASP.NET Core 主机 Blazor Server 或 Blazor WebAssembly 主机。

    该文件中的代码对于通过 Blazor WebAssembly 模板创建的应用是唯一的，不含 Startup。根组件 App.razor 被指定为 Add 方法的 app DOM 元素。

- Startup.cs 包含 Blazor Server 应用的启动逻辑

    Startup 类定义两个方法，ConfigureServices 配置应用的 依赖项注入 (DI) 服务。 在 Blazor Server 应用中，通过调用 AddServerSideBlazor 添加服务。

    另一个方法 Configure 配置应用的请求处理管道，调用 MapBlazorHub 可以为与浏览器的实时连接设置终结点。 使用 SignalR 创建连接，该框架用于向应用添加实时 Web 功能。调用 `MapFallbackToPage("_Host")` 以设置应用的根页面，`Pages/_Host.cshtml` ，它指定根 App 组件 (App.razor) 的呈现位置并启用导航。根页面加载 `blazor.server.js` JavaScript 文件，用于在浏览器和服务器之间建立实时 SignalR 连接。

- wwwroot/index.html 为 Blazor WebAssembly 项目的 HTML 根页面

    最初请求应用的任何页面时，都会呈现此页面并在响应中返回，此页面指定根 App 组件的呈现位置。 App 组件 (App.razor) 在 Startup.Configure 中指定为 AddComponent 方法的 app DOM 元素。

    此页面一个重要的功能是加载 `blazor.webassembly.js` JavaScript 文件，该文件用于下载 .NET 运行时、应用和应用依赖项，初始化运行时以运行应用。

- `App.razor` 应用的 app 根组件

    它使用 Router 组件设置客户端路由，路由组件会截获浏览器导航并呈现与请求的地址匹配的页面。在路由视图 RouteView 或 LayoutView 设置了默认的布局组件 `Shared/MainLayout.razor`，布局组件配置了页面的基本骨架，主要是导航菜单 `NavMenu.razor`。

- Pages 文件夹

    包含构成 Blazor 应用的可路由组件/页面 (.razor) 和 Blazor Server 应用的根 Razor 页面。 每个页面的路由都是使用 @page 指令指定的。 

- Shared 文件夹

    包含应用使用的其他 UI 组件 ( .razor)，MainLayout (MainLayout.razor) 为应用的布局组件。NavMenu (NavMenu.razor) 实现侧栏导航。 包括 NavLink 组件 (NavLink)，该组件可向其他 Razor 组件呈现导航链接。 NavLink 组件会在系统加载其组件时自动指示选定状态，这有助于用户了解当前显示的组件。

    Razor Page 或 ASP.Net Core MVC 项目的 Shared 目录在 Views 或 Pages 目录下。

- `_Imports.razor` 包括要包含在应用组件 (.razor) 中的常见 Razor 指令，例如用于命名空间的 @using 指令 。

- Data 文件夹包含 Blazor Server 项目使用的 WeatherForecast 类和 WeatherForecastService 的实现，它们向应用的 FetchData 组件提供示例天气数据服务。

- wwwroot 应用的 Web 根目录文件夹，其中包含应用的公共静态资源。
- appsettings.json 为 Blazor Server 应用的配置文件，例如，保存数据连接信息。


Blazor Server 入口 Program.cs：

    using System;
    using System.Collections.Generic;
    using System.Threading.Tasks;
    using Microsoft.AspNetCore;
    using Microsoft.AspNetCore.Hosting;
    using Microsoft.Extensions.Configuration;
    using Microsoft.Extensions.Hosting;
    using Microsoft.Extensions.Logging;

    namespace blazorServerWebApp
    {
        public class Program
        {
            public static void Main(string[] args)
            {
                CreateHostBuilder(args).Build().Run();
            }

            public static IHostBuilder CreateHostBuilder(string[] args) =>
                Host.CreateDefaultBuilder(args)
                    .ConfigureWebHostDefaults(webBuilder =>
                    {
                        webBuilder.UseStartup<Startup>();
                    });
        }
    }

Blazor WebAssembly 只入口 Program.cs 没有 Startup 配置，主要差别在使用 Host 类型是 WebAssemblyHost：

    using System;
    using System.Net.Http;
    using System.Collections.Generic;
    using System.Threading.Tasks;
    using System.Text;
    using Microsoft.AspNetCore.Components.WebAssembly.Hosting;
    using Microsoft.Extensions.Configuration;
    using Microsoft.Extensions.DependencyInjection;
    using Microsoft.Extensions.Logging;

    namespace blazorWasmWebApp
    {
        public class Program
        {
            public static async Task Main(string[] args)
            {
                var builder = WebAssemblyHostBuilder.CreateDefault(args);
                builder.RootComponents.Add<App>("app");

                builder.Services.AddTransient(sp => new HttpClient { BaseAddress = new Uri(builder.HostEnvironment.BaseAddress) });

                await builder.Build().RunAsync();
            }
        }
    }

Blazor Server 和 Razor Page 项目的差别在 Statups.cs 中的配置中调用 `AddServerSideBlazor()` 和 `MapBlazorHub()`，`MapFallbackToPage("/_Host")`，引用了 Microsoft.AspNetCore.Components：

    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Threading.Tasks;
    using Microsoft.AspNetCore.Builder;
    using Microsoft.AspNetCore.Components;
    using Microsoft.AspNetCore.Hosting;
    using Microsoft.AspNetCore.HttpsPolicy;
    using Microsoft.Extensions.Configuration;
    using Microsoft.Extensions.DependencyInjection;
    using Microsoft.Extensions.Hosting;
    using blazorServerWebApp.Data;

    namespace blazorServerWebApp
    {
        public class Startup
        {
            public Startup(IConfiguration configuration)
            {
                Configuration = configuration;
            }

            public IConfiguration Configuration { get; }

            // This method gets called by the runtime. Use this method to add services to the container.
            // For more information on how to configure your application, visit https://go.microsoft.com/fwlink/?LinkID=398940
            public void ConfigureServices(IServiceCollection services)
            {
                services.AddRazorPages();  // for Razor Page
                services.AddServerSideBlazor();
                services.AddSingleton<WeatherForecastService>();
            }

            // This method gets called by the runtime. Use this method to configure the HTTP request pipeline.
            public void Configure(IApplicationBuilder app, IWebHostEnvironment env)
            {
                if (env.IsDevelopment())
                {
                    app.UseDeveloperExceptionPage();
                }
                else
                {
                    app.UseExceptionHandler("/Error");
                    // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
                    app.UseHsts();
                }

                app.UseHttpsRedirection();
                app.UseStaticFiles();

                app.UseRouting();

                app.UseEndpoints(endpoints =>
                {
                    endpoints.MapRazorPages();  // for Razor Page
                    endpoints.MapBlazorHub();
                    endpoints.MapFallbackToPage("/_Host");
                });
            }
        }
    }


根页面 `Pages/_Host.cshtml`:

    @page "/"
    @namespace blazorServerWebApp.Pages
    @addTagHelper *, Microsoft.AspNetCore.Mvc.TagHelpers
    @{
        Layout = null;
    }

    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>blazorServerWebApp</title>
        <base href="~/" />
        <link rel="stylesheet" href="css/bootstrap/bootstrap.min.css" />
        <link href="css/site.css" rel="stylesheet" />
    </head>
    <body>
        <app>
            <component type="typeof(App)" render-mode="ServerPrerendered" />
        </app>

        <div id="blazor-error-ui">
            <environment include="Staging,Production">
                An error has occurred. This application may no longer respond until reloaded.
            </environment>
            <environment include="Development">
                An unhandled exception has occurred. See browser dev tools for details.
            </environment>
            <a href="" class="reload">Reload</a>
            <a class="dismiss">🗙</a>
        </div>

        <script src="_framework/blazor.server.js"></script>
    </body>
    </html>


根组件 `App.razor`:

    <Router AppAssembly="@typeof(Program).Assembly">
        <Found Context="routeData">
            <RouteView RouteData="@routeData" DefaultLayout="@typeof(MainLayout)" />
        </Found>
        <NotFound>
            <LayoutView Layout="@typeof(MainLayout)">
                <p>Sorry, there's nothing at this address.</p>
            </LayoutView>
        </NotFound>
    </Router>


Blazor Server 和 Razor Page 程序有一致的入口 Program.cs。 Blazor Server 的程序结构和普通的 ASP.NET Core Web App 结构很相似，配置好后，二者可以在同一个项目中并存。注意，Razor 组件需要在 Blazor 中解析，不能在 Razor Page 使用 Razor 组件，这看起来很奇怪。

二者并存首先要解决的问题是路由设置，二者默认的首页不同，在访问时就有同一个路由对应多个视图的冲突：

- `Pages/_Host.cshtml` Blazor Home
- `Pages/Index.cshtml` Razor Page Home

或给 Index.cshtml 改名，或者修改 `Pages/_Host.cshtml` 的 @page "/" 指令，不使用主页的路由匹配。


## Razor Component 组件 
https://docs.microsoft.com/zh-cn/aspnet/core/blazor/lifecycle?view=aspnetcore-3.1

Razor Component 或 Page 可以通过命令生成模板，-na 给 Razor Page 指定命名空间：

    dotnet new razorcomponent -o=. -n="View"
    dotnet new page -o=. -na="Razor.Pages" -n="Home"

Razor 组件实例 Counter.razor，这有点类似 Vue 的单文件组件的实现，可以在其它组件中使用，像这样 `<Counter />`：

    @page "/counter"

    <h1>Counter</h1>

    <p>Current count: @currentCount</p>

    <button class="btn btn-primary" @onclick="IncrementCount">Click me</button>

    @code {
        private int currentCount = 0;

        [Parameter]
        public int IncrementAmount { get; set; } = 1;

        private void IncrementCount()
        {
            currentCount += IncrementAmount;
        }
    }

- 添加了一个公共属性 IncrementAmount 并相设置 [Parameter] 特性。
- 成员 IncrementCount 方法增加 currentCount 的值。
- 定义 Parameter 公共属性可以这样使用 `<Counter IncrementAmount="2" />`。
- @currentCount 或 @onclick 用来绑定属性数据到视图，绑定事件到组件。

使用 HTML 定义 Counter 组件的 UI，动态呈现逻辑，例如，循环、条件、表达式，使用名为 Razor 的嵌入式 C# 语法添加的。 HTML 标记和 C# 呈现逻辑在构建时转换为组件类，生成的 .NET 类的名称与文件名匹配。

@code 表示组件类成员代码块，可以指定组件状态，属性、字段，和方法用于处理事件或定义其他组件逻辑。 然后，可以将这些成员用作组件呈现逻辑的一部分，并用于处理事件。

文件顶部的 @page 指令指定 Counter 组件是路由终结点，Counter 组件处理发送到 /counter 的请求。 如果没有 @page 指令，组件将无法处理路由的请求，但该组件仍可以被其他组件使用。

单击选中 buton 按钮时：

- 调用 Counter 组件的已注册 onclick 处理程序 IncrementCount 方法。
- Counter 组件重新生成其呈现树。
- 将新的呈现树与前一个呈现树进行比较。
- 仅应用对文档对象模型 DOM 的修改。 显示的计数将会更新。


Razor 组件生命周期与 React 组件的生命周期类似，也分为三个阶段：初始化阶段、运行中阶段和销毁阶段：

Blazor 生命周期方法主要包括：

- 设置参数前         SetParametersAsync
- 初始化               OnInitialized / OnInitializedAsync
- 设置参数后         OnParametersSet / OnParametersSetAsync
- 组件渲染呈现后       OnAfterRender / OnAfterRenderAsync
- 判断是否渲染组件  ShouldRender / ShouldRenderAsync
- 组件删除前         Dispose
- 通知组件状态已更改 StateHasChanged

在所有生命周期函数中，有以下需要注意的点：

- 前 5 种方法的声明都是 virtual，除 SetParametersAsync 为 public 外，其他的都是 protected。
- OnAfterRender/OnAfterRenderAsync 方法有一个 bool 类型的形参 firstRender 用于指示是否是第一次渲染。
- 同步方法总是先于异步方法执行。
- Dispose 函数需要通过使用 @implements 指令实现 IDisposable 接口来实现。
- StateHasChanged 无法被重写，可以被显示调用，以便强制实现组件刷新，如果 ShouldRender 返回 true，并且 Blazor 认为需要刷新时；当组件状态更改时不必显示调用此函数，也可导致组件的重新渲染，如果 ShouldRender 返回 true。因为其已经在 ComponentBase 内部的处理过程中被调用，第一次初始化设置参数时、设置参数后和 DOM 事件处理等。

在呈现组件之前，在生命周期事件中执行的异步操作可能尚未完成。 执行生命周期方法时，对象可能为 null 或未完全填充数据。 提供呈现逻辑以确认对象已初始化。 对象为 null 时，呈现占位符 UI 元素（例如，加载消息）。

在 Blazor 模板的 FetchData 组件中，替代 OnInitializedAsync 以异步接收预测数据 (forecasts)。 当 forecasts 为 null 时，将向用户显示加载消息。 OnInitializedAsync 返回的 Task 完成后，该组件以更新后的状态重新呈现。

如果组件实现 IDisposable，则在从 UI 中删除该组件时调用 Dispose 方法。 以下组件使用 @implements IDisposable 和 Dispose 方法：

    @using System
    @implements IDisposable

    ...

    @code {

        private EventHandler<FieldChangedEventArgs> fieldChanged;

        protected override void OnInitialized()
        {
            editContext.OnFieldChanged += fieldChanged;
        }

        public void Dispose()
        {
            editContext.OnFieldChanged -= fieldChanged;
            ...
        }
    }

不支持在 Dispose 中调用 StateHasChanged。 StateHasChanged 可能在拆除呈现器时调用，因此不支持在此时请求 UI 更新。


在 Blazor Server 应用中，当 RenderMode 为 ServerPrerendered 时，组件最初作为页面的一部分静态呈现。 浏览器重新建立与服务器的连接后，将再次呈现组件，并且该组件现在为交互式。 如果存在用于初始化组件的 OnInitialized{Async} 生命周期方法，则该方法执行两次：

- 在静态预呈现组件时执行一次。
- 在建立服务器连接后执行一次。

在最终呈现组件时，这可能导致 UI 中显示的数据发生明显变化。若要避免 Blazor Server 应用中出现双重呈现，请执行以下操作：

- 传递一个标识符，该标识符可用于在预呈现期间缓存状态并在应用重启后检索状态。
- 在预呈现期间使用该标识符保存组件状态。
- 预呈现后使用该标识符检索缓存的状态。

以下代码演示基于模板的 Blazor Server 应用中更新后的 WeatherForecastService，其避免了双重呈现：

    public class WeatherForecastService
    {
        private static readonly string[] summaries = new[]
        {
            "Freezing", "Bracing", "Chilly", "Cool", "Mild",
            "Warm", "Balmy", "Hot", "Sweltering", "Scorching"
        };
        
        public WeatherForecastService(IMemoryCache memoryCache)
        {
            MemoryCache = memoryCache;
        }
        
        public IMemoryCache MemoryCache { get; }

        public Task<WeatherForecast[]> GetForecastAsync(DateTime startDate)
        {
            return MemoryCache.GetOrCreateAsync(startDate, async e =>
            {
                e.SetOptions(new MemoryCacheEntryOptions
                {
                    AbsoluteExpirationRelativeToNow = 
                        TimeSpan.FromSeconds(30)
                });

                var rng = new Random();

                await Task.Delay(TimeSpan.FromSeconds(10));

                return Enumerable.Range(1, 5).Select(index => new WeatherForecast
                {
                    Date = startDate.AddDays(index),
                    TemperatureC = rng.Next(-20, 55),
                    Summary = summaries[rng.Next(summaries.Length)]
                }).ToArray();
            });
        }
    }



在 Blazor Server 应用进行预呈现时，由于尚未建立与浏览器的连接，因此无法执行调用 JavaScript 等特定操作。 预呈现时，组件可能需要进行不同的呈现。

要将 JavaScript 互操作调用延迟到与浏览器建立连接之后，可使用 OnAfterRenderAsync 组件生命周期事件。 仅在完成呈现应用并与客户端建立连接后，才会调用此事件。

    @using Microsoft.JSInterop
    @inject IJSRuntime JSRuntime

    <div @ref="divElement">Text during render</div>

    @code {
        private ElementReference divElement;

        protected override async Task OnAfterRenderAsync(bool firstRender)
        {
            if (firstRender)
            {
                await JSRuntime.InvokeVoidAsync(
                    "setElementText", divElement, "Text after render");
            }
        }
    }

对于上述示例代码，请在视图 HEAD 元素中提供一个 setElementText JavaScript 函数 。 该函数通过 IJSRuntime.InvokeVoidAsync 进行调用，不返回值：

    <script>
      window.setElementText = (element, text) => element.innerText = text;
    </script>

警告，上述示例直接修改文档对象模型 (DOM)，以便仅供演示所用。 大多数情况下，不建议使用 JavaScript 直接修改 DOM，因为 JavaScript 可能会干扰 Blazor 的更改跟踪。

以下组件展示了如何以一种与预呈现兼容的方式将 JavaScript 互操作用作组件初始化逻辑的一部分。 该组件显示可从 OnAfterRenderAsync 内部触发呈现更新。 开发人员必须避免在此场景中创建无限循环。

如果调用 JSRuntime.InvokeAsync，则 ElementRef 仅在 OnAfterRenderAsync 中使用，而不在任何更早的生命周期方法中使用，因为呈现组件后才会有 JavaScript 元素。

会调用 StateHasChanged，使用从 JavaScript 互操作调用中获取的新状态重新呈现该组件。 此代码不会创建无限循环，因为仅在 infoFromJs 为 null 时才调用 StateHasChanged。

    @page "/prerendered-interop"
    @using Microsoft.AspNetCore.Components
    @using Microsoft.JSInterop
    @inject IJSRuntime JSRuntime

    <p>
        Get value via JS interop call:
        <strong id="val-get-by-interop">@(infoFromJs ?? "No value yet")</strong>
    </p>

    Set value via JS interop call:
    <div id="val-set-by-interop" @ref="divElement"></div>

    @code {
        private string infoFromJs;
        private ElementReference divElement;

        protected override async Task OnAfterRenderAsync(bool firstRender)
        {
            if (firstRender && infoFromJs == null)
            {
                infoFromJs = await JSRuntime.InvokeAsync<string>(
                    "setElementText", divElement, "Hello from interop call!");

                StateHasChanged();
            }
        }
    }
    
对于上述示例代码，请在视图中相应提供一个 setElementText JavaScript 函数 该函数通过 IJSRuntime.InvokeAsync 进行调用，会返回值：

    <script>
      window.setElementText = (element, text) => {
        element.innerText = text;
        return text;
      };
    </script>



组件通常会执行长时间运行的后台工作，如进行网络调用 (HttpClient) 以及与数据库交互。 在几种情况下，最好停止后台工作以节省系统资源。 例如，当用户离开组件时，后台异步操作不会自动停止。

后台工作项可能需要取消的其他原因包括：

- 正在执行的后台任务由错误的输入数据或处理参数启动。
- 正在执行的一组后台工作项必须替换为一组新的工作项。
- 必须更改当前正在执行的任务的优先级。
- 必须关闭应用才能将其重新部署到服务器。
- 服务器资源受到限制，需要重新计划后台工作项。

要在组件中实现可取消的后台工作模式：

- 使用 CancellationTokenSource 和 CancellationToken。
- 在释放组件时，以及需要随时通过手动取消标记进行取消时，请调用 CancellationTokenSource.Cancel 以指示应取消后台工作。
- 异步调用返回后，对该标记调用 ThrowIfCancellationRequested。

如下示例中：

await Task.Delay(5000, cts.Token); 表示长时间运行的异步后台工作。

BackgroundResourceMethod 表示如果在调用方法之前释放 Resource，则不应启动的长时间运行的后台方法。
razor


    @implements IDisposable
    @using System.Threading

    <button @onclick="LongRunningWork">Trigger long running work</button>

    @code {
        private Resource resource = new Resource();
        private CancellationTokenSource cts = new CancellationTokenSource();

        protected async Task LongRunningWork()
        {
            await Task.Delay(5000, cts.Token);

            cts.Token.ThrowIfCancellationRequested();
            resource.BackgroundResourceMethod();
        }

        public void Dispose()
        {
            cts.Cancel();
            cts.Dispose();
            resource.Dispose();
        }

        private class Resource : IDisposable
        {
            private bool disposed;

            public void BackgroundResourceMethod()
            {
                if (disposed)
                {
                    throw new ObjectDisposedException(nameof(Resource));
                }
                
                ...
            }
            
            public void Dispose()
            {
                disposed = true;
            }
        }
    }



## Blazor Events 事件处理

Razor 组件提供事件处理功能。 对于具有委托类型值且名为 @on{EVENT}（例如 @onclick）的 HTML 元素特性，Razor 组件将该特性的值视为事件处理程序。

- @on{EVENT} 为 Razor 组件提供事件处理功能。
- @on{EVENT}:preventDefault 禁止事件的默认操作。
- @on{EVENT}:stopPropagation 停止事件的事件传播。

在 UI 中选择该按钮时，以下代码调用 UpdateHeading 方法：

    <button class="btn btn-primary" @onclick="UpdateHeading">
        Update heading
    </button>

    @code {
        private void UpdateHeading(MouseEventArgs e)
        {
            ...
        }
    }

UI 中的该复选框更改时，以下代码调用 CheckChanged 方法：

    <input type="checkbox" class="form-check-input" @onchange="CheckChanged" />

    @code {
        private void CheckChanged()
        {
            ...
        }
    }

事件处理程序也可以是异步处理程序，并返回 Task。 无需手动调用 StateHasChanged。 异常发生时，它们将被记录下来。

在下面的示例中，选择该按钮时，异步调用 UpdateHeading：

    <button class="btn btn-primary" @onclick="UpdateHeading">
        Update heading
    </button>

    @code {
        private async Task UpdateHeading(MouseEventArgs e)
        {
            ...
        }
    }




使用 `@on{EVENT}:preventDefault` 指令属性可阻止事件的默认操作。

在输入设备上选择某个键并且元素焦点位于某个文本框上时，浏览器通常在该文本框中显示该键的字符。 在下面的示例中，通过指定 `@onkeypress:preventDefault` 指令属性来阻止默认行为。

以下按键计数器，通过禁止 `<input>` 的默认行为，使得按下的字符不会被捕获到元素中显示，否则元素捕捉到输入的字符，然后 KeyHandler 更累计次数再次显示，就会出现数字和字符的交替显示：

    <input value="@count" @onkeypress="KeyHandler" @onkeypress:preventDefault />

    @code {
        private int count = 0;

        private void KeyHandler(KeyboardEventArgs e)
        {
            if (e.Key == "=")
            {
                count++;
            }
        }
    }

指定没有值的 @on{EVENT}:preventDefault 属性等同于 @on{EVENT}:preventDefault="true"。
属性的值也可以， 在下面的示例中，shouldPreventDefault 是设置为 true 或 false 的 bool 字段：

    <input @onkeypress:preventDefault="shouldPreventDefault" />


使用 @on{EVENT}:stopPropagation 指令属性来停止事件传播。HTML 的事件有捕捉和冒泡两个流程：

- Events Capture 在元素各注册的事件捕捉处理函数中，父级元素优先子级获得事件处理权；
- Events Popagation 在元素各注册的侦听处理函数中，子级元素优先父级获得事件处理权；
- 当事件处理函数高等 stop popagation 动作，那后续的其它事件处理函数将不再执行。

在下例中，选中复选框可阻止第二个子级 `<div>` 中的单击事件传播到父级 `<div>`：


    <label>
        <input @bind="stopPropagation" type="checkbox" />
        Stop Propagation
    </label>

    <div @onclick="OnSelectParentDiv">
        <h3>Parent div</h3>

        <div @onclick="OnSelectChildDiv">
            Child div that doesn't stop propagation when selected.
        </div>

        <div @onclick="OnSelectChildDiv" @onclick:stopPropagation="stopPropagation">
            Child div that stops propagation when selected.
        </div>
    </div>

    @code {
        private bool stopPropagation = false;

        private void OnSelectParentDiv() => 
            Console.WriteLine($"The parent div was selected. {DateTime.Now}");
        private void OnSelectChildDiv() => 
            Console.WriteLine($"A child div was selected. {DateTime.Now}");
    }



事件处理器还可以使用 Lambda 表达式：

    <button @onclick="@(e => Console.WriteLine("Hello, world!"))">Say hello</button>

在 Lambda 表达式中可以使用通过本地变量捕获的 for 循环中的循环变量 (i) 。 直接在 Lambda 表达式将使用 for 的循环变量，导致所有 Lambda 中的 i 值相同。 始终在本地变量中捕获其值（在前面的示例中为 buttonNumber），然后使用它。

示例创建了三个按钮，在 UI 中选中这些按钮时，每个按钮都调用 UpdateHeading 传递事件参数 (MouseEventArgs) 和其按钮编号 (buttonNumber)：

    <SurveyPrompt Title="How is Blazor working for you?" Content="@message" />

    @for (var i = 1; i < 4; i++)
    {
        var buttonNumber = i;

        <button class="btn btn-primary"
                @onclick="@(e => UpdateHeading(e, buttonNumber))">
            Button #@i
        </button>
    }

    @code {
        private string message = "Select a button to learn its position.";

        private void UpdateHeading(MouseEventArgs e, int buttonNumber)
        {
            message = $"You selected Button #{buttonNumber} at " +
                $"mouse position: {e.ClientX} X {e.ClientY}.";
        }
    }


EventCallback 适用于嵌套组件的一个常见场景，希望在子组件事件发生时运行父组件的方法，例如当子组件中发生 onclick 事件时。 若要跨组件公开事件，请使用 EventCallback，父组件可向子组件的 EventCallback 分配回调方法。

这可以解决子组件向父组件传递数据，参考 Data Bindding 数据绑定。

示例应用 ChildComponent.razor 演示如何设置按钮的 onclick 处理程序以供 ParentComponent 接收 EventCallback 委托。 EventCallback 是用 MouseEventArgs 类型，这适用于来自鼠标等外围设备的 onclick 事件：

    <div class="panel panel-default">
        <div class="panel-heading">@Title</div>
        <div class="panel-body">@ChildContent</div>

        <button class="btn btn-primary" @onclick="OnClickCallback">
            Trigger a Parent component method
        </button>
    </div>

    @code {
        [Parameter]
        public string Title { get; set; }

        [Parameter]
        public RenderFragment ChildContent { get; set; }

        [Parameter]
        public EventCallback<MouseEventArgs> OnClickCallback { get; set; }
    }

ParentComponent 将子级的 OnClickCallback 委托 ShowMessage 方法进行处理。当子级触发 onclick 事件即调用 ParentComponent 的 ShowMessage 方法处理，messageText 得到更新并显示

    @page "/ParentComponent"

    <h1>Parent-child example</h1>

    <ChildComponent Title="Panel Title from Parent"
                    OnClickCallback="@ShowMessage">
        Content of the child component is supplied
        by the parent component.
    </ChildComponent>

    <p><b>@messageText</b></p>

    @code {
        private string messageText;

        private void ShowMessage(MouseEventArgs e)
        {
            messageText = $"Blaze a new trail with Blazor! ({e.ScreenX}, {e.ScreenY})";
        }
    }

回调方法 (ShowMessage) 中不需要对 StateHasChanged 的调用。 自动调用 StateHasChanged 以重新呈现 ParentComponent，就像子事件触发组件重新呈现于在子级中执行的事件处理程序中一样。

EventCallback 和 EventCallback<T> 允许异步委托。EventCallback 为弱类型，允许任何参数类型。 EventCallback<T> 为强类型，需要指定的参数类型，能向用户提供更好的组件错误反馈。 与其他 UI 事件处理程序类似，指定事件参数是可选操作。

    <ChildComponent 
        OnClickCallback="@(async () => { await Task.Yield(); messageText = "Blaze It!"; })" />

在子级的 onclick 中使用 InvokeAsync 调用 EventCallback 或 EventCallback<T> 并等待 Task：

    await callback.InvokeAsync(arg);



对于某些事件，允许使用事件参数类型定义在 Microsoft.AspNetCore.Components.Web。 仅当方法中使用了事件类型时，才需要在方法调用中指定该事件类型。支持的 EventArgs 类型，事件分类及相关的 DOM 事件和说明：

- 剪贴板   ClipboardEventArgs

    oncut, oncopy, onpaste

- 拖动    DragEventArgs

    ondrag, ondragstart, ondragenter, ondragleave, ondragover, ondrop, ondragend

    DataTransfer 和 DataTransferItem 保留拖动的项数据。

- 错误    ErrorEventArgs  onerror

- 一般事件  EventArgs

    常规
    onactivate、onbeforeactivate、onbeforedeactivate、ondeactivate、onended、onfullscreenchange、onfullscreenerror、onloadeddata、onloadedmetadata、onpointerlockchange、onpointerlockerror、onreadystatechange、onscroll

    剪贴板
    onbeforecut, onbeforecopy, onbeforepaste

    输入
    oninvalid, onreset, onselect, onselectionchange, onselectstart, onsubmit

    介质
    oncanplay、oncanplaythrough、oncuechange、ondurationchange、onemptied、onpause、onplay、onplaying、onratechange、onseeked、onseeking、onstalled、onstop、onsuspend、ontimeupdate、onvolumechange、onwaiting

- 焦点    FocusEventArgs  

    onfocus, onblur, onfocusin, onfocusout

    不包含对 relatedTarget 的支持。

- 输入    ChangeEventArgs

    onchange，oninput

- 键盘    KeyboardEventArgs

    onkeydown, onkeypress, onkeyup

- 鼠标    MouseEventArgs

    onclick, oncontextmenu, ondblclick, onmousedown, onmouseup, onmouseover, onmousemove, onmouseout

- 鼠标指针  PointerEventArgs    

    onpointerdown, onpointerup, onpointercancel, onpointermove, onpointerover, onpointerout, onpointerenter, onpointerleave, ongotpointercapture, onlostpointercapture

- 鼠标滚轮  WheelEventArgs  

    onwheel，onmousewheel

- 进度    ProgressEventArgs   

    onabort, onload, onloadend, onloadstart, onprogress, ontimeout

- 触控    TouchEventArgs  

    ontouchstart, ontouchend, ontouchmove, ontouchenter, ontouchleave, ontouchcancel

    TouchPoint 表示触控敏感型设备上的单个接触点。



## State Management 状态管理
https://docs.microsoft.com/zh-cn/aspnet/core/blazor/state-management?view=aspnetcore-3.1

Blazor 服务器是有状态的应用框架。 大多数情况下，应用保持与服务器的持续连接。 用户的状态保留在线路中的服务器内存中 。

为用户线路保留的状态示例包括：

- 呈现的 UI — 组件实例的层次结构及其最新的呈现输出。
- 组件实例中的任何字段和属性的值。
- 在线路范围内的依赖关系注入 (DI) 服务实例中保留的数据。

本文介绍 Blazor 服务器应用中的状态暂留。 Blazor WebAssembly 应用可以利用浏览器中的客户端状态暂留，但需要自定义解决方案或第三方包（这些并不在本文的讨论范围之内）。

Blazor 线路

如果用户遇到暂时的网络连接丢失问题，Blazor 会尝试将用户重新连接到其原始线路，以便用户继续使用该应用。 但是，将用户重新连接到服务器内存中的原始电路并非总是能够实现的：

- 服务器不能永久保留断开连接的线路。 超时后或在服务器面临内存压力时，服务器必须释放断开连接的线路。

- 在多服务器、负载均衡的部署环境中，任何服务器处理请求在任何给定时间都可能变得不可用。 不再需要单个服务器处理整个请求量时，它可能会失败或被自动删除。 当用户尝试重新连接时，原始服务器可能不可用。

- 用户可能会关闭并重新打开其浏览器或重载页面，这会删除浏览器内存中保留的所有状态。 例如，通过 JavaScript 互操作调用设置的值将丢失。

当无法将用户重新连接到其原始线路时，用户将收到一个具有空状态的新线路。 这等效于关闭并重新打开桌面应用。


Blazor 跨线路保留状态

在某些应用场景下，需要跨线路保留状态。 如果出现以下情况，应用可以为用户保留重要数据：

- Web 服务器不可用。
- 用户的浏览器被强制使用新的 Web 服务器启动新线路。

通常情况下，跨线路保持状态适用于用户主动创建数据，而不是简单地读取已存在的数据的应用场景。

若要在单个电路之外保留状态，请勿只是将数据存储在服务器的内存中 。 应用必须将数据保留到其他存储位置。 状态暂留并非是自动进行的 — 必须在开发应用时采取措施来实现有状态的数据暂留。

通常，只有用户投入了大量精力所创建的高价值状态才需要数据暂留。 在下面的示例中，保留状态可以节省时间或有助于商业活动：

- 多步骤 Web 窗体 – 在一个多步骤进程中，如果用户的状态丢失，则需为多个已完成步骤重新输入数据，而这非常耗时。 如果用户离开多步骤窗体并在稍后返回，在这种应用场景下，用户将失去状态。

- 购物车 – 代表潜在收入的应用的所有具有重要商业价值的组件都可进行维护。 如果用户丢失了其状态，进而丢失了其购物车，则在他们稍后返回站点时可购买较少的产品或服务。

通常不需要保留易于重新创建的状态，例如在登录对话框中输入的尚未提交的用户名。


有三个常见位置用于保留 Blazor 服务器应用中的状态。 每种方法分别适用于不同的应用场景，且有不同的注意事项：

- 数据库中的服务器端
- URL
- 浏览器中的客户端

对于永久数据暂留或必须跨多个用户或设备的任何数据，独立的服务器端数据库几乎肯定是最佳选择。 选项包括：

- 关系 SQL 数据库
- 键值存储
- Blob 存储
- 表存储

将数据保存到数据库后，用户可以随时启动新线路。 用户数据会保留且在任何新线路中可用。

对于用户正在主动创建的暂时性数据，通用后备存储是浏览器的 localStorage 和 sessionStorage 集合。 如果放弃该线路，则应用无需管理或清除存储的状态。与服务器端存储相比，这是一项优势。
 备注

本节中的“客户端”是指浏览器中的客户端方案，而不是 BlazorWebAssembly 托管模型。 localStorage 和 sessionStorage 可用于 Blazor WebAssembly 应用，但只能通过编写自定义代码或使用第三方包进行使用。

localStorage 的应用范围限定为用户的浏览器。 如果用户重载页面或关闭并重新打开浏览器，则状态保持不变。 如果用户打开多个浏览器选项卡，则状态跨选项卡共享。 数据保留在 localStorage 中，直到被显式清除为止。

sessionStorage 的应用范围限定为用户的浏览器选项卡。如果用户重载该选项卡，则状态保持不变。 如果用户关闭该选项卡或该浏览器，则状态丢失。 如果用户打开多个浏览器选项卡，则每个选项卡都有自己独立的数据版本。

通常，sessionStorage 使用起来更安全。 sessionStorage 避免了用户打开多个选项卡并遇到以下问题的风险：

- 跨选项卡的状态存储中出现 bug。
- 一个选项卡覆盖其他选项卡的状态时出现混乱行为。

如果应用必须在关闭和重新打开浏览器期间保持状态，则 localStorage 是更好的选择。

使用浏览器存储时的注意事项：

- 与使用服务器端数据库类似，加载和保存数据都是异步的。
- 与服务器端数据库不同，在预呈现期间，存储不可用，因为在预呈现阶段，请求的页面在浏览器中不存在。
- 保留状态的位置对于 Blazor 服务器应用，持久存储几千字节的数据是合理的。 超出几千字节后，你就须考虑性能影响，因为数据是跨网络加载和保存的。
- 用户可以查看或篡改数据。 ASP.NET Core 数据保护可以降低风险。


Microsoft.AspNetCore.ProtectedBrowserStorage 就是一个为 localStorage 和 sessionStorage 提供数据保护的 NuGet 实验性包，目前不适合用于生产。

在 Blazor 服务器应用项目中安装 Microsoft.AspNetCore.ProtectedBrowserStorage 包：

    dotnet add package Microsoft.AspNetCore.ProtectedBrowserStorage

在顶级 HTML（例如，在默认项目模板中的 `Pages/_Host.cshtml` 文件中）中，添加以下标记 ：

    <script src="_content/Microsoft.AspNetCore.ProtectedBrowserStorage/protectedBrowserStorage.js"></script>

在 Startup.ConfigureServices 方法中，调用 AddProtectedBrowserStorage 以将 localStorage 和 sessionStorage 服务添加到服务集合：

    services.AddProtectedBrowserStorage();

保存和加载组件中的数据，在需要将数据加载或保存到浏览器存储的任何组件中，使用 @inject 注入以下任意一项的实例：

    ProtectedLocalStorage
    ProtectedSessionStorage

此选择取决于你要使用的后备存储。 在以下示例中，使用 sessionStorage：

    @using Microsoft.AspNetCore.ProtectedBrowserStorage
    @inject ProtectedSessionStorage ProtectedSessionStore

可将 @using 语句放置在 `_Imports.razor` 文件而不是组件中 。 使用 `_Imports.razor` 文件可使命名空间可用于应用的较大部分或整个应用 。

若要在项目模板的 Counter 组件中保留 currentCount 值，请修改 IncrementCount 方法以使用 ProtectedSessionStore.SetAsync：

    private async Task IncrementCount()
    {
        currentCount++;
        await ProtectedSessionStore.SetAsync("count", currentCount);
    }

在更大、更真实的应用中，存储单个字段是不太可能出现的情况。 应用更有可能存储包含复杂状态的整个模型对象。 ProtectedSessionStore 自动串行化和反序列化 JSON 数据。

在前面的代码示例中，currentCount 数据存储为用户浏览器中的 sessionStorage['count']。 数据不会以纯文本形式存储，而是使用 ASP.NET Core 的数据保护进行保护。 如果在浏览器的开发人员控制台中评估了 sessionStorage['count']，则可以查看加密的数据。

若要在用户稍后返回到 Counter 组件时（包括他们位于全新线路上时）恢复 currentCount 数据，请使用 ProtectedSessionStore.GetAsync：

    protected override async Task OnInitializedAsync()
    {
        currentCount = await ProtectedSessionStore.GetAsync<int>("count");
    }

如果组件的参数包括导航状态，请调用 ProtectedSessionStore.GetAsync 并将结果分配给 OnParametersSetAsync，而不是 OnInitializedAsync。 OnInitializedAsync 仅在首次实例化组件时调用一次。 如果用户导航到不同的 URL，而仍然停留在相同的页面上，则 OnInitializedAsync 之后不会再次调用。 有关详细信息，请参阅 ASP.NET Core Blazor 生命周期。

 警告

本节中的示例仅在服务器未启用预呈现的情况下有效。 启用预呈现后，将生成如下错误：
此时无法发出 JavaScript 互操作调用。 这是因为该组件已预呈现。
禁用预呈现或添加其他代码以处理预呈现。 若要了解有关编写可处理预呈现的代码的详细信息，请参阅处理预呈现一节。



## Dependence Injection 依赖注入服务
- [依赖注入 - 控制器](https://docs.microsoft.com/zh-cn/aspnet/core/mvc/controllers/dependency-injection?view=aspnetcore-3.1)
- [依赖注入 - 视图](https://docs.microsoft.com/zh-cn/aspnet/core/mvc/views/dependency-injection?view=aspnetcore-3.1)

如果使用的是 Blazor Server 应用，服务可以在 Startup.ConfigureServices 中注册为单一实例。 可通过依赖关系注入 (DI) 在整个应用中使用服务的实例：

    public void ConfigureServices(IServiceCollection services)
    {
        services.AddRazorPages();
        services.AddServerSideBlazor();
        services.AddSingleton<WeatherForecastService>();
    }

服务类型 WeatherForecastService 以及数据模型类 WeatherForecast 定义如下，服务类定义 GetForecastAsync 方法来生成随机天气预测数据：

    using System;
    using System.Linq;
    using System.Threading.Tasks;

    namespace blazorServerWebApp.Data
    {
        public class WeatherForecast
        {
            public DateTime Date { get; set; }
            public int TemperatureC { get; set; }
            public int TemperatureF => 32 + (int)(TemperatureC / 0.5556);
            public string Summary { get; set; }
        }

        public class WeatherForecastService
        {
            private static readonly string[] Summaries = new[]
            {
                "Freezing", "Bracing", "Chilly", "Cool", "Mild", "Warm", "Balmy", "Hot", "Sweltering", "Scorching"
            };

            public Task<WeatherForecast[]> GetForecastAsync(DateTime startDate)
            {
                var rng = new Random();
                return Task.FromResult(Enumerable.Range(1, 5).Select(index => new WeatherForecast
                {
                    Date = startDate.AddDays(index),
                    TemperatureC = rng.Next(-20, 55),
                    Summary = Summaries[rng.Next(Summaries.Length)]
                }).ToArray());
            }
        }
    }

使用 @inject 指令将服务的实例注入到组件中，然后组件就可以使用已经注入的服务。这里的服务实例 ForecastService 用来检索 WeatherForecast 对象的数组：

    @using blazorServerWebApp.Data
    @inject WeatherForecastService ForecastService

    ...

    @if (forecasts == null)
    {
        <p><em>Loading...</em></p>
    }
    else
    {
        <table class="table">
            <thead>
                <tr>
                    <th>Date</th>
                    <th>Temp. (C)</th>
                    <th>Temp. (F)</th>
                    <th>Summary</th>
                </tr>
            </thead>
            <tbody>
                @foreach (var forecast in forecasts)
                {
                    <tr>
                        <td>@forecast.Date.ToShortDateString()</td>
                        <td>@forecast.TemperatureC</td>
                        <td>@forecast.TemperatureF</td>
                        <td>@forecast.Summary</td>
                    </tr>
                }
            </tbody>
        </table>
    }

    @code {
        private WeatherForecast[] forecasts;

        protected override async Task OnInitializedAsync()
        {
            forecasts = await ForecastService.GetForecastAsync(DateTime.Now);
        }
    }

服务传送的数据将通过 SignalR 即 WebSocket 传输，这是 Blazor Server 与 Blazor WebAssembly 两种应用的最大区别。


如果使用的是 Blazor WebAssembly 应用，则注入 HttpClient 实例，通过它提供的 GetFromJsonAsync 方法以 GET 方式获取服务端的 weather.json 文件，并将 JSON 对象转换为 WeatherForecast 对象以提供天气预测数据，然后使用 @foreach 循环将数据渲染到视图上：

    @inject HttpClient Http

    ...

    @code {
        private WeatherForecast[] forecasts;

        protected override async Task OnInitializedAsync()
        {
            forecasts = await Http.GetFromJsonAsync<WeatherForecast[]>("sample-data/weather.json");
        }

        public class WeatherForecast
        {
            public DateTime Date { get; set; }
            public int TemperatureC { get; set; }
            public string Summary { get; set; }
            public int TemperatureF => 32 + (int)(TemperatureC / 0.5556);
        }
    }

在真实的生产环境中，需要提供可以生成以下 JSON 格式的 Web API：

    [
      { "date": "2018-05-06", "temperatureC": 1, "summary": "Freezing" },
      { "date": "2018-05-07", "temperatureC": 14, "summary": "Bracing" },
      { "date": "2018-05-08", "temperatureC": -13, "summary": "Freezing" },
      { "date": "2018-05-09", "temperatureC": -16, "summary": "Balmy" },
      { "date": "2018-05-10", "temperatureC": -2, "summary": "Chilly" }
    ]



## MySQL 数据库中间层
- https://docs.automapper.org/en/stable/index.html
- https://dev.mysql.com/doc/dev/connector-net/8.0/html/connector-net-reference.htm
- https://docs.microsoft.com/zh-cn/ef/

数据库的读写，常用中间层封装以方便整个项目的数据读写逻辑的实现。

ASP.NET Core 内置 Entity Framework Core 来处理数据库。 EF Core 是对象关系映射 (ORM) 框架，可以简化需要编写的数据访问代码。

在远古的 Windows 编程中，数据访问是 DAO - Data Access Object 模式，这是相当于直接使用数据库 API 来读写数据，这完全跟不上现代的编程模式。一个解决数据库中间层的流行方法就是，使用 MO - Model Object 和 DTO - Data Transfer Object，通过映射将关系数据表的记录转换成程序中的对象。MO 用来表示从数据库中读取的数据，而 DTO 用来表示在网络上所传输的数据。

如果要使用依赖注入使用数据服务，默认的 Web 应用使用 Microsoft.Extensions.DependencyInjection 做依赖注入，Startup 中使用到的 IServiceCollection 就是依赖注入容器接口，通过它来注入各种模块。

AutoMapper 可以作为对象映射器，将一种类型的对象转换为另一种类型的对象，继承自 DependencyInjection。它提供了映射规则及操作方法，使我们不用过多配置就可以映射两个类, 可以帮我们免于编写无聊的映射代码，在代码层与层之间隔离模型上非常有用。

Entity Framework Core 是适用于 .NET 的新式对象数据库映射器。 它支持 LINQ 查询、更改跟踪、更新和架构迁移。 EF Core 适用于很多数据库，包括 SQL 数据库（本地和 Azure）、SQLite、MySQL、PostgreSQL 和 Azure Cosmos DB。

这里使用 MySql.Data 访问 MySql 数据库，首先向项目添加 NuGet 包引用，完成后 csproj 项目文件就会包含 MySql.Data 包的引用，以下命令，按需使用：

    dotnet add package MySql.Data --version 8.0.20

    dotnet add package Microsoft.Extensions.DependencyInjection --version 3.1.4
    dotnet add package AutoMapper.Extensions.Microsoft.DependencyInjection --version 7.0.0

然后修改你的 appsettings.json 文件，添加一个联接字符串 ConnectionStrings 设置：

    "ConnectionStrings": {
        "DefaultConnection": "server=127.0.0.1;userid=root;password=123456;database=dbname;"
    },

相应修改 Startup 中的 ConfigureServices 以使用连接字符串，并将后面要实现的数据上下文对象注入作为数据服务：

    string cons = Configuration.GetConnectionString("DefaultConnection");
    services.Add(new ServiceDescriptor(typeof(UserContext), new UserContext(cons)));

在类文件中引用相应类空间，开始编写代码，先创建一个上下文服务类 UserContext 以检索或写入数据，这里只做查询示例。这里作为内嵌类 UserDTO 根据数据表定义了相应的成员，其中 ID 作为附加成员保存一个 System.Guid 标志：

    using System;
    using System.Collections.Generic;
    using System.Text;
    using MySql.Data.MySqlClient;

    namespace myWebApp
    {

        public class UserDTO
        {
            public Guid ID { get; set; }
            public int id { get; set; }
            public string name { get; set; } = "";
            public string nickname { get; set; }
            public string email { get; set; }
            public int level { get; set; }
            public DateTime created_at { get; set; }
        }

        public class UserContext
        {
            public string ConnectionString { get; set; }
            public UserContext(string connectionString)
            {
                this.ConnectionString = connectionString;
            }

            private MySqlConnection GetConnection()
            {
                return new MySqlConnection(ConnectionString);
            }

            public List<UserDTO> GetAllUsers()
            {
                List<UserDTO> list = new List<UserDTO>();
                using (MySqlConnection msconnection = GetConnection())
                {
                    try {
                        msconnection.Open();
                    }catch{
                        Console.WriteLine("Error to connect database...");
                        return list;
                    }
                    MySqlCommand mscommand = new MySqlCommand("select id,name,nickname,email,level,created_at from users", msconnection);
                    using (MySqlDataReader reader = mscommand.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            list.Add(new UserDTO()
                            {
                                ID = Guid.NewGuid(),
                                id = reader.IsDBNull(reader.GetOrdinal("id"))? -1: reader.GetInt32("id"),
                                name = reader.IsDBNull(reader.GetOrdinal("name"))? null: reader.GetString("name"),
                                nickname = reader.IsDBNull(reader.GetOrdinal("nickname"))? null: reader.GetString("nickname"),
                                email = reader.IsDBNull(reader.GetOrdinal("email"))? null: reader.GetString("email"),
                                level = reader.IsDBNull(reader.GetOrdinal("level"))? -1: reader.GetInt32("level"),
                                created_at = reader.IsDBNull(reader.GetOrdinal("created_at"))? new DateTime(): reader.GetDateTime("created_at")
                            });
                        }
                    }
                }
                return list;
            }
        }

    }


修改视图类 Index.cshtml.cs 通过 HttpContext 获取前面注入的数据服务模块，并通过 data 导出数据供视图模板使用：

    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Threading.Tasks;
    using Microsoft.AspNetCore.Mvc;
    using Microsoft.AspNetCore.Mvc.RazorPages;
    using Microsoft.Extensions.Logging;
    using myWebApp;

    namespace myWebApp.Pages
    {
        public class IndexModel : PageModel
        {
            private readonly ILogger<IndexModel> _logger;

            [BindProperty]
            public List<UserDTO> data { get; set; }

            public IndexModel(ILogger<IndexModel> logger)
            {
                _logger = logger;
            }

            public void OnGet()
            {
                UserContext uc = HttpContext.RequestServices.GetService(typeof(UserContext)) as UserContext;
                data = uc.GetAllUsers();
                Console.WriteLine($"OnGet {data.Count} {data[0]}...");
            }
        }
    }


修改视图模板 Index.cshtml 以渲染数据，默认的 Web 应用使用了 Bootstrap 前端框架，可以设置表格的美化样式：

    @page
    @model IndexModel
    @{
        ViewData["Title"] = "Home page";
    }

    <div class="text-center">
        <h1 class="display-4">Welcome</h1>
        <p>Learn about <a href="https://docs.microsoft.com/aspnet/core">building Web apps with ASP.NET Core</a>.</p>
        <div class="jumbotron">

    <table class="table table-striped table-hover table-condensed">
        <tbody>
        @foreach (var item in Model.data) {
            <tr>
                <td>
                    @Html.DisplayFor(modelItem => item.name)
                </td>
                <td>
                    @Html.DisplayFor(modelItem => item.nickname)
                </td>
                <td>
                    @Html.DisplayFor(modelItem => item.email)
                </td>
                <td>
                    @Html.DisplayFor(modelItem => item.level)
                </td>
                <td>
                    @Html.DisplayFor(modelItem => item.created_at)
                </td>
                <td>
                    <a asp-page="./Edit" asp-route-id="@item.ID" asp-route-n="@item.name">Edit</a> |
                    <a asp-page="./Details" asp-route-id="@item.ID" asp-route-n="@item.name">Details</a> |
                    <a asp-page="./Delete" asp-route-id="@item.ID" asp-route-n="@item.name">Delete</a>
                </td>
            </tr>
        }
        </tbody>
    </table>

        </div>
    </div>


其它功能页面 Razor Page 骨架可以通过命令添加：

    dotnet new page -o=Pages -na="Razor.Pages" -n="Edit"
    dotnet new page -o=Pages -na="Razor.Pages" -n="Details"
    dotnet new page -o=Pages -na="Razor.Pages" -n="Delete"



# Features 语言特性

## C# 版本特性进化

- C# 8.0 增强功能

    https://docs.microsoft.com/zh-cn/dotnet/csharp/whats-new/csharp-8

    - Readonly 成员
    - 默认接口方法
    - 模式匹配增强功能：
        - Switch 表达式
        - 属性模式
        - 元组模式
        - 位置模式
    - Using 声明
    - 静态本地函数
    - 可处置的 ref 结构
    - 可为空引用类型
    - 异步流
    - 异步可释放
    - 索引和范围
    - Null 合并赋值
    - 非托管构造类型
    - 嵌套表达式中的 Stackalloc
    - 内插逐字字符串的增强功能

     .NET Core 3.x 和 .NET Standard 2.1 支持 C# 8.0 。

    新增的匹配模式 Pattern matching 是为了简化嵌套 if-else 结构的：

        static decimal GetTicket_Pattern(string sex, int age, string area)
        {
            return (sex, age, area) switch
            {
                ("男", < 20, "安徽") => 2000,
                ("男", < 40, "上海") => 4000,
                ("男", _, _) => 3000,
                ("女", < 20, "安徽") => 2500,
                ("女", < 60, "安徽") => 1500,
                _ => 0
            };
        }
    
    比如要查看上海小于 20 岁男性的数据，上面的 switch 会自动执行匹配模式查找数据。它相应生成的也是 if-else 语句，只不过匹配模式角化了写法。

- C# 7.0 新功能

    https://docs.microsoft.com/zh-cn/dotnet/csharp/whats-new/csharp-7

    - out 变量 可以内联作为参数声明到使用这些参数的方法中。
    - 元组 可以创建包含多个公共字段的轻量级未命名类型。 编译器和 IDE 工具可理解这些类型的语义。
    - 弃元 指在不关心所赋予的值时，赋值中使用的临时只写变量。 在对元组和用户定义类型进行解构，以及在使用 out 参数调用方法时，它们的作用最大。
    - 模式匹配 可以基于任意类型和这些类型的成员的值创建分支逻辑。
    - ref 局部变量和返回结果 方法局部参数和返回值可以是对其他存储的引用。
    - 本地函数 可以将函数嵌套在其他函数内，以限制其范围和可见性。
    - 更多的 expression-bodied 成员 可使用表达式创作的成员列表有所增长。
    - throw 表达式 可以在之前因为 throw 是语句而不被允许的代码构造中引发异常。
    - 通用的异步返回类型 使用 async 修饰符声明的方法可以返回除 Task 和 Task<T> 以外的其他类型。
    - 数字文本语法改进 新令牌可提高数值常量的可读性。

- C# 6.0 版本包含许多可提高开发人员工作效率的功能

    https://docs.microsoft.com/zh-cn/dotnet/csharp/whats-new/csharp-6

    C# 6.0 版本包含许多可提高开发人员工作效率的功能。 这些功能的总体效果是让你编写的代码更简洁、更具可读性。 该语法不像许多常见做法那样繁琐。 可以更轻松地看出设计意图。 好好了解这些功能可以帮助你提高生产力，编写更具可读性的代码。 你可以更专注于功能，而不是语言的构造。

    - Compiler-as-a-service (Roslyn)
    - Import of static type members into namespace 支持仅导入类中的静态成员
    - Exception filters 异常过滤器
    - Await in catch/finally blocks 支持在catch/finally语句块使用await语句
    - Auto property initializers 自动属性初始化
    - Default values for getter-only properties 设置只读属性的默认值
    - Expression-bodied members 支持以表达式为主体的成员方法和只读属性
    - Null propagator (null-conditional operator, succinct null checking) Null条件操作符
    - String interpolation 字符串插值，产生特定格式字符串的新方法
    - nameof operator nameof操作符，返回方法、属性、变量的名称
    - 只读自动属性
    - 自动属性初始化表达式
    - Expression-bodied 函数成员
    - using static
    - Null 条件运算符
    - 字符串内插
    - 异常筛选器
    - nameof 表达式
    - Catch 和 Finally 块中的 Await
    - 使用索引器初始化关联集合
    - 集合初始值设定项中的扩展 Add 方法
    - 改进了重载解析
    - Dictionary initializer 字典初始化


- C# 3.0 特性 (VS 2008)

    - Implicitly typed local variables  本地 var 类型推理
    - Object and collection initializers    对象和集合初始化器
    - Auto-Implemented properties   自动属性，自动生成属性方法，声明更简洁
    - Anonymous types   匿名类型
    - Extension methods 扩展方法
    - Query expressions 查询表达式，语言集成查询 (LINQ)
    - Lambda expression Lambda表达式
    - Expression trees  表达式树，以树形数据结构表示代码，是一种新数据类型
    - Partial methods   部分方法


- C# 2 特性 (VS 2005)

    - Generics  泛型
    - Partial types 分部类型，可以将类、结构、接口等类型定义拆分到多个文件中
    - Anonymous methods 匿名方法
    - iterators 迭代器
    - Nullable types    可以为Null的类型，该类可以是其它值或者null
    - Getter/Setter separate accessibility  属性访问控制
    - Method group conversions (delegates)  方法组转换，可以将声明委托代表一组方法，隐式调用
    - Covariance and contravariance for delegates and interfaces    委托、接口的协变和逆变
    - Static classes    静态类
    - Delegate inference    委托推断，允许将方法名直接赋给委托变量


- C# 1.0 特性

    Visual Studio .NET 2002 一起发布的 C# 1.0 非常像 Java。 在 ECMA 制定的设计目标中，它旨在成为一种“简单、现代、面向对象的常规用途语言”。 当时，它和 Java 类似，说明已经实现了上述早期设计目标。

    - Classes   面向对象特性，支持类类型
    - Structs   结构
    - Interfaces    接口
    - Events    事件
    - Properties    属性，类的成员，提供访问字段的灵活方法
    - Delegates 委托,一种引用类型，表示对具有特定参数列表和返回类型的方法的引用
    - Expressions,Statements,Operators  表达式、语句、操作符
    - Attributes    特性，为程序代码添加元数据或声明性信息，运行时，通过反射可以访问特性信息
    - Literals  字面值（或理解为常量值），区别常量，常量是和变量相对的


其它历史版本可以在 GitHub 上的 dotnet/roslyn 存储库上找到详细的语言功能状态，包括考虑在即将发布的版本中添加的功能。

https://docs.microsoft.com/en-us/dotnet/csharp/whats-new/csharp-version-history
https://github.com/dotnet/roslyn/blob/master/docs/Language%20Feature%20Status.md


## try-catch 异常处理

最简单写法 

    try{
        Console.ReadKey();
    } catch {} // InvalidOperationException


try-catch，使用 when 条件判断，throw 再抛出

    object o2 = null;
    try
    {
        int i2 = (int)o2;   // Error
    }

    catch (ArgumentException e) when (e.ParamName == "…")
    {
    }

    catch (IOException e)
    {
        // Extract some information from this exception, and then
        // re-throw it to the parent method.
        if (e.Source != null)
            Console.WriteLine("IOException source: {0}", e.Source);
        throw;
    }

    catch (InvalidCastException e)
    {
        // Perform some action here, and then throw a new exception.
        throw new YourCustomException("Put your error message here.", e);
    }

try-finally

    public class ThrowTestA
    {
        static void Main()
        {
            int i = 123;
            string s = "Some string";
            object obj = s;

            try
            {
                // Invalid conversion; obj contains a string, not a numeric type.
                i = (int)obj;

                // The following statement is not run.
                Console.WriteLine("WriteLine at the end of the try block.");
            }
            finally
            {
                Console.WriteLine("\nExecution of the finally block after an unhandled\n" +
                    "error depends on how the exception unwind operation is triggered.");
                Console.WriteLine("i = {0}", i);
            }
        }
        // Output:
        // Unhandled Exception: System.InvalidCastException: Specified cast is not valid.
        //
        // Execution of the finally block after an unhandled
        // error depends on how the exception unwind operation is triggered.
        // i = 123
    }

try-catch-finally

    public class EHClass
    {
        void ReadFile(int index)
        {
            // To run this code, substitute a valid path from your local machine
            string path = @"c:\users\public\test.txt";
            System.IO.StreamReader file = new System.IO.StreamReader(path);
            char[] buffer = new char[10];
            try
            {
                file.ReadBlock(buffer, index, buffer.Length);
            }
            catch (System.IO.IOException e)
            {
                Console.WriteLine("Error reading from {0}. Message = {1}", path, e.Message);
            }

            finally
            {
                if (file != null)
                {
                    file.Close();
                }
            }
            // Do something with buffer...
        }
    }


try and Async：

    public async Task DoSomethingAsync()
    {
        Task<string> theTask = DelayAsync();

        try
        {
            string result = await theTask;
            Debug.WriteLine("Result: " + result);
        }
        catch (Exception ex)
        {
            Debug.WriteLine("Exception Message: " + ex.Message);
        }
        Debug.WriteLine("Task IsCanceled: " + theTask.IsCanceled);
        Debug.WriteLine("Task IsFaulted:  " + theTask.IsFaulted);
        if (theTask.Exception != null)
        {
            Debug.WriteLine("Task Exception Message: "
                + theTask.Exception.Message);
            Debug.WriteLine("Task Inner Exception Message: "
                + theTask.Exception.InnerException.Message);
        }
    }

    private async Task<string> DelayAsync()
    {
        await Task.Delay(100);

        // Uncomment each of the following lines to
        // demonstrate exception handling.

        //throw new OperationCanceledException("canceled");
        //throw new Exception("Something happened.");
        return "Done";
    }

    // Output when no exception is thrown in the awaited method:
    //   Result: Done
    //   Task IsCanceled: False
    //   Task IsFaulted:  False

    // Output when an Exception is thrown in the awaited method:
    //   Exception Message: Something happened.
    //   Task IsCanceled: False
    //   Task IsFaulted:  True
    //   Task Exception Message: One or more errors occurred.
    //   Task Inner Exception Message: Something happened.

    // Output when a OperationCanceledException or TaskCanceledException
    // is thrown in the awaited method:
    //   Exception Message: canceled
    //   Task IsCanceled: True
    //   Task IsFaulted:  False

Task.WhenAll example

    public async Task DoMultipleAsync()
    {
        Task theTask1 = ExcAsync(info: "First Task");
        Task theTask2 = ExcAsync(info: "Second Task");
        Task theTask3 = ExcAsync(info: "Third Task");

        Task allTasks = Task.WhenAll(theTask1, theTask2, theTask3);

        try
        {
            await allTasks;
        }
        catch (Exception ex)
        {
            Debug.WriteLine("Exception: " + ex.Message);
            Debug.WriteLine("Task IsFaulted: " + allTasks.IsFaulted);
            foreach (var inEx in allTasks.Exception.InnerExceptions)
            {
                Debug.WriteLine("Task Inner Exception: " + inEx.Message);
            }
        }
    }

    private async Task ExcAsync(string info)
    {
        await Task.Delay(100);

        throw new Exception("Error-" + info);
    }

    // Output:
    //   Exception: Error-First Task
    //   Task IsFaulted: True
    //   Task Inner Exception: Error-First Task
    //   Task Inner Exception: Error-Second Task
    //   Task Inner Exception: Error-Third Task


## var 隐式类型推导

从 Visual C# 3.0 开始，在方法范围内声明的变量可以具有隐式类型 var。 隐式类型本地变量为强类型，就像用户已经自行声明该类型，但编译器决定类型一样。 i 的以下两个声明在功能上是等效的：

    var i = 10; // Implicitly typed.
    int i = 10; // Explicitly typed.


## checked & unchecked

checked 关键字用于对整型类型算术运算和转换显式启用溢出检查。

默认情况下，如果表达式仅包含常量值，且产生的值在目标类型范围之外，则会导致编译器错误。 

如果表达式包含一个或多个变量量值，则编译器检测不到溢出。 在下面的示例中，计算赋给 i2 的表达式不会导致编译器错误。

    // The following example causes compiler error CS0220 
    // because 2147483647 is the maximum value for integers.
    //int i1 = 2147483647 + 10;

    int ten = 10;
    int i2 = 2147483647 + ten;

    Console.WriteLine(i2);
    // 2,147,483,647 + 10 = -2,147,483,639


可以通过编译器选项、环境配置或使用 checked 关键字来启用溢出检查。 下面的示例演示如何使用 checked 表达式或 checked 块，在运行时检测由前面的求和计算导致的溢出。 

    // If the previous sum is attempted in a checked environment, an
    // OverflowException error is raised.

    // Checked expression.
    Console.WriteLine(checked(2147483647 + ten));

    // Checked block.
    checked
    {
        int i3 = 2147483647 + ten;
        Console.WriteLine(i3);
    }

可以使用 unchecked 关键字阻止溢出检查。

示例演示如何使用 checked 启用运行时溢出检查。


    class OverFlowTest
    {
        // Set maxIntValue to the maximum value for integers.
        static int maxIntValue = 2147483647;

        // Using a checked expression.
        static int CheckedMethod()
        {
            int z = 0;
            try
            {
                // The following line raises an exception because it is checked.
                z = checked(maxIntValue + 10);
            }
            catch (System.OverflowException e)
            {
                // The following line displays information about the error.
                Console.WriteLine("CHECKED and CAUGHT:  " + e.ToString());
            }
            // The value of z is still 0.
            return z;
        }

        // Using an unchecked expression.
        static int UncheckedMethod()
        {
            int z = 0;
            try
            {
                // The following calculation is unchecked and will not
                // raise an exception.
                z = maxIntValue + 10;
            }
            catch (System.OverflowException e)
            {
                // The following line will not be executed.
                Console.WriteLine("UNCHECKED and CAUGHT:  " + e.ToString());
            }
            // Because of the undetected overflow, the sum of 2147483647 + 10 is
            // returned as -2147483639.
            return z;
        }

        static void Main()
        {
            Console.WriteLine("\nCHECKED output value is: {0}",
                              CheckedMethod());
            Console.WriteLine("UNCHECKED output value is: {0}",
                              UncheckedMethod());
        }
    }


## String Format & Interpolation 字符串格式与插值
- https://docs.microsoft.com/zh-cn/dotnet/csharp/tutorials/exploration/interpolated-strings-local
- https://docs.microsoft.com/en-us/dotnet/api/system.string?view=netcore-3.1#methods

C# Special Characters

    @, the verbatim identifier character.
    $, the interpolated string character.

C# 6.0 支持字符串插值

    using System;
    using System.Collections.Generic;

    public class Example
    {
        public static void Main()
        {

            var name = "h";
            Console.WriteLine("Hello " + name +"!");
            Console.WriteLine($"Hello {name}!");
            Console.WriteLine($"Hello {name.ToUpper()}!");

            var titles = new Dictionary<string, string>()
            {
                ["Doyle, Arthur Conan"] = "Hound of the Baskervilles, The",
                ["London, Jack"] = "Call of the Wild, The",
                ["Shakespeare, William"] = "Tempest, The"
            };

            Console.WriteLine("Author and Title List");
            Console.WriteLine();
            Console.WriteLine($"|{"Author",-25}|{"Title",30}|");
            foreach (var title in titles)
                Console.WriteLine($"|{title.Key,-25}|{title.Value,30}|");
        }
    }

创建者姓名采用左对齐方式，其所写标题采用右对齐方式。 通过在内插表达式后面添加一个逗号（“,”）并指定“最小” 字段宽度来指定对齐方式。 如果指定的值是正数，则该字段为右对齐。 如果它为负数，则该字段为左对齐。

    using System;

    public class TipCalculator
    {
        private const double tipRate = 0.18;
        public static void Main(string[] args)
        {
            double billTotal;
            if (args.Length == 0 || ! Double.TryParse(args[0], out billTotal))
            {
                Console.WriteLine("usage: TIPCALC total");
                return;
            }
            double tip = billTotal * tipRate;
            Console.WriteLine();
            Console.WriteLine($"Bill total:\t{billTotal,8:c}");
            Console.WriteLine($"Tip total/rate:\t{tip,8:c} ({tipRate:p1})");
            Console.WriteLine(("").PadRight(24, '-'));
            Console.WriteLine($"Grand total:\t{billTotal + tip,8:c}");
        }
    }

    /*
    >tipcalc 52.23

    Bill total:       $52.23
    Tip total/rate:    $9.40 (18.0 %)
    ------------------------
    Grand total:      $61.63
    */

格式设置有两个三个部分，数据来源，宽度和左右对齐，数据类型和小数点位数，格式任何一个部分都是可选的。以 `"{0,-16:C4}"` 为例，第一个 0 表数据来源自紧跟格式字符串后的变量，再后面一个变量参数就是 `{1}` 等等。然后，是逗号后面指定的宽度 16 个字符和负号指定左对齐，默认不使用负号右对齐，只要宽度足够。最后是冒号后面指定的数据类型 C - Currency 货币，E - Scientific 科学计数法。数据类型后面的数字指定小数点后的位数，默认为 2 位小数。对于不同的数据来源，比如 D 表示十进制数值格式，或者表示日期的长格式。

    decimal price = 169.32m;
    string[] format = new string[]{
        "{0,16}", "{0,16}", "{0:C4}", "{0:C2}", 
        "{0,16:C4}", "{0,16:C2}", "{0,-16:C4}", "{0,-16:C2}",
        "{0,16:E4}", "{0,16:E2}", "{0,-16:E4}", "{0,-16:E2}"
        };
    Console.WriteLine(string.Join("\n", format), price);
    
    string guidString = "ba748d5c-ae5f-4cca-84e5-1ac5291c38cb";
    string[] gf = new string[]{"D", "d", "N", "n", "P", "p", "B", "b", "X", "x"};
    gf.Count(f => {
            try{
                Console.WriteLine("GUID[{0}]: {1}", f, Guid.ParseExact(guidString, f)); // D & d
            } catch{}
            return true;
        });

输出效果：

              169.32
              169.32
    ￥169.3200
    ￥169.32
           ￥169.3200
             ￥169.32
    ￥169.3200       
    ￥169.32         
         1.6932E+002
           1.69E+002
    1.6932E+002     
    1.69E+002       
    GUID[D]: ba748d5c-ae5f-4cca-84e5-1ac5291c38cb
    GUID[d]: ba748d5c-ae5f-4cca-84e5-1ac5291c38cb



若要逐字解释转义序列，可使用逐字字符串文本。 内插逐字字符串以 $ 字符开头，后跟 @ 字符。 从 C# 8.0 开始，可以按任意顺序使用 $ 和 @ 标记：$@"..." 和 @$"..." 均为有效的内插逐字字符串。

    var xs = new int[] { 1, 2, 7, 9 };
    var ys = new int[] { 7, 9, 12 };
    Console.WriteLine($"Find the intersection of the {{{string.Join(", ",xs)}}} and {{{string.Join(", ",ys)}}} sets.");

    var userName = "Jane";
    var stringWithEscapes = $"C:\\Users\\{userName}\\Documents";
    var verbatimInterpolated = $@"C:\Users\{userName}\Documents";
    Console.WriteLine(stringWithEscapes);
    Console.WriteLine(verbatimInterpolated);

    // Expected output:
    // Find the intersection of the {1, 2, 7, 9} and {7, 9, 12} sets.
    // C:\Users\Jane\Documents
    // C:\Users\Jane\Documents

因为冒号 (:) 在具有内插表达式的项中具有特殊含义，在内插表达式中使用三元条件运算符 ?: 请将表达式放在括号内，如下例所示：

    var rand = new Random();
    for (int i = 0; i < 7; i++)
    {
        Console.WriteLine($"Coin flip: {(rand.NextDouble() < 0.5 ? "heads" : "tails")}");
    }

格式化字符和 Console.WriteLine(format, args....) 方法使用的相同：

    using System;
    class Sample
    {
        enum Color {Yellow = 1, Blue, Green};
        static DateTime thisDate = DateTime.Now;

        public static void Main()
        {
            Console.Clear();

            // Format a negative integer or floating-point number in various ways.
            Console.WriteLine("Standard Numeric Format Specifiers");
            Console.WriteLine(
                "(C) Currency: . . . . . . . . {0:C}\n" +
                "(D) Decimal:. . . . . . . . . {0:D}\n" +
                "(E) Scientific: . . . . . . . {1:E}\n" +
                "(F) Fixed point:. . . . . . . {1:F}\n" +
                "(G) General:. . . . . . . . . {0:G}\n" +
                "    (default):. . . . . . . . {0} (default = 'G')\n" +
                "(N) Number: . . . . . . . . . {0:N}\n" +
                "(P) Percent:. . . . . . . . . {1:P}\n" +
                "(R) Round-trip: . . . . . . . {1:R}\n" +
                "(X) Hexadecimal:. . . . . . . {0:X}\n",
                -123, -123.45f);

            // Format the current date in various ways.
            Console.WriteLine("Standard DateTime Format Specifiers");
            Console.WriteLine(
                "(d) Short date: . . . . . . . {0:d}\n" +
                "(D) Long date:. . . . . . . . {0:D}\n" +
                "(t) Short time: . . . . . . . {0:t}\n" +
                "(T) Long time:. . . . . . . . {0:T}\n" +
                "(f) Full date/short time: . . {0:f}\n" +
                "(F) Full date/long time:. . . {0:F}\n" +
                "(g) General date/short time:. {0:g}\n" +
                "(G) General date/long time: . {0:G}\n" +
                "    (default):. . . . . . . . {0} (default = 'G')\n" +
                "(M) Month:. . . . . . . . . . {0:M}\n" +
                "(R) RFC1123:. . . . . . . . . {0:R}\n" +
                "(s) Sortable: . . . . . . . . {0:s}\n" +
                "(u) Universal sortable: . . . {0:u} (invariant)\n" +
                "(U) Universal full date/time: {0:U}\n" +
                "(Y) Year: . . . . . . . . . . {0:Y}\n",
                thisDate);

            // Format a Color enumeration value in various ways.
            Console.WriteLine("Standard Enumeration Format Specifiers");
            Console.WriteLine(
                "(G) General:. . . . . . . . . {0:G}\n" +
                "    (default):. . . . . . . . {0} (default = 'G')\n" +
                "(F) Flags:. . . . . . . . . . {0:F} (flags or integer)\n" +
                "(D) Decimal number: . . . . . {0:D}\n" +
                "(X) Hexadecimal:. . . . . . . {0:X}\n",
                Color.Green);
        }
    }

This code example produces the following results:

    Standard Numeric Format Specifiers
    (C) Currency: . . . . . . . . ($123.00)
    (D) Decimal:. . . . . . . . . -123
    (E) Scientific: . . . . . . . -1.234500E+002
    (F) Fixed point:. . . . . . . -123.45
    (G) General:. . . . . . . . . -123
        (default):. . . . . . . . -123 (default = 'G')
    (N) Number: . . . . . . . . . -123.00
    (P) Percent:. . . . . . . . . -12,345.00 %
    (R) Round-trip: . . . . . . . -123.45
    (X) Hexadecimal:. . . . . . . FFFFFF85

    Standard DateTime Format Specifiers
    (d) Short date: . . . . . . . 6/26/2004
    (D) Long date:. . . . . . . . Saturday, June 26, 2004
    (t) Short time: . . . . . . . 8:11 PM
    (T) Long time:. . . . . . . . 8:11:04 PM
    (f) Full date/short time: . . Saturday, June 26, 2004 8:11 PM
    (F) Full date/long time:. . . Saturday, June 26, 2004 8:11:04 PM
    (g) General date/short time:. 6/26/2004 8:11 PM
    (G) General date/long time: . 6/26/2004 8:11:04 PM
        (default):. . . . . . . . 6/26/2004 8:11:04 PM (default = 'G')
    (M) Month:. . . . . . . . . . June 26
    (R) RFC1123:. . . . . . . . . Sat, 26 Jun 2004 20:11:04 GMT
    (s) Sortable: . . . . . . . . 2004-06-26T20:11:04
    (u) Universal sortable: . . . 2004-06-26 20:11:04Z (invariant)
    (U) Universal full date/time: Sunday, June 27, 2004 3:11:04 AM
    (Y) Year: . . . . . . . . . . June, 2004

    Standard Enumeration Format Specifiers
    (G) General:. . . . . . . . . Green
        (default):. . . . . . . . Green (default = 'G')
    (F) Flags:. . . . . . . . . . Green (flags or integer)
    (D) Decimal number: . . . . . 3
    (X) Hexadecimal:. . . . . . . 00000003

字符串类提供很多有用的处理函数，如 StartsWith/ EndsWith/ Equals/ IndexOf/ LastIndexOf 等。


## Numbers int/float/decimal
https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/builtin-types/value-types

int 类型表示整数，如果运算生成的值超过这些限值，则会出现下溢或溢出的情况。 答案似乎是从一个限值循环覆盖到另一个限值的范围。


    int max = int.MaxValue;
    int min = int.MinValue;
    Console.WriteLine($"The range of integers is {min} to {max}");

    int what = max + 3;
    Console.WriteLine($"An example of overflow: {what + 2}");

输出：

    The range of integers is -2147483648 to 2147483647
    An example of overflow: -2147483644

如果 int 类型无法满足需求，还会用到限值和精度不同的数字类型。

double 双精度浮点数，浮点数可用于表示数量级可能非常大或非常小的非整数。 双精度是一个相对术语，描述用于存储值的二进制数位数。 双精度数字的二进制数位数是单精度 float 的两倍。 在新式计算机上，使用双精度数字比使用单精度数字更为常见。 


打印出来的这些值用科学记数法表示。 E 左侧为有效数字。 右侧为是 10 的 n 次幂。与数学上的十进制数字一样，C# 中的双精度值可能会有四舍五入误差。 试运行以下代码：

    double max = double.MaxValue;
    double min = double.MinValue;
    Console.WriteLine($"The range of double is {min} to {max}");
    double third = 1.0 / 3.0;
    Console.WriteLine(third);

输出：

    The range of double is -1.7976931348623157E+308 to 1.7976931348623157E+308
    0.3333333333333333


decimal 类型的范围较小，但精度高于 double。

    decimal min = decimal.MinValue;
    decimal max = decimal.MaxValue;
    Console.WriteLine($"The range of the decimal type is {min} to {max}");

    double a = 1.0;
    double b = 3.0;
    Console.WriteLine(a / b);

    decimal c = 1.0M;
    decimal d = 3.0M;
    Console.WriteLine(c / d);

输出：

    The range of the decimal type is -79228162514264337593543950335 to 79228162514264337593543950335
    0.3333333333333333
    0.3333333333333333333333333333

- 数字中的 M 后缀指明了常数应如何使用 decimal 类型。
- 可以看到，使用十进制类型执行数学运算时，十进制小数点右侧的数字更多。
- 数字中的 M 后缀指明了常数应如何使用 decimal 类型。 否则，编译器假定为 double 类型。


提示：.NET 包含 PI 常数 Math.PI，可用于相应的值计算。 与 System.Math 类型中声明的所有常量一样，Math.PI 也是 double 值。

C# 支持以下预定义整型类型：

    System.SByte    sbyte      -128 ~ 127   8 位带符号整数
    System.Byte     byte          0 ~ 255   无符号的 8 位整数
    System.Int16    short   -32,768 ~ 32,767    有符号 16 位整数
    System.UInt16   ushort        0 ~ 65,535    无符号 16 位整数
    System.Int32    int     -2,147,483,648 ~ 2,147,483,647  带符号的 32 位整数
    System.UInt32   uint          0 ~ 4,294,967,295 无符号的 32 位整数
    System.Int64    long    -9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807  64 位带符号整数
    System.UInt64   ulong         0 ~ 18,446,744,073,709,551,615    无符号 64 位整数

C# 支持以下预定义浮点类型：

    System.Single   float   ±1.5 x 10−45 ~ ±3.4 x 1038  大约 6-9 位数字  4 个字节
    System.Double   double  ±5.0 × 10−324 ~ ±1.7 × 10308    大约 15-17 位数字    8 个字节
    System.Decimal  decimal ±1.0 x 10-28 ~ ±7.9228 x 1028   28-29 位 16 个字节

下表显示内置数值类型之间的预定义隐式转换：

    sbyte   -> short、int、long、float、double 或 decimal
    byte    -> short、ushort、int、uint、long、ulong、float、double 或 decimal
    short   -> int、long、float、double 或 decimal
    ushort  -> int、uint、long、ulong、float、double 或 decimal。
    int     -> long、float、double 或 decimal
    uint    -> long、ulong、float、double 或 decimal
    long    -> float、double 或 decimal
    ulong   -> float、double 或 decimal
    float   -> double


## char & string
https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/builtin-types/char
https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/strings/
https://docs.microsoft.com/zh-cn/dotnet/standard/base-types/regular-expressions


char 类型关键字是 .NET System.Char 结构类型的别名，它表示 Unicode UTF-16 字符。char 类型的默认值为 \0，即 U+0000。字符串类型将文本表示为 char 值的序列。

    char    U+0000 到 U+FFFF 16 位    System.Char

可以使用以下命令指定 char 值：

- 字符文本。
- Unicode 转义序列，它是 \u 后跟字符代码的十六进制表示形式（四个符号）。
- 十六进制转义序列，它是 \x 后跟字符代码的十六进制表示形式。

例如：

    var chars = new[]
    {
        'j',
        '\u006A',
        '\x006A',
        (char)106,
    };
    Console.WriteLine(string.Join(" ", chars));  // output: j j j j

字符串是值为文本的 String 类型对象。 文本在内部存储为 Char 对象的依序只读集合。 在 C# 字符串末尾没有 null 终止字符；因此，一个 C# 字符串可以包含任何数量的嵌入的 null 字符 ('\0')。 字符串的 Length 属性表示其包含的 Char 对象数量，而非 Unicode 字符数。 若要访问字符串中的各个 Unicode 码位，请使用 StringInfo 对象。

字符串对象是不可变的，它们在创建后无法更改。 看起来是在修改字符串的所有 String 方法和 C# 运算符实际上都是在新的字符串对象中返回结果。

当字符串文本包含反斜杠字符（例如在文件路径中）时，出于便捷性和更强的可读性的考虑，使用逐字字符串。 由于逐字字符串将新的行字符作为字符串文本的一部分保留，因此可将其用于初始化多行字符串。 使用双引号在逐字字符串内部嵌入引号。 下面的示例演示逐字字符串的一些常见用法：

    string filePath = @"C:\Users\scoleridge\Documents\";
    //Output: C:\Users\scoleridge\Documents\

    string text = @"My pensive SARA ! thy soft cheek reclined
        Thus on mine arm, most soothing sweet it is
        To sit beside our Cot,...";
    /* Output:
    My pensive SARA ! thy soft cheek reclined
       Thus on mine arm, most soothing sweet it is
       To sit beside our Cot,...
    */

    string quote = @"Her name was ""Sara.""";
    //Output: Her name was "Sara."

字符串转义序列

    转义序列    字符名称    Unicode 编码
    \'  单引号 0x0027
    \"  双引号 0x0022
    \\  反斜杠 0x005C
    \0  null    0x0000
    \a  警报  0x0007
    \b  Backspace   0x0008
    \f  换页  0x000C
    \n  换行  0x000A
    \r  回车  0x000D
    \t  水平制表符   0x0009
    \v  垂直制表符   0x000B
    \u  Unicode 转义序列 (UTF-16)   \uHHHH（范围：0000 - FFFF；示例：\u00E7 =“ç”）
    \U  Unicode 转义序列 (UTF-32)   \U00HHHHHH（范围：000000 - 10FFFF；示例：\U0001F47D =“👽”)
    \x  除长度可变外，Unicode 转义序列与“\u”类似  \xH[H][H][H]（范围：0 - FFFF；示例：\x00E7、\x0E7 或 \xE7 =“ç”）

String.Split 方法通过基于一个或多个分隔符，也可以可采用字符串数组来拆分输入字符串，任何分隔符的连续实例都会在输出数组中生成空字符串。

以下示例使用空格、逗号、句点、冒号和制表符，所有内容均在包含这些分隔字符的数组中传递到 Split。

    char[] delimiterChars = { ' ', ',', '.', ':', '\t' };

    string text = "one\ttwo three:four,five six seven";
    System.Console.WriteLine($"Original text: '{text}'");

    string[] words = text.Split(delimiterChars);
    System.Console.WriteLine($"{words.Length} words in text:");

    foreach (var word in words)
    {
        System.Console.WriteLine($"<{word}>");
    }

    string str = @"var ng = new Range( 1,6);
    Console.WriteLine(Range.EndAt(2));
    Console.WriteLine(ng.GetOffsetAndLength(3));
    Console.WriteLine(Range.StartAt(2));";
    Console.WriteLine(string.Join("\n", (str.Split(new string[]{"Console"}, StringSplitOptions.None))));
    
    StringSplitOptions.None
    StringSplitOptions.RemoveEmptyEntries

若要连接字符串变量，可使用 + 或 += 运算符、字符串内插或 String.Format、String.Concat、String.Join、StringBuilder.Append 方法。 + 运算符易于使用，有利于产生直观代码。 

另一个字符串连接方法为 String.Format。 此方法非常适用于从少量组件字符串生成字符串的情况。在其他情况下，可能需要将字符串合并在循环中，此时不知道要合并的源字符串的数量，而且源字符串的实际数量可能很大。 StringBuilder 类专门用于此类方案。 以下代码使用 StringBuilder 类的 Append 方法串联字符串。

还可使用 String.Concat 方法联接集合中的字符串。 如果源字符串应使用分隔符分隔，请使用 String.Join 方法。

    string[] words = { "The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog." };

    var unreadablePhrase = string.Concat(words);
    System.Console.WriteLine(unreadablePhrase);

    var readablePhrase = string.Join(" ", words);
    System.Console.WriteLine(readablePhrase);


利用 DateTime 提供的 Parse 和 TryParse 方法可转换日期和时间的多个常见表示方法。 ParseExact 和 TryParseExact 方法可转换符合日期和时间格式字符串指定的模式的字符串表示形式。 

    CultureInfo MyCultureInfo = new CultureInfo("de-DE");
    string MyString = "12 Juni 2008";
    DateTime MyDateTime = DateTime.Parse(MyString, MyCultureInfo);
    Console.WriteLine(MyDateTime);
    // The example displays the following output:
    //       6/12/2008 12:00:00 AM


    CultureInfo MyCultureInfo = new CultureInfo("en-US");
    string[] MyString = { " Friday, April 10, 2009", "Friday, April 10, 2009" };
    foreach (string dateString in MyString)
    {
        try
        {
            DateTime MyDateTime = DateTime.ParseExact(dateString, "D", MyCultureInfo);
            Console.WriteLine(MyDateTime);
        }
        catch (FormatException)
        {
            Console.WriteLine("Unable to parse '{0}'", dateString);
        }
    }
    // The example displays the following output:
    //       Unable to parse ' Friday, April 10, 2009'
    //       4/10/2009 12:00:00 AM


修改单个字符

    var source = "source";
    char[] chars = source.ToCharArray();
    chars[0] = 'S';

.NET Core 提供了一种 String.Create 方法，该方法使你可以通过回调以编程方式填充字符串的字符内容，同时避免中间的临时字符串分配。

    // constructing a string from a char array, prefix it with some additional characters
    char[] chars = { 'a', 'b', 'c', 'd', '\0' };
    int length = chars.Length + 2;
    string result = String.Create (length, chars, (Span<char> strContent, char[] charArray) =>
    {
        strContent[0] = '0';
        strContent[1] = '1';
        for (int i = 0; i < charArray.Length; i++)
        {
            strContent[i + 2] = charArray[i];
        }
    });

    Console.WriteLine(result);

.NET 提供字符串方法：

    "source".Replace("our", "we")   替换文本
    "source".Trim/TrimStart/TrimEnd()   去除空格
    "source".Remove(start, length)  删除文本

    "source".IndexOf/LastIndexOf("ur")  查找字符串位置

    String.Compare  比较两个字符串的值。 返回一个整数值。
    String.CompareOrdinal   比较两个字符串的值而不考虑本地区域性。 返回一个整数值。
    String.CompareTo    比较当前字符串对象和另一个字符串。 返回一个整数值。
    String.StartsWith   确定字符串是否以传递字的符串开头。 返回一个布尔值。
    String.EndsWith 确定字符串是否以传递的字符串结尾。 返回一个布尔值。
    String.Equals   确定两个字符串是否相同。 返回一个布尔值。
    String.IndexOf  返回字符或字符串的索引位置，从正在检查的字符串的开头开始。 返回一个整数值。
    String.LastIndexOf  返回字符或字符串的索引位置，从正在检查的字符串的结尾开始。 返回一个整数值。


使用正则表达式处理字符串

    using System;
    using System.Text.RegularExpressions;

    public class Example
    {
       public static void Main()
       {
          string pattern = "(Mr\\.? |Mrs\\.? |Miss |Ms\\.? )";
          string[] names = { "Mr. Henry Hunt", "Ms. Sara Samuels",
                             "Abraham Adams", "Ms. Nicole Norris" };
          foreach (string name in names)
             Console.WriteLine(Regex.Replace(name, pattern, String.Empty));
       }
    }
    // The example displays the following output:
    //    Henry Hunt
    //    Sara Samuels
    //    Abraham Adams
    //    Nicole Norris


    string[] sentences =
    {
        "Put the water over there.",
        "They're quite thirsty.",
        "Their water bottles broke."
    };

    string sPattern = "the(ir)?\\s";

    foreach (string s in sentences)
    {
        Console.Write($"{s,24}");

        if (System.Text.RegularExpressions.Regex.IsMatch(s, sPattern, System.Text.RegularExpressions.RegexOptions.IgnoreCase))
        {
            Console.WriteLine($"  (match for '{sPattern}' found)");
        }
        else
        {
            Console.WriteLine();
        }
    }


## Array 数组
https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/arrays/

在 C# 中，数组实际上是对象，而不只是如在 C 和 C++ 中的连续内存的可寻址区域。 Array 是所有数组类型的抽象基类型。 可以使用 Array 具有的属性和其他类成员。 例如，使用 Length 属性来获取数组的长度。

ArrayList 大小会根据需要动态增加的数组，由于 ArrayList 存在类型不安全、装箱拆箱损耗性能，不建议使用这个出于兼容目的保留的类型。使用 `List<T>` 强类型泛型实现的列表对象替代。

通过 new 运算符，可以使用数组初始值设定项（在分隔符 { 和 } 内编写的表达式列表）指定数组元素的初始值。 以下示例分配 int[]，并将其初始化为包含三个元素。也可以自动推断长度：

    int[] a = {1, 2, 3};

    int[] a = new int[] {1, 2, 3};


以下示例分别分配一维、二维、三维数组。

    int[] a1 = new int[10];
    int[,] a2 = new int[10, 5];
    int[,,] a3 = new int[10, 5, 2];
    Console.WriteLine(a2[0,1]);

每个元素都是 int[] 类型，并且初始值均为 null。 后面的代码行将这三个元素初始化为引用长度不同的各个数组实例。

    int[][] a = new int[3][];
    a[0] = new int[10];
    a[1] = new int[5];
    a[2] = new int[20];
    Console.WriteLine(messages[0]);

    int[][] b =
    {
        new int[] {1},
        new int[] {1,2},
        new int[] {1,2,5,10}
    };

形如 int[][] 这样的叫做交错数组 Jagged Array，而 int[,] 这种中括号带逗号的矩形数组 Rectangular Array，又称多维数组，元素长度统一，访问时需要指定完整的索引下标，配合 GetLength() 获取各维长度信息。

对于单维数组，foreach 语句以递增索引顺序处理元素（从索引 0 开始并以索引 Length - 1 结束）：

    int[] numbers = { 4, 5, 6, 1, 2, 3, -2, -1, 0 };
    foreach (int i in numbers)
    {
        System.Console.Write("{0} ", i);
    }
    // Output: 4 5 6 1 2 3 -2 -1 0

对于多维数组，遍历元素的方式为：首先增加最右边维度的索引，然后是它左边的一个维度，以此类推，向左遍历元素：

    int[,] numbers2D = new int[3, 2] { { 9, 99 }, { 3, 33 }, { 5, 55 } };
    // Or use the short form:
    // int[,] numbers2D = { { 9, 99 }, { 3, 33 }, { 5, 55 } };

    foreach (int i in numbers2D)
    {
        System.Console.Write("{0} ", i);
    }
    // Output: 9 99 3 33 5 55

使用嵌套的 for 循环可以更好地控制处理数组元素的顺序。

可以创建隐式类型化的数组，其中数组实例的类型通过数组初始值设定项中指定的元素来推断。 针对隐式类型化变量的任何规则也适用于隐式类型化数组。

    var a = new[] { 1, 10, 100, 1000 }; // int[]
    var b = new[] { "hello", null, "world" }; // string[]

    // single-dimension jagged array
    var c = new[]
    {
        new[]{1,2,3,4},
        new[]{5,6,7,8}
    };

    // jagged array of strings
    var d = new[]
    {
        new[]{"Luca", "Mads", "Luke", "Dinesh"},
        new[]{"Karen", "Suma", "Frances"}
    };


## Range

C# 语法上支持 Range 表达：

    int[] someArray = new int[5] { 1, 2, 3, 4, 5 };
    int[] subArray1 = someArray[0..2];               // { 1, 2 }
    int[] subArray2 = someArray[1..^0];              // { 2, 3, 4, 5 }

构造器可指定开始、结束值：

    Range(Index, Index) 

有三个属性，用来获取子集，返回 Range 对象，除了 End：

| All   | 获取 Range 所有值 |    
| End   | 获取指定结束位后的索引对象 |   
| Start | 获取指定起点到结束的值|

方法：

| EndAt(Index)  | 获取指定结束值的集合 |
| StartAt(Index)    | 获取指定开始值的集合 |
| Equals(Object)    | 与另一个对象里德比较是否相同 |
| Equals(Range) | 与另一个 Range 对象里德比较是否相同 |
| GetHashCode() | 获取当前实例的 Hash 值 |
| GetOffsetAndLength(Int32) | 返回 ValueTuple<Int32,Int32>， Calculates the start offset and length of the range object using a collection length. |
| ToString()    | 将 Range 转换成字符串表达 |

示例：

    using System;

    class Demo
    {
        static void Main(){
            var ng = new Range( 1,6);
            Console.WriteLine(Range.EndAt(2));
            Console.WriteLine(Range.StartAt(2));
            Console.WriteLine(ng.Equals(new int[]{1,2,3,4,5,6}));
            Console.WriteLine(ng.Equals(new int[]{1,2,3,4,5,6}));
            Console.WriteLine(ng.GetHashCode().ToString("X"));
            ValueTuple<int, int> vt = ng.GetOffsetAndLength(-30);
            Console.WriteLine(vt);
        }
    }

输出：

    0..2
    2..^0
    False
    False
    8439A85A
    (1, 5)



## Collections 集合
https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.generic?view=netcore-3.1

System.Collections.Generic 命名空间包含定义泛型集合的接口和类，用户可以使用泛型集合来创建强类型集合，这种集合能提供比非泛型强类型集合更好的类型安全性和性能。

    using System;
    using System.Collections.Generic;

    namespace csdemo
    {
        class Program
        {
            static void Main(string[] args)
            {
                var names = new List<string> { "Felipe", "Emillia" };
                foreach (var name in names)
                {
                    Console.WriteLine($"Hello {name.ToUpper()}!");
                }

                var messages = new Dictionary<int, string>
                {
                    // 早期版本的 C#
                    // {302, "Page moved, but left a forwarding address."},
                    // {404, "Page not Found"},
                    // {500, "The web server can't come out to play today."}

                    // C# 6.0 使用索引器初始化关联集合
                    [302] = "Page moved, but left a forwarding address.",
                    [404] = "Page not Found",
                    [500] = "The web server can't come out to play today."
                };
                Console.WriteLine(messages[404]);
            }
        }
    }

例，匿名对象字典：

    var o404 = new {code = 404};
    var o302 = new {code = 302};
    var o500 = new {code = 500};
    var messages = new Dictionary<object, string>
    {
        {o404, "Page not Found"},
        {o302, "Page moved, but left a forwarding address."},
        {o500, "The web server can't come out to play today."}
    };
    Console.WriteLine(messages[o404]);

ArrayList 大小会根据需要动态增加的数组，由于 ArrayList 保存 object 类型，值类型与 object 类型进行转换的过程就会产生拆箱装箱，存在类型不安全、装箱拆箱损耗性能，不建议使用这个出于兼容目的保留的类型。使用 `List<T>` 强类型泛型实现的列表对象替代。

有些人喜欢用ArrayList是因为对存储对象的类型没有要求，用起来方便，伴随而来的就是类型的不安全，这在静态语言中是不可取的。

数组的容量是固定的，您只能一次获取或设置一个元素的值，而 ArrayList 或 List 的容量可根据需要自动扩充、修改、删除或插入数据。

数组可以具有多个维度，而 ArrayList 或 List 始终只具有一个维度，但可以轻松创建数组列表或列表的列表。除 Object 外的特定类型的数组 的性能优于 ArrayList 的性能。 这是因为 ArrayList 的元素属于 Object 类型；所以在存储或检索值类型时通常发生装箱和取消装箱操作。不过，在不需要重新分配时，即在需要扩容量时，List 的性能与同类型的数组十分相近。

在决定使用 List 还是使用 ArrayList 类时，记住 List 类在大多数情况下执行得更好并且是类型安全的。如果对 List 类的类型 T 使用引用类型，则两个类的行为是完全相同的。但是，如果对类型 T 使用值类型，则需要考虑实现和装箱问题。


## Unmanaged 非托管类型

如果某个类型是以下类型之一，则它是非托管类型 ：

- sbyte、byte、short、ushort、int、uint、long、ulong、char、float、double、decimal 或 bool
- 任何枚举类型
- 任何指针类型
- 任何用户定义的 struct 类型，只包含非托管类型的字段，并且在 C# 7.3 及更早版本中，不是构造类型（包含至少一个类型参数的类型）



## Nullable
https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/builtin-types/nullable-reference-types

通过注解激活 nullable：

    #nullable disable
    #nullable enabled
    #nullable restore


可空类型允许包含 null 值，这对处理数据库中包含可选字段以及很多方面都有很大帮助。

    string? name;
    name!.Length; // null-forgiving operator !

C# 2.0 提供一个新操作符 ?? 用来合并空值。

    var result = a;
    if(a == null)
    {
        result = "XYZ";
    }

    // 等价代码
    result = a?? "XYZ";


C# 6.0 提供用于在执行成员访问 ?. 或索引 ?[] 操作之前，测试是否存在 NULL。 这些运算符可帮助编写更少的代码来处理 null 检查，尤其是对于下降到数据结构。

    int? count = customers?[0]?.Orders?.Count(); 
     // null if customers, the first customer, or Orders is null



## Tuples & ValueTuple 元组
- [Exploring Tuples as a Library Author](https://blog.marcgravell.com/2017/04/exploring-tuples-as-library-author.html)
- [Whats new in C# 7.0](https://blogs.msdn.microsoft.com/dotnet/2016/08/24/whats-new-in-csharp-7-0/)
- [C# tuple types](https://docs.microsoft.com/zh-cn/dotnet/csharp/tuples)

C# 4.0 引入元组 Tuple，在大部分支持 Tuple 的语言中，常常表示成员数目确定，每个成员类型也确定的结构。常常用于表示函数的多个返回值或者查询的结果等，或者避免为一些简单的结构或对象而去新建一个类。Tuple 应当是强类型的，即所有成员的类型在编译时确定。Tuple 可以看作不用事先声明的结构体，可以根据所使用的场合灵活地创建。

元组（Tuple）在 .Net 4.0 推出时有些缺点，还不够轻量级，如：

- Tuple 会影响代码的可读性，因为它的属性名都是：Item1，Item2.. 。
- Tuple 还不够轻量级，因为它是引用类型（Class）。

C# 7 中的元组 ValueTuple 解决了上述两个缺点，值元组也是一种数据结构，用于表示特定数量和元素序列，但是是和元组类不一样的，主要区别如下：

- ValueTuple 值元组的数据成员是字段不是属性，支持语义上的字段命名，即命名元组。
- ValueTuple 是值类型 Struct，而元组（Tuple）是类，引用类型；
- 值元组元素是可变的，不是只读的，也就是说可以改变值元组中的元素值；

根据 C# 版本选择创建的方式，需要引用 System.ValueTuple NuGet 包

元组主要目的用于在方法返回单个对象，借助元组，可以更轻松地对该单个对象中的多个值打包。

    var messages = (a: "xyz", b: new int[3]{1, 2, 3} );

    var left = (a: 5, b: 10);
    var right = (a: 5, b: 10);
    (int a, int b)? nullableTuple = right;
    Console.WriteLine(left == nullableTuple); // true

    (int a, string b) pair = (1, "Hello");
    (int z, string y) another = (1, "Hello");
    Console.WriteLine(pair == another); // true. Member names don't participate.
    Console.WriteLine(pair == (z: 1, y: "Hello")); // warning: literal contains different member names

    var ToString = "This is some text";
    var one = 1;
    var Item1 = 5;
    var projections = (ToString, one, Item1);
    // Accessing the first field:
    Console.WriteLine(projections.Item1);
    // There is no semantic name 'ToString'
    // Accessing the second field:
    Console.WriteLine(projections.one);
    Console.WriteLine(projections.Item2);
    // Accessing the third field:
    Console.WriteLine(projections.Item3);
    // There is no semantic name 'Item1`.

    var pt1 = (X: 3, Y: 0);
    var pt2 = (X: 3, Y: 4);

    var xCoords = (pt1.X, pt2.X);
    // There are no semantic names for the fields
    // of xCoords.

    // Accessing the first field:
    Console.WriteLine(xCoords.Item1);
    // Accessing the second field:
    Console.WriteLine(xCoords.Item2);

创建元组：

    var ValueTuple = (1, 2);                           // 使用语法糖创建元组 ValueTuple
    var ValueTuple2 = ValueTuple.Create(1, 2);         // 使用静态方法 Create 创建元组
    var tValueTuple3 = new ValueTuple<int, int>(1, 2);  // 使用 new 运算符创建元组
    var tuple1 = new Tuple<int,int>(1,2);
    (string Alpha, string Beta) namedLetters = ("a", "b"); // 命名元组
    var msg = new { a = "XYZ", b = new int[]{1, 2, 3}, c = new {s = "ABC"} }; // anonymous type
    var msg = new Tuple<String, int[], Tuple<String, int>>("XYZ", new int[]{1, 2, 3}, Tuple.Create("ABC", 123));


利用 Tuple 静态方法构建元组，最多支持八个元素，如果成员超过，可以将第 8 个成员当成一个元组，通过元祖的嵌套去完成。

定义元组时，每子项默认命名为 Item1、Item2、Item3 等，C# 7。0 引入 ValueTuple 支持自定义修改，也可以通过以下方法定制 Tuple：

- 通过扩展方法实现，只是此时不再是属性，变成了方法。可以定义多个扩展方法，也可以定义一个方法来按名称检索；
- 自定义类，封装 Tuple 提供固化属性读取字段；
- 自定义 dynamic 类，封装 Tuple 提供动态属性或固化属性读取字段；
- 派生 Tuple 类，提供固化属性读取字段；


取值：

    var unnamed = (1, 2);
    var named = (first: 1, second: 2);
    var tuple1 = new Tuple<int, int, int, int, int, int,  List<int>>(1, 1, 1, 1, 1,  1, new List<int>() { 2, 3 });
    var tuple2 = new Tuple<int, int, int, int, int, int, int, Tuple<int, int>>(1, 1, 1, 1, 1, 1, 1, new Tuple<int,int>(2,3));
    var u = unnamed.Item1;
    ar o = named.first;
    var k = tuple1.Item7[0]; 
    var l = tuple2.Rest.Item2; 

作为方法返回值

    private static Tuple<int,int>  testTuple()
    {
        int i = 0;
        int j = 1;
        return new Tuple<int, int>(i, j);
    }

C# 7.3 提供 == 和 != 以及相等的可空元组提升转换

    var left = (a: 5, b: 10);
    var right = (a: 5, b: 10);
    Console.WriteLine(left == right);  // displays 'true'
    var left = (a: 5, b: 10);
    var right = (a: 5, b: 10);
    (int a, int b)? nullableTuple = right;
    Console.WriteLine(left == nullableTuple);  // Also true



## Enum 枚举类型

枚举类型 是由基础整型数值类型的一组命名常量定义的值类型。 若要定义枚举类型，请使用 enum 关键字并指定枚举成员 的名称：

    enum Season
    {
        Spring,
        Summer,
        Autumn,
        Winter
    }

默认情况下，枚举成员的关联常数值为类型 int；它们从零开始，并按定义文本顺序递增 1。 可以显式指定任何其他整数数值类型作为枚举类型的基础类型。 还可以显式指定关联的常数值，如下面的示例所示：

    enum ErrorCode : ushort
    {
        None = 0,
        Unknown = 1,
        ConnectionLost = 100,
        OutlierReading = 200
    }

不能在枚举类型的定义内定义方法。 若要向枚举类型添加功能，请创建扩展方法。
枚举类型 E 的默认值是由表达式 (E)0 生成的值，即使零没有相应的枚举成员也是如此。
可以使用枚举类型，通过一组互斥值或选项组合来表示选项。 若要表示选项组合，请将枚举类型定义为位标志。

作为位标志的枚举类型

如果希望枚举类型表示选项组合，请为这些选项定义枚举成员，以便单个选项成为位字段。 也就是说，这些枚举成员的关联值应该是 2 的幂。 然后，可以使用按位逻辑运算符合并选项或交叉组合选项。 若要指示枚举类型声明位字段，请对其应用 Flags 属性。 如下面的示例所示，还可以在枚举类型的定义中包含一些典型组合。

    [Flags]
    public enum Days
    {
        None      = 0b_0000_0000,  // 0
        Monday    = 0b_0000_0001,  // 1
        Tuesday   = 0b_0000_0010,  // 2
        Wednesday = 0b_0000_0100,  // 4
        Thursday  = 0b_0000_1000,  // 8
        Friday    = 0b_0001_0000,  // 16
        Saturday  = 0b_0010_0000,  // 32
        Sunday    = 0b_0100_0000,  // 64
        Weekend   = Saturday | Sunday
    }

    public class FlagsEnumExample
    {
        public static void Main()
        {
            Days meetingDays = Days.Monday | Days.Wednesday | Days.Friday;
            Console.WriteLine(meetingDays);
            // Output:
            // Monday, Wednesday, Friday

            Days workingFromHomeDays = Days.Thursday | Days.Friday;
            Console.WriteLine($"Join a meeting by phone on {meetingDays & workingFromHomeDays}");
            // Output:
            // Join a meeting by phone on Friday

            bool isMeetingOnTuesday = (meetingDays & Days.Tuesday) == Days.Tuesday;
            Console.WriteLine($"Is there a meeting on Tuesday: {isMeetingOnTuesday}");
            // Output:
            // Is there a meeting on Tuesday: False

            var a = (Days)37;
            Console.WriteLine(a);
            // Output:
            // Monday, Wednesday, Saturday
        }
    }

有关详细信息和示例，请参阅 System.FlagsAttribute API 参考页和 System.Enum API 参考页的非独占成员和 Flags 属性部分。

System.Enum 类型和枚举约束

System.Enum 类型是所有枚举类型的抽象基类。 它提供多种方法来获取有关枚举类型及其值的信息。 有关更多信息和示例，请参阅 System.Enum API 参考页。
从 C# 7.3 开始，你可以在基类约束中使用 System.Enum（称为枚举约束），以指定类型参数为枚举类型。

转换

对于任何枚举类型，枚举类型与其基础整型类型之间存在显式转换。 如果将枚举值转换为其基础类型，则结果为枚举成员的关联整数值。

    public enum Season
    {
        Spring,
        Summer,
        Autumn,
        Winter
    }

    public class EnumConversionExample
    {
        public static void Main()
        {
            Season a = Season.Autumn;
            Console.WriteLine($"Integral value of {a} is {(int)a}");  // output: Integral value of Autumn is 2

            var b = (Season)1;
            Console.WriteLine(b);  // output: Summer

            var c = (Season)4;
            Console.WriteLine(c);  // output: 4
        }
    }

使用 Enum.IsDefined 方法来确定枚举类型是否包含具有特定关联值的枚举成员。


## foreach-in 枚举循环
- [`System.Collections.IEnumerable`](https://docs.microsoft.com/en-us/dotnet/api/system.collections.ienumerable)
- [`System.Collections.Generic.IEnumerable<T>`](https://docs.microsoft.com/en-us/dotnet/api/system.collections.generic.ienumerable-1)
- [`System.Collections.Generic.IAsyncEnumerable<T>`](https://docs.microsoft.com/en-us/dotnet/api/system.collections.generic.iasyncenumerable-1)


支持枚举操作的数据类型在 C# 中是最常见的，所有数组都是最基本的枚举数据类型：

    var fibNumbers = new List<int> { 0, 1, 1, 2, 3, 5, 8, 13 };
    int count = 0;
    foreach (int element in fibNumbers)
    {
        count++;
        Console.WriteLine($"Element #{count}: {element}");
    }
    Console.WriteLine($"Number of elements: {count}");

The next example uses the foreach statement with an instance of the System.Span<T> type, which doesn't implement any interfaces:

    public class IterateSpanExample
    {
        public static void Main()
        {
            Span<int> numbers = new int[] { 3, 14, 15, 92, 6 };
            foreach (int number in numbers)
            {
                Console.Write($"{number} ");
            }
            Console.WriteLine();
        }
    }

使用 ref 关键字引用被枚举的条目：

    Span<int> storage = stackalloc int[10];
    int num = 0;
    foreach (ref int item in storage)
    {
        item = num++;
    }

    foreach (ref readonly var item in storage)
    {
        Console.Write($"{item} ");
    }
    // Output:
    // 0 1 2 3 4 5 6 7 8 9

C# 8.0 新增使用 await 进行异步枚举：

    await foreach (var item in GenerateSequenceAsync())
    {
        Console.WriteLine(item);
    }


枚举数据的循环中，C# foreach 不支持语法获取索引 index，只能通过其它方式获取：

    int i = 0;
    foreach (var item in arr)
    {
        i++;
    }

    foreach (var item in arr)
    {
        int index = arr.indexOf(item); //  Array.IndexOf()
    }


## type cast

### byte to String

    string  str    = System.Text.Encoding.UTF8.GetString(bytes);
    byte[] decBytes = System.Text.Encoding.UTF8.GetBytes(str);

还可以用其它编码：

System.Text.Encoding.Default
System.Text.Encoding.ASCII

System.Text.Encoding.UTF8.GetString(bytes).TrimEnd('\0') 给字符串加上结束标识。

    string    str    = BitConverter.ToString(bytes); 
    String[] tempArr = str.Split('-');
    byte[]   decBytes = new byte[tempArr.Length];
    for (int i = 0; i < tempArr.Length; i++)
    {
        decBytes[i] = Convert.ToByte(tempArr[i], 16);
    }

给字符串加上 '-' 连字符，并且没有函数转换回去。所以需要手动转换为bytes。

    string str      = Convert.ToBase64String(bytes); 
    byte[] decBytes = Convert.FromBase64String(str);

这种方法简单明了，注意，转换出来的 string 作为 URL 地址的话，需要进行 encode。

    string  str    = HttpServerUtility.UrlTokenEncode(bytes); 
    byte[] decBytes = HttpServerUtility.UrlTokenDecode(str);

这种方法会自动编码 URL 地址的特殊字符，可以直接当做 URL 地址使用，依赖 System.Web 库。


## delegate 委托
- https://docs.microsoft.com/dotnet/csharp/language-reference/operators/delegate-operator
- https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/delegates/

delegate 是一种可用于封装命名方法或匿名方法的引用类型。 委托类似于 C++ 中的函数指针；但是，与 C 函数指针不同的是，委托是面向对象的、类型安全的和可靠的，委托是安全封装方法的类型。 

委托具有以下属性：

- 委托类似于 C++ 函数指针，但委托完全面向对象，不像 C++ 指针会记住函数，委托会同时封装对象实例和方法。
- 委托允许将方法作为参数进行传递。
- 委托可用于定义回调方法。
- 委托可以链接在一起；例如，可以对一个事件调用多个方法。
- 方法不必与委托类型完全匹配。 有关详细信息，请参阅使用委托中的变体。
- C# 2.0 版引入了匿名方法的概念，可以将代码块作为参数（而不是单独定义的方法）进行传递。 
- C# 3.0 引入了 Lambda 表达式，利用它们可以更简练地编写内联代码块。
- 匿名方法和 Lambda 表达式（在某些上下文中）都可编译为委托类型，这些功能现在统称为匿名函数。

委托对象通常通过提供委托将封装的方法的名称或使用匿名函数构造。 对委托进行实例化后，委托会将对其进行的方法调用传递到该方法。 调用方传递到委托的参数将传递到该方法，并且委托会将方法的返回值（如果有）返回到调用方。 这被称为调用委托。 实例化的委托可以按封装的方法本身进行调用。 例如:

    public delegate void Del(string message);

    // Create a method for a delegate.
    public static void DelegateMethod(string message)
    {
        Console.WriteLine(message);
    }

    // Instantiate the delegate.
    Del handler = DelegateMethod;

    // Call the delegate.
    handler("Hello World");

委托可以与命名方法相关联，使用命名方法实例化委托时，该方法作为参数传递。 使用命名方法构造的委托可以封装静态方法或实例方法。 命名方法是在早期版本的 C# 中实例化委托的唯一方式。 如果创建新方法会造成多余开销，C# 允许你实例化委托并立即指定调用委托时委托将处理的代码块。 代码块可包含 Lambda 表达式或匿名方法。

合并委托，也叫多播委托 Multicast Delegate，常用于事件处理函数的处理。委托对象通过使用 + 运算符将多个对象分配到一个委托实例。 多播委托包含已分配委托列表，此多播委托被调用时会依次调用列表中的委托，仅可合并类型相同的委托。- 运算符可用于从多播委托中删除组件委托。

示例：

    using System;

    public class Demo
    {
        // Declare a delegate.
        delegate void Del(int x);

        // Define named method.
        void DoWork(int k) { 
            Console.WriteLine("{0} {1}", this, k); 
        }

        static void DoWorkStatic(int k) { 
            Console.WriteLine("{0} {1}", "static", k); 
        }

        public static void Main()
        {
            // Instantiate the delegate using the method as a parameter.
            Del d = new Demo().DoWork;
            d(123);

            // Create an instance of the delegate.
            Del d2 = new Del(Demo.DoWorkStatic);
            d2(456);

            // C# 2.0 provides a simpler way to declare an instance of Del.
            Del d3 = Demo.DoWorkStatic;

            // C# 2.0+ Instantiate Del by using an anonymous method.
            Del d4 = delegate(int k) { Console.WriteLine($"Notification for anonymous: {k}"); };

            // C# 3.0+ Instantiate Del by using a lambda expression.
            Del d5 = k =>  { Console.WriteLine($"Notification for lambda: {k}"); };

            Del MulticastDelegate = d + d2 + d3 + d2 + d4 + d5;
            MulticastDelegate -= d2; // remove d2
            MulticastDelegate -= d2; // remove d3
            MulticastDelegate -= d2; // remove d2
            MulticastDelegate -= d2; // remove nomore
            MulticastDelegate(789);
        }
    }

在 .NET 中，System.Action 和 System.Func 类型为许多常见委托提供泛型定义。 可能不需要定义新的自定义委托类型。 相反，可以创建提供的泛型类型的实例化。

使用 Action 委托以参数的形式传递方法，而无需显式声明自定义委托。 封装的方法必须对应于由此委托定义的方法签名。 这意味着封装的方法必须没有任何参数，并且不能有返回值。使用其它重载的 Action 委托，如 Action<T> 委托，可以封装定义使用单个参数封装方法的委托。

    Action<string> write = delegate(string s) { Console.WriteLine(s); };


delegate 运算符创建一个可以转换为委托类型的匿名方法，和 Action 一样，Func 泛型是内置的委托类型：

    Func<int, int, int> sum = delegate (int a, int b) { return a + b; };
    Console.WriteLine(sum(3, 4));  // output: 7

从 C# 3 开始，lambda 表达式提供了一种更简洁和富有表现力的方式来创建匿名函数。 使用 => 运算符构造 lambda 表达式：

    Func<int, int, int> sum = (a, b) => a + b;
    Console.WriteLine(sum(3, 4));  // output: 7

注意 System.Func 泛型参数中最后一个为委托函数的返回类型：

    System.Func<TResult>
    System.Func<T,TResult>
    System.Func<T1,T2,TResult>
    System.Func<T1,T2,T3,TResult>
    System.Func<T1,T2,T3...T16,TResult>

使用 delegate 运算符时，可以省略参数列表。 如果这样做，可以将创建的匿名方法转换为具有任何参数列表的委托类型，如以下示例所示：

    Action greet = delegate { Console.WriteLine("Hello!"); };
    greet();

    Action<int, double> introduce = delegate { Console.WriteLine("This is world!"); };
    introduce(42, 2.7);

    // Output:
    // Hello!
    // This is world!

这是 lambda 表达式不支持的匿名方法的唯一功能。 在所有其他情况下，lambda 表达式是编写内联代码的首选方法。

还可以使用 delegate 关键字声明委托类型。 委托类型的声明与方法签名相似， 它有一个返回值和任意数目任意类型的参数：

    public delegate void MessageDelegate(string message);
    public delegate int AnotherDelegate(MyType m, long num);


下面的示例，定义了一个委托类型 ShowValue，然后通过实例化 ShowValue 或 Action 委托来调用被委托的方法。使用 Action 可以简化代码，而不用显式定义一个新委托并为其分配一个命名方法。委托方法有 Action 实例化，匿名方式，lambda 表达式方式。

    using System;
    using System.Windows.Forms;

    public delegate void ShowValue();

    public class Name
    {
       private string instanceName;

       public Name(string name)
       {
          this.instanceName = name;
       }

       public void DisplayToConsole()
       {
          Console.WriteLine(this.instanceName);
       }

       public void DisplayToWindow()
       {
          MessageBox.Show(this.instanceName);
       }
    }

    public class testTestDelegate
    {
       public static void Main()
       {

          Name testName = new Name("Koani");
          ShowValue delegateShow = testName.DisplayToWindow;
          delegateShow();

          Action anonymousSHow = delegate() { testName.DisplayToWindow();} ;
          anonymousSHow();

          Action lambdaShow = () => testName.DisplayToWindow();
          lambdaShow();

          Action actionShow = testName.DisplayToWindow;
          actionShow.Invoke();
       }
    }


##  Generic 协变性和逆变性
https://zhuanlan.zhihu.com/p/143054881

在 C# 4.0 中引入了泛型的协变和逆变性，泛型的三个特性：

- 不变性 invariance
- 协变性 covariance 是指方能从委托的返回类型派生一个类型作为方法返回类型。
- 逆变性 contravariance 是指方法参数可以是委托的参数类型的基类。

示例：

    delegate Object MyCallback(FileStream s);
    string SomeMethod(Stream s){
        ...
    };

例子，SomeMethod 可以绑定 MyCallBack 委托，符号协变性和逆变性。因为其返回类型 string 派生自 Object 即委托返回类型，这种协变性是允许的。其参数类型 Stream 的基类是 FileStream 即委托的参数类型，这种逆变性是允许的。

注意：只有引用类型才支持协变性与逆变性，值类型或 void 不支持。所以不能把下面的方法绑定到 MyCallBack 委托：

    int SomeOtherMethod(Stream s);

虽然 SomeOtherMethod 的返回类型 int 派生自 MyCallback 的返回类型 Object，但这种形式的协变性是不允许的，因为 int 是值类型。显然，值类型和 void 之所以不支持，是因为它们的存储结构是变化的，而引用类型的存储结构始终是一个指针。



## Generics & List 泛型
- https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/
- []()

泛型类和泛型方法兼具可重用性、类型安全性和效率，这是非泛型类和非泛型方法无法实现的。 泛型通常与集合以及作用于集合的方法一起使用。 `System.Collections.Generic` 命名空间包含几个基于泛型的集合类。 非泛型集合，如 ArrayList 不建议使用，并且保留用于兼容性目的。

- 使用泛型类型可以最大限度地重用代码、保护类型安全性以及提高性能。
- 泛型最常见的用途是创建集合类。
- `System.Collections.Generic` 命名空间中包含几个新的泛型集合类。 应尽可能使用这些类来代替某些类，如 `System.Collections.ArrayList`。
- 可以创建自己的泛型接口、泛型类、泛型方法、泛型事件和泛型委托。
- 可以对泛型类进行约束以访问特定数据类型的方法。
- 在泛型数据类型中所用类型的信息可在运行时通过使用反射来获取。


也可以创建自定义泛型类型和泛型方法，以提供自己的通用解决方案，设计类型安全的高效模式。 

    // Declare the generic class.
    public class GenericList<T>
    {
        public void Add(T input) {
            // do nothing...
        }
    }
    class TestGenericList
    {
        private class ExampleClass { }
        static void Main()
        {
            // Declare a list of type int.
            GenericList<int> list1 = new GenericList<int>();
            list1.Add(1);

            // Declare a list of type string.
            GenericList<string> list2 = new GenericList<string>();
            list2.Add("");

            // Declare a list of type ExampleClass.
            GenericList<ExampleClass> list3 = new GenericList<ExampleClass>();
            list3.Add(new ExampleClass());
        }
    }

当然，也可以创建自定义泛型类型和泛型方法，以提供自己的通用解决方案，设计类型安全的高效模式。

以下代码示例演示了出于演示目的的简单泛型链接列表类。 大多数情况下，应使用 .NET Framework 类库提供的 List<T> 类，而不是自行创建类。 其使用方法如下：

- 在 AddHead 方法中 T 作为方法参数的类型。
- 泛型 T 在嵌套类中作链表数据结构中节点的 Node 的 Data 属性类型。
- 泛型 T 在嵌套类中私有成员 data 的类型。

请注意，T 可用于 Node 嵌套类。 如果使用具体类型实例化 GenericList<T>，例如，`GenericList<int>`，则所有 T 都将替换为 int。

    // type parameter T in angle brackets
    public class GenericList<T>
    {
        // The nested class is also generic on T.
        private class Node
        {
            // T used in non-generic constructor.
            public Node(T t)
            {
                next = null;
                data = t;
            }

            private Node next;
            public Node Next
            {
                get { return next; }
                set { next = value; }
            }

            // T as private member data type.
            private T data;

            // T as return type of property.
            public T Data
            {
                get { return data; }
                set { data = value; }
            }
        }

        private Node head;

        // constructor
        public GenericList()
        {
            head = null;
        }

        // T as method parameter type:
        public void AddHead(T t)
        {
            Node n = new Node(t);
            n.Next = head;
            head = n;
        }

        public IEnumerator<T> GetEnumerator()
        {
            Node current = head;

            while (current != null)
            {
                yield return current.Data;
                current = current.Next;
            }
        }
    }




## pragma 指令
-[Recommended tags for documentation comments](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/xmldoc/recommended-tags-for-documentation-comments)
-[C# preprocessor directives](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/preprocessor-directives)

pragma disable 禁用了不感兴趣的特别警告，pragma restore 个恢复了它。

禁用尽可能小的一段代码的警告是一个良好的做法，以便你不会错过任何真正应该修复的错误。

如果你想在单独一行上禁用或恢复多个警告，那么只需用逗号分隔多个警告编号。如果你没有指定任何警告编号，将一次性禁用或恢复所有警告——不过无论从哪个方面想这都是个坏主意

        class Program
        {
            static void Main(string[] args)
            {

            }
        }
        public class FieldUsedOnlyByReflection
        {
    #pragma warning disable 0169
            int x;
    #pragma warning restore 0169


## Namespace & Using Alias 命名空间别名
- https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/namespaces/

namespace 关键字用于声明包含一组相关对象的作用域。 可以使用命名空间来组织代码元素并创建全局唯一类型。

    namespace SomeNameSpace
    {
        public class MyClass
        {
            static void Main()
            {
                Nested.NestedNameSpaceClass.SayHello();
            }
        }

        // a nested namespace
        namespace Nested
        {
            public class NestedNameSpaceClass
            {
                public static void SayHello()
                {
                    Console.WriteLine("Hello");
                }
            }
        }
    }

using 指令有三种用途：

允许在命名空间中使用类型，这样无需在该命名空间中限定某个类型的使用：

    using System.Text;

using static 允许访问类型的静态成员和嵌套类型，而无需限定使用类型名称进行访问。

    using static System.Console;
    using static System.Math;

    class Program
    {
        static void Main()
        {
            WriteLine(Sqrt(3*3 + 4*4));
        }
    }

为命名空间或类型创建别名。 这称为 using 别名指令。

    using Project = PC.MyCompany.Project;


命名空间别名用法 ALIAS::CLASS：

    using WinForm = System.Windows.Forms;

    namespace Test01
    {
        class WinForm { }
        class Program
        {
            static void Main(string[] args)
            {
                Console.WriteLine(typeof(WinForm::Button));
                Console.ReadKey();
            }
        }
    }

全局命名空间别名 global::CLASS

    using System;

    class Configuration { }

    namespace Test01
    {
        class Configuration { }
        class Program
        {
            static void Main(string[] args)
            {
                Console.WriteLine(typeof(Configuration)); // Test01.Configuration
                Console.WriteLine(typeof(global::Configuration)); // Configuration
                Console.WriteLine(typeof(global::Test01.Configuration)); // Test01.Configuration
                Console.ReadKey();
            }
        }
    }


若要引用具有相同的完全限定类型名称的两个程序集，必须在命令提示符处指定别名，如下所示：

    /r:GridV1=grid.dll

    /r:GridV2=grid20.dll

这将创建外部别名 GridV1 和 GridV2。 若要从程序中使用这些别名，请通过使用 extern 关键字引用它们。 例如:

    extern alias GridV1;

    extern alias GridV2;

GridV1::Grid 是 grid.dll 中的网格控件，GridV2::Grid 是 grid20.dll 中的网格控件。


## Implementing the Singleton Pattern in C# - C# in Depth
http://csharpindepth.com/Articles/General/Singleton.aspx#performance
https://www.cnblogs.com/xtxk110/p/12884937.html

C# in Depth 此书中关于单例模式 Implementing the Singleton Pattern in C#

单例模式是软件工程中最着名的模式之一。从本质上讲，单例是一个只允许创建自身的单个实例的类，并且通常可以简单地访问该实例。


第六版 - 使用 .NET 4 的 Lazy 类型

.NET 4 或更高版本可以使用 System.Lazy 类型使惰性变得非常简单。您需要做的就是将委托传递给调用Singleton　构造函数的构造函数——使用　lambda　表达式最容易做到这一点。

    public sealed class Singleton
    {
        private static readonly Lazy<Singleton> lazy =
            new Lazy<Singleton>(() => new Singleton());
        
        public static Singleton Instance { get { return lazy.Value; } }

        private Singleton()
        {
        }
    }

它很简单，而且性能很好。它还允许您检查是否已使用　IsValueCreated 属性创建实例（如果需要的话）。

上面的代码隐式地将 LazyThreadSafetyMode.ExecutionAndPublication 用作 Lazy<Singleton> 的线程安全模式。


第五版 - 完全懒惰的实例化

    public sealed class Singleton
    {
        private Singleton() { }

        public static Singleton Instance { get { return Nested.instance; } }
            
        private class Nested
        {
            // Tell compiler NOT to Use BeforeFieldInit
            static Nested() { }

            internal static readonly Singleton instance = new Singleton();
        }
    }

在这里，实例化是由对嵌套类的静态成员的第一次引用触发的，该引用只发生在实例化时。这意味着实现是完全懒惰的，但是具有前面实现的所有性能优势。请注意，尽管嵌套类可以访问封闭类的私有成员，但反之则不然，因此需要在此处实例化为内部成员。不过，这不会引起任何其他问题，因为类本身是私有的。但是，为了使实例化变得懒惰，代码要稍微复杂一些。


第四版 - 不太懒，不使用锁且线程安全

    public sealed class Singleton
    {
        private static readonly Singleton instance = new Singleton();

        // Tell compiler NOT to Use BeforeFieldInit
        static Singleton() { }

        private Singleton() { }

        public static Singleton Instance
        {
            get
            {
                return instance;
            }
        }
    }

这实际上非常简单，但是为什么它是线程安全的，它有多懒惰？ C# 中的静态构造函数仅在创建类的实例或引用静态成员时执行，并且每个 AppDomain 只执行一次。

第三版 - 糟糕的双重检查锁定尝试线程安全

    public sealed class Singleton
    {
        private static Singleton instance = null;
        private static readonly object padlock = new object();

        Singleton()
        {
        }

        public static Singleton Instance
        {
            get
            {
                if (instance == null)
                {
                    lock (padlock)
                    {
                        if (instance == null)
                        {
                            instance = new Singleton();
                        }
                    }
                }
                return instance;
            }
        }
    }

该实现尝试是线程安全的，而不必每次都取出锁。不幸的是糟糕的实现，缺点多。

它在 Java 中不起作用，这似乎是一个奇怪的事情，但是如果您需要 Java 中的单例模式，这应该要知道，C# 程序员也可能是 Java 程序员。Java 内存模型无法确保构造函数在新对象的引用分配给实例之前完成。Java 内存模型经历了 1.5 版本的重新改进，但是在没有 volatile 变量（如在C＃中）的情况下，双重检查锁定仍然会被破坏。

第二版 —— 简单的线程安全

    public sealed class Singleton
    {
        private static Singleton instance = null;
        private static readonly object padlock = new object();

        Singleton() { }

        public static Singleton Instance
        {
            get
            {
                lock (padlock)
                {
                    if (instance == null)
                    {
                        instance = new Singleton();
                    }
                    return instance;
                }
            }
        }
    }

此实现是线程安全的。线程取消对共享对象的锁定，然后在创建实例之前检查是否已创建实例。这会解决内存屏障问题，锁定确保在获取锁之后逻辑上发生所有读取，并且解锁确保在锁定释放之前逻辑上发生所有写入。并确保只有一个线程将创建实例，仅限于一次只能有一个线程可以访问锁定代码，当第二个线程进入它时，第一个线程将创建实例，因此表达式将计算为 false。不幸的是，每次请求实例时都会获得锁定，因此性能会受到影响。

第一版 —— 非线程安全的（不建议）

    // 糟糕的代码！不要使用！
    public  sealed  class  Singleton 
    { 
        private  static  Singleton instance = null ; 

        private  Singleton（）
        { 
        } 

        public  static  Singleton Instance 
        { 
            get 
            { 
                if  （instance == null）
                { 
                    instance =  new  Singleton（）; 
                } 
                return  instance; 
            } 
        } 
    }

两个不同的线程都可以在 (instance==null) 条件中得到 true，然后两个都创建实例，这违反了单例模式。实际上，在计算表达式之前可能已经创建了实例，但是内存模型不保证其他线程可以看到实例的新值，除非已经传递了合适的内存屏障（互斥锁）。


## static contructor & BeforeFieldInit

CLR - Common Language Runtime 运行时相当于一个运行环境，相当于 JVM。

IL - Intermidiate Language 中间语言，C# 先编译成中间语言再在 CLR 上面执行。

当泛型类没有静态构造函数的时候，在 C# 的 IL 中该类会被标记为 BeforeFieldInit，即个静态成员会在字段初始化前将执行，先于入口函数执行，这个是由编译器自动完成的。

只要定义了静态函数，即使是不做任何动作的空函数，那么候静态初始化发生在使用前期：

    using System;
    using System.Collections.Generic;
    using System.Threading;
    using System.Threading.Tasks;

    public static class StaticDemo<T>
    {
        public static readonly DateTime Time = GetNow();
        private static DateTime GetNow()
        {
            Console.WriteLine("GetNow execute!");
            return DateTime.Now;
        }
        // Tell compiler NOT to Use BeforeFieldInit
        static StaticDemo(){}
    }

    class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine("Main execute!");
            Console.WriteLine("stage 1: {0:mm:ss.fff}ms", StaticDemo<int>.Time);
            Thread.Sleep(1000);
            Console.WriteLine("stage 2: {0:mm:ss.fff}ms", StaticDemo<string>.Time);
            Console.WriteLine("stage 3: {0:mm:ss.fff}ms", StaticDemo<int>.Time);
            Console.WriteLine("stage 4: {0:mm:ss.fff}ms", StaticDemo<string>.Time);
            // Console.ReadLine();
        }
    }

输出：

    Main execute!
    GetNow execute!
    stage 1: 35:05.524ms
    GetNow execute!
    stage 2: 35:06.526ms
    stage 1: 35:05.524ms
    stage 2: 35:06.526ms

在首次执行时，不定义静态构造函数，即 BeforeFieldInit 会提高性能，因为预处理了。

C# 中的静态构造函数仅在创建类的实例或引用静态成员时执行，并且每个 AppDomain 只执行一次。



## Class & Interface 类与接口
- [可引用的数据类型](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/reference-types)
- [类和结构](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/classes-and-structs/)
- [访问修饰符 - C# 关键字](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/access-modifiers)
- [C# Interface](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/interfaces/)

C# 中有两种类型：引用类型和值类型。 引用类型的变量存储对其数据（对象）的引用，而值类型的变量直接包含其数据。 对于引用类型，两种变量可引用同一对象；因此，对一个变量执行的操作会影响另一个变量所引用的对象。 对于值类型，每个变量都具有其自己的数据副本，对一个变量执行的操作不会影响另一个变量，in、ref 和 out 参数变量除外。

.NET 类型系统中的所有类型除了可以通过单一继承进行继承之外，还可以隐式继承自 Object 或其派生的类型。 Object 的常用功能可用于任何类型，所有类都继承自 System.Object 类。

和类不同，结构是值类型，结构都继承自 System.ValueType 类。 创建结构时，向其分配结构的变量保留结构的实际数据。结构在栈上分配内容，Enum 枚举类型不是。 将结构分配给新变量时，会复制结构。 因此，新变量和原始变量包含相同数据的副本（共两个）。 对一个副本所做的更改不会影响另一个副本。

类和结构是 .NET Framework 通用类型系统的两种基本构造。 每种本质上都是一种数据结构，其中封装了同属一个逻辑单元的一组数据和行为。 数据和行为是类或结构的成员，包括方法、属性和事件等。



下列关键字用于声明引用类型：

- class
- interface
- delegate

C# 也提供了下列内置引用类型：

- dynamic
- object
- string

使用 class 关键字声明类，如下例中所示：

    using System;
    using System.Linq;
    using System.Collections.Generic;

    namespace Demo
    {
        public static class Program
        {
            public static void Main()
            {
                var test = new TestClass("ABC");
                test.Quadruple = 2;
                // test.Pi = 2; // Not Allow assign readonly property
                // var t = test._title; // Not Allow to access to protected
            }
        }

        interface IBasic
        {
            double Pi {get;}
            void Log();
            void Log(int level);
            // write definition for an interface from C# 8.0
        }

        abstract class Basic: IBasic {

            // fields members
            protected internal int _count = 1; // private protected | C# 7.2
            protected string _title = string.Empty; 

            // readonly fields members
            readonly double _pi = 3.14159265358; 

            // readonly property members
            public double Pi => this._pi; // implementation of IBasic

            // normal property members
            public int Quadruple { 
                get {
                    return this._count * 4;
                }
                set {
                    Console.WriteLine("Not Allow to change to {0}, keep {1}", value, this.Quadruple);
                }
            } 

            public Basic(string t){
                _title = t;
                Console.WriteLine($"Basic(t={t})");
            }

             // implementation of IBasic
            public virtual void Log(){
                Console.WriteLine($"Log _title({this._title})");
            }

            public abstract void Log(int level);
        }

        class TestClass: Basic
        {
            public TestClass(string t): base(t)
            {
                this._title = "Test";
                base.Log();
                this.Log();
            }

            public override void Log()
            {
                Console.WriteLine($"Log[New] _title is {this._title}");
            }
            
            public override void Log(int level){
                Console.WriteLine($"Log LEVEL[{level}] _title is {this._title}");
            }

            // Methods, properties, fields, events, delegates
            // and nested classes go here.
            public sealed class nestedClass : TestClass
            {
                public  nestedClass(string t): base(t){

                }
            }
        }

        // class NotAllowToExtendsSealedClass: TestClass.nestedClass {}

    }


在 C# 中仅允许单一继承，但是，一个类可实现多个接口。

直接在命名空间中声明的、未嵌套在其它类中的类，可以是公共或内部， 默认情况下类为 internal。

一个类可包含下列成员的声明：

- 构造函数 Constructors
- 常量 Constants
- 字段 Fields
- 终结器 Finalizers
- 方法 Methods
- 属性 Properties
- 索引器 Indexers
- 运算符 Operators
- 事件 Events
- 委托 Delegates
- 类 Classes
- 接口 Interfaces
- 结构类型 Structure types
- 枚举类型 Enumeration types

静态构造器 static constructor 是实现对一个类进行初始化的方法成员， 它一般用于对静态数据的初始化，静态构造函数不能有参数，不能有修饰符而且不能被调用，随着类加载时自动执行。在一个程序的执行过程中，只执行一次，而且先于任何类的静态成员被引用之前，静态成员初始化之后执行，或者说编译器会将静态成员初始化语句转换成赋值语句放在静态构造器执行的最开始。

    class Program
        {
            static void Main(string[] args)
            {
                Demo p1 = new Demo();
                Console.ReadKey();
            }
        }
        class Demo
        {
            static Demo()
            {
                Console.WriteLine("Static Constructor...“);
            }
            public Demo()
            {
                Console.WriteLine("Demo()...");
            }
        }


类或结构可以嵌套在另一类或结构中。如果不方便或没有必要创建已命名的类，可以使用匿名类型。

    var anonArray = new[] { new { name = "apple", diam = 4 }, new { name = "grape", diam = 1 }};

    public class Outer
    {
        // protected method:
        protected void Pedal() { }
    
        class nested
        {
            int wheels;
        }
    }

类成员包括嵌套的类，可以是以下各种访问级别，默认情况下成员为 private。所有类型和类型成员都具有可访问性级别，可以控制是否可以从你的程序集或其他程序集中的其他代码中使用它们。 可以使用以下访问修饰符在进行声明时指定类型或成员的可访问性：

| 可访问性级别    | 注解 |
| :---------    | :--------- |
| public    | 同一程序集中的任何其他代码或引用该程序集的其他程序集都可以访问该类型或成员。 |
| private   | 只有同一 class 或 struct 中的代码可以访问该类型或成员。 |
| protected | 只有同一 class 或者从该 class 派生的 class 中的代码可以访问该类型或成员。 |
| internal  | 同一程序集中的任何代码都可以访问该类型或成员，但其他程序集中的代码不可以。 |
| protected internal    | 该类型或成员可由对其进行声明的程序集或另一程序集中的派生 class 中的任何代码访问。 |
| private protected | C# 7.2 可用。只有在其声明程序集内，通过相同 class 中的代码或派生自该 class 的类型，才能访问类型或成员。 |

作为其他类型的成员的嵌套类型可以具有如下表所示的声明的可访问性：

使用 abstract 关键字可以创建不完整且必须在派生类中实现的类和 class 成员。

使用 sealed 关键字可阻止其他类继承自该类，可以防止继承以前标记为 virtual 的类或某些类成员。

使用 static 修饰符可声明属于类型本身而不是属于特定对象的静态成员。 static 修饰符可用于声明 static 类。 在类、接口和结构中，可以将 static 修饰符添加到字段、方法、属性、运算符、事件和构造函数。 static 修饰符不能用于索引器或终结器。 

非静态类可以包含静态方法、字段、属性或事件。 即使未创建类的任何实例，也可对类调用静态成员。


默认成员可访问性：

| 成员        | 默认成员可访问性  | 允许的成员的声明的可访问性 |
| :---------| :-------------    | :--------- |
| enum      | public            | 无 |
| class     | private           | public /protected /internal /private /protected internal /private protected |
| interface | public            | 无 |
| struct    | private /public /internal /private |

嵌套类型的可访问性依赖于它的可访问域，该域是由已声明的成员可访问性和直接包含类型的可访问域这二者共同确定的。 但是，嵌套类型的可访问域不能超出包含类型的可访问域。


多态性常被视为自封装和继承之后，面向对象的编程的第三个支柱。 Polymorphism（多态性）是一个希腊词，指“多种形态”，多态性具有两个截然不同的方面：

- 在运行时，在方法参数和集合或数组等位置，派生类的对象可以作为基类的对象处理。 在出现此多形性时，该对象的声明类型不再与运行时类型相同。

- 基类可以定义并实现虚方法，派生类可以重写这些方法，即派生类提供自己的定义和实现 。 在运行时，客户端代码调用该方法，CLR 查找对象的运行时类型，并调用虚方法的重写方法。 你可以在源代码中调用基类的方法，执行该方法的派生类版本。

虚方法 virtual 允许你以统一方式处理多组相关的对象。 例如，假定你有一个绘图应用程序，允许用户在绘图图面上创建各种形状。 你在编译时不知道用户将创建哪些特定类型的形状。

使用多态性解决这一问题：

- 创建一个类层次结构，其中每个特定形状类均派生自一个公共基类。
- 使用虚方法通过对基类方法的单个调用来调用任何派生类上的相应方法。

使用接口解决这一问题：

- 创建一个基础接口，定义与具体形状无关的绘画方法。
- 为具体的形状定义一个类，并实现基础接口。
- 通过接口实例调用绘画方法。

示例：

    using System;
    using System.Linq;
    using System.Collections.Generic;

    namespace Demo
    {
        public static class Program
        {
            public static void Main()
            {
                var shapes = new List<Shape>
                {
                    new Rectangle(),
                    new Triangle(),
                    new Circle()
                };

                // Polymorphism at work #2: the virtual method Draw is
                // invoked on each of the derived classes, not the base class.
                foreach (var shape in shapes)
                {
                    shape.Draw();
                }
            }
        }

        public class Shape
        {
            public int X { get; private set; }
            public int Y { get; private set; }

            public virtual void Draw(string type = "Shape")
            {
                // string interpolation require C# 6.0
                Console.WriteLine($"Drawing a {type} at ({X},{Y})");
            }
        }

        public class Circle : Shape
        {
            public override void Draw(string type)
            {
                base.Draw(this.GetType().Name);
            }
        }
        public class Rectangle : Shape
        {
            public override void Draw(string type)
            {
                base.Draw(this.GetType().Name);
            }
        }
        public class Triangle : Shape
        {
            public override void Draw(string type)
            {
                base.Draw(this.GetType().Name);
            }
        }

    }



### Extension Methods 扩展方法

通常，可以通过两种方式向现有类型添加方法：

- 修改该类型的源代码。 当然，如果并不拥有该类型的源代码，则无法执行该操作。 并且，如果还添加任何专用数据字段来支持该方法，这会成为一项重大更改。
- 在派生类中定义新方法。 无法使用其他类型（如结构和枚举）的继承来通过此方式添加方法。 也不能使用此方式向封闭类“添加”方法。

使用扩展方法 Extension Methods 也可向现有 C# 类型添加方法，而无需修改类型本身或在继承的类型中实现新方法。 扩展方法也无需驻留在与其扩展的类型相同的程序集中，要把扩展方法当作是定义的类型成员一样调用。


为了理解命名空间引入 C# 扩展方法的作用，可以先将 System.Linq 注解，编译就会发现，numbers 数据根本没有 Select 方法，这是因为它是 System.Linq 扩展数组得来的方法，只有引入命名空间后才可以使用：

    using System;
    using System.Linq;

    class Example
    {
        public static void Main()
        {
            int[] numbers = new int[]{2, 2, 3, 4, 5};
            var a = numbers.Select( i => new string('*', i));
            Console.WriteLine(string.Join(",",a));
        }
    }


下面的示例演示为 System.String 类定义的一个扩展方法。 扩展方法总是定义在非嵌套的、非泛型静态类内部，注意 this 关键字的用法，还有 using 引入扩展命名空间：

    namespace ExtensionMethods
    {
        public static class MyExtensions
        {
            public static int WordCount(this String str)
            {
                return str.Split(new char[] { ' ', '.', '?' },
                                 StringSplitOptions.RemoveEmptyEntries).Length;
            }
        }
    }

可使用此 WordCount 指令将 using 扩展方法置于范围中：

    using ExtensionMethods;

而且，可以使用以下语法从应用程序中调用该扩展方法：

    string s = "Hello Extension Methods";
    int i = s.WordCount();

另一个例子，注意输出 `ABC -> ####ABC`，原来的字符串 test 并没有改变，尽管 it 赋值了，但是字符串变量总是不会改变的，赋值后的字符串不是原来的 test 而是内存中的另一个地址的字符串。

    using System;
    using ExtensionsDemo;

    public class Demo
    {
        public static void Main()
        {
            string test = "ABC";
            string n = test.PaddingLeft('#', 4);
            Console.WriteLine($"{test} -> {n}");
        }
    }

    namespace ExtensionsDemo
    {
        public static class Demo
        {
            public static string PaddingLeft(this string it, char tpl, int len)
            {
                it = new String(tpl, len) + it;
                return it;
            }
        }
    }

### Overload Override Hidden


C# 中三个基础概念：

- 子类的方法与基类方法同名且同样的参数列表，需要使用 new 限定显式隐藏基类方法；
- 基类方法使用 virtual 修饰，子类可以重写 override；
- 方法同名时，但参数列表有差别即方法的重载 overload；

基类 Root 有两个同名的 Log 方法，但是参数不一样，是方法重载 Overload，执行时根据传入参数调用。重载的方法可分别出现在基类和子类上，并不一定同在子类或基类上定义。注意，方法返回类型并不在分别条件中。

基类其中一个方法使用了 virtual 声明表示在子类中可以被重写 override。

而基类的另一个 Log(string msg) 方法没有 virtual 修饰，表示它不可以被重写。但是子类又定义了一个同名同参数的方法，那么编译器需要显式声明以明确它的意义，如果这是一个新的方法就需要前缀 new 关键字修饰。如果不是，那么就可能名字错了，编译器给出 CS0108 警告信息就是提醒作用。忽略警告，运行程序相当于编译器自行添加 new 前缀修饰。

重写和隐藏的区别在于，重写是用子类的方法替代基类的方法，而隐藏是在子类中隐藏基类的方法，基类的方法还存在可以通过基类调用。

示例代码：·

    using System;

    public class Root
    {
        public virtual void Log(int msg)
        {
            Console.WriteLine("  Root Log[integer] {0}", msg);
        }
        public void Log(string msg)
        {
            Console.WriteLine("  Root Log[string] {0}", msg);
        }
    }
     
    public class Ramous : Root
    {
        public override void Log(int msg)
        {
            Console.WriteLine("Ramous Log...");
        }
        public new void Log(string msg)
        {
            Console.WriteLine("Ramous Log[string] {0}", msg);
        }
    }

    public class Example
    {

        public static void Main()
        {
            Ramous ram = new Ramous();
            Root rot = ram;
            ram.Log(1);
            rot.Log(1);
            ram.Log("1");
            rot.Log("1");
        }
    }

输出：

    Ramous Log...
    Ramous Log...
    Ramous Log[string] 1
      Root Log[string] 1


## Parallel Programming
- [基于异步任务并行编程](https://docs.microsoft.com/zh-cn/dotnet/standard/parallel-programming/task-based-asynchronous-programming)


## async & await 异步编程
- [async & await 异步编程](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/async/)
- [await 运算符](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/operators/await)
- [.NET 中的并行处理、并发和异步编程](https://docs.microsoft.com/zh-cn/dotnet/standard/parallel-processing-and-concurrency)

新型应用广泛使用文件和网络 I/O。 默认情况下 I/O API 一般会阻塞，导致糟糕的用户体验和硬件利用率，除非希望学习和使用富有挑战的模式。 基于任务的异步 API 和语言级异步编程模型改变了这种模型，只需了解几个新概念就可默认进行异步执行，提升用户体验。

异步代码具有以下特点：

- 等待 I/O 请求返回的同时，可通过生成处理更多请求的线程，处理更多的服务器请求。
- 等待 I/O 请求的同时生成 UI 交互线程，并通过将长时间运行的工作转换到其他 CPU 核心，让 UI 的响应速度更快。
- 许多较新的 .NET APIs 都是异步的。
- 在 .NET 中编写异步代码很简单！


现实中的例子，早上起来手上要做三件事，依次冲咖啡，煎蛋，烤肉，每件事都要消耗资源占用时间：

    using System;
    using System.Linq;
    using System.Threading.Tasks;

    using Coffee = System.String;
    using Bacon = System.String;
    using Egg = System.String;

    namespace AsyncBreakfast
    {
        class Program
        {
            static void Main(string[] args)
            {
                Coffee cup = PourCoffee();
                Console.WriteLine("coffee is ready");

                Egg eggs = FryEggs(2);
                Console.WriteLine("eggs are ready");

                Bacon bacon = FryBacon(3);
                Console.WriteLine("bacon is ready");
            }

            private static Bacon FryBacon(int slices)
            {
                Console.WriteLine($"putting {slices} slices of bacon in the pan");
                Console.WriteLine("cooking first side of bacon...");
                Task.Delay(3000).Wait();
                for (int slice = 0; slice < slices; slice++)
                {
                    Console.WriteLine("flipping a slice of bacon");
                }
                Console.WriteLine("cooking the second side of bacon...");
                Task.Delay(3000).Wait();
                Console.WriteLine("Put bacon on plate");

                return new Bacon("Good Bacon");
            }

            private static Egg FryEggs(int howMany)
            {
                Console.WriteLine("Warming the egg pan...");
                Task.Delay(3000).Wait();
                Console.WriteLine($"cracking {howMany} eggs");
                Console.WriteLine("cooking the eggs ...");
                Task.Delay(3000).Wait();
                Console.WriteLine("Put eggs on plate");

                return new Egg("Fine Egg");
            }

            private static Coffee PourCoffee()
            {
                Console.WriteLine("Pouring coffee");
                return new Coffee("Smelly coffee");
            }

        }
    }

有经验的你可能会先开始加热平底锅以备煎蛋，接着手再切肉。 你可将面包放进烤面包机，然后再煎鸡蛋。在此过程的每一步，你都可以先开始一项任务，将本来用于等待的时间，转移到准备其他任务上。

做早餐是非并行异步工作的一个好示例，单人（或单线程）即可处理所有这些任务。 一个人可以以异步方式做早餐，即在第一个任务完成之前开始进行下一个任务。 不管是否有人在看着，做早餐的过程都在进行。 对于并行算法而言，你则需要多名厨师（或线程）。 一名厨师煎鸡蛋，一名厨师煎培根，依次类推。 每名厨师将仅专注于一项任务。 每名厨师（或线程）都在同步等待需要翻动培根或面包弹出时都将受到阻。

计算机不会按人类的方式来解释这些指令，计算机将阻塞每条语句，直到工作完成，然后再继续运行下一条语句。 后续任务直到早前任务完成后才会启动，这样做早餐花费的时间要长得多，有些食物在上桌之前就已经凉了。

如果你希望计算机异步执行上述指令，则必须编写异步代码。
这些问题对即将编写的程序而言至关重要。 编写客户端程序时，你希望 UI 能够响应用户输入。 从 Web 下载数据时，你的应用程序不应让手机出现卡顿。 编写服务器程序时，你不希望线程受到阻塞， 这些线程可以用于处理其他请求。 

成功的现代应用程序需要异步代码，使用异步的方案就是节省等待时间。不要阻塞，而要 await 来设置回调跳过要等待的事件。 同步代码，顾名思义，此代码将阻止执行这段代码的线程执行任何其他操作。 在任何任务进行过程中，此代码也不会被中断。 就如同你将面包放进烤面包机后盯着此烤面包机一样。 你会无视任何跟你说话的人，直到面包弹出。

在异步方案中，应该立即启动若干独立的任务。 然后，在每个任务完成时，你可以继续进行已准备的其他工作。 在早餐类比中，这就是更快完成做早餐的方法。 你也几乎将在同一时间完成所有工作。 你将吃到一顿热气腾腾的早餐。

System.Threading.Tasks.Task 和相关类型是可以用于推断正在进行中的任务的类。 这使你能够编写更类似于实际做早餐方式的代码。 你可以同时开始煎鸡蛋、培根和烤面包。 由于每个任务都需要操作，所以你会将注意力转移到那个任务上，进行下一个操作，然后等待其他需要你注意的事情。
启动一项任务并等待表示运行的 Task 对象。 你将首先 await 每项任务，然后再处理它的结果。
让我们对早餐代码进行这些更改。 

第一步是存储任务以便在这些任务启动时进行操作，而不是等待，用 Task 去存储一个函数。为了不立即执行，而是加入回调管理，需要改造原有的函数结构，然后再通过任务启动方法开始执行：

    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Threading.Tasks;

    using Coffee = System.String;
    using Bacon = System.String;
    using Egg = System.String;

    namespace AsyncBreakfast
    {
        class Program
        {
            static async Task Main(string[] args)
            {
                DateTime s1 = DateTime.Now;

                Task<Egg> eggsTask = FryEggsAsync(2);
                Task<Bacon> baconTask = FryBaconAsync(3);

                // this is synchronal style code
                // Egg egg = await FryEggsAsync(2);
                // Bacon bacon = await FryBaconAsync(3);

                Egg egg =  await eggsTask;
                Console.WriteLine("eggs are ready");

                Bacon bacon =  await baconTask;
                Console.WriteLine("bacon is ready");
                
                Coffee coffee = PourCoffee();
                Console.WriteLine("coffee is ready");

                DateTime s2 = DateTime.Now;
                Console.WriteLine($"Elapsed Time {(s2-s1)}");
            }

            private static async Task<Bacon> FryBaconAsync(int slices)
            {
                Console.WriteLine($"putting {slices} slices of bacon in the pan");
                Console.WriteLine("cooking first side of bacon...");
                await Task.Delay(3000);
                for (int slice = 0; slice < slices; slice++)
                {
                    Console.WriteLine("flipping a slice of bacon");
                }
                Console.WriteLine("cooking the second side of bacon...");
                await Task.Delay(3000);
                Console.WriteLine("Put bacon on plate");

                return new Bacon("Good Bacon");
            }

            private static async Task<Egg> FryEggsAsync(int howMany)
            {
                Console.WriteLine("Warming the egg pan...");
                await Task.Delay(3000);
                Console.WriteLine($"cracking {howMany} eggs");
                Console.WriteLine("cooking the eggs ...");
                await Task.Delay(3000);
                Console.WriteLine("Put eggs on plate");

                return new Egg("Fine Egg");
            }

            private static Coffee PourCoffee()
            {
                Console.WriteLine("Pouring coffee");
                return new Coffee("Smelly coffee");
            }

        }
    }

注意，两个耗时的任务修改的返回类型 Task<T>，耗时的关键点使用了 await，但 return 返回的还是原样的东西，同时使用了 async 修改函数。这样，在 await Task<T> 时，封闭的回调函数就知道如果将 return 的返回值传送给执行任务一方。

注意，为了执行 await Tast<T> 等待异步任务，需要将入口函数 Main 也修改为 async 修饰的异步函数。

任务的执行，还有 Task.WenAll 和 Task.WhenAny 两种方式：

    await Task.WhenAll(eggsTask, baconTask);
    
    List<Task> breakfastTasks = new List<Task>{ eggsTask, baconTask};
    while (breakfastTasks.Count>0)
    {
        Task finishedTask = await Task.WhenAny(breakfastTasks);
        breakfastTasks.Remove(finishedTask);

        if (finishedTask == eggsTask)
        {
            Console.WriteLine("eggs are ready");
        }
        else if (finishedTask == baconTask)
        {
            Console.WriteLine("bacon is ready");
        }
    }

以下特征总结了示例成为异步方法的原因：

- 方法签名包含 async 修饰符。
- 按照约定，异步方法的名称以 Async 后缀结尾。
- 返回类型为下列类型之一：

    - 如果你的方法有操作数为 TResult 类型的返回语句，则为 Task<TResult>。
    - 如果你的方法没有返回语句或具有没有操作数的返回语句，则为 Task。
    - void：如果要编写异步事件处理程序。
    - 包含 GetAwaiter 方法的其他任何类型（自 C# 7.0 起）。

- 方法通常包含至少一个 await 表达式，该表达式标记一个点，在该点上，直到等待的异步操作完成方法才能继续。 同时，将方法挂起，并且控制返回到方法的调用方。 本主题的下一节将解释悬挂点发生的情况。


另一个例子，Razor Component 组件文档修改而来，模拟天气预报数据获取，Enumerable.Range 产生的数据使用了 Linq 方式处理：

    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Threading.Tasks;

    namespace demo
    {
        public class WeatherForecastService
        {
            private static readonly string[] summaries = new[]
            {
                "Freezing", "Bracing", "Chilly", "Cool", "Mild",
                "Warm", "Balmy", "Hot", "Sweltering", "Scorching"
            };
            
            public static async Task Main()
            {
                Task<WeatherForecast[]> forecastTask = WeatherForecastService.GetForecastAsync(DateTime.Now);
                var o = await forecastTask;
                foreach( var i in o )
                {
                    Console.WriteLine(i.Summary);
                }
            }
            public static async Task<WeatherForecast[]> GetForecastAsync(DateTime startDate)
            {
                var rng = new Random();

                await Task.Delay(TimeSpan.FromSeconds(5));

                return Enumerable.Range(1, 5).Select(index => new WeatherForecast
                {
                    Date = startDate.AddDays(index),
                    TemperatureC = rng.Next(-20, 55),
                    Summary = summaries[rng.Next(summaries.Length)]
                }).ToArray();
            }
        }

        public class WeatherForecast
        {
            public DateTime Date { get; set; }

            public int TemperatureC { get; set; }

            public int TemperatureF => 32 + (int)(TemperatureC / 0.5556);

            public string Summary { get; set; }
        }
    }


异步编程模式主题概述了 .NET 支持的三个异步编程模式：

- 异步编程模型 (APM)（旧版）
- 基于事件的异步模式 (EAP)（旧版）
- 基于任务的异步模式 (TAP)（建议用于新开发）

从 .NET Framework 4 开始，任务并行库为异步和并行编程提供了一种新模型， Task Parallel Library (TPL) 和 Task-based Asynchronous Pattern (TAP)。

任务并行库 (TPL) 是 System.Threading 和 System.Threading.Tasks 空间中的一组公共类型和 API。 TPL 的目的是通过简化将并行和并发添加到应用程序的过程来提高开发人员的工作效率。 TPL 动态缩放并发的程度以最有效地使用所有可用的处理器。 此外，TPL 还处理工作分区、ThreadPool 上的线程调度、取消支持、状态管理以及其他低级别的细节操作。 通过使用 TPL，你可以在将精力集中于程序要完成的工作，同时最大程度地提高代码的性能。

自 .NET Framework 4 起，首选 TPL 编写多线程代码和并行代码。 但是，并不是所有代码都适合并行化；例如，如果某个循环在每次迭代时只执行少量工作，或它在很多次迭代时都不运行，那么并行化的开销可能导致代码运行更慢。 此外，像任何多线程代码一样，并行化会增加程序执行的复杂性。 尽管 TPL 简化了多线程方案，但我们建议你对线程处理概念（例如，锁、死锁和争用条件）进行基本的了解，以便能够有效地使用 TPL。


await 运算符暂停对其所属的 async 方法的求值，直到其操作数表示的异步操作完成。 异步操作完成后，await 运算符将返回操作的结果（如果有）。 当 await 运算符应用到表示已完成操作的操作数时，它将立即返回操作的结果，而不会暂停其所属的方法。 await 运算符不会阻止计算异步方法的线程。 当 await 运算符暂停其所属的异步方法时，控件将返回到方法的调用方。
在下面的示例中，HttpClient.GetByteArrayAsync 方法返回 `Task<byte[]>` 实例，该实例表示在完成时生成字节数组的异步操作。 在操作完成之前，await 运算符将暂停 DownloadDocsMainPageAsync 方法。 当 DownloadDocsMainPageAsync 暂停时，控件将返回到 Main 方法，该方法是 DownloadDocsMainPageAsync 的调用方。 Main 方法将执行，直至它需要 DownloadDocsMainPageAsync 方法执行的异步操作的结果。 当 GetByteArrayAsync 获取所有字节时，将计算 DownloadDocsMainPageAsync 方法的其余部分。 之后，将计算 Main 方法的其余部分。

从 C# 7.1 开始，作为应用程序入口点的 Main 方法可以返回 Task 或 `Task<int>`，使其成为异步的，以便在其主体中使用 await 运算符。 在较早的 C# 版本中，为了确保 Main 方法等待异步操作完成，可以检索由相应的异步方法返回的 Task<TResult> 实例的 Task<TResult>.Result 属性值。 对于不生成值的异步操作，可以调用 Task.Wait 方法。

从 C# 8.0 开始，可使用 await foreach 语句来使用异步数据流。 

    using System;
    using System.Net.Http;
    using System.Threading.Tasks;

    public class AwaitOperator
    {
        public static async Task Main()
        {
            Task<int> downloading = DownloadDocsMainPageAsync();
            Console.WriteLine($"{nameof(Main)}: Launched downloading.");

            int bytesLoaded = await downloading;
            Console.WriteLine($"{nameof(Main)}: Downloaded {bytesLoaded} bytes.");
        }

        private static async Task<int> DownloadDocsMainPageAsync()
        {
            Console.WriteLine($"{nameof(DownloadDocsMainPageAsync)}: About to start downloading.");

            var client = new HttpClient();
            byte[] content = await client.GetByteArrayAsync("https://docs.microsoft.com/en-us/");

            Console.WriteLine($"{nameof(DownloadDocsMainPageAsync)}: Finished downloading.");
            return content.Length;
        }
    }

    // Output similar to:
    // DownloadDocsMainPageAsync: About to start downloading.
    // Main: Launched downloading.
    // DownloadDocsMainPageAsync: Finished downloading.
    // Main: Downloaded 27700 bytes.

上一个示例使用异步 Main 方法，该方法从 C# 7.1 开始可用。


## Task & CancellationToken

异步请求中，可在创建 Task 时传入一个 CancellationToken 令牌对象，以控制如何结束请求，如果 CancellationToken 在 Task 调度前取消，那么 Task 就会被取消永远都不执行。





## JSON 处理
- [.NET JSON 序列化和反序列化](https://docs.microsoft.com/zh-cn/dotnet/standard/serialization/system-text-json-overview)

System.Text.Json 命名空间提供用于序列化和反序列化 JavaScript 对象表示法 (JSON) 的功能。该库是作为 .NET Core 3.0 共享框架的一部分内置的。

    using System;
    using System.Linq;
    using System.Text.Json;
    using System.Text.Json.Serialization;
    using System.Collections.Generic;

    public class FlagsEnumExample
    {
        public static void Main()
        {

            // JObject staff = new JObject();
            //         staff.Add(new JProperty("Name", "Newtonsoft.Json"));
            //         staff.Add(new JProperty("Age", 33));
            //         staff.Add(new JProperty("Department", "Personnel Department"));
            //         staff.Add(new JProperty("Leader", new JObject(new JProperty("Name", "Tom"), new JProperty("Age", 44), new JProperty("Department", "Personnel Department"))));
            //         Console.WriteLine(staff.ToString());

            // int[,] msg = new int[2,3]{{1, 2, 3},{4, 5, 6}}; // Rectangular Array Is Not Supported
            // int[][] msg = new int[][]{new int[]{1, 2, 3}, new int[]{4, 5, 6}}; // Array OK
            // var msg = (a: "xyz", b: new int[3]{1, 2, 3} ); // to be {}
            // (String a, int[] b) msg = ("XYZ", new int[]{1, 2, 3}); // this named tuple to be {}
            // var msg = new ValueTuple<String, int[]>("XYZ", new int[]{1, 2, 3}); // to be {}
            // var msg = new Tuple<String, int[], Tuple<String, int>>("XYZ", new int[]{1, 2, 3}, Tuple.Create("ABC", 123)); // OK! {"Item1": "XYZ"...}
            var msg = new { a = "XYZ", b = new int[]{1, 2, 3}, c = new {s = "ABC", k = 123} }; // anonymous type OK! {"a": "XYZ"...}
            
            byte[] jsonUtf8Bytes;
            var options = new JsonSerializerOptions
            {
                WriteIndented = true
            };

            jsonUtf8Bytes = JsonSerializer.SerializeToUtf8Bytes(msg, options);
            Console.WriteLine(System.Text.Encoding.UTF8.GetString(jsonUtf8Bytes));


            var utf8Reader = new Utf8JsonReader(jsonUtf8Bytes);
            var myjson = JsonSerializer.Deserialize<MyJSON>(ref utf8Reader);
            // Console.WriteLine("{0}, {1}, {2}.", myjson.a, myjson.b, myjson.c);
            Console.WriteLine($"{myjson.a}, {myjson.b}, {myjson.c.s}.");
        }

        public class MyJSON
        {
            public string a { get; set; }
            public int[] b { get; set; }
            public inner c { get; set; }

            public class inner
            {
                public string s { get; set; }
                public int k { get; set; }
            }
        }
        
    }



库还提供了用于处理内存中文档对象模型 (DOM) 的类。 此功能允许对 JSON 文件或字符串中的元素进行随机只读访问。

库的设计强调对广泛的功能集实现高性能和低内存分配。 内置的 UTF-8 支持可优化读写以 UTF-8 编码的 JSON 文本的过程，UTF-8 编码是针对 Web 上的数据和磁盘上的文件的最普遍的编码方式。

Newtonsoft.Json 可以迁移到 System.Text.Json。如果之前项目使用的是 Newtonsoft.Json, 升级建议继续使用 Newtonsoft.Json, 如果是新项目或者想少个三方依赖, 可以试试 System.Text.Json, 毕竟更轻量性能更好。与 JToken（如 JObject、JArray）相比的 JsonDocument 和 JsonElement

System.Text.Json 命名空间包含所有入口点和主要类型。 System.Text.Json.Serialization 命名空间包含用于高级方案的特性和 API，以及特定于序列化和反序列化的自定义。

System.Text.Json.JsonDocument 提供从现有 JSON 有效负载分析和生成只读 文档对象模型 (DOM) 的功能。 DOM 提供对 JSON 有效负载中的数据的随机访问。 可以通过 JsonElement 类型访问构成有效负载的 JSON 元素。 JsonElement 类型提供用于将 JSON 文本转换为常见 .NET 类型的 API。 JsonDocument 公开了 RootElement 属性。

大多数序列化示例代码将 JsonSerializerOptions.WriteIndented 设置为 true，以 JSON 进行优质打印（包含缩进和空格，以提高可读性）。 对于生产用途，通常对于此设置会接受默认值 false。

Utf8JsonReader、Utf8JsonWriter 和 JsonDocument

System.Text.Json.Utf8JsonReader 是面向 UTF-8 编码 JSON 文本的一个高性能、低分配的只进读取器，从 ReadOnlySpan<byte> 或 ReadOnlySequence<byte> 读取信息。 Utf8JsonReader 是一种低级类型，可用于生成自定义分析器和反序列化程序。 JsonSerializer.Deserialize 方法在后台使用 Utf8JsonReader。

System.Text.Json.Utf8JsonWriter 是一种高性能方式，从常见 .NET 类型（例如，String、Int32 和 DateTime）编写 UTF-8 编码的 JSON 文本。 该编写器是一种低级类型，可用于生成自定义序列化程序。 JsonSerializer.Serialize 方法在后台使用 Utf8JsonWriter。

System.Text.Json.JsonDocument 提供使用 Utf8JsonReader 生成只读文档对象模型 (DOM) 的功能。 DOM 提供对 JSON 有效负载中的数据的随机访问。 可以通过 JsonElement 类型访问构成有效负载的 JSON 元素。 JsonElement 类型提供数组和对象枚举器，以及用于将 JSON 文本转换为常见 .NET 类型的 API。 JsonDocument 公开了 RootElement 属性。


反序列化，读入 JSON：

    jsonString = File.ReadAllText(fileName);
    usertype = JsonSerializer.Deserialize<UserType>(jsonString);

若要使用异步代码从文件进行反序列化，请调用 DeserializeAsync 方法：

    using (FileStream fs = File.OpenRead(fileName))
    {
        usertype = await JsonSerializer.DeserializeAsync<UserType>(fs);
    }

若要从 UTF-8 进行反序列化，请调用采用 Utf8JsonReader 或 ReadOnlySpan<byte> 的 JsonSerializer.Deserialize 重载，如下面的示例中所示。 这些示例假设 JSON 处于名为 jsonUtf8Bytes 的字节数组中。

    var readOnlySpan = new ReadOnlySpan<byte>(jsonUtf8Bytes);
    usertype = JsonSerializer.Deserialize<UserType>(readOnlySpan);

    var utf8Reader = new Utf8JsonReader(jsonUtf8Bytes);
    usertype = JsonSerializer.Deserialize<UserType>(ref utf8Reader);


JsonDocument 处理 JSON 数据：

    double sum = 0;
    int count = 0;

    using (JsonDocument document = JsonDocument.Parse(jsonString))
    {
        JsonElement root = document.RootElement;
        JsonElement studentsElement = root.GetProperty("Students");
        foreach (JsonElement student in studentsElement.EnumerateArray())
        {
            if (student.TryGetProperty("Grade", out JsonElement gradeElement))
            {
                sum += gradeElement.GetDouble();
            }
            else
            {
                sum += 70;
            }
            count++;
        }
    }

    double average = sum / count;
    Console.WriteLine($"Average grade : {average}");

通过 JsonDocument 写入 JSON：

    string jsonString = File.ReadAllText(inputFileName);

    var writerOptions = new JsonWriterOptions
    {
        Indented = true
    };

    var documentOptions = new JsonDocumentOptions
    {
        CommentHandling = JsonCommentHandling.Skip
    };

    using FileStream fs = File.Create(outputFileName);
    using var writer = new Utf8JsonWriter(fs, options: writerOptions);
    using JsonDocument document = JsonDocument.Parse(jsonString, documentOptions);

    JsonElement root = document.RootElement;

    if (root.ValueKind == JsonValueKind.Object)
    {
        writer.WriteStartObject();
    }
    else
    {
        return;
    }

    foreach (JsonProperty property in root.EnumerateObject())
    {
        property.WriteTo(writer);
    }

    writer.WriteEndObject();

    writer.Flush();

前面的代码：
读取 JSON 文件，将数据加载到 JsonDocument 中，并将格式化（进行了优质打印的）JSON 写入文件。
使用 JsonDocumentOptions 可指定允许但会忽略输入 JSON 中的注释。
完成后，对编写器调用 Flush。 一种替代方法是让编写器在释放时自动刷新

JSON 数据：

    {
      "Class Name": "Science",
      "Teacher\u0027s Name": "Jane",
      "Semester": "2019-01-01",
      "Students": [
        {
          "Name": "John",
          "Grade": 94.3
        },
        {
          "Name": "James",
          "Grade": 81.0
        },
        {
          "Name": "Julia",
          "Grade": 91.9
        },
        {
          "Name": "Jessica",
          "Grade": 72.4
        },
        {
          "Name": "Johnathan"
        }
      ],
      "Final": true
    }


## Lambda 表达式

lambda 表达式可以理解为内嵌匿名函数，lambda 运算符 => 将左侧的输入参数与右侧的 lambda 主体分开。

=> 令牌支持两种形式：作为 lambda 运算符、作为成员名称的分隔符和表达式主体定义中的成员实现。


    var list = new [] { "aa", "bb", "ac" };
    var result = Array.FindAll(list, s => (s.IndexOf("a") > -1));
    foreach (var v in result)
    Console.WriteLine(v);

使用 Lambda 表达式定义匿名函数：

    class Program
    {
        static void Main(string[] args)
        {
            var names = GetFullName();
            Console.WriteLine($"{names.First} {names.Middle} {names.Last}");
        }

        static (string First, string Middle, string Last) GetFullName() => ("Alen", "Bob", "Robin");
    }

以上匿名函数编译后得到的结果会添加 TupleElementNamesAttribute 作为元组成员的名称映射，本质依然是借助泛型类型来实现的，同时也需要编译器对新语法形式的支持。

    [TupleElementNames(new string[]
    {
            "First",
            "Middle",
            "Last"
    })]
    private static ValueTuple<string, string, string> GetFullName()
    {
        return new ValueTuple<string, string, string>("Alen", "Bob", "Robin");
    }



## LINQ 语言集成查询
- [查询表达式基础](https://docs.microsoft.com/zh-cn/dotnet/csharp/linq/query-expression-basics)
- [语言集成查询 LINQ](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/linq/)
- [查询关键字](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/query-keywords)
- [System.Linq 命名空间](https://docs.microsoft.com/zh-cn/dotnet/api/system.linq?view=netcore-3.1)
- [`IEnumerable<T>`](https://docs.microsoft.com/en-us/dotnet/api/system.collections.generic.ienumerable-1?view=netcore-3.1)
- [`IQueryable<T>`](https://docs.microsoft.com/en-us/dotnet/api/system.linq.iqueryable-1?view=netcore-3.1)
- [`IGrouping<TKey,TElement>`](https://docs.microsoft.com/en-us/dotnet/api/system.linq.igrouping-2?view=netcore-3.1)

语言集成查询 LINQ - Language Integrated Query 是一系列查询功能集成到 C# 语言的技术统称。从技术角度而言，LINQ定义了大约40个查询操作符，如 select/from/in/where/order by 等，使用这些操作符可以编写查询语句。熟悉 SQL 数据查询语言就更容易理解什么是 LINQ，不过，这些查询还可以基于很多类型的数据，每个数据类型都需要一个单独的 LINQ 类型。

匿名类型 Anonymous type 是 C# 3.0 新增的功能，它允许开发人员可以使用不具类型的方式创建新的数据结构，而真正的类型在编译时期，由 C# Compiler 自动产生，并写入编译目标文件中，它可以让开发人员能够很简单利用匿名类型创建对象，LINQ 中的 select 指令即是利用这种特性来创建回传对象。

数据查询历来都表示为简单的字符串，没有编译时类型检查或 IntelliSense 支持。 此外，需要针对每种类型的数据源了解不同的查询语言：SQL 数据库、XML 文档、各种 Web 服务等。 借助 LINQ，查询成为了最高级的语言构造，就像类、方法和事件一样。 可以使用语言关键字和熟悉的运算符针对强类型化对象集合编写查询。 LINQ 系列技术提供了针对对象 (LINQ to Objects)、关系数据库 (LINQ to SQL) 和 XML (LINQ to XML) 的一致查询体验。

查询 是一组指令，描述要从给定数据源（或源）检索的数据以及返回的数据应具有的形状和组织。 查询与它生成的结果不同。 通常情况下，源数据按逻辑方式组织为相同类型的元素的序列。 例如，SQL 数据库表包含行的序列。 在 XML 文件中，存在 XML 元素的“序列”（尽管这些元素在树结构按层次结构进行组织）。 内存中集合包含对象的序列。


对于编写查询的开发者来说，LINQ 最明显的“语言集成”部分就是查询表达式。 查询表达式采用声明性查询语法编写而成。 使用查询语法，可以用最少的代码对数据源执行筛选、排序和分组操作。 可使用相同的基本查询表达式模式来查询和转换 SQL 数据库、ADO .NET 数据集、XML 文档和流以及 .NET 集合中的数据。

在 C# 中可为以下对象编写 LINQ 查询：SQL Server 数据库、XML 文档、ADO.NET 数据集以及支持 IEnumerable 或泛型 IEnumerable<T> 接口的任何对象集合。 此外，第三方也为许多 Web 服务和其他数据库实现提供了 LINQ 支持。

foreach 可以枚举的数据都可以使用 Linq 处理， IEnumerable or IEnumerable<T>，还有子类如 IQueryable<T> 。 

所有 LINQ 查询操作都由以下三个不同的操作组成，它们和 IEnumerable or IEnumerable<T> 提供的成员方法基本对应：

- 获取数据源，使用 from 或者直接 select。
- 创建查询，使用 where/join/group/orderby 等，并以 select 或 group 结束。
- 执行查询，使用 ToArray()/ToList() 等。


Linq 可以使用的查询关键字列表：

| Clause    | Description |
| :-------- | :---------- |
| from  | 指定数据源，或变量区间 |
| where | 过滤条件，使用逻辑运算 AND and OR( && or || ) 返回 Boolean 的表达式 |
| select    | 查询被执行时，选择要输出的数据 |
| group | 根据 by 指定的 Key 进行分组 |
| into  | 为 join, group 或者 select 从句提供一个标识符号以供引用数据 |
| orderby   | 可以使用 orderby 对分数据进行排序 ascending 或者 descending 指定升或降序|
| join  | 根据 on 指定的条件对两个数据源进行联合操作 |
| let   | 指定变量区间以存储查询子表达式的结果 |
| in    | Contextual keyword in a join clause. |
| on    | Contextual keyword in a join clause. |
| equals    | Contextual keyword in a join clause. |
| by    | Contextual keyword in a group clause. |
| ascending | Contextual keyword in an orderby clause. |
| descending    | Contextual keyword in an orderby clause. |


以下是 Linq 需要的三个基本类空间，主要是 System.Linq，其它两个提供基本的数据类型定义：

    using System;
    using System.Collections;
    using System.Linq;

强制立即执行，Count、Max、Average 和 First 就属于此类查询。对一系列源元素执行聚合函数的查询必须首先循环访问这些元素。  由于查询本身必须使用 foreach 以便返回结果，因此这些查询在执行时不使用显式 foreach 语句。 另外还要注意，这些类型的查询返回单个值，而不是 IEnumerable 集合。 

    int[] numbers = {1,2,3,4,5}; // Enumerable.Range(1, 5)
    Console.WriteLine("Average {0}", numbers.Average());

为了理解命名空间引入 C# 扩展方法的作用，可以先将 System.Linq 注解，编译就会发现，numbers 数据根本没有 Select 方法，这是因为它是 System.Linq 扩展数组得来的方法，只有引入命名空间后才可以使用：

    using System;
    using System.Linq;

    class Example
    {
        public static void Main()
        {
            int[] numbers = new int[]{2, 2, 3, 4, 5};
            var a = numbers.Select( i => new string('*', i));
            Console.WriteLine(string.Join(",",a));
        }
    }

下面的查询返回源数组中偶数的计数：

    var evenNumQuery =
        from num in numbers
        where (num % 2) == 0
        select num;

    int evenNumCount = evenNumQuery.Count();

要强制立即执行任何查询并缓存其结果，可调用 ToList 或 ToArray 方法。

    List<int> numQuery2 =
        (from num in numbers
         where (num % 2) == 0
         select num).ToList();

    // or like this:
    // numQuery3 is still an int[]

    var numQuery3 =
        (from num in numbers
         where (num % 2) == 0
         select num).ToArray();

下面的示例展示了完整的查询操作。 完整的操作包括创建数据源、定义查询表达式和在 foreach 语句中执行查询。

    // Specify the data source
    // int[] numbers = { 5, 4, 1, 3, 9, 8, 6, 7, 2, 0 };
    int[] scores = new int[] { 97, 92, 81, 60 };

    // Define the query expression.
    IEnumerable<int> scoreQuery =
        from score in scores
        where score > 80
        select score;

    // Execute the query.
    // Output: 97 92 81
    foreach (int i in scoreQuery)
    {
        Console.Write(i + " ");
    }

结合了 Lambda 表达式的 Linq 字符串处理：

    string[] words = { "bot", "apple", "apricot" };
    int minimalLength = words
      .Where(w => w.StartsWith("a"))
      .Min(w => w.Length);
    Console.WriteLine(minimalLength);   // output: 5

    int[] numbers = { 1, 4, 7, 10 };
    int product = numbers.Aggregate(1, (interim, next) => interim * next);
    Console.WriteLine(product);   // output: 280

分割字符串的 Linq 处理方式：

    Console.WriteLine("Linq data".Select((char i)=>{
        Console.WriteLine(i);
        return i;
    }).ToList());

使用 let 关键字保存子查询的临时数据，例子查找以无音字母开头的单词，其中 `let words` 保存了分割好的字符串：

    string[] strings =
    {
        "A penny saved is a penny earned.",
        "The early bird catches the worm.",
        "The pen is mightier than the sword."
    };

    // Split the sentence into an array of words
    // and select those whose first letter is a vowel.
    var earlyBirdQuery =
        from sentence in strings
        let words = sentence.Split(' ')
        from word in words
        let w = word.ToLower()
        where (new char[]{'a', 'e', 'i', 'o', 'u'}).Contains(w[0])
        select word;

    // Execute the query.
    foreach (var v in earlyBirdQuery)
    {
        Console.WriteLine("\"{0}\" starts with a vowel", v);
    }

两种不同的风格，Linq 风格，和 IEnumerable<TSource> 方法调用风格：

    using System;
    using System.Linq;

    namespace demo
    {
        public class LinqStyle
        {
            public static void Main()
            {
                // Linq Style
                Func<int, bool> IsEven = delegate (int i){ return i%2==0; };
                var q = from num in "Enumerable.Range(1, 5)" where IsEven(num) select (int)num;
                Console.WriteLine("Average {0}", q.Average());

                // IEnumerable<TSource> Method Style
                string assembly = typeof(LinqStyle).Assembly.ToString();
                int count = assembly.Select(
                    (char i)=>{
                        Console.Write("{0} -> ", i);
                        return (int)i;
                    }
                ).Count(
                    (int i)=>{
                        bool filter = i == 'i';
                        if (filter)
                        {
                            Console.WriteLine("Filtered {0} {1}", i, filter);
                        }
                        return filter;
                    }
                );
                Console.WriteLine("Count {0}", count);
            }
        }
    }

### Linq & Join 联合查询

非同等联接通过使用多个 from 子句将新序列单独引入查询，可以执行非同等联接、交叉联接和其他自定义联接操作。

Cross Join 交叉联接，Non-Equijoin 非等值连接示例：

    char[] upperCase = { 'A', 'B', 'C' };
    char[] lowerCase = { 'x', 'y', 'z' };

    // The type of joinQuery1 is IEnumerable<'a>, where 'a
    // indicates an anonymous type with {char upper, char lower}.
    var joinQuery1 =
        from upper in upperCase
        from lower in lowerCase
        select new { upper, lower };

    // The type of joinQuery2 is IEnumerable<'a>, where 'a
    // indicates an anonymous type with {char lower, char upper}.
    var joinQuery2 =
        from lower in lowerCase
        where lower != 'x'
        from upper in upperCase
        select new { lower, upper };

    // Execute the queries.
    Console.WriteLine("Cross join:");
    foreach (var pair in joinQuery1)
    {
        Console.WriteLine("{0} is matched to {1}", pair.upper, pair.lower);
    }

    Console.WriteLine("Filtered non-equijoin:");
    foreach (var pair in joinQuery2)
    {
        Console.WriteLine("{0} is matched to {1}", pair.lower, pair.upper);
    }

    // Keep the console window open in debug mode.
    Console.WriteLine("Press any key to exit.");
    try{
        Console.ReadKey();
    } catch { }

join 子句执行的所有联接都是同等联接，将 2 个源序列作为输入。 每个序列中的元素都必须是可以与其他序列中的相应属性进行 equals 比较的属性，或者包含一个这样的属性。join 子句执行同等联接，换言之，只能基于 2 个项之间的相等关系进行匹配。 不支持其他类型的比较，例如大于或不等于。 为了表明所有联接都是同等联接，join 子句使用 equals 关键字而不是 == 运算符。 equals 关键字只能在 join 子句中使用，并且其与 == 运算符之间存在一个重要差别。 对于 equals，左键使用外部源序列，而右键使用内部源序列。 外部源仅在 equals 的左侧位于范围内，而内部源序列仅在其右侧位于范围内。

join 子句的输出形式取决于执行的联接的具体类型，以下是 3 种最常见的联接类型：

- Inner join 内部联接

    以下示例演示了一个简单的内部同等联接。 此查询从 categories/products 两个数据源生成一个产品名称/类别对平面序列。 同一类别字符串将出现在多个元素中，即 categories 中的类别可可能对应多表产品，那么联接后的平面序列中这些产品都包含分类信息。 如果 categories 中的某个元素没有匹配的 products，则该类别不会出现在结果中。

        var innerJoinQuery =
            from category in categories
            join prod in products on category.ID equals prod.CategoryID
            select new { ProductName = prod.Name, Category = category.Name }; // produces flat sequence

- Group join 分组联接

    含有 into 表达式的 join 子句称为分组联接。

    分组联接会生成分层的结果序列，该序列将左侧源序列中的元素与右侧源序列中的一个或多个匹配元素相关联。 分组联接没有等效的关系术语；它本质上是一个对象数组序列。

        var innerGroupJoinQuery =
            from category in categories
            join prod in products on category.ID equals prod.CategoryID into prodGroup
            select new { CategoryName = category.Name, Products = prodGroup };


- Left outer join 左外部连接

    在左外部联接中，将返回左侧源序列中的所有元素，即使右侧序列中没有其匹配元素也是如此。 若要在 LINQ 中执行左外部联接，请结合使用 `DefaultIfEmpty` 方法与分组联接，指定要在某个左侧元素不具有匹配元素时生成的默认右侧元素。 可以使用 null 作为任何引用类型的默认值，也可以指定用户定义的默认类型。

    以下示例演示了用户定义的默认类型：

        var leftOuterJoinQuery =
            from category in categories
            join prod in products on category.ID equals prod.CategoryID into prodGroup
            from item in prodGroup.DefaultIfEmpty(new Product { Name = String.Empty, CategoryID = 0 })
            select new { CatName = category.Name, ProdName = item.Name };

`DefaultIfEmpty` 的使用主要是为了避免空引用引起程序异常，向查询填充一个默认的数据对象，保证查询为空时返回这个默认数据对象，看以下例程演示。

    class Pet
    {
        public string Name { get; set; }
        public int Age { get; set; }
    }


    // Create a list of Pet objects.
    List<Pet> pets =
        new List<Pet>{ new Pet { Name="Barley", Age=8 },
                       new Pet { Name="Boots", Age=4 },
                       new Pet { Name="Whiskers", Age=1 } };

    // This query selects only those pets that are 10 or older.
    // In case there are no pets that meet that criteria, call
    // DefaultIfEmpty(). This code passes an (optional) default
    // value to DefaultIfEmpty().
    string[] oldPets =
        pets.AsQueryable()
        .Where(pet => pet.Age >= 10)
        .Select(pet => pet.Name)
        .DefaultIfEmpty("[EMPTY]")
        .ToArray();

    Console.WriteLine("First query: " + oldPets[0]);

    // This query selects only those pets that are 10 or older.
    // This code does not call DefaultIfEmpty().
    string[] oldPets2 =
        pets.AsQueryable()
        .Where(pet => pet.Age >= 10)
        .Select(pet => pet.Name)
        .ToArray();

    try
    {
        Console.WriteLine("Second query: " + oldPets2[0]);
    }
    catch (Exception e)
    {
        Console.WriteLine("Second query: An exception was thrown: " + e.Message);
    }

各种联合操作的示例：

    using System;
    using System.Collections;
    using System.Collections.Generic;
    using System.Linq;

    class CompoundFrom
    {
        public class Student
        {
            public int ID { get; set; }
            public string LastName { get; set; }
            public List<int> Scores {get; set; }
        }

        public class ContactInfo
        {
            public int ID { get; set; }
            public string Email { get; set; }
            public string Phone {get; set; }
        }

        private static List<Student> students = new List<Student>
        {
            new Student {ID=111, LastName="Omelchenko", Scores= new List<int> {97, 72, 81, 60}},
            new Student {ID=112, LastName="O'Donnell", Scores= new List<int> {75, 84, 91, 39}},
            new Student {ID=113, LastName="Mortensen", Scores= new List<int> {88, 94, 65, 85}},
            new Student {ID=114, LastName="Garcia", Scores= new List<int> {97, 89, 85, 82}},
            new Student {ID=115, LastName="Beebe", Scores= new List<int> {35, 72, 91, 70}}
        };

        private static List<ContactInfo> contacts = new List<ContactInfo>()
        {
            new ContactInfo {ID=111, Email="SvetlanO@Contoso.com", Phone="206-555-0108"},
            new ContactInfo {ID=112, Email="ClaireO@Contoso.com", Phone="206-555-0298"},
            new ContactInfo {ID=113, Email="SvenMort@Contoso.com", Phone="206-555-1130"},
            new ContactInfo {ID=115, Email="BeeHive@Contoso.com", Phone="206-555-0521"},
            new ContactInfo {ID=115, Email="BeeHive@gmail.com", Phone="206-555-0522"}
        };

        static void Main()
        {
            ScoreQuery("Score Query");
            DataSample("Data Sample Query");
            InnerJoin("Inner Join Query");
            GroupJoin("Group Join Query");
            LeftOuterJoin("Left Outer Join Query");
            Group("Group Query");

            // Keep the console window open in debug mode.
            Console.WriteLine("Press any key to exit.");
            try{
                Console.ReadKey();
            } catch {} // InvalidOperationException
        }

        public static void ScoreQuery(string title)
        {
            var scoreQuery = from student in students
                             from score in student.Scores
                                where score > 90
                                select new { Last = student.LastName, score };

            SetTitle(title);
            // Execute the queries.
            foreach (var student in scoreQuery)
            {
                Console.WriteLine("{0} Score: {1}", student.Last, student.score);
            }
            Console.Write(System.Environment.NewLine);
        }

        public static void DataSample(string title)
        {
            var query = from an in students
                        let score = string.Join(", ", an.Scores)
                        select string.Format("{0,8} {1,12} {2}", an.ID, an.LastName, score);

            var query2 = from an in contacts
                        select string.Format("{0,8} {1,24} {2}", an.ID, an.Email, an.Phone);

            SetTitle(title);
            Console.WriteLine("Students Table as left:");
            Console.WriteLine("{0,8} {1,12} {2}", "ID", "Name", "Scores");
            query.Select((string i) => { Console.WriteLine(i); return i;} ).ToList();
            Console.WriteLine("Contacts Table as right:");
            Console.WriteLine("{0,8} {1,24} {2}", "ID", "Email", "Phone");
            query2.Select((string i) => { Console.WriteLine(i); return i;} ).ToList();

            Console.Write(System.Environment.NewLine);

        }

        public static void InnerJoin(string title)
        {
            var innerJoinQuery =
                from student in students
                join item in contacts on student.ID equals item.ID
                select new { ID = student.ID, Name = student.LastName, Email = item.Email, Phone = item.Phone };

            SetTitle(title);
            foreach (var an in innerJoinQuery)
            {
                Console.WriteLine("{0,8} {1,10}: {2,24} {3,16}", an.ID, an.Name, an.Email, an.Phone);
            }
            Console.Write(System.Environment.NewLine);
        }

        public static void GroupJoin(string title)
        {
            var groupJoinQuery =
                from student in students
                join item in contacts on student.ID equals item.ID into items
                
                // Items is an IEnumerable<IGrouping<int, ContactInfo>>
                // select items;

                // produces flat sequence
                // select new { Name = student.LastName, Items = items };

                // with custom
                select new {
                    Name = student.LastName, 
                    // Items = items,
                    Items = from it in items
                            orderby it.Email ascending
                            select it
                };

            SetTitle(title);
            foreach (var an in groupJoinQuery)
            {
                // Console.WriteLine("Group Count: {0}", an.Count());
                // foreach (var item in an)
                // {
                //  Console.WriteLine(" {0}: {1,24} {2,16}", item.ID, item.Email, item.Phone);
                // }

                // var count = an.Items.Count();
                // var email = string.Join(", ", an.Items.Select( i => i.Email ));
                // // var email = count>0? an.Items.First().Email:null;
                // var many = count==1? "has an":count==0?"has no any":"has many";
                // Console.WriteLine("{0,10} {2,10} Email {1}", an.Name, email, many);
                
                Console.WriteLine("Items Count: {0}", an.Items.Count());
                foreach (var item in an.Items)
                {
                    Console.WriteLine("{0,8}: {1,24} {2,16}", item.ID, item.Email, item.Phone);
                }
            }
            Console.Write(System.Environment.NewLine);
        }

        public static void LeftOuterJoin(string title)
        {
            var leftOuterJoinQuery =
                from student in students
                join item in contacts on student.ID equals item.ID into g

                // with DefaultIfEmpty<TSource>(IEnumerable<TSource>)
                // Query variable is an IEnumerable<IGrouping<int, ContactInfo>>
                // select g.DefaultIfEmpty(new ContactInfo { Email = String.Empty,  ID = student.ID });
                // select g.DefaultIfEmpty(); // null as default

                // produces flat sequence
                // Query variable is an IEnumerable<AnonymousType>
                from item in g.DefaultIfEmpty()
                orderby student.LastName ascending // descending
                select new { ID = student.ID, Name = student.LastName, Email = item?.Email, Phone = item?.Phone };

            SetTitle(title);
            foreach (var an in leftOuterJoinQuery)
            {
                // Console.WriteLine("Group Count: {0}", an.Count());
                // foreach (var item in an)
                // {
                //  Console.WriteLine(" Contact for {0}: {1,24} {2,16}", item.ID, item.Email, item.Phone);
                // }

                // display data from flat sequence
                Console.WriteLine("Contact for {0} {1,10}: {2,24} {3,16}", an.ID, an.Name, an.Email, an.Phone);
            }
            Console.Write(System.Environment.NewLine);
        }

        public static void Group(string title)
        {
            // Group students by the first letter of their last name
            // Query variable is an IEnumerable<IGrouping<char, Student>>
            var groupedQuery =
                from student in students
                group student by student.LastName[0] into g
                orderby g.Key ascending // descending
                select g;

            SetTitle(title);
            foreach (IGrouping<char, Student> g in groupedQuery)
            {
                foreach (var student in g)
                {
                    Console.WriteLine("{0,10} group by {1}", student.LastName, g.Key);
                }
            }
            Console.Write(System.Environment.NewLine);
        }

        static void SetTitle(string title)
        {
            Console.BackgroundColor = ConsoleColor.DarkBlue;
            Console.WriteLine(title);
            Console.ResetColor();
        }
    }

输出：

    Score Query
    Omelchenko Score: 97
    O'Donnell Score: 91
    Mortensen Score: 94
    Garcia Score: 97
    Beebe Score: 91

    Data Sample Query
    Students Table as left:
          ID         Name Scores
     111   Omelchenko 97, 72, 81, 60
     112    O'Donnell 75, 84, 91, 39
     113    Mortensen 88, 94, 65, 85
     114       Garcia 97, 89, 85, 82
     115        Beebe 35, 72, 91, 70
    Contacts Table as right:
          ID                    Email Phone
     111     SvetlanO@Contoso.com 206-555-0108
     112      ClaireO@Contoso.com 206-555-0298
     113     SvenMort@Contoso.com 206-555-1130
     115      BeeHive@Contoso.com 206-555-0521
     115        BeeHive@gmail.com 206-555-0522

    Inner Join Query
         111 Omelchenko:    SvetlanO@Contoso.com     206-555-0108
         112  O'Donnell:     ClaireO@Contoso.com     206-555-0298
         113  Mortensen:    SvenMort@Contoso.com     206-555-1130
         115      Beebe:     BeeHive@Contoso.com     206-555-0521
         115      Beebe:       BeeHive@gmail.com     206-555-0522

    Group Join Query
    Items Count: 1
         111:    SvetlanO@Contoso.com     206-555-0108
    Items Count: 1
         112:     ClaireO@Contoso.com     206-555-0298
    Items Count: 1
         113:    SvenMort@Contoso.com     206-555-1130
    Items Count: 0
    Items Count: 2
         115:     BeeHive@Contoso.com     206-555-0521
         115:       BeeHive@gmail.com     206-555-0522

    Left Outer Join Query
    Contact for 115      Beebe:     BeeHive@Contoso.com     206-555-0521
    Contact for 115      Beebe:       BeeHive@gmail.com     206-555-0522
    Contact for 114     Garcia:                                         
    Contact for 113  Mortensen:    SvenMort@Contoso.com     206-555-1130
    Contact for 112  O'Donnell:     ClaireO@Contoso.com     206-555-0298
    Contact for 111 Omelchenko:    SvetlanO@Contoso.com     206-555-0108

    Group Query
         Beebe group by B
        Garcia group by G
     Mortensen group by M
    Omelchenko group by O
     O'Donnell group by O






# Reflection 反射
- [C# Reflection](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/reflection)
- [C# Type Class](https://docs.microsoft.com/en-us/dotnet/api/system.type?view=netcore-3.1)
- [C# Assembly Class](https://docs.microsoft.com/en-us/dotnet/api/system.reflection.assembly?view=netcore-3.1)
- [Assembly manifest](https://docs.microsoft.com/en-us/dotnet/standard/assembly/manifest)
- [.NET 中的反射](https://docs.microsoft.com/zh-cn/dotnet/framework/reflection-and-codedom/reflection)
- [利用特性扩展元数据](https://docs.microsoft.com/zh-cn/dotnet/standard/attributes/)
- [System Activator](https://docs.microsoft.com/en-us/dotnet/api/system.activator.createinstance)

System.Reflection 命名空间中的类与 System.Type 使你能够获取有关加载的程序集和其中定义的类型的信息，如类、接口和值类型（即结构和枚举）。

反射提供描述程序集、模块和类型的对象（Type 类型）。 可以使用反射动态地创建类型的实例，将类型绑定到现有对象，或从现有对象中获取类型，然后调用其方法或访问器字段和属性。 如果代码中使用了特性，可以利用反射来访问它们。 

下面一个简单的反射示例，使用方法 GetType() 以获取变量类型，所有 Object 基类的类型都继承此方法：

请确保在 .cs 文件顶部添加引用：

    using System;
    using System.Reflection;

    // Using GetType to obtain type information:
    int i = 42;
    Type type = i.GetType();
    Console.WriteLine(type); // Output: System.Int32 

下面的示例使用反射获取已加载的程序集的完整名称。

    // Using Reflection to get information of an Assembly:
    Type type = typeof(int);
    Assembly info = type.Assembly;
    Console.WriteLine(info);

Type 这表类是描述类型的类，它是一个类，但是用途特殊，包含一般类型如 class types /interface types /array types /value type /enumeration type 等等的声明，为反射机制提供基础支持。通过 Type 类型实例，可以根据它提供的声明信息实现被描述类型的各种数据或方法的访问：

    using System;
    using System.Reflection;

    class Example
    {
        static void Main()
        {
            Type t = typeof(String);

            MethodInfo substr = t.GetMethod("Substring", 
                new Type[] { typeof(int), typeof(int) });

            Object result = 
                substr.Invoke("Hello, World!", new Object[] { 7, 5 });
            Console.WriteLine("{0} returned \"{1}\".", substr, result);
        }
    }

反射与泛型：

    using System;
    using System.Linq;
    using System.Reflection;
    using System.Collections.Generic;
    using System.Security;

    public class MyClass
    {
        class Wraper<T>
        {
            public T target;

            public Wraper(T i)
            {
                target = i;
            }
            public void Log(){
                Console.WriteLine("Log target {0}", target);
            }
        }


        public static void Main()
        {
            // 使用 Reflection 创建泛型类的实例
            Type elType = typeof(MyClass); // Type.GetType(new MyClass())
            Type genType = typeof(Wraper<>).MakeGenericType(elType);
            object obj = Activator.CreateInstance(genType, new[]{ new MyClass() });

            //调用对象的方法
            MethodInfo method = genType.GetMethod("Log",BindingFlags.Instance | BindingFlags.Public);
            method.Invoke(obj, null);
        }
    }


程序集包含模块、模块包含类型，而类型包含成员。 反射提供封装程序集、模块和类型的对象。 可以使用反射动态地创建类型的实例，将类型绑定到现有对象，或从现有对象中获取类型。 然后，可以调用类型的方法或访问其字段和属性。 反射的典型用法如下所示：

- `Assembly` 用来定义和加载程序集，加载程序集清单中列出的模块，以及在此程序集中定位一个类型并创建一个它的实例。包括打包在程序集的数据或流资源的读取：

    - `GetManifestResourceInfo(String)`
    - `GetManifestResourceNames()`
    - `GetManifestResourceStream(String)`
    - `GetManifestResourceStream(Type, String)`

- `Module` 用来发现信息，如包含模块的程序集和模块中的类。 还可以获取所有全局方法或模块上定义的其它特定的非全局方法。
- `ConstructorInfo` 用来发现信息，如名称 ConstructorName、参数、访问修饰符如 IsPublic 或 IsPrivate 和构造函数的实现信息如 IsAabstract 或 IsVirtual。 使用 Type 类型的 GetConstructors 或 GetConstructor 方法来获取构造器信息。
- `MethodInfo` 用来发现方法信息，如名称、返回类型、参数、访问修饰符（如 public 或 private）和方法的实现详细信息（如 abstract 或 virtual）。 使用 Type 的 GetMethods 或 GetMethod 方法来获取特定方法信息。

- `FieldInfo` 用来发现信息，如名称、访问修饰符（如 public 或 private）和一个字段的实现详细信息 （如 static）；并获取或设置字段值。

- `EventInfo` 用来发现信息（如名称、事件处理程序的数据类型、自定义特性、声明类型以及事件的反射的类型），并添加或删除事件处理程序。
- `PropertyInfo` 用来发现信息（如名称、数据类型、声明类型，反射的类型和属性的只读或可写状态），并获取或设置属性值。
- `ParameterInfo` 用来发现参数信息，如参数的名称 Name、 ParameterType、参数是输入参数 IsIn 还是输出参数 IsOut 以及参数在方法签名中的位置 Position。
- `CustomAttributeData` 用于应用程序域的仅反射上下文中工作时发现有关自定义特性的信息。 CustomAttributeData 使你能够检查特性，而无需创建它们的实例。

GetFilds 这类方法可能获取不到想要的数据，RuntimeReflectionExtensions
提供了相应的运行时版本扩展方法，GerRuntimeFields/Method/Properties 等。

利用反射技术可以调用对象的构造函数执行实例化，System.Activator 提供了更简单的静态方法 CreateInstance 或 CreateInstanceFrom 来做实例化，有许多重载方法只可以使用。

    public static System.Runtime.Remoting.ObjectHandle CreateInstanceFrom (string assemblyFile, string typeName, object[] activationAttributes);

实例化一个类的方式有多种，常见的用 New 关键字实例化一个类，用 Activator 实例化一个类以在本地或从远程创建对象，是比较有效率的一种方法。

程序集 Assembly 可重用、无版本冲突并且可自我描述的公共语言运行库应用程序构造块。该类可以加载程序集、浏览程序集的元数据和构成部分、发现程序集中包含的类型以及创建这些类型的实例。加载程序集的推荐方式是使用 Load 方法。GetType 方法可用于在程序集中搜索特定类型。CreateInstance 方法可用于在程序集中搜索和创建类型的实例。


示例，获取任意对象的构造器、方法、字段、属性，但不包含扩展方法，成员包括了构造器和属性，属性或字段可以通过 GetValue 获取其值：


    using System;
    using System.Linq;
    using System.Reflection;

    class Demo
    {
        static void Main(){
            Reflected(new System.Drawing.Color());
        }
        public static void Reflected(object obj)
        {
            Type it = obj.GetType();
            Console.WriteLine($"# {it.FullName}"); 

            var constructors = it.GetConstructors().OrderBy(c => c.GetParameters().Length).ToList();
            Console.WriteLine($"\n## Constructors Found {constructors.Count()}:"); 
            constructors.Select(e => {
                Console.WriteLine("### {0}", e); 
                return e;
                }).Count();

            var methods = it.GetMethods().OrderBy(c => c.GetParameters().Count()).ToList();
            Console.WriteLine($"\n## Methods Found {methods.Count()}:"); 
            foreach (var mi in methods)
            {
                Console.WriteLine("### {0} {1}", mi.IsPublic?"public":"", mi);
            }

            var props = it.GetProperties().OrderBy(c => c.Name).ToList();
            Console.WriteLine($"\n## Properties Found {props.Count()}:"); 
            foreach (var pi in props)
            {
                // pi.PropertyType
                string RWState =  (pi.CanRead?"Read":"") +(pi.CanWrite?"Write":"");
                Console.WriteLine("### {0} {1} {2}", RWState, pi, pi.GetValue(obj));
            }

            // var members = it.GetMembers().OrderBy(c => c.MemberType).ToList();
            // Console.WriteLine($"\n## Members Found {members.Count()}:"); 
            // foreach (var mi in members)
            // {
            //  Console.WriteLine("### {0} {1}", mi.MemberType, mi);
            // }

            // var fields = it.GetFields().OrderBy(c => c.Name).ToList();
            var fields = it.GetRuntimeFields().OrderBy(c => c.Name).ToList();
            Console.WriteLine($"\n## Runtime Fields Found {fields.Count()}:"); 
            foreach (var fi in fields)
            {
                Console.WriteLine("### {0}{1} {2} {3}", fi.IsStatic?"static":"", fi.IsPublic?"public":"", fi.FieldType.Name, fi);
            }
        }
    }


项目设置：

    <Project Sdk="Microsoft.NET.Sdk.WindowsDesktop">
    <!-- <Project Sdk="Microsoft.NET.Sdk"> -->

      <PropertyGroup>
        <OutputType>Exe</OutputType>
        <TargetFramework>net5.0</TargetFramework>
        <UseWindowsForms>true</UseWindowsForms>
      </PropertyGroup>

      <ItemGroup>
        <PackageReference Include="Microsoft.AspNetCore.Http" Version="2.2.2" />
      </ItemGroup>

    </Project>


构造函数获取与实例化：

    using System;
    using System.Linq;
    using System.Reflection;
    using System.Security;

    public class MyClass
    {
        public int tick = 0;

        public MyClass(){}
        public MyClass(int i){
            tick = i;
        }

        public static void Main()
        {
            var constructors = typeof(MyClass).GetConstructors().OrderBy(c => c.GetParameters().Length).ToList();
            if (constructors.Count == 0)
            {
                throw new MissingMethodException("No public constructor defined for this object");
            }
            Console.WriteLine($"{typeof(MyClass).Name} Constructors Found:"); 
            constructors.Select(e => {
                Console.WriteLine(" {0}", e); 
                return e;
                }).Count();

            object[] parameters = new object[constructors[0].GetParameters().Length];
            var instance = constructors[0].Invoke(parameters);

            try
            {
                Type myType = typeof(MyClass);

                // types in parameters list
                Type[] types = new Type[1];
                types[0] = typeof(int);

                // Get the constructor that takes an integer as a parameter.
                ConstructorInfo constructorInfoObj = myType.GetConstructor(types);
                if (constructorInfoObj != null)
                {
                    object[] args = new[]{ (object)99 };
                    var obj = constructorInfoObj.Invoke(args);
                    Console.WriteLine("Instance from Constructor(int) {0}", obj);
                }
            }
            catch(Exception e)
            {
                Console.WriteLine("Exception caught.");
                Console.WriteLine("Source: " + e.Source);
                Console.WriteLine("Message: " + e.Message);
            }
        }
    }

## Reflection & DI - Dependency Injection
- [C# Generics 泛型编程](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/generics/)

Microsoft DependencyInjection 作为一个开源的依赖注入实现，在 .Net Core 里被广泛的使用，这里用一百行代码结合反射技术实现一个简版 IoC 容器，实现对象服务注入、构造函数参数注入等。

先来看看测试用的代码：

    public class DiDemo
    {
        private static void Main(string[] args)
        {
            Services services = Services.GetInstance();

            // register services
            services.Add("Some string...");
            services.Add(new MyService("More string..."));
            services.Add<MyService>();
            services.Add<MyServiceTest>();

            Log(Services.Name);

            var str = services.GetService<string>() as string;
            Log($"Got String: {str}");

            var ms = services.GetService<MyService>() as MyService;
            Log($"Got MyService: {ms.DataSource}");

            var mst = services.GetService<MyServiceTest>() as MyServiceTest;
            mst?.Test(); // if got a service and use it
        }
        public static void Log(string msg)
        {
            string stamp = DateTime.Now.ToString("hh:mm:ss ffff");
            Console.WriteLine("\n{0}:\n\t{1}", stamp, msg);
        }
    }

    public class MyService
    {
        public string DataSource {get; set;}

        // use DI here when constructor call
        public MyService(string data = "Text for testing")
        {
            DataSource = data;
        }
    }

    public class MyServiceTest
    {
        protected MyService _service;

        // Use DI here when constructor call
        public MyServiceTest(MyService service)
        {
            _service = service;
        }

        public void Test()
        {
            Console.WriteLine($"Testing Text from MyService: {_service.DataSource}.");
        }
    }

分别定义了 MyService 和 MyServiceTest 两种服务，后者用来测试前提供的字符串服务，测试构造函数的依赖注入。也可以使用其他类型，如字符串作为服务。Services 是 IoC 容器，提供几个核心方法：

- Add(object service)   注册服务实例；
- Add<T>()  通过泛型函数注册服务类型；
- GetService()  获取已经注册的服务，优先返回注册的服务实例，其次返回可以通过反射方式构造的服务实例；

IoC 容器实现语法上使用了 C# 的特色 Linq 查询语言，还有泛型：

    using System;
    using System.Collections;
    using System.Collections.Generic;
    using System.Linq;

    public class Services
    {
        public static string Name = "IoC Container(IoC - Iversion of Control, DI - Dependency Injection)";
        protected static Services Instance;
        protected static List<object> Singletons;
        protected static List<Type> ServiceTypes;

        public static Services GetInstance()
        {
            if (Instance == null) 
            {
                Instance = new Services(); 
                ServiceTypes = new List<Type>{}; 
                Singletons = new List<object>{};
            }
            return Instance;
        }

        public Services Add(Object it)
        {
            Singletons.Add(it);
            return this;
        }

        public Services Add<T>()
        {
            ServiceTypes.Add(typeof(T));
            return this;
        }

        public object GetService<T>()
        {
            var singleton = GetSingleton(typeof(T));
            if (singleton != null)
            {
                return singleton;
            }

            foreach (var ti in ServiceTypes)
            {
                if (ti == typeof(T))
                {
                    return Build(ti);
                }
            }
            return new MyService("Default IoC Service");
        }

        protected object Build(Type ti)
        {
            // retrive ConstructorInfo[]
            var constructors = ti.GetConstructors().OrderBy(c => c.GetParameters().Length).ToList();
            if (constructors.Count == 0)
            {
                throw new MissingMethodException("No public constructor defined for this object");
            }
            foreach (var ctor in constructors)
            {
                // retrive ParameterInfo[]
                var paras = ctor.GetParameters();
                object[] parameters = new object[paras.Length];
                int idx = 0;
                foreach (var pa in paras)
                {
                    var it = GetSingleton(pa.ParameterType);
                    if (it==null) break;
                    parameters[idx ++] = it;
                }
                if (idx < paras.Length) continue;
                try
                {
                    var instance = ctor.Invoke(parameters);
                    return instance;
                }
                catch (Exception ex)
                {
                    Console.WriteLine("EX:"+ex.ToString());
                }
            }
            return null;
        }

        protected object GetSingleton(Type ti)
        {
            foreach(var it in Singletons)
            {
                if (it.GetType() == ti)
                {
                    return it;
                }
            }
            return null;
        }
    }

进一步修改 MyServiceTest 按如下实现另外一个构造函数，加入 info 参数，在有两个构造函数的情况下，看 IoC 会执行哪个：

    public class MyServiceTest
    {
        protected MyService _service;
        protected string _info = "unchanged";

        public MyServiceTest(MyService service, string info)
        {
            _service = service;
            _info = info;
        }

        // Use DI here when constructor call
        public MyServiceTest(MyService service)
        {
            _service = service;
        }
        
        public void Test()
        {
            Console.WriteLine($"Testing Text from MyService & info: {_service.DataSource} [{_info}].");
        }
    }

试着修改 IoC 实现的 Build 方法，修改 Linq 排序方式，再试试：

    OrderBy(c => -c.GetParameters().Length)



## Metadata 元数据编程

元数据 Metadata 是一种保存在程序文件的二进制信息，用以对存储在公共语言运行库可移植可执行文件 PE 文件或存储在内存中的程序进行描述。将您的代码编译为 PE 文件时，便会将元数据插入到该文件的一部分中，而将代码转换为 Microsoft 中间语言 (MSIL) 并将其插入到该文件的另一部分中。当执行代码时，运行库将元数据加载到内存中，并引用它来发现有关代码的类、成员、继承等信息。

使用元数据以非特定语言的方式描述在代码中定义的每一类型和成员，元数据可以存储以下信息：

- 程序集的说明。
- 标识（名称、版本、区域性、公钥）。 
- 导出的类型。
- 该程序集所依赖的其他程序集。
- 运行所需的安全权限。
- 类型的说明。
- 名称、可见性、基类和实现的接口。
- 成员（方法、字段、属性、事件、嵌套的类型）。
- 属性。
- 修饰类型和成员的其他说明性元素。

元数据是现代编译语言的基本功能，对于一种更简单的编程模型来说，元数据是关键，该模型不再需要接口定义语言 (IDL) 文件、头文件或任何外部组件引用方法。元数据允许 .NET 语言自动以非特定语言的方式对其自身进行描述，而这是开发人员和用户都无法看见的。另外，通过使用属性，可以对元数据进行扩展。

元数据的应用示例，以下代码示例显示如何声明 System.ObsoleteAttribute 将代码标记为已过时。特性描述的代码被调用时，此特性会导致产生编译器警告，显示传递进来的字符串。

    public class Example
    {
        // Specify attributes between square brackets in C#.
        // This attribute is applied only to the Add method.
        [Obsolete("Will be removed in next version.")]
        public static int Add(int a, int b)
        {
            return (a + b);
        }
    }

    class Test
    {
        public static void Main()
        {
            // This generates a compile-time warning.
            int i = Example.Add(2, 2);
        }
    }

要在程序集级别应用属性，比如设置程序集标题，请使用 **assembly** 关键字，Visual Basic 中用 Assembly。 下列代码显示在程序集级别应用的 AssemblyTitleAttribute。

    using System.Reflection;
    [assembly:AssemblyTitle("My Assembly")]

可通过后列方法查看特性：使用 MSIL 反汇编程序 (Ildasm.exe)，或创建一个自定义程序来检索查看。

要设计你自己的自定义特性，无需掌握许多新的概念。 如果你熟悉面向对象的编程，并且知道如何设计类，那么你已经具备大部分所需知识。 自定义属性本质上是直接或间接派生自 System.Attribute 的传统类。 与传统类一样，自定义特性包含用于存储和检索数据的方法。

正确设计自定义特性的主要步骤如下：

- 应用 AttributeUsageAttribute
- 声明特性类
- 声明构造函数
- 声明属性

例如，你可以指定其他类是否可以继承你的特性，或者指定此特性可以应用到哪些元素。 下面的代码片段演示了 System.AttributeUsageAttribute 的使用方式。

    // This defaults to Inherited = true.
    public class MyAttribute : Attribute
    {
        //...
    }

    [AttributeUsage(AttributeTargets.Method, Inherited = false)]
    public class YourAttribute : Attribute
    {
        //...
    }

    public class MyClass
    {
        [MyAttribute]
        [YourAttribute]
        public virtual void MyMethod()
        {
            //...
        }
    }

AttributeUsageAttribute 包含三个成员，它们对创建自定义属性非常重要：AttributeTargets、Inherited 和 AllowMultiple。

- AttributeTargets 成员指定特性适用范围

    上述示例中指定了 AttributeTargets.All，它表示此特性可应用于所有程序元素。 或者，你可指定 AttributeTargets.Class 和 AttributeTargets.Method，前者表示你的特性仅可适用于一个类，后者表示你的特性仅可应用于一种方法。

- Inherited 属性指明要对其应用属性的类的派生类能否继承此属性。

    从基类 MyClass 中继承类 YourClass。 方法 MyMethod 显示 MyAttribute，但不显示 YourAttribute。

- AllowMultiple 属性指明元素能否包含属性的多个实例。 

    如果设置为 true，则允许多个实例；如果设置为 false（默认值），则只允许一个实例。当应用这些特性的多个实例时， MyAttribute 会生成编译器错误。 下面的代码示例显示 YourAttribute 的有效用法和 MyAttribute的无效用法。

检索自定义属性，首先，声明要检索的属性实例。 然后，使用 Attribute.GetCustomAttribute 或 Attribute.GetCustomAttributes 方法，以要检索的属性的值初始化新属性。 在初始化新属性后，只需使用它的属性即可获取值。

    using System;

    public class ExampleAttribute : Attribute
    {
        private string stringVal;

        public ExampleAttribute()
        {
            stringVal = "This is the default string.";
        }

        public string StringValue
        {
            get { return stringVal; }
            set { stringVal = value; }
        }
    }

    [Example(StringValue="This is a string.")]
    class Class1
    {
        public static void Main()
        {
            System.Reflection.MemberInfo info = typeof(Class1);
            foreach (object attrib in info.GetCustomAttributes(true))
            {
                Console.WriteLine(attrib);
            }
        }
    }

例二：

    using System;
    using System.Reflection;


    [Developer("Joan Smith", "42", Reviewed = true)]
    class ReflectionApp
    {
        public static void Main()
        {
            // Call function to get and display the attribute.
            GetAttribute(typeof(ReflectionApp));
        }

        public static void GetAttribute(Type t)
        {
            // Get instance of the attribute.
            DeveloperAttribute att =
                (DeveloperAttribute) Attribute.GetCustomAttribute(t, typeof (DeveloperAttribute));

            if (att == null)
            {
                Console.WriteLine("The attribute was not found.");
            }
            else
            {
                // Get the attribute values.
                Console.WriteLine("The Developer Attribute is: {0} {1} {2}.", att.Name, att.Level, att.Reviewed);
            }
        }
    }

    [AttributeUsage(AttributeTargets.All)]
    public class DeveloperAttribute : Attribute
    {
        // Private fields.
        private string name;
        private string level;
        private bool reviewed;

        public DeveloperAttribute(string name, string level)
        {
            this.name = name;
            this.level = level;
            this.reviewed = false;
        }

        // Define read-only Name property.
        public virtual string Name
        {
            get {return name;}
        }

        // Define read-only Level property.
        public virtual string Level
        {
            get {return level;}
        }

        // Define read/write Reviewed property.
        public virtual bool Reviewed
        {
            get {return reviewed;}
            set {reviewed = value;}
        }
    }

基类库 (BCL) 中的有许多工具和框架都会使用的特性。 NUnit 和 NUnit 测试运行程序都使用 [Test] 和 [TestFixture] 之类的特性。 ASP.NET MVC 使用 [Authorize] 之类的特性，并提供可密切关注 MVC 操作的操作筛选器框架。 PostSharp 使用特性语法，支持在 C# 中进行面向特性的编程。

下面介绍了一些值得注意的 .NET Core 基类库内置特性：

- [Obsolete]。 此特性已在上面的示例中使用过，位于 System 命名空间中。 可用于提供关于不断变化的基本代码的声明性文档。 可以提供字符串形式的消息，并能使用另一布尔参数将编译器警告升级为编译器错误。

- [Conditional]。 此特性位于 System.Diagnostics 命名空间中。 可应用于方法（或特性类）。 必须向构造函数传递字符串。 如果该字符串与 #define 指令不匹配，那么 C# 编译器将删除对该方法（而不是方法本身）的所有调用。 此特性通常用于调试（诊断）目的。

- [CallerMemberName]。 此特性可应用于参数，位于 System.Runtime.CompilerServices 命名空间中。 可用于插入正在调用另一方法的方法的名称，在编译期实现像 JavaScript 动态语言的 arguments.caller。 此特性通常用于在各种 UI 框架中实现 INotifyPropertyChanged 时清除“神奇字符串”。 

C# 关键字 nameof 表达式也可生成变量、类型或成员的名称作为字符串常量。

[Obsolete] 及自定义特性：

    using System;
    using System.Collections;
    using System.Reflection;

    [Obsolete("ThisClass is obsolete. Use ThisClass2 instead.")]
    public class ThisClass { }

    [Gotcha("Fine")]
    public class ThisClass2 { }

    public class GotchaAttribute : Attribute
    {
        public string Info;

        public GotchaAttribute(string str) 
        {
            Info = str;
        }
    }

    class Demo
    {
        public static void Main()
        {
            // var tc = new ThisClass();
            var tc = new ThisClass2();

            TypeInfo typeInfo = typeof(ThisClass2).GetTypeInfo();
            Console.WriteLine("The assembly qualified name is " + typeInfo.AssemblyQualifiedName);

            var attrs = typeInfo.GetCustomAttributes();
            foreach(var attr in attrs)
            {
                string ana = attr.GetType().Name;
                if (ana == "GotchaAttribute")
                {
                    var got = attr as GotchaAttribute;
                    Console.WriteLine($"Gotchar has info {got.Info}");
                }
                else
                {
                    Console.WriteLine($"Attribute on MyClass2: {ana}");
                }
            }

        }
    }

流行的 MVVM - Model-View-ViewModel 编程模式中，通过对象属性数据的变动来更新 UI，使用 [CallerMemberName] 特性只可以很轻松实现属性脏数据触发的变动事件，直接驱动 UI 的更新事件方法。

    using System;
    using System.ComponentModel;
    using System.Runtime.CompilerServices;

    class Demo
    {
        public static void Main()
        {
            var ui = new MyUIClass();
            ui.PropertyChanged += (sender, eventArg) => {
                Console.WriteLine($"{sender} PropertyChaned, {eventArg.PropertyName}");
            };
            ui.Score = 9;
            ui.Name = "Any";

        }
    }

    public class MyUIClass : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        public void RaisePropertyChanged([CallerMemberName] string propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        private int _score;
        public int Score { 
            get { return _score; }
            set 
            {
                if (value != _score)
                {
                    _score = value;
                    RaisePropertyChanged();
                }
            }
        }
        
        private string _name;
        public string Name
        {
            get { return _name;}
            set
            {
                if (value != _name)
                {
                    _name = value;
                    RaisePropertyChanged();
                }
            }
        }
    }

除了 CallerMemberName 还有 CallerFilePath CallerLineNumber ，它们用来获取调用方法名称，路径，行号

    using System;
    using System.Runtime.CompilerServices;

    class Program
    {
        static void Main(string[] args)
        {
            Log();
            Console.Read();
        }

        public static void Log(
            [CallerMemberName] string memberName = "",
            [CallerFilePath] string filePath = "",
            [CallerLineNumber] int lineNumber = 0)
        {
            Console.WriteLine("Caller: {0} File:{1} line:{2}", memberName, filePath, lineNumber);
        }
    }


# Iterators 迭代器 
-[Iterators 迭代器](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/concepts/iterators)

迭代器 可用于逐步迭代集合，例如列表和数组。

迭代器方法或 get 访问器可对集合执行自定义迭代。 迭代器方法使用 yield return 语句返回元素，每次返回一个。 到达 yield return 语句时，会记住当前在代码中的位置。 下次调用迭代器函数时，将从该位置重新开始执行。

通过 foreach 语句或 LINQ 查询从客户端代码中使用迭代器。

在以下示例中，foreach 循环的首次迭代导致 SomeNumbers 迭代器方法继续执行，直至到达第一个 yield return 语句。 此迭代返回的值为 3，并保留当前在迭代器方法中的位置。 在循环的下次迭代中，迭代器方法的执行将从其暂停的位置继续，直至到达 yield return 语句后才会停止。 此迭代返回的值为 5，并再次保留当前在迭代器方法中的位置。 到达迭代器方法的结尾时，循环便已完成。

    static void Main()
    {
        foreach (int number in SomeNumbers())
        {
            Console.Write(number.ToString() + " ");
        }
        // Output: 3 5 8
        Console.ReadKey();
    }

    public static System.Collections.IEnumerable SomeNumbers()
    {
        yield return 3;
        yield return 5;
        yield return 8;
    }

迭代器方法或 get 访问器的返回类型可以是 IEnumerable、IEnumerable<T>、IEnumerator 或 IEnumerator<T>。
可以使用 yield break 语句来终止迭代。

下例包含一个位于 for 循环内的 yield return 语句。 在 Main 中，foreach 语句体的每次迭代都会创建一个对迭代器函数的调用，并将继续到下一个 yield return 语句。

    using System;

    class App
    {

        static void Main()
        {
            foreach (int number in EvenSequence(5, 18))
            {
                Console.Write(number.ToString() + " ");
            }
            // Output: 6 8 10 12 14 16 18
            Console.ReadKey();
        }
        
        public static System.Collections.Generic.IEnumerable<int>
            EvenSequence(int firstNumber, int lastNumber)
        {
            // Yield even numbers in the range.
            for (int number = firstNumber; number <= lastNumber; number++)
            {
                if (number % 2 == 0)
                {
                    yield return number;
                }
            }
        }
    }


在以下示例中，DaysOfTheWeek 类实现 IEnumerable 接口，此操作需要 GetEnumerator 方法。 编译器隐式调用 GetEnumerator 方法，此方法返回 IEnumerator。GetEnumerator 方法通过使用 yield return 语句每次返回 1 个字符串。

    using System;
    using System.Collections;

    class App
    {
        static void Main()
        {
            DaysOfTheWeek days = new DaysOfTheWeek();

            foreach (string day in days)
            {
                Console.Write(day + " ");
            }
            // Output: Sun Mon Tue Wed Thu Fri Sat
            Console.ReadKey();
        }

        public class DaysOfTheWeek : IEnumerable
        {
            private string[] days = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

            public IEnumerator GetEnumerator()
            {
                for (int index = 0; index < days.Length; index++)
                {
                    // Yield each day of the week.
                    yield return days[index];
                }
            }
        }
    }



# System.DateTime
https://docs.microsoft.com/zh-cn/dotnet/api/system.datetime?view=netcore-3.1
https://docs.microsoft.com/zh-cn/dotnet/api/system.timespan?view=netcore-3.1
https://docs.microsoft.com/zh-cn/dotnet/api/system.console.writeline?view=netcore-3.1

命名空间: System
程序集: System.Runtime.dll

表示时间上的一刻，通常以日期和当天的时间表示。

    public struct DateTime : IComparable, IComparable<DateTime>, IConvertible, IEquatable<DateTime>, IFormattable, System.Runtime.Serialization.ISerializable

继承 Object -> ValueType -> DateTime


DateTime 值类型表示日期和时间，其值范围为00:00:00 （午夜），0001年1月1日至年1月1日下午11:59:59，年12月31日，9999公元 公元公历。
时间值以100毫微秒为单位进行度量。 特定日期是自公元12:00 年1月1日午夜开始的计时周期数。 公元在 GregorianCalendar 日历中。 数字不包括闰秒将添加的刻度。 例如，31241376000000000L 的滴答值表示日期星期五，0100 12:00:00 午夜。 DateTime 值始终在显式或默认日历的上下文中表示。
 备注

如果使用的计时周期值要转换为其他时间间隔（如分钟或秒），则应使用 TimeSpan.TicksPerDay、TimeSpan.TicksPerHour、TimeSpan.TicksPerMinute、TimeSpan.TicksPerSecond或 TimeSpan.TicksPerMillisecond 常量来执行转换。 例如，若要将指定的刻度数表示的秒数添加到 DateTime 值的 Second 部分，可以使用表达式 dateValue.Second + nTicks/Timespan.TicksPerSecond。

传输到 COM 应用程序的 DateTime 值，然后将其传输回托管应用程序。 但 DateTime 值仅指定时间不会像预期的那样往返。

如果只往返时间（如下午3点），则最终日期和时间为公元1899年12月30日 在下午3:00，而不是公元0001年1月1日 下午3:00 在仅指定时间时，.NET Framework 和 COM 将假定为默认日期。 但是，COM 系统假定基准日期为公元1899年12月30日，而 .NET Framework 假设基准日期为公元0001年1月1日。

当只将时间从 .NET Framework 传递到 COM 时，会执行特殊处理，将时间转换为 COM 使用的格式。 如果仅将时间从 COM 传递到 .NET Framework，则不会执行任何特殊处理，因为这样会损坏1899年12月30日或之前的合法日期和时间。 如果日期从 COM 开始往返，则 .NET Framework 和 COM 将保留日期。


    var date1 = new DateTime(2008, 5, 1, 8, 30, 52);
    Console.WriteLine(date1);
    Console.WriteLine($"{dat1:d} {dat1:D} {dat1:t} {dat1:T}"); // 0001-01-01 0001年1月1日 0:00 0:00:00

    Dim dates As Date() = {#6/14/2014 6:32AM#, #7/10/2014 11:49PM#,
                      #1/10/2015 1:16AM#, #12/20/2014 9:45PM#,
                      #6/2/2014 3:14PM#}

    Console.WriteLine(DateTime.Now); // 2020-05-22 21:02:11
    Console.WriteLine(DateTime.Today); // 2020-05-22 0:00:00
    Console.WriteLine(DateTime.UtcNow); // 2020-05-22 13:02:11

    var dat1 = new DateTime();
    // The following method call displays 1/1/0001 12:00:00 AM.
    Console.WriteLine(dat1.ToString(System.Globalization.CultureInfo.InvariantCulture));
    // The following method call displays True.
    Console.WriteLine(dat1.Equals(DateTime.MinValue));

    var dateString = "5/1/2008 8:30:52 AM";
    DateTime date1 = DateTime.Parse(dateString,
                              System.Globalization.CultureInfo.InvariantCulture);
    var iso8601String = "20080501T08:30:52Z";
    DateTime dateISO8602 = DateTime.ParseExact(iso8601String, "yyyyMMddTHH:mm:ssZ",
                                    System.Globalization.CultureInfo.InvariantCulture);


ToString 格式字符

    using System;

    public class DateToStringExample
    {
       public static void Main()
       {
          DateTime dateValue = new DateTime(2008, 6, 15, 21, 15, 07);
          // Create an array of standard format strings.
          string[] standardFmts = {"d", "D", "f", "F", "g", "G", "m", "o",
                                   "R", "s", "t", "T", "u", "U", "y"};
          // Output date and time using each standard format string.
          foreach (string standardFmt in standardFmts)
             Console.WriteLine("{0}: {1}", standardFmt,
                               dateValue.ToString(standardFmt));
          Console.WriteLine();

          // Create an array of some custom format strings.
          string[] customFmts = {"h:mm:ss.ff t", "d MMM yyyy", "HH:mm:ss.f",
                                 "dd MMM HH:mm:ss", @"\Mon\t\h\: M", "HH:mm:ss.ffffzzz" };
          // Output date and time using each custom format string.
          foreach (string customFmt in customFmts)
             Console.WriteLine("'{0}': {1}", customFmt,
                               dateValue.ToString(customFmt));
       }
    }
    // This example displays the following output to the console:
    //       d: 6/15/2008
    //       D: Sunday, June 15, 2008
    //       f: Sunday, June 15, 2008 9:15 PM
    //       F: Sunday, June 15, 2008 9:15:07 PM
    //       g: 6/15/2008 9:15 PM
    //       G: 6/15/2008 9:15:07 PM
    //       m: June 15
    //       o: 2008-06-15T21:15:07.0000000
    //       R: Sun, 15 Jun 2008 21:15:07 GMT
    //       s: 2008-06-15T21:15:07
    //       t: 9:15 PM
    //       T: 9:15:07 PM
    //       u: 2008-06-15 21:15:07Z
    //       U: Monday, June 16, 2008 4:15:07 AM
    //       y: June, 2008
    //
    //       'h:mm:ss.ff t': 9:15:07.00 P
    //       'd MMM yyyy': 15 Jun 2008
    //       'HH:mm:ss.f': 21:15:07.0
    //       'dd MMM HH:mm:ss': 15 Jun 21:15:07
    //       '\Mon\t\h\: M': Month: 6
    //       'HH:mm:ss.ffffzzz': 21:15:07.0000-07:00


TimeSpan 时间跨度，WriteLine 方法中，参数逗号后指定的格式 32 表示右对齐 32 个字符空间，-32 表示左对齐：

    // Define two dates.
    DateTime date1 = new DateTime(2010, 1, 1, 8, 0, 15);
    DateTime date2 = new DateTime(2010, 8, 18, 13, 30, 30);

    // Calculate the interval between the two dates.
    TimeSpan interval = date2 - date1;
    Console.WriteLine("{0} - {1} = {2}", date2, date1, interval.ToString());

    // Display individual properties of the resulting TimeSpan object.
    Console.WriteLine("   {0,32} {1,20}", "Value of Days Component:", interval.Days);
    Console.WriteLine("   {0,32} {1,20}", "Total Number of Days:", interval.TotalDays);
    Console.WriteLine("   {0,32} {1,20}", "Value of Hours Component:", interval.Hours);
    Console.WriteLine("   {0,32} {1,20}", "Total Number of Hours:", interval.TotalHours);
    Console.WriteLine("   {0,32} {1,20}", "Value of Minutes Component:", interval.Minutes);
    Console.WriteLine("   {0,32} {1,20}", "Total Number of Minutes:", interval.TotalMinutes);
    Console.WriteLine("   {0,32} {1,20:N0}", "Value of Seconds Component:", interval.Seconds);
    Console.WriteLine("   {0,32} {1,20:N0}", "Total Number of Seconds:", interval.TotalSeconds);
    Console.WriteLine("   {0,32} {1,20:N0}", "Value of Milliseconds Component:", interval.Milliseconds);
    Console.WriteLine("   {0,32} {1,20:N0}", "Total Number of Milliseconds:", interval.TotalMilliseconds);
    Console.WriteLine("   {0,32} {1,20:N0}", "Ticks:", interval.Ticks);

    // This example displays the following output:
    //       8/18/2010 1:30:30 PM - 1/1/2010 8:00:15 AM = 229.05:30:15
    //         Value of Days Component:                  229
    //            Total Number of Days:   229.22934027777777
    //        Value of Hours Component:                    5
    //           Total Number of Hours:    5501.504166666667
    //      Value of Minutes Component:                   30
    //         Total Number of Minutes:            330090.25
    //      Value of Seconds Component:                   15
    //         Total Number of Seconds:             19805415
    // Value of Milliseconds Component:                    0
    //    Total Number of Milliseconds:          19805415000
    //                           Ticks:      198054150000000


DateTime 属性：

    Date        获取此实例的日期部分。
    Day     获取此实例所表示的日期为该月中的第几天。
    DayOfWeek   获取此实例所表示的日期是星期几。
    DayOfYear   获取此实例所表示的日期是该年中的第几天。
    Hour        获取此实例所表示日期的小时部分。
    Kind        获取一个值，该值指示由此实例表示的时间是基于本地时间、协调世界时 (UTC)，还是两者皆否。
    Millisecond 获取此实例所表示日期的毫秒部分。
    Minute      获取此实例所表示日期的分钟部分。
    Month       获取此实例所表示日期的月份部分。
    Now     获取一个 DateTime 对象，该对象设置为此计算机上的当前日期和时间，表示为本地时间。
    Second      获取此实例所表示日期的秒部分。
    Ticks       获取表示此实例的日期和时间的计时周期数。
    TimeOfDay   获取此实例的当天的时间。
    Today       获取当前日期。
    UtcNow      获取一个 DateTime 对象，该对象设置为此计算机上的当前日期和时间，表示为协调通用时间 (UTC)。
    Year        获取此实例所表示日期的年份部分。

# System.Math
https://docs.microsoft.com/zh-cn/dotnet/api/system.math?view=netcore-3.1

命名空间: System
程序集: System.Runtime.Extensions.dll

为三角函数、对数函数和其他通用数学函数提供常数和静态方法。

    public static class Math

继承 Object -> Math

字段

    E   表示自然对数的底，它由常数 e 指定。
    PI  表示圆的周长与其直径的比值，由常数 π 指定。

方法 

    Abs()   返回数字的绝对值。
    Acos(Double)    返回余弦值为指定数字的角度。
    Acosh(Double)   返回双曲余弦值为指定数字的角度。
    Asin(Double)    返回正弦值为指定数字的角度。
    Asinh(Double)   返回双曲正弦值为指定数字的角度。
    Atan(Double)    返回正切值为指定数字的角度。
    Atan2(Double, Double)   返回正切值为两个指定数字的商的角度。
    Atanh(Double)   返回双曲正切值为指定数字的角度。
    BigMul(Int32, Int32)    生成两个 32 位数字的完整乘积。
    BitDecrement(Double)    返回小于 x 的下一个最小值。
    BitIncrement(Double)    返回大于 x 的下一个最大值。
    Cbrt(Double)    返回指定数字的立方根。
    Ceiling(Decimal)    返回大于或等于指定的十进制数的最小整数值。
    Ceiling(Double) 返回大于或等于指定的双精度浮点数的最小整数值。
    Clamp() 返回限制在 value 和 min 范围内（含首尾）的 max。
    CopySign(Double, Double)    返回一个值，它具有 x 的大小和 y 的符号。
    Cos(Double) 返回指定角度的余弦值。
    Cosh(Double)    返回指定角度的双曲余弦值。
    DivRem(Int32, Int32, Int32) 计算两个 32 位有符号整数的商，并通过输出参数返回余数。
    DivRem(Int64, Int64, Int64) 计算两个 64 位有符号整数的商，并通过输出参数返回余数。
    Exp(Double) 返回 e 的指定次幂。
    Floor(Decimal)  返回小于或等于指定小数的最大整数值。
    Floor(Double)   返回小于或等于指定双精度浮点数的最大整数值。
    FusedMultiplyAdd(Double, Double, Double)    返回 (x * y) + z，舍入为一个三元运算。
    IEEERemainder(Double, Double)   返回一指定数字被另一指定数字相除的余数。
    ILogB(Double)   返回指定数字以 2 为底的整数对数。
    Log(Double) 返回指定数字的自然对数（底为 e）。
    Log(Double, Double) 返回指定数字在使用指定底时的对数。
    Log10(Double)   返回指定数字以 10 为底的对数。
    Log2(Double)    返回指定数字以 2 为底的对数。
    Max()   返回两个数中较大的一个。
    Max(Decimal, De
    MaxMagnitude(Double, Double)    返回两个双精度浮点数字中的较大值。
    Min()   返回两个 8 位无符号整数中较小的一个。
    MinMagnitude(Double, Double)    返回两个双精度浮点数字中的较小值。
    Pow(Double, Double) 返回指定数字的指定次幂。
    Round(Decimal)  将小数值舍入到最接近的整数值，并将中点值舍入到最接近的偶数。
    Round(Decimal, Int32)   将小数值舍入到指定数量的小数位，并将中点值舍入到最接近的偶数。
    Round(Decimal, Int32, MidpointRounding) 将小数值舍入到指定数量的小数位，并为中点值使用指定的舍入规则。
    Round(Decimal, MidpointRounding)    将小数值舍入到最接近的整数，并为中点值使用指定的舍入规则。
    Round(Double)   将双精度浮点值舍入到最接近的整数值，并将中点值舍入到最接近的偶数。
    Round(Double, Int32)    将双精度浮点值舍入到指定数量的小数位，并将中点值舍入到最接近的偶数。
    Round(Double, Int32, MidpointRounding)  将双精度浮点值舍入到指定数量的小数位，并为中点值使用指定的舍入规则。
    Round(Double, MidpointRounding) 将双精度浮点值舍入到最接近的整数，并为中点值使用指定的舍入约定。
    ScaleB(Double, Int32)   返回有效计算的 x * 2^n。
    Sign()  返回表示数值符号的整数。
    Sin(Double) 返回指定角度的正弦值。
    Sinh(Double)    返回指定角度的双曲正弦值。
    Sqrt(Double)    返回指定数字的平方根。
    Tan(Double) 返回指定角度的正切值。
    Tanh(Double)    返回指定角度的双曲正切值。
    Truncate(Decimal)   计算一个数字的整数部分。
    Truncate(Double)    计算指定双精度浮点数的整数部分。




