using System;
using System.ComponentModel;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc.Razor.TagHelpers;
using Microsoft.AspNetCore.Razor.TagHelpers;
using Microsoft.Extensions.Logging;

namespace AppWeb.TagHelpers
{
    [HtmlTargetElement("me")] // <me asp-href="demo.css">Test Me</me>
    [EditorBrowsable(EditorBrowsableState.Never)]
    public class MyTagComponentTagHelper : TagHelperComponentTagHelper
    {
        public MyTagComponentTagHelper(
            ITagHelperComponentManager manager, 
            ILoggerFactory loggerFactory) : base(manager, loggerFactory) 
        {
            //...
        }

        public override async Task ProcessAsync(TagHelperContext context,
                                          TagHelperOutput output)
        {
            TagHelperContent childContent = await output.GetChildContentAsync();
         
            output.TagName = "b";
            var text = childContent.GetContent().ToUpper()+DateTime.Now.ToString(" ss-fff");
            output.Content.AppendHtml(text);
            Console.WriteLine("TagHelperComponentTagHelper....{0}", context.TagName);
        }
    }
    
    public class LinkStyleTagComponent : TagHelperComponent
    {
        private string _style = 
            @"<link rel=""stylesheet"" href=""@"" />";

        public override int Order => 1;

        public LinkStyleTagComponent()
        {
            // ...
        }

        public override async Task ProcessAsync(TagHelperContext context,
                                          TagHelperOutput output)
        {
            TagHelperContent childContent = await output.GetChildContentAsync();
         
            if (string.Equals(context.TagName, "head", // body or head
                StringComparison.OrdinalIgnoreCase))
            {
                var style = _style.Replace("@", "/css/demo.css");
                output.PostContent.AppendHtml(style);
            }
            // Console.WriteLine("TagHelperComponent....{0}", context.TagName);
        }
    }

    // [HtmlTargetElement("email", TagStructure = TagStructure.NormalOrSelfClosing)]
    // [HtmlTargetElement("email", TagStructure = TagStructure.WithoutEndTag)] 
    [HtmlTargetElement("email")]
    public class EmailTagHelper : TagHelper
    {
        // passed by <email to="name@domain.com" />
        public string To { get; set; }

        public EmailTagHelper()
        {
            //...
        }

        public override void Process(TagHelperContext context, TagHelperOutput output)
        {
            output.TagName = "a";    // Replaces <email> with <a> tag

            string href = "mailto:"+To;
            output.Attributes.SetAttribute("href", href);
            // string inner = output.Content.GetContent();
            output.Content.SetContent($"<i>{To}</i>");
            output.TagMode = TagMode.StartTagAndEndTag; // SelfClosing or StartTagOnly
            // output.SuppressOutput();
        }

        public override async Task ProcessAsync(TagHelperContext context, TagHelperOutput output)
        {
            output.TagName = "a"; // Replaces <email> with <a> tag
            var childContent = await output.GetChildContentAsync();
            string content = childContent.GetContent();
            output.Attributes.SetAttribute("href", "mailto:" + To);
            output.Content.SetHtmlContent($"<b>{content}</b>");
            // foreach(var a in output.Attributes)
            // {
            //     Console.WriteLine("TagHelper {0}:{1}", a.Name, a.Value);
            // }
        }
    }

}
