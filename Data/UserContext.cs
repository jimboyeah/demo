using System;
using System.Collections.Generic;
using System.Text;
using MySql.Data.MySqlClient;
// using MC = MySql.Data.MySqlClient;
// using Pomelo.EntityFrameworkCore.MySql;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace AppWeb.Data
{
	// [Keyless]
	// [Table("users", Schema = "main")]
	[Table("users")]
	public class UserDTO
	{
		[NotMapped]
		public Guid guid { get; set; }
		[Key]
		public int Id { get; set; }
		public string name { get; set; } = "";
		public string email { get; set; }
		#nullable enable
		public string? nickname { get; set; }
		public int? level { get; set; }
		public DateTime created_at { get; set; }
		#nullable disable
	}

	public class UserContext
	{
		public string ConnectionString { get; set; }
		public UserContext(string connectionString)
		{
			this.ConnectionString = connectionString;
		}

		private MySqlConnection GetConnection()
		{
			return new MySqlConnection(ConnectionString);
		}

		public List<UserDTO> GetAllUsers()
		{
			List<UserDTO> list = new List<UserDTO>();
			using (MySqlConnection msconnection = GetConnection())
			{
				try {
					msconnection.Open();
				}catch{
					Console.WriteLine("Error to connect database...");
					return list;
				}
				MySqlCommand mscommand = new MySqlCommand("select id,name,nickname,email,level,created_at from users", msconnection);
				using (MySqlDataReader reader = mscommand.ExecuteReader())
				{
					while (reader.Read())
					{
						list.Add(new UserDTO()
						{
							guid = Guid.NewGuid(),
							Id = reader.IsDBNull(reader.GetOrdinal("id"))? -1: reader.GetInt32("id"),
							name = reader.IsDBNull(reader.GetOrdinal("name"))? null: reader.GetString("name"),
							nickname = reader.IsDBNull(reader.GetOrdinal("nickname"))? null: reader.GetString("nickname"),
							email = reader.IsDBNull(reader.GetOrdinal("email"))? null: reader.GetString("email"),
							level = reader.IsDBNull(reader.GetOrdinal("level"))? -1: reader.GetInt32("level"),
							created_at = reader.IsDBNull(reader.GetOrdinal("created_at"))? new DateTime(): reader.GetDateTime("created_at")
						});
					}
				}
			}
			return list;
		}
	}

}
