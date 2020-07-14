using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Components.Web;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Logging;
using AppWeb;
using AppWeb.Data;

namespace AppWeb.Pages
{
    public class IndexModel : PageModel
    {
        private readonly ILogger<IndexModel> _logger;

        [BindProperty(SupportsGet = true)] 
        public string Name {get; set;} = "anonymous";

        public const string SessionKeyName = "_name";
        public const string SessionKeyCount = "_count";

        public string SessionName { get; private set; }
        public string SessionCount { get; private set; }

        public List<UserDTO> data { get; set; }

        public IndexModel(ILogger<IndexModel> logger)
        {
            _logger = logger;
        }

        public void set()
        {
            int count = HttpContext.Session.GetInt32(SessionKeyCount) ?? 1;
            HttpContext.Session.SetString(SessionKeyName, "Second");
            HttpContext.Session.SetInt32(SessionKeyCount, ++count);
        }

        public void OnGet()
        {
            set();
            UserContext uc = HttpContext.RequestServices.GetService(typeof(UserContext)) as UserContext;
            data = uc.GetAllUsers();
            Console.WriteLine($"IndexModel.OnGet() {data.Count} {data[0]}...");
        }
    }
}
