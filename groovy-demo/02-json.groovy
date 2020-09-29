/*
Groovy - JSON https://www.tutorialspoint.com/groovy/groovy_json.htm
dependency to groovy-all artifact in this project or a separate ivy-2.4.0.jar
*/

// https://mvnrepository.com/artifact/org.apache.ivy/ivy
// https://mvnrepository.com/artifact/org.codehaus.groovy/groovy-all
// https://mvnrepository.com/artifact/org.codehaus.groovy/groovy-json
@Grapes([
    @Grab(group='org.apache.ivy', module='ivy', version='2.5.0'),
    @Grab(group='org.codehaus.groovy', module='groovy-all', version='3.0.5'),
    @Grab(group='org.codehaus.groovy', module='groovy-json', version='3.0.5')
])
// @Grab("org.codehaus.groovy:groovy-json")

import groovy.json.JsonSlurper;
// import org.apache.ivy.plugins.resolver.DependencyResolver;

class Example 
{
   static void main(String[] args) 
   {
      def jsonSlurper = new JsonSlurper();
      def object = jsonSlurper.parseText('{ "name": "John", "ID" : "1"}');
    
      println(object.name);
      println("object.ID");
   } 
}
