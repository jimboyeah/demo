using Microsoft.EntityFrameworkCore.Migrations;

namespace AppWeb.Migrations
{
    public partial class update_20 : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<bool>(
                name: "IsMajor",
                table: "Course",
                nullable: true);

            migrationBuilder.AddColumn<string>(
                name: "Version",
                table: "Course",
                nullable: true);
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "IsMajor",
                table: "Course");

            migrationBuilder.DropColumn(
                name: "Version",
                table: "Course");
        }
    }
}
