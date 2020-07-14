#  Xamarin 跨平台开发

开发软件：Visual Studio 2019 社区版
工作系统：Windows 10
代码仓库：https://github.com/jimboyeah/demo/tree/XamarinVS2019

Xamarin.Forms 是一个开放源代码跨平台的 UI 框架。 Xamarin.Forms 使开发人员可以从单个共享基本代码生成 Android、iOS 和 Windows 应用程序。Xamarin.Forms 提供了一个公共 API，它可跨平台呈现本机控件，但特定平台的功能可能在其他平台上不存在。 例如，Android 平台具有用于在 ListView 中快速滚动的本机功能，但 iOS 却没有。 通过 Xamarin.Forms 平台特定内容可以使用仅在特定平台上提供的功能。

和 Cordova Ionic 这类结合 HTML 5 开发的 HyperApp 不同，Xamarin 以接近移动平台原生的方式运行，效率不可相比。

Xamarin 和 Flutter 更为相似，关键的技术是 Xamarin.Forms 把 iOS、Android、UWP 等平台的 GUI 统一抽象成同一个 UI 框架，开发者只需要写一套代码，编译器会在编译时将界面映射到原先控件上，从而获得原生平台的外观和性能。损耗小并不代表没有，官方也表示，Xamarin.Forms 不适合用于开发图形界面操作特别复杂且频繁的应用，像大型的 3D 游戏。在一些平台差异化的实现中，Xamarin.iOS、Xamarin.Android 就提供解决问题的实施方案。

Xamarin.Forms 提供的功能的一些示例包括：

- XAML 用户界面语言
- 数据绑定
- 笔势
- 效果
- 样式

通过 Visual Studio 2019 创建的 Xamarin 工程，在提供 Xamarin.Forms 基础通用 UI 框架项目外，它生成一个共享库，供 Xamarin.Android 和 Xamarin.iOS 等平台使用，生成平台差异化的应用。

Xamarin.iOS 为 .NET 开发人员提供了完整的 iOS SDK。 在 Visual Studio 中使用 C# 或 F# 生成完全本机的 iOS 应用。

Xamarin.Android 为 .NET 开发人员提供了完整的 Android SDK。 在 Visual Studio 中使用 C# 或 F# 生成完全本机的 Android 应用。

Xamarin.Essentials 是一个库，可为本机设备功能提供跨平台 API。 与 Xamarin 本身一样，Xamarin.Essentials 是一种简化本机功能访问过程的抽象。 

Xamarin.Essentials 提供的功能的一些示例包括：

- 设备信息
- 文件系统
- 加速计
- 电话拨号程序
- 文本到语音转换
- 屏幕锁定

Xamarin 是一个开放源代码平台，用于通过 .NET 构建适用于 iOS、Android 和 Windows 的新式高性能应用程序。 Xamarin 是一个抽象层，可管理共享代码与基础平台代码的通信。 Xamarin 在提供便利（如内存分配和垃圾回收）的托管环境中运行。

Xamarin 使开发人员可以跨平台共享其应用程序（平均 90%）。 此模式允许开发人员以一种语言编写所有业务逻辑（或重复使用现有应用程序代码），但在每个平台上实现本机性能和外观。
Xamarin 应用程序可以在电脑或 Mac 上进行编写并编译为本机应用程序包，如 Android 上的 .apk 文件，或 iOS 上的 .ipa 文件。

Xamarin.Android 应用程序从 C# 编译为中间语言 (IL)，随后在启动应用程序时，再实时 (JIT) 编译为本机程序集。 Xamarin.Android 应用程序在 Mono 执行环境中与 Android 运行时 (ART) 虚拟机并行运行。 Xamarin 向 Android.* 和 Java.* 命名空间提供 .NET 绑定。 Mono 执行环境通过托管可调用包装器 (MCW) 调入这些命名空间，并向 ART 提供 Android 可调用包装器 (ACW)，这使两种环境可以相互调用代码。

在 Android 上大多数系统功能 (如音频、图形、OpenGL 和电话服务) 都不能直接用于本机应用程序, 它们只能通过驻留在某个 Java.* 命名空间或 Android.* 命名空间的运行时 Java API 公开。

可以使用 System、 System.IO、 System.Net 和 .net 类库的其余部分来访问基础 Linux 操作系统设备。

对比一下 Xamarin 和 JAVA 开发的 Android 应用程序编译执行过程：

    *.java ---> JavaC ----> .class ---> JVM load class
    *.cs ---> C# complier ---> IL  --->  MonoVM + JIT execute 

根据其类型和复杂性，Xamarin 应用程序通常比本地应用程序大，一个 HelloWorld 大小可能需要 16 MB 组成：

- Mono Runtime 1.2 MB
- BCL - Base Class Library
    - mscorlib runtime 2.6 MB
    - System 1.0 MB
    - XML Model 1.2 MB
    - System.Core 370 KB
    - Mono.Security 280 KB
    - Mono.Android 9.4 MB
- HelloWorld 6 KB

Xamarin 项目被编译成 DLL 程序集，打包成 apk 文件，可以通过像 DotPeek 反射很容易被逆向工程破解，可以考虑增加混淆加密 Obfuscation 或 AOT - Ahead of Time 编译技术。

