using System;
using System.IO;
using System.Text;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using XamarinVS2019.Models;

namespace XamarinVS2019.Controllers
{
    [Route("api/item")]
    [ApiController]
    public class ItemController : ControllerBase
    {
        private readonly IItemRepository ItemRepository;

        public ItemController(IItemRepository itemRepository)
        {
            ItemRepository = itemRepository;
        }

        [HttpGet]
        [ProducesResponseType(StatusCodes.Status200OK)]
        public ActionResult<IEnumerable<Item>> List()
        {
            Log(this.GetType().Name + " List()");
            return ItemRepository.GetAll().ToList();
        }

        [HttpGet("{id}")]
        [ProducesResponseType(StatusCodes.Status200OK)]
        [ProducesResponseType(StatusCodes.Status404NotFound)]
        public ActionResult<Item> GetItem(string id)
        {
            Log(this.GetType().Name + " GetItem(string id)");
            Item item = ItemRepository.Get(id);

            if (item == null)
                return NotFound();

            return item;
        }

        [HttpPost]
        [ProducesResponseType(StatusCodes.Status201Created)]
        [ProducesResponseType(StatusCodes.Status400BadRequest)]
        // public async Task<ActionResult<Item>> CreateAsync([FromBody] Item item)
        public ActionResult<Item> Create([FromBody] Item item)
        {
            Log(this.GetType().Name + $" Create([FromBody] Item {item}...)");
            ItemRepository.Add(item);
            return CreatedAtAction(nameof(GetItem), new { item.Id }, item);
        }

        [HttpPut]
        [ProducesResponseType(StatusCodes.Status204NoContent)]
        [ProducesResponseType(StatusCodes.Status400BadRequest)]
        public ActionResult Edit([FromBody] Item item)
        {
            Log(this.GetType().Name + " Edit([FromBody] Item item)");
            try
            {
                ItemRepository.Update(item);
            }
            catch (Exception)
            {
                return BadRequest("Error while editing item");
            }
            return NoContent();
        }

        [HttpDelete("{id}")]
        [ProducesResponseType(StatusCodes.Status200OK)]
        [ProducesResponseType(StatusCodes.Status404NotFound)]
        public ActionResult Delete(string id)
        {
            Log(this.GetType().Name + "  Delete(string id)");
            Item item = ItemRepository.Remove(id);

            if (item == null)
                return NotFound();

            return Ok();
        }

        public void Log(string msg)
        {
            var url = HttpContext.Request.Path + " " + HttpContext.Request.QueryString;
            Console.WriteLine("{0:h:mm:ss.ff} - {1} {2}", DateTime.Now, msg, url);
        }
    }
}
