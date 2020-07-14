using System;
using System.Collections.Generic;

namespace AppWeb.Data.reverse
{
    public partial class PasswordResets
    {
        public string Email { get; set; }
        public string Token { get; set; }
        public DateTimeOffset? CreatedAt { get; set; }
    }
}