ProGuard 是一个用于链接和混淆 Java 代码的 Android SDK 工具，通常用于减少 APK 中的大型库（如Google Play服务）的占用量，以此创建较小的应用。ProGuard 可以删除未使用的 Java 字节码，以此来减小最终的应用大小。在 Xamarin.Android 应用中通常可以减小大约 24% 的大小，在含有多个库依赖的大型应用中，会有更加明显的缩减。


安装完 Xamarin 后，编译 Android 项目时卡死好长时间进度都不动，可能是因在 Android 项目在第一次编译时要去 google 网站上下一个 Andorid SDK ，国内连接不上就卡住，解决办法就是自已到国内的一些镜像网站上下载 Android SDK。还有，最好连接手机，打开开发者选项进行调试。根据已经安装的 SDK 版本，和连接手机设备，设置项目的最低 Android API 版本和目标 Android API 版本。

使用模拟器需要启用 Windows 功能：

- Hyper-V 
- Windows Hypervisor Platform 虚拟机监控平台

# 快速开始 - 多页面工程

一个多页面的 Multi-Page 起步项算是一个完整的 Xamarin 项目骨架，通过这个项目达成以下技能学习目标：

- 往 Xamarin.Forms 项目添加页面对象；
- 实现页面间的导航跳转；
- 使用数据绑定在 UI 组件间同步数据；

Visual Studio 2019 提供的 Xamarin.Forms 工程模板就是很好的学习案例：

    └───XamarinVS2019   项目根目录
      ├─── App.xaml     程序对象视图实现
      ├─── App.xaml.cs  负责程序对象的初始化，配置数据依赖服务等
      ├─── AssemblyInfo.cs  程序集信息，Company、 FileVersion、 Product、 Title 等
      ├─── XamarinVS2019.csproj C# 工程配置文件，SDK、Framework、引用库、程序类型配置等
      │ 
      ├─── Models   数据模型文件夹
      │ ├─── HomeMenuItem.cs    
      │ └─── Item.cs    
      │ 
      ├─── Services     服务文件夹，存放各种服务类实现
      │ ├─── AzureDataStore.cs  
      │ ├─── IDataStore.cs  
      │ └─── MockDataStore.cs   
      │ 
      ├─── ViewModels   MVVM 视图模型文件夹
      │ ├─── AboutViewModel.cs  
      │ ├─── BaseViewModel.cs   
      │ ├─── ItemDetailViewModel.cs 
      │ └─── ItemsViewModel.cs  
      │ 
      └─── Views    MVVM 视图文件夹
        ├─── AboutPage.xaml 
        ├─── AboutPage.xaml.cs  
        ├─── ItemDetailPage.xaml    
        ├─── ItemDetailPage.xaml.cs 
        ├─── ItemsPage.xaml 
        ├─── ItemsPage.xaml.cs  
        ├─── MainPage.xaml  
        ├─── MainPage.xaml.cs   
        ├─── MenuPage.xaml  
        ├─── MenuPage.xaml.cs   
        ├─── NewItemPage.xaml   
        └─── NewItemPage.xaml.cs    

默认工程可以选择 Xamarin.Android、Xamarin.iOS 还有配套的 Web 数据服务接口，它以 MVC API 方式实现，具体参考 .Net Core MVC 的开发，和 ApiController 类的使用。

接下来，对程序进行运行流程的分析，并在分析过程中说明涉及到的 Xamarin 技术点。

# 应用程序与主页面对象

Application 和 MainPge 的首要任务：

- 设置程序初始化信息，包括使用什么数据服务；
- 装入初始页面，即 Application.MainPage 属性设置的页面；
- 由 MainPage 设置版面风格，模板工程使用的是 MasterDetailPage，用于显示一个侧栏菜单和内容，设置 MasterBehavior.Popover ；
- 装入 MenuPage 到 MainPage.Master 生成菜单上视图；

Application 视图对象是整个程序的入口，可以配置全局的资源等：

```xml
    <?xml version="1.0" encoding="utf-8" ?>
    <Application xmlns="http://xamarin.com/schemas/2014/forms"
                 xmlns:x="http://schemas.microsoft.com/winfx/2009/xaml"
                 xmlns:d="http://xamarin.com/schemas/2014/forms/design"
                 xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
                 mc:Ignorable="d"
                 x:Class="XamarinVS2019.App">

        <Application.Resources>
            <ResourceDictionary>
                <!--Global Styles-->
                <Color x:Key="NavigationPrimary">#2196F3</Color>
                <Style TargetType="NavigationPage">
                    <Setter Property="BarBackgroundColor" Value="{StaticResource NavigationPrimary}" />
                    <Setter Property="BarTextColor" Value="White" />
                </Style>
            </ResourceDictionary>
        </Application.Resources>
        
    </Application>
```


根据不同的平台，程序运行有各种状态，对应 Application 的事件处理 OnStart、 OnSleep、 OnResume。程序实例化时，设置数据接口服务，默认提供演示用的 Mock 数据，即在程序内部生成模拟数据。

