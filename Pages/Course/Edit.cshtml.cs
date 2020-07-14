using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using AppWeb.TagHelpers;
using ContosoUniversity.Data;
using ContosoUniversity.Models;
using System.ComponentModel.DataAnnotations;

namespace AppWeb.Pages.Courses
{
    public class EditModel : PageModel
    {
        private readonly ContosoUniversity.Data.SchoolContext _context;

        [BindProperty]
        public List<SelectListItem> items {get; set; } = new List<SelectListItem>{
            new SelectListItem{ Value = "false", Text = "False" },
            new SelectListItem{ Value = "true", Text = "True" },
            };

        public enum YesNo
        {
            [Display(Name = "No")]
            Yes,
            [Display(Name = "Yes")]
            No
        }

        // private readonly ITagHelperComponentManager _tagHelperComponentManager;

        public EditModel(ContosoUniversity.Data.SchoolContext context)
        {
            _context = context;
        }

        // public EditModel(ContosoUniversity.Data.SchoolContext context,
        //     ITagHelperComponentManager tagHelperComponentManager,
        //     ILoggerFactory loggerFactory)
        // {
        //     _context = context;

        //     _tagHelperComponentManager = tagHelperComponentManager;
        //     _tagHelperComponentManager.Components.Add(new LinkStyleTag());
        // }

        [BindProperty]
        public Course Course { get; set; }

        public async Task<IActionResult> OnGetAsync(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            Course = await _context.Courses.FirstOrDefaultAsync(m => m.CourseID == id);

            if (Course == null)
            {
                return NotFound();
            }
            return Page();
        }

        // To protect from overposting attacks, enable the specific properties you want to bind to, for
        // more details, see https://aka.ms/RazorPagesCRUD.
        public async Task<IActionResult> OnPostAsync()
        {
            if (!ModelState.IsValid)
            {
                return Page();
            }

            _context.Attach(Course).State = EntityState.Modified;

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!CourseExists(Course.CourseID))
                {
                    return NotFound();
                }
                else
                {
                    throw;
                }
            }

            return RedirectToPage("./Index");
        }

        private bool CourseExists(int id)
        {
            return _context.Courses.Any(e => e.CourseID == id);
        }
    }
}
