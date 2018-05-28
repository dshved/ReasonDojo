type state = {dojos: array(Api.dojoLocation)};

type action =
  | Fetch(array(Api.dojoLocation));

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  didMount: self => {
    Js.Promise.then_(
      data => {
        self.send(Fetch(data));
        Js.Promise.resolve(data);
      },
      Api.getData(),
    );
    ();
  },
  initialState: () => {dojos: [||]},
  reducer: (action, _state) =>
    switch (action) {
    | Fetch(data) => ReasonReact.Update({dojos: data})
    },
  render: self =>
    <div>
      <Map.ComposableMap width=800 height=600>
        <Map.ZoomableGroup>
          <Map.Geographies geography="../world.json">
            ...(
                 (geographies, projection) =>
                   Array.map(
                     geography =>
                       <Map.Geography
                         geography
                         key=(Map.Geographies.id(geography))
                         projection
                       />,
                     geographies,
                   )
               )
          </Map.Geographies>
          <Map.Markers>
            (
              ReasonReact.array(
                Array.map(
                  marker =>
                    <Map.Marker
                      key=marker.Api.username
                      marker=(
                        Map.MarkerData.marker(
                          ~coordinates=marker.Api.location,
                        )
                      )>
                      <circle cx="0" cy="0" r="6" fill="red" />
                    </Map.Marker>,
                  self.state.dojos,
                ),
              )
            )
          </Map.Markers>
        </Map.ZoomableGroup>
      </Map.ComposableMap>
    </div>,
};