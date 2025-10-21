/*
#include<iostream>
#include <string>
#include<curl/curl.h>

//Note: Needs to be run in x64 Release mode.

int main() {
	CURL* curl;
	CURLcode res;

	std::string ftpUrl = "ftp://example.com/myfile.txt";
	std::string username = "myusername";
	std::string password = "mypassword";
	std::string ftpCommand = "RNFR myfile.txt";
	std::string renameCommand = "RNTO newfile.txt";

	curl_global_init(CURL_GLOBAL_DEFAULT);

	curl = curl_easy_init();
	if (curl) {
		struct curl_slist* headerlist = NULL;
		headerlist = curl_slist_append(headerlist, ftpCommand.c_str());

		headerlist = curl_slist_append(headerlist, renameCommand.c_str());

		curl_easy_setopt(curl, CURLOPT_URL, ftpUrl.c_str());
		curl_easy_setopt(curl, CURLOPT_USERNAME, username.c_str());
		curl_easy_setopt(curl, CURLOPT_PASSWORD, password.c_str());
		curl_easy_setopt(curl, CURLOPT_POSTQUOTE, headerlist);
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

		res = curl_easy_perform(curl);

		if (res != CURLE_OK) {
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		}
		curl_slist_free_all(headerlist);

		curl_easy_cleanup(curl);
	}

	curl_global_cleanup();
	return 0;
}

*/