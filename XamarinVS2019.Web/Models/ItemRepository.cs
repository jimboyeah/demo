using System;
using System.Collections.Generic;
using System.Collections.Concurrent;

namespace XamarinVS2019.Models
{
    public class ItemRepository : IItemRepository
    {
        private static ConcurrentDictionary<string, Item> items =
            new ConcurrentDictionary<string, Item>();

        public ItemRepository()
        {
            Add(new Item { 
                Id = Guid.NewGuid().ToString(), 
                Text = "Item 1", 
                Description = "对 Android SDK 工具的更改" });
            Add(new Item { 
                Id = Guid.NewGuid().ToString(), 
                Text = "Item 2", 
                Description = "Android SDK 25.3.0 和更高版本管理 Android SDK 和 Android 虚拟设备。" });
            Add(new Item { 
                Id = Guid.NewGuid().ToString(), 
                Text = "Item 3", 
                Description = "https://192.168.0.112:5001/localhost-friendly.pfx" });
        }

        public IEnumerable<Item> GetAll()
        {
            return items.Values;
        }

        public void Add(Item item)
        {
            item.Id = Guid.NewGuid().ToString();
            items[item.Id] = item;
        }

        public Item Get(string id)
        {
            items.TryGetValue(id, out Item item);
            return item;
        }

        public Item Remove(string id)
        {
            items.TryRemove(id, out Item item);
            return item;
        }

        public void Update(Item item)
        {
            items[item.Id] = item;
        }
    }
}
