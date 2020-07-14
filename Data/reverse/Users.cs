using System;
using System.Collections.Generic;

namespace AppWeb.Data.reverse
{
    public partial class Users
    {
        public long Id { get; set; }
        public string Name { get; set; }
        public string Nickname { get; set; }
        public string Email { get; set; }
        public DateTimeOffset? EmailVerifiedAt { get; set; }
        public string Password { get; set; }
        public int? Level { get; set; }
        public string RememberToken { get; set; }
        public DateTimeOffset? CreatedAt { get; set; }
        public DateTimeOffset? UpdatedAt { get; set; }
    }
}
