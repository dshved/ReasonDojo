let apiEndpoint = "http://immense-river-25513.herokuapp.com/locations";

type dojoLocation = {
  username: string,
  location: Map.coordinates,
};

let decodeLocaton = (json: Js.Json.t) : dojoLocation => {
  open! Json.Decode;
  {
    username: json |> field("username", string),
    location: json |> field("location", pair(float, float)),
  };
};

let getData = () =>
  Js.Promise.(
    Fetch.fetch(apiEndpoint)
    |> then_(Fetch.Response.json)
    |> then_(json => Json.Decode.array(decodeLocaton, json) |> resolve)
  );
