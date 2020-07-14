using Microsoft.AspNetCore.Http;
using System.Globalization;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Builder;
using System;

namespace AppWeb
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
                Console.WriteLine(cultureQuery);

            }

            // Call the next delegate/middleware in the pipeline
            await _next(context);
        }
    }
}


    namespace AppWeb
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