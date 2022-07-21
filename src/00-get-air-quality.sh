
CITY=americana
AQICN_TOKEN=YOUR_TOKEN_HERE

if [ -f ~/secrets.sh ]; then
  . ~/secrets.sh
fi

FILENAME=../data/${CITY}-air-quality.json

if [ ${AQICN_TOKEN} == "YOUR_TOKEN_HERE" ]; then
   echo "  1 - Go to http://aqicn.org/data-platform/token/#/ and obtain a token."
   echo "  2 - Open this file and replace YOUR_TOKEN with the token you have"
   echo "      received from the site."
else
   curl https://api.waqi.info/feed/${CITY}/?token=${AQICN_TOKEN} -o ${FILENAME}
   echo "File wrote to ${FILENAME}"
fi
