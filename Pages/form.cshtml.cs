using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Components.Web;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Logging;
using Huanent.Logging.File;
using AppWeb;

namespace AppWeb.Pages
{
    public class MyModel {

        [BindProperty(SupportsGet = true)] 
        public string Name {get; set;} = "anonymous";

        [BindProperty] 
        public int Age {get; set;} = 18;

    }

    public class FormModel : PageModel
    {
        [BindProperty] 
        public int id {get; set;} = 18;

        [BindProperty(SupportsGet = true)] 
        public string Name {get; set;} = "anonymous";

        [Range(18, 60)]
        [BindProperty]
        public int Age {get; set;} = 8;

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
                return RedirectToPage("/home/welcome");
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
}