```javascript
    using System;
    using Xamarin.Essentials;
    using Xamarin.Forms;
    using Xamarin.Forms.Xaml;
    using XamarinVS2019.Services;
    using XamarinVS2019.Views;

    namespace XamarinVS2019
    {
        public partial class App : Application
        {
            //TODO: Replace with *.azurewebsites.net url after deploying backend to Azure
            //To debug on Android emulators run the web backend against .NET Core not IIS
            //If using other emulators besides stock Google images you may need to adjust the IP address
            public static string AzureBackendUrl = 
                DeviceInfo.Platform == DevicePlatform.Android ? 
                "http://192.168.0.109:5001" : "http://localhost:5000";
            public static bool UseMockDataStore = true;

            public App()
            {
                InitializeComponent();

                if (UseMockDataStore)
                    DependencyService.Register<MockDataStore>();
                else
                    DependencyService.Register<AzureDataStore>();
                MainPage = new MainPage();
            }

            protected override void OnStart()
            {
            }

            protected override void OnSleep()
            {
            }

            protected override void OnResume()
            {
            }
        }
    }
```

App 对象在整个工程中作为入口点，它首先加载的就是 MainPage：

    MainPage = new MainPage();

MainPage 在整个程序中，担任着页面的导航任务，在用户与 UI 交互过程中，各页面根据用户操作进行导航切换。

Xamarin.Forms 的 NavigationElement 是提供导航能力的基类，子类 Page 或 View 都具有导航能力，在页面中通常使用继承自 Page 类的 NavigationPage 来管理其他页面堆栈的导航。 

NavigationPage 提供的分层导航基于 LIFO 堆栈实现，Last-In First-Out 即后进先出，后面推送的页面显示在最顶层，弹出后就显示最后那一个页面。 

在工程中，通常推送 ContentPage 页面实例到导航堆栈，这也是建议使用的页面类型，实例填充 NavigationPage。


MainPage 继承自 MasterDetailPage，这是一种大纲/详细信息页面，和 NavigationPage 一样继承自 
Page 类型。MasterDetailPage 通过 Master 和 Detail 属性设置两个子页，以对应显示条目列表和条目详情。在模板工程中，利用它们分别显示菜单和数据列表。

MasterDetailPage 通过 MasterBehavior 属性指定 Master 页的呈现方式：

| 方式      | 值       | Master 页面呈现方式 |
| :-------  | :-------  | :-------  |
| Default   | 0 | 默认值，按平台默认方式呈现 |
| Popover   | 3 | 显示 Detail 页面，通过按钮弹出 Master 页面 |
| Split     | 2 | 页面总是分割屏幕显示 Detail |
| SplitOnLandscape  | 1 | 在横屏状态，Detail 在分割区域显示出来，手机端无效 |
| SplitOnPortrait   | 4 | 在竖屏状态，Detail 在分割区域显示出来，手机端无效 |

MasterBehavior 属性对手机端无效，在页面呈现处理分割状态时，不能通过 IsPresented 来设置 Master 的状态。在平板测试中，分割显示的 Master 有时会隐藏不显示，菜单按钮也丢失。

可以设置是不可以通过侧滑手势打开大纲页面，也可以设置大纲页面的背景色，但是不能设置宽度高度等，因为页面对象的宽高只读：

    IsGestureEnabled = true;
    Master.BackgroundColor = Color.AliceBlue

除 MasterDetailPage 这种页面布局窗口外，还有选项卡 TabbedPage 和 CarouselPage 侧滑等页面布局容器。


MainPage 视图类在 XAML 文件中载入 MenuPage 页面到大纲视图，在构造函数中初始化一个字典页面字典 MenuPages 来关联现有的页面。

在 MainPage.xaml 文件中，通过 `<x:Arguments>` 方式传入 ItemsPage 作为 MasterDetailPage 构造函数的参数，即向大纲视图填充了一个 ItemsPage 页面对象，它会在页面 MainPage 构造构造函数中的组件初始化方法中设置好，同时构造函数也相应添加 Detail 页面的关联数据到字典中：

    InitializeComponent();
    ...
    MenuPages.Add((int)MenuItemType.Browse, (NavigationPage)Detail);

MainPage 实现 `NavigateFromMenu` 方法应菜单的点击，每次执行时判断字典中是否已经已经有相应页面的实例，有且当前没有显示出来就直接加载到 Detail 视图。

菜单页面 MenuPage 在其构造函数中设置绑定的菜单数据，如页面标题信息供视图文件 MenuPage.xaml 中的 ListView 组件使用。并且，在 MenuPage 函数中绑定了菜单点击处理函数，用户点击菜单上的条目时，执行 MainPage 上定义的 `NavigateFromMenu` 方法加载字典对应的条目。

```js
    ListViewMenu.SelectedItem = menuItems[0];
    ListViewMenu.ItemSelected += async (sender, e) =>
    {
        if (e.SelectedItem == null)
            return;

        var id = (int)((HomeMenuItem)e.SelectedItem).Id;
        await RootPage.NavigateFromMenu(id);
    };
```

默认的菜单条目类型定义了只有 Title 和 Id 两个属性，定义 MenuItemType 枚举值作为 Id 类型，只有 Broswer 和 About 对应两个页面。


