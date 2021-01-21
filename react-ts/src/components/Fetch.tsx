import Fetch from 'isomorphic-fetch';

// http://www.ruanyifeng.com/blog/2020/12/fetch-tutorial.html

// let def: object = {
//     mode: "no-cors", // 非跨域模式下只加载不访问返回内容
//     method: "GET",
//     headers: {
//       "Content-Type": "application/x-www-form-urlencoded"
//     },
//     body: ""
// };

function fetch(url: string, params?: object | undefined)
{
  return Fetch(url, params)
  .then((res: Response) => {
    let type = res.headers.get("Content-Type") || "text";
    if(res.status>400) throw new Error("Bad response from server");
    console.log('fetch body', type, res);
    // res.headers.forEach((v: string, k:string)=>console.log(k, v));
    // return for next then() method
    return res;
  })
  // .then((body: object) =>{
  //   console.log('fetch body', body);
  //   // return for next then() method
  //   return "done!";
  // })
}
function get(url: string, params:{method:string}|object = {method: 'GET'})
{
    return fetch(url, params).then((res: Response)=>{
      let type = res.headers.get("Content-Type") || "text";
      return type.indexOf("json")<0? res.text():res.json();
    });
}
function post(url: string, params:{method:string}|object = {method: 'POST'})
{
    return fetch(url, params).then((res: Response)=>{
      let type = res.headers.get("Content-Type") || "text";
      return type.indexOf("json")<0? res.text():res.json();
    });
}
export default Fetch
export {get, post, fetch}
