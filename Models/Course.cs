using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;

namespace ContosoUniversity.Models
{
    public class Course
    {
        [DatabaseGenerated(DatabaseGeneratedOption.None)]
        public int CourseID { get; set; }
        public string Title { get; set; }
        public int Credits { get; set; }
        #nullable enable
        public bool? IsMajor { get; set; }
        public string? Version { get; set; }
        #nullable disable

        public ICollection<Enrollment> Enrollments { get; set; }
    }
}