菜单的数据在 MenuPage 类型的构造函数中填充，MenuPage.xaml 中以 `d:` 命名空间的组件是为 Visual Studio 设计器所使用，像 `<d:ListView.ItemsSource>` 可以不要管它。

    xmlns:d="http://xamarin.com/schemas/2014/forms/design"

但从数据绑定的功能上，是同样的原理，就是通过 x:Array 标记扩展向 ListView.ItemsSource 传入一个数组作为数据源，数组的元素是字符串：

```xml
    <d:ListView.ItemsSource>
        <x:Array Type="{x:Type x:String}">
            <x:String>Item 1</x:String>
            <x:String>Item 2</x:String>
        </x:Array>
    </d:ListView.ItemsSource>
```

以上是顶层页面和导航菜单逻辑的实现，说实话，个人感觉菜单这部分代码处理的很糟糕，错综复杂，使用很不方便，添加一个页面就要改动几个地方：

- HomeMenuItem 数据模型中增加枚举值；
- MenuPage 菜单页面中增加页面的标题等信息；
- MainPage 顶层页面中修改 NavigateFromMenu 方法，增加 switch 的选择；


如果我要修改菜单逻辑会这样做，使用了反射好像太浮夸，But，能节省关联修改的技术都是极好：

- 给菜单条目设置一个 Tag 属性，通过 Tag 比较是什么页面：

        public Type Tag { get; set; }

- 定义一个 MenuPagesTag 字典保存字符串映射：

        Dictionary<Type, NavigationPage> MenuPagesTag = new Dictionary<Type, NavigationPage>();

- 再重载一个 NavigateFromMenu 方法接收页面类型在 MenuPagesTag 比较，并通过反射方法实例化：

```js
    public async Task NavigateFromMenu(Type tag)
        if (!MenuPagesTag.ContainsKey(tag))
        {
            var page = System.Activator.CreateInstance(tag) as Page;
            MenuPagesTag.Add(tag, new NavigationPage(page));
        }
```

- 改写菜单页面 ItemSelected 的事件处理逻辑，根据 Tag 是不设置来执行导航方法，如果要判断 Id 可以设置枚举起始值 Browse = 1，用 0 表示没有设置 Id：

```js
    var item = (HomeMenuItem)e.SelectedItem;
    if (item.Tag == null)
    {
        await RootPage.NavigateFromMenu(item.Id);
    }else{
        await RootPage.NavigateFromMenu(item.Tag);
    }
```

- 然后在 MenuPage 中注册新页面，只需要添加一行代码：

```js
    new HomeMenuItem {Tag = typeof(NamedColor), Title="Named Color" },
```

# 服务与依赖注入

数据服务是通过 DependencyInjection 模块实现依赖注入的，这是随处可见的编程模式，用于各个模块关系的解耦，参考 .Net Core 的依赖注入内容。

