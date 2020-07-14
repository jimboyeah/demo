using System;
using System.Collections.Generic;

namespace AppWeb.Data.reverse
{
    public partial class Orders
    {
        public long Id { get; set; }
        public DateTimeOffset? CreatedAt { get; set; }
        public DateTimeOffset? UpdatedAt { get; set; }
    }
}
