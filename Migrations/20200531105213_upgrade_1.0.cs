using System;
using Microsoft.EntityFrameworkCore.Migrations;

namespace AppWeb.Migrations
{
    public partial class upgrade_10 : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            Console.WriteLine("upgrade_10 UP...");
            migrationBuilder.DropColumn(
                name: "IsMajor",
                table: "Course");
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            Console.WriteLine("upgrade_10 Down...");
            migrationBuilder.AddColumn<int>(
                name: "IsMajor",
                table: "Course",
                type: "int",
                nullable: false,
                defaultValue: 0);
        }
    }
}
