using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Logging;

namespace AppWeb.Pages
{
    public class SignalRModel : PageModel
    {
        private readonly ILogger<SignalRModel> _logger;

        public SignalRModel(ILogger<SignalRModel> logger)
        {
            _logger = logger;
        }

        public void OnGet()
        {
        }
    }
}
