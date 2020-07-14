using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Hosting;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using Microsoft.Extensions.Logging;
using ContosoUniversity.Data;

namespace AppWeb
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
                    // context.Database.EnsureCreated();
                    SchoolDbInitializer.Initialize(context);
                }
                catch (Exception ex)
                {
                    var logger = services.GetRequiredService<ILogger<Program>>();
                    logger.LogError(ex, "An error occurred creating the DB.");
                    Console.WriteLine("\n\n\n+++++++++++++++++++++{0}",ex);
                }
            }
        }


        public static IHostBuilder CreateHostBuilder(string[] args) =>
            Host.CreateDefaultBuilder(args)
                .ConfigureWebHostDefaults(webBuilder =>
                {
                    webBuilder.UseStartup<Startup>()
                        // .UseUrls("http://*:5000;http://localhost:5001;https://hostname:5002")
                        // .UseWebRoot("public")
                        // .UseStartup("StartupAssemblyName")
                        // .UseSetting("https_port", "8080")
                        .ConfigureLogging(builder => builder.AddFile());

                    webBuilder.UseStartup<Startup>()
                        .UseKestrel(options =>
                        {
                            options.ConfigureHttpsDefaults(i =>
                            {
                                // i.ServerCertificate = new X509Certificate2("ca-test/localhost.pfx", "123456");
                                i.ServerCertificate = new X509Certificate2("../XamarinVS2019/XamarinVS2019.Web/ca-test/localhost.pfx", "123456");
                            });
                        })
                        .UseContentRoot(Directory.GetCurrentDirectory())
                        .UseUrls("https://*:443");
                });
    }
}
