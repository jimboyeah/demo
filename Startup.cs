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
using Microsoft.EntityFrameworkCore;
// using Pomelo.EnityFrameworkCore.MySql;
// using MySql.Data.MySqlClient;
using System.Globalization;
using Microsoft.AspNetCore.Http;
using Huanent.Logging.File.UI;
using AppWeb;
using AppWeb.Data;
using AppWeb.Data.reverse;
using AppWeb.TagHelpers;
using ContosoUniversity;
using ContosoUniversity.Data;
using ContosoUniversity.Models;
using System.ComponentModel;
using Microsoft.AspNetCore.Mvc.Razor.TagHelpers;
using Microsoft.AspNetCore.Razor.TagHelpers;


namespace AppWeb
{
    public class Startup
    {
        public Startup(IConfiguration configuration)
        {
            Configuration = configuration;
        }

        public IConfiguration Configuration { get; }

        // This method gets called by the runtime. Use this method to add services to the container.
        public void ConfigureServices(IServiceCollection services)
        {
            // MvcBuilder Console.WriteLine($"AddRasorPage {services.AddRazorPages()}");

            services.AddSignalR();
            services.AddControllersWithViews();
            services.AddServerSideBlazor();

            services.AddTransient<ITagHelperComponent, LinkStyleTagComponent>();

            // services.AddLoggingFileUI();

            services.AddDistributedMemoryCache();

            services.AddRazorPages()
                .AddRazorPagesOptions(options => {
                    options.Conventions.AddPageRoute("/Session", "TheSessionPage/{text?}");
                });

            services.AddSession(options =>
            {
                options.IdleTimeout = TimeSpan.FromSeconds(10);
                options.Cookie.HttpOnly = true;
                options.Cookie.IsEssential = true;
            });

            services.AddSingleton<WeatherForecastService>();

            string cons = Configuration.GetConnectionString("DefaultConnection");
            services.Add(new ServiceDescriptor(typeof(UserContext), new UserContext(cons)));

            // services.AddSingleton<UserDC>();
            services.AddDbContext<UserDC>();

            services.AddDbContext<ReverDBContext>(options =>
                options.UseMySQL(Configuration.GetConnectionString("DefaultConnection")));

            services.AddDbContext<SchoolContext>(options =>
                // options.UseMySQL(Configuration.GetConnectionString("MySql")));
                options.UseSqlite(Configuration.GetConnectionString("SchoolContext")));
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
            app.UseSession();

            app.UseRequestCulture();

            // app.Run(async (context) =>
            // {
            //     Console.WriteLine($"Culture DisplayName {CultureInfo.CurrentCulture.DisplayName}");
            //     await context.Response.WriteAsync(
            //         $"Hello {CultureInfo.CurrentCulture.DisplayName}");
            // });


            app.UseHttpsRedirection();

            // app.UseDefaultFiles();
            app.UseStaticFiles();
            // app.UseMvc()
            // MvcOptions.EnableEndpointRouting = false;

            app.UseRouting();

            app.UseAuthorization();
            app.UseAuthorization();


            app.UseEndpoints(endpoints =>
            {
                endpoints.MapRazorPages();
                endpoints.MapBlazorHub();

                endpoints.MapControllers(); // use [Route] attributes

                endpoints.MapFallbackToPage("/_Host");
                endpoints.MapControllerRoute(
                    name: "myhome",
                    pattern: "{controller=Home}/{action=Index}/{Name?}");
                // endpoints.MapControllerRoute(
                //     name: "default",
                //     pattern: "api/{controller=Hello}/{action=Index}/{id?}");
                endpoints.MapHub<ChatHub>("/hub");
            });
        }
    }
}
