using System;
using System.Linq;
using System.Threading.Tasks;
using AppWeb.Models;

namespace AppWeb.Data
{
    public class WeatherForecastService
    {
        public Task<WeatherForecast[]> GetForecastAsync(DateTime startDate)
        {
        	var ran = new Random();
        	return Task.FromResult(Enumerable.Range(1,5).Select(index => new WeatherForecast{
        		Date = startDate.AddDays(index),
        		TemperatureC = ran.Next(-30, 50),
        		Summary = Summaries[ran.Next(Summaries.Length)]
        		}).ToArray());
        }

        public string[] Summaries = new[]
        {
        	"Freezing", "Bracing", "Chilly", 
        	"Cool", "Mild", "Warm", 
        	"Balmy", "Hot", "Sweltering", "Scorching"
        };
    }
}
