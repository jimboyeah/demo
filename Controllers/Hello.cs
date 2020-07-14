using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using AppWeb.Data;

namespace AppWeb
{
    [Route("[controller]")]
    [ApiController]
    public class Hello : Controller
    {
        private readonly UserDC _context;

        public Hello(UserDC context)
        {
            _context = context;
        }

        // GET: Hello
        [HttpGet]
        public async Task<ActionResult<IEnumerable<UserDTO>>> GetUserDTO()
        {
            Console.WriteLine($"Hello.GetUserDTO()");
            var userDTO = await _context.UserDTO.ToListAsync();
            ViewData["data"] = userDTO;
            return View();
        }

        // GET: Hello/5
        [HttpGet("{id}")]
        public async Task<ActionResult<IEnumerable<UserDTO>>> Details(int id)
        {
            Console.WriteLine($"Hello.Details(id={id})");
            var userDTO = await _context.UserDTO.ToListAsync();
            ViewData["data"] = userDTO;
            return View();
        }


        // GET: Hello/5/name
        [Route("api/hello/edit", Name="api_edit")]
        [HttpGet("{id}/{name}")]
        // public async Task<ActionResult<UserDTO>> GetUserDTO(int id, string name = "NONAME")
        public object GetUserDTO(int id, string name)
        {
            Console.WriteLine($"Hello.GetUserDTO(id={id}, name={name})");
            HttpRequest req = HttpContext.Request;
            string testForm = req.HasFormContentType ? req.Form["name"].ToString():"NO";
            Console.WriteLine("[{0}|{1}|{2}] [Path: {3}] [QueryString: {4}]", 
                string.Join(",", req.RouteValues.Keys), testForm, req.Query["name"], req.Path, req.QueryString);

            var userDTO = _context.UserDTO.ToList();
            ViewData["data"] = userDTO;

            if (userDTO == null)
            {
                return NotFound(); // return HTTP 404
            }

            return View();
            // return userDTO;
        }

        // PUT: Hello/5
        // To protect from overposting attacks, enable the specific properties you want to bind to, for
        // more details, see https://go.microsoft.com/fwlink/?linkid=2123754.
        [HttpPut("{id}")]
        public async Task<IActionResult> PutUserDTO(int id, UserDTO userDTO)
        {
            if (id != userDTO.Id)
            {
                return BadRequest();
            }

            _context.Entry(userDTO).State = EntityState.Modified;

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!UserDTOExists(id))
                {
                    return NotFound();
                }
                else
                {
                    throw;
                }
            }

            return NoContent();
        }

        // POST: Hello
        // To protect from overposting attacks, enable the specific properties you want to bind to, for
        // more details, see https://go.microsoft.com/fwlink/?linkid=2123754.
        [HttpPost]
        public async Task<ActionResult<UserDTO>> PostUserDTO(UserDTO userDTO)
        {
            _context.UserDTO.Add(userDTO);
            await _context.SaveChangesAsync();

            return CreatedAtAction("GetUserDTO", new { id = userDTO.Id }, userDTO);
        }

        // DELETE: Hello/5
        [HttpDelete("{id}")]
        public async Task<ActionResult<UserDTO>> DeleteUserDTO(int id)
        {
            var userDTO = await _context.UserDTO.FindAsync(id);
            if (userDTO == null)
            {
                return NotFound();
            }

            _context.UserDTO.Remove(userDTO);
            await _context.SaveChangesAsync();

            return userDTO;
        }

        private bool UserDTOExists(int id)
        {
            return _context.UserDTO.Any(e => e.Id == id);
        }
    }
}
