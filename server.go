package main

import (
	"github.com/zserge/webview"
	"log"
	"net"
	"net/http"
)

func startServer() string {
	ln, err := net.Listen("tcp", "127.0.0.1:0") // Port 0 for randomly
	if err != nil {
		log.Fatal(err)
	}
	go func() {
		defer ln.Close()
		http.HandleFunc("/test", func(w http.ResponseWriter, r *http.Request) {
			w.Write([]byte(`<h1>Go Working!</h1>`))
		})
		http.Handle("/static/", http.StripPrefix("/static/", http.FileServer(http.Dir("./"))))
		log.Fatal(http.Serve(ln, nil))
	}()
	return "http://" + ln.Addr().String()
}

func handleRPC(w webview.WebView, data string) {
	log.Println("Handle PRC", data)
	switch data {
	case "close":
		w.Terminate()
	case "fullscreen":
		w.SetFullscreen(true)
	}
}

func main() {
	url := startServer() + "/static/readme_bizCharts.html"
	w := webview.New(webview.Settings{
		Width:                  980,
		Height:                 640,
		Title:                  "Simple Window demo",
		Resizable:              true,
		URL:                    url,
		ExternalInvokeCallback: handleRPC,
	})
	log.Println("Serve on: ", url)
	w.SetColor(255, 0, 255, 128)
	defer w.Exit()
	w.Run()
}
