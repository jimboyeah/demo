using System;
using System.IO;
using System.Collections.Generic;
using Microsoft.AspNetCore.Hosting;
using Microsoft.Extensions.Hosting;
using System.Security.Cryptography.X509Certificates;

namespace XamarinVS2019.Web
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
                    webBuilder.UseStartup<Startup>()
                        .UseKestrel(options =>
                        {
                            options.ConfigureHttpsDefaults(i =>
                            {
                                // i.ServerCertificate = new X509Certificate2("ca-test/localhost.pfx", "123456");
                                i.ServerCertificate = new X509Certificate2("ca-test/localhost-friendly.pfx");
                            });
                        })
                        .UseContentRoot(Directory.GetCurrentDirectory());
                        // .UseUrls("https://*:443");
                });
    }
}