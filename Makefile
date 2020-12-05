start: test.cpp
	c++ -std=c++17 test.cpp

deploy:
	echo "${DPASS}" | docker login -u "${DUSER}" --password-stdin
	docker push "${DUSER}"/RSA
