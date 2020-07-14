using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
// using MySql.Data;
// using MySql.Data.EntityFrameworkCore;
// using Pomelo.EntityFrameworkCore.MySql;
using Microsoft.Extensions.Configuration;

namespace AppWeb.Data
{
	public class UserDC : DbContext
	{
		public UserDC (DbContextOptions<UserDC> options)
			// : base(options)
		{
			IConfiguration Configuration = new ConfigurationBuilder()
			    .SetBasePath(Environment.CurrentDirectory)
			    .AddJsonFile("appSettings.json")
			    .Build();

			cons = Configuration.GetConnectionString("Sqlite");
			Console.WriteLine($"CONNECTION SQLITE {cons} {options}");
		}

		protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
		{
			optionsBuilder.UseSqlite(cons);
			// optionsBuilder.UseMySQL(cons);
		}

		protected override void OnModelCreating(ModelBuilder modelBuilder)
		{
			modelBuilder.Entity<UserDTO>()
	    		.Property(b => b.nickname)
	    		.IsRequired();

	    	// modelBuilder.Query<UserDTO>();
		}


		public string cons = "";
		public DbSet<UserDTO> UserDTO { get; set; } = null;
			// { 
			// 	_users = value;//.Where(i => i.nickname!=null).ToList();
			// 	Console.WriteLine($"set {value}");
			// 	foreach(var i in value)
			// 	{
			// 		if(i.nickname==null) i.nickname = "";
			// 		Console.WriteLine($"set... {i.name} {i.nickname} {i.email} {i.level} {i.created_at}");
			// 	}
			// }
	}
}