如果想了解 DI 的实现，可以戳这里， [100 行代码带你进入 IoC 和 DI - Dependency Injection](https://www.jianshu.com/p/99b3ead5c2a2)。

在 App 类的代码中使用了 Xamarin.Forms.DependencyService 的静态方法在服务容器中注册数据服务类，然后，在程序其它需要使用数据服务的地方，再从服务窗口中获取数据服务类。

工程模板的视图模型 ItemsViewModel 和 ItemDetialViewModel 都需要数据服务，它们继承 BaseViewModel 从它那里获取到了数据服务：

    public IDataStore<Item> DataStore => DependencyService.Get<IDataStore<Item>>();


数据服务是根据 IDataStore 接口实现的，它定义了基本的 CURD 操作：

```js
    using System;
    using System.Collections.Generic;
    using System.Threading.Tasks;

    namespace XamarinVS2019.Services
    {
        public interface IDataStore<T>
        {
            Task<bool> AddItemAsync(T item);
            Task<bool> UpdateItemAsync(T item);
            Task<bool> DeleteItemAsync(string id);
            Task<T> GetItemAsync(string id);
            Task<IEnumerable<T>> GetItemsAsync(bool forceRefresh = false);
        }
    }
```

和接口配套的数据模型是 Item 模型类，只定义了三个属性：

```js
    using System;

    namespace XamarinVS2019.Models
    {
        public class Item
        {
            public string Id { get; set; }
            public string Text { get; set; }
            public string Description { get; set; }
        }
    }
```

数据服务重点在 AzureDataStore 的实现，它负责从服务器上获取和传送数据，通过 System.Net.Http.HttpClient 与数据服务器通信。

在使用 Xamarin 开发 Android 应用时，可能会遇到不允许明文 HTTP 请求异常，因为，从 Android 9.0 开始，出于完全因素考虑，默认不再支持 HTTP 网络请求，需要使用 HTTPS。

临时解决办法，修改 AndroidManifest.xml 以许可明文 HTTP，降低 android:targetSandboxVersion 版本降价安全要求：

```xml
    <?xml version="1.0" encoding="utf-8"?>
    <manifest android:targetSandboxVersion="1">
        <uses-permission android:name="android.permission.INTERNET" />
        <application
            ...
            android:usesCleartextTraffic="true"
```

使用 HTTPS 就需要配置好服务器的证书。

数据服务类中，使用静态类 Xamarin.Essentials.Connectivity 的属性进行网络状态的判断：

    bool IsConnected => Connectivity.NetworkAccess == NetworkAccess.Internet;

它有一个 ConnectivityChanged 事件可以用来监视网络连接的变化，还有 ConnectionProfiles 提供当前系统存在的各种网络配置：

    public static event EventHandler<ConnectivityChangedEventArgs> ConnectivityChanged;

    public static IEnumerable<ConnectionProfile> ConnectionProfiles { get; }

网络连接状态枚举定义：

| 网络类型  | 枚举值   | 含义    |
| :------   | :------   | :------ |
| Bluetooth | 1 | 系统提供蓝牙数据连接 |
| Cellular  | 2 | 移动电话/蜂窝网络数据连接 |
| Ethernet  | 3 | 以太网数据连接 |
| Unknown   | 0 | 未知连接 |
| WiFi      | 4 | WiFI 数据连接 |

然后通过 HttpClient 的各种方法和 Web 服务器进行数据通信：

- GetAsync(...)
- GetByteArrayAsync(String or Uri)
- GetStreamAsync(String or Uri)
- GetStringAsyncnc
- PostAsync
- PutAsync
- DeleteAsync

通信前，给 HttpClient.BaseAddress 设定了一个根地址，各种方法获取。

可以通过 HttpCompletionOption 枚举指定请求如何完成处理，`ResponseContentRead` 表示从服务器中完全获取数据后才完成，`ResponseHeadersRead` 表示获取 HTTP 响应头信息后就当作完成请求。

异步请求中，可在创建 Task 时传入一个 CancellationToken 令牌对象，以控制如何结束请求，如果 CancellationToken 在 Task 调度前取消，那么 Task 就会被取消永远都不执行。

除 Get 指定内容类型，其它 HTTP 方法还会返回 HttpContent 内容，可以使用以下方法对数据进行处理：

```js
    Task<byte[]> ReadAsByteArrayAsync ();
    Task<Stream> ReadAsStreamAsync ();
    Task<string> ReadAsStringAsync ();
    Task SerializeToStreamAsync (Stream stream, TransportContext context);
```

相比 XML 数据格式，现在的 JSON 更为流行，它结构更简洁，更方便于程序的处理。工程模板使用的是 Newtonsoft.Json 库，其提供的 SerializeObject
和 DeserializeObject 是配对的方法，序列化将对象转化成 JSON 字符串，反序列化将字符串转化为对象：

```js
    items = await Task.Run(() => JsonConvert.DeserializeObject<IEnumerable<Item>>(json));

    JsonConvert.SerializeObject(item);
    JsonConvert.DeserializeObject(item);
```

服务器的代码中，ApiController 默认就是输出 JSON 数据，客户端获取后通过 System.Text.Json.Serialization 包下的工具进行处理。


# MVVM ViewModel

在 MVVM 编程模式中，页面视图始终和 ViewModel 如影相随，基本每个页面都会需要通过 BindingContext 绑定一个 ViewModel。

视图类与模型产生关系是通过 BindingContext 属性上绑定模型实例：

```xml
    <ContentPage.BindingContext>
        <vm:AboutViewModel />
    </ContentPage.BindingContext>
```

在模板项目中，视图模型从 BaseViewModel 继承，主要是继承 PropertyChanged 的属性变更通知事件的能力，同时获取数据接口服务以同 Web 服务器进行数据通信。

MVVM 框架会自动对实现 System.ComponentModel.INotifyPropertyChanged 接口的类型进行属性跟踪，通过它发现绑定到视图中的属性变动时，就更新视图，这就是 MVVM 的基本原理。

其中 SetProperty 和 OnPropertyChanged 方法的实现是比较值得参考的，使用了 C# 5.0 的成员名称特性 [CallerMemberName] 自动获取成员的名字字符串，这是编译期完成的：

```js
    using System;
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.Runtime.CompilerServices;

    using Xamarin.Forms;

    using XamarinVS2019.Models;
    using XamarinVS2019.Services;

    namespace XamarinVS2019.ViewModels
    {
        public class BaseViewModel : INotifyPropertyChanged
        {
            public IDataStore<Item> DataStore => DependencyService.Get<IDataStore<Item>>();

            bool isBusy = false;
            public bool IsBusy
            {
                get { return isBusy; }
                set { SetProperty(ref isBusy, value); }
            }

            string title = string.Empty;
            public string Title
            {
                get { return title; }
                set { SetProperty(ref title, value); }
            }

            protected bool SetProperty<T>(ref T backingStore, T value,
                [CallerMemberName] string propertyName = "",
                Action onChanged = null)
            {
                if (EqualityComparer<T>.Default.Equals(backingStore, value))
                    return false;

                backingStore = value;
                onChanged?.Invoke();
                OnPropertyChanged(propertyName);
                return true;
            }

            #region INotifyPropertyChanged
            public event PropertyChangedEventHandler PropertyChanged;
            protected void OnPropertyChanged([CallerMemberName] string propertyName = "")
            {
                var changed = PropertyChanged;
                if (changed == null)
                    return;

                changed.Invoke(this, new PropertyChangedEventArgs(propertyName));
            }
            #endregion
        }
    }
```

有了基础视图模型，其它页面的视图模型实现就可以简化结构，只需要通过数据服务接口获取需要的数据，或传送数据到服务器上。

ItemsViewModel 视图模型就只使用了数据服务接口的其中之一，从服务器上获取数据条目列表。考虑到 ItemsPage 页面会有 RefreshView 组件实现的下拉刷新功能，所以将数据获取的功能封装成 Command 形式，这样即使用是点击按钮，也可以通过 Command 来获取数据列表。

ItemsViewModel 视图模型中使用到了 Xamarin.Forms.MessagingCenter 消息中心，它是按订阅者编程模式编写的一个消息管理对象。消息提供方通过 Send 方发送消息广播，消息消费方通过 Subscirbe 订阅感兴趣的消息。当不再需要获取消息时，通过 Unsubscribe 取消订阅，这些静态方法原形如下，TSender 代表类型：

```js
    void Send<TSender> (TSender sender, string message);
    void Send<TSender,TArgs> (TSender sender, string message, TArgs args);

    void Subscribe<TSender,TArgs> (object subscriber, string message, Action<TSender,TArgs> callback, TSender source = null);
    void Subscribe<TSender> (object subscriber, string message, Action<TSender> callback, TSender source = null);

    void Unsubscribe<TSender> (object subscriber, string message);
    void Unsubscribe<TSender,TArgs> (object subscriber, string message);
```

使用方法：

```js
    public class SubscriberThing 
    {
        public int IntProperty { get; set; }
    }
        
    var subscriber = new SubscriberThing();
    MessagingCenter.Subscribe<MyPage, int> (subscriber, "IntPropertyMessage", 
        (sender, eventArg) => {
            subscriber.IntProperty = eventArg; 
        });
        
    //...later...
        
    MessagingCenter.Send<MyPage, int>(this, "IntPropertyMessage", 2);
    Assert.AreEqual(2, subscriber.IntProperty);
```

需要注意，Send 和 Subscirbe 两者第二个参数必须一样，双方才能实现消息连接。订阅者模式的好处是可以解耦模块的关系，不局限在同一个的功能模块，也可以通过消息中心与其他目标模块进行消息通信，实现数据传递的同时又不增加耦合关系，用完即走。

ItemsViewModel 视图模型订阅了一条 AddItem 消息，这条消息会在 NewItemPage 页面中广播，表明它在添加一条数据记录。ItemsViewModel 接收到消息后就通过数据服务接口将数据发往 Web 服务器。

# 页面功能分解 - About Page

About 页面的演示了图片和文字的处理，以及在按钮组件上使用 Command 对象来打开网页链接。

注意，在 MVVM 编程模式下，每个页面的结构基本由三个文件组件，一个实现 Model 模型，另外两个实现页面视图类，cs 文件也叫 code-behind 代码文件。

- AboutViewModel.cs 页面模型类定义;
- AboutPage.xaml 页面视图 XAML 定义;
- AboutPage.xaml.cs 页面视图类定义;

实现页面视图的两个文件是一体的，因为 AboutPage.xaml 文件编译后形成 AboutPage.xaml.g.cs 就是 partical 类，两者合一才是完整个的 View 视图类：

```js
    [assembly: global::Xamarin.Forms.Xaml.XamlResourceIdAttribute("XamarinVS2019.Views.AboutPage.xaml", "Views/AboutPage.xaml", typeof(global::XamarinVS2019.Views.AboutPage))]

    namespace XamarinVS2019.Views {
        
        
        [global::Xamarin.Forms.Xaml.XamlFilePathAttribute("Views\\AboutPage.xaml")]
        public partial class AboutPage : global::Xamarin.Forms.ContentPage {
            
            [global::System.CodeDom.Compiler.GeneratedCodeAttribute("Xamarin.Forms.Build.Tasks.XamlG", "2.0.0.0")]
            private void InitializeComponent() {
                global::Xamarin.Forms.Xaml.Extensions.LoadFromXaml(this, typeof(AboutPage));
            }
        }
    }
```

视图类与模型产生关系是通过数据绑定，即 BindingContext 属性上绑定模型实例：

    <ContentPage.BindingContext>
        <vm:AboutViewModel />
    </ContentPage.BindingContext>

其中 `vm:` 这个 XML 命名空间需要在 XAML 顶级节点定义：

```xml
    <?xml version="1.0" encoding="utf-8" ?>
    <ContentPage xmlns="http://xamarin.com/schemas/2014/forms"
                 xmlns:x="http://schemas.microsoft.com/winfx/2009/xaml"
                 xmlns:d="http://xamarin.com/schemas/2014/forms/design"
                 xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
                 mc:Ignorable="d"
                 x:Class="XamarinVS2019.Views.AboutPage"
                 xmlns:vm="clr-namespace:XamarinVS2019.ViewModels"
                 Title="{Binding Title}">
```

数据绑定是 MVVM 模式 View 视图中常用的数据访问方式，事件处理是 UI 组件的常用工具，另一种是通过 Command 命令的方式和模型进行交互： 

```xml
    <Button Margin="0,10,0,0" Text="Learn more"
            Command="{Binding OpenWebCommand}"
            BackgroundColor="{StaticResource Primary}"
            TextColor="White" />
```


视图文字部分，使用了 FormattedString 组件，这个组件可以内嵌任意 Span 字符组件。

注意图片组件，Source 属性，对于 Android 应用可以设置一个以 drawable 目录为起点的路径，位于 Resource 资源目录下：

    <Image Source="xamarin_logo.png" VerticalOptions="Center" HeightRequest="64" />

Source 是 ImageSource 类型，可以给它指定字符串，是因为 XAML 解析器会对其进行 ImageSourceConverter 做类型转换：

    [Xamarin.Forms.TypeConverter(typeof(Xamarin.Forms.ImageSourceConverter))]
    public Xamarin.Forms.ImageSource Source { get; set; }

又如：

```xml
    <Button>
        <Button.Background>
            <ImageBrush ImageSource="bg.jpg"/>
        </Button.Background>
    </Button>
```

在没有 ImageSourceConverter 转换器的条件上下，对应的的 C# 代码为

```js
    ImageBrush imageBrush = new ImageBrush();
    imageBrush.ImageSource = new BitmapImage(new Uri("bg.jpg", UriKind.Relative));
    button.Background = imageBrush;
```

# 页面功能分解 - ItemsPage

ItemsPage 是数据条目列表页面，也是由 MainPage 加载到 Detial 视图中的第一个细节页面。

在 MainPage.xaml 文件中，通过 `<x:Arguments>` 方式传入 ItemsPage 作为 MasterDetailPage 构造函数的参数，即向大纲视图填充了一个 ItemsPage 页面对象，它会在页面 MainPage 构造构造函数中的组件初始化方法 InitializeComponent 中设置好：

```xml
    <MasterDetailPage.Detail>
        <NavigationPage>
            <x:Arguments>
                <views:ItemsPage />
            </x:Arguments>
            <NavigationPage.Icon>
                <OnPlatform x:TypeArguments="FileImageSource">
                    <On Platform="iOS" Value="tab_feed.png"/>
                </OnPlatform>
            </NavigationPage.Icon>
        </NavigationPage>
    </MasterDetailPage.Detail>
```

同时还使用了 `x:TypeArguments` 这个泛型标记扩展， 即往 OnPlatform 组件传入一个泛型参数，类型为 FileImageSource，也就是显示在 Xamarin.iOS 项目目录下的图片。

ItemsPage 的构造函数中，会实例化 ItemsViewModel 视图模型对象，它在实例化时就会从数据库上获取数据列表，然后通过 BindingContext 属性绑定到 ItemsPage 上。

可以和 AboutPage 中 axml 绑定方式比较一下差别，它们作用是等价的，绑定后就可以在 xaml 中通过类似 Binding 这样的标记扩展访问模型上的数据：

```js
    BindingContext = viewModel = new ItemsViewModel();
```

```xml
    <ContentPage.BindingContext>
        <vm:AboutViewModel />
    </ContentPage.BindingContext>
```


同菜单页面一样，数据列表页面也使用了 `d:` 这个专为 Visual
Studio 设计器准备的命名空间，`<d:CollectionView.ItemsSource>` 表示为设计器中的视图填充数据，实现运行不起作用。还有 `[DesignTimeVisible(false)]` 也是设计器使用的特性，直接路过。

比较重要是数据绑定用到的标记扩展，Data Binding & Markup Extension，这里只使用了其中两个标记扩展用于数据绑定：

| 扩展标记  | 用法要点 |
| :------   | :------ |
| Binding   | 绑定标记扩展将属性值延迟为数据绑定值，创建中间表达式对象并解释在运行时应用于元素及其绑定的数据上下文。 |
| DynamicResource   | 使用推迟资源绑定到属性，该资源的查找行为类似于运行时查找。 |

在 AboutPage 中已经使用过 `BindingContext` 属性进行数据绑定的方法，但 Xamarin MVVM 数据绑定不仅局限这里用到的几种途径。

在 XAML 中定义数据绑定时，有多种方式设置 BindingContext 目标对象的。 有时，从代码隐藏文件，有时使用 StaticResource 或 x:Static 标记扩展设置，有时是 BindingContext 属性元素标记的内容。

绑定视图模型中的标题数据到 xaml 视图就最简单的一种用法 `{Binding Title}`：

```xml
    <ContentPage.ToolbarItems>
        <ToolbarItem Text="Add" Clicked="AddItem_Clicked" />
    </ContentPage.ToolbarItems>
    <Label Text="{Binding Title}" />
```

代码片断中，还设置页面的 ToolbarItems 属性，在标题栏上设置了一个 Add 按钮，用来添加数据条目。点击这个按钮就会执行页面导航，显示 NewItemPage 页面，并且以模态页面的方式呈现：

    await Navigation.PushModalAsync(new NavigationPage(new NewItemPage()));

模态页面和 MainPage 中的导航方式是显示的页面差别在于，模态页面没有后退功能，需要开发者提供模态页面的退出操作 UI 组件。

点击数据列表条目时，触发 CollectionView 列表下的 ItemSelected 事件，通过 StackLayout 堆叠布局组件下放置的 TapGestureRecognizer 组件设置，它可以识别屏幕上的触碰事件。事件触发的主体是 StackLayout，而绑定数据的主体是 CollectionView，这个列表组件会将每个数据条目绑定到 StackLayout 的 BindingContext 属性上，事件处理器中通过它来获取绑定的数据。再通过 ItemDetailPage 的构造函数传递到新的页面上显示出来：

```js
    async void OnItemSelected(object sender, EventArgs args)
    {
        var layout = (BindableObject)sender;
        var item = (Item)layout.BindingContext;
        await Navigation.PushAsync(new ItemDetailPage(new ItemDetailViewModel(item)));
    }
```

剩下 ItemDetailPage 和 NewItemPage 的页面逻辑就较简单多了，加载绑定的数据到视图中，用到的知识就是通过设置页面的 ToolbarItems 属性，在标题栏上添加页面按钮。其中创建数据条目的页面，还使用 MessagingCenter 和 ItemsViewModel 进行通信，以传送新数据到后端服务器，前面讲数据服务接口已经细说过。


# 程序集信息文件

最后顺带讲一下程序集的信息模块 AssemblyInfo。

程序集特性 [assembly] 不限于在 AssemblyInfo.cs 文件中使用，而是可以在任何的 .cs 文件中使用。 AssemblyInfo.cs 文件一般由系统自动处理。

```js
    //------------------------------------------------------------------------------
    // <auto-generated>
    //     This code was generated by a tool.
    //
    //     Changes to this file may cause incorrect behavior and will be lost if
    //     the code is regenerated.
    // </auto-generated>
    //------------------------------------------------------------------------------

    using System;
    using System.Reflection;

    [assembly: System.Reflection.AssemblyCompanyAttribute("WebApp")]
    [assembly: System.Reflection.AssemblyConfigurationAttribute("Debug")]
    [assembly: System.Reflection.AssemblyFileVersionAttribute("1.0.0.0")]
    [assembly: System.Reflection.AssemblyInformationalVersionAttribute("1.0.0")]
    [assembly: System.Reflection.AssemblyProductAttribute("WebApp")]
    [assembly: System.Reflection.AssemblyTitleAttribute("WebApp")]
    [assembly: System.Reflection.AssemblyVersionAttribute("1.0.0.0")]

    // 由 MSBuild WriteCodeFragment 类生成。
```

程序集的版本信息由下面四个值组成:

- Major Version Number 主版本号
- Minor Version Number 次版本号 
- Build Version Number 内部版本号
- Revision Version Number 修订版本号

可以指定所有这些值，也可以使用内部版本号和修订号的默认值，方法是使用 `*` 替代具体数值:

```js
    [assembly:AssemblyTitle("程序集标题")]
    [assembly:AssemblyDescription("程序集描述")]
    [assembly:AssemblyProduct("产品名称")]
    [assembly:AssemblyCompany("公司名称")]
    [assembly:AssemblyTrademark("合法商标")]
    [assembly:AssemblyCulture("区域性")]
    [assembly:AssemblyCopyright("Copyright 2014")]

    // 配置文件，如零售、发布、调试等信息。程序集在运行时不会使用该信息
    [assembly:AssemblyConfiguration("")]
    [assembly:AssemblyVersion("1.0.*.0")]

    // 控制程序集中所有类型对COM的可访问性
    [assembly:ComVisible(false)]
    // 如果此项目向 COM 公开，则下列 GUID 用于类型库的 ID
    [assembly: Guid("77bf07c6-941f-4ba7-b95d-6a5c18401f74")]
```

对于同一个特性，程序集中仅能设置一次，否则编译时将报错。

```js
    [assembly:AssemblyProduct("DemoProduct")]
    namespace Company.App {
      public class Demo{
      }
    }
```

要读取程序集的信息，通过反射技术实现：

```js
    // Type t = obj.GetType();
    Type t = typeof(Program);
    AssemblyProductAttribute pd = t.Assembly.GetCustomAttributes(
        typeof(AssemblyProductAttribute), true)[0] as AssemblyProductAttribute;
    Console.WriteLine(pd.Product);
```

# 截屏展示

| About | MenuPage  | NamedColor |
|--|--|--|
| ![about](https://images.gitbook.cn/61f2fa40-b8d5-11ea-85d7-7f2c1a676408) | ![menu](https://images.gitbook.cn/1d1f5940-b8d5-11ea-809d-01f3be381c22)  | ![nameedcolor](https://images.gitbook.cn/50fb9030-b8d5-11ea-af4f-db1aea8b8c95) |

# 参考
- [Xamarin 数据绑定基础知识](https://docs.microsoft.com/zh-cn/xamarin/xamarin-forms/xaml/xaml-basics/data-binding-basics)
- [Perform Navigation in a Multi-Page Xamarin.Forms Application](https://docs.microsoft.com/en-us/xamarin/get-started/quickstarts/multi-page)

借用 Xamarin 团队的一句话结束本文：
> 感谢你的努力学习！